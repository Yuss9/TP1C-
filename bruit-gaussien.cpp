#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "GrayLevelImage2D.hpp"
#include "GrayLevelImage2D.cpp"
#include <math.h>

using namespace std;

double rand01()
{
  return (double)random() / (double)RAND_MAX;
}

int main(int argc, char **argv)
{
  typedef GrayLevelImage2D::GrayLevel GrayLevel;
  typedef GrayLevelImage2D::Iterator Iterator;
  if (argc < 2)
  {
    std::cerr << "Usage: bruit-gaussian <input.pgm> <prob> <power>" << std::endl;
    return 0;
  }
  GrayLevelImage2D img;
  ifstream input("lena.pgm");
  bool ok = img.importPGM(input);
  if (!ok)
  {
    std::cerr << "Error reading input file." << std::endl;
    return 1;
  }
  input.close();

  double prob = (argc > 2) ? atof(argv[2]) : 0.01;
  double power = (argc > 3) ? atof(argv[3]) : 50;

  // double prob = 0.35;
  // double power = 50;
  for (Iterator it = img.begin(), itE = img.end(); it != itE; ++it)
  {
    if (rand01() < prob)
    {
      // formule de Box-Muller
      *it = *it + power * (sqrt(-2 * log(rand01())) * cos(2 * M_PI * rand01()));
    }
  }
  ofstream output("bruited_" + string("lena.pgm"));
  ok = img.exportPGM(output, false);
  if (!ok)
  {
    std::cerr << "Error writing output file." << std::endl;
    return 1;
  }
  output.close();
  return 0;
}