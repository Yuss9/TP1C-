// double-brightness.cpp
#include <iostream>
#include <fstream>
#include "GrayLevelImage2D.hpp"
#include "GrayLevelImage2D.cpp"
using namespace std;

int testMedianFilter()
{
  typedef GrayLevelImage2D::GrayLevel GrayLevel;
  typedef GrayLevelImage2D::Iterator Iterator;
  // if (argc < 3)
  // {
  //   std::cerr << "Usage: double-brightness <input.pgm> <output.pgm>" << std::endl;
  //   return 0;
  // }
  GrayLevelImage2D img;
  ifstream input("lenaBruit.pgm"); // récupère le 1er argument.
  bool ok = img.importPGM(input);
  if (!ok)
  {
    std::cerr << "Error reading input file." << std::endl;
    return 1;
  }
  input.close();

  img.medianFilter(10);

  // for (Iterator it = img.begin(), itE = img.end(); it != itE; ++it)
  // {
  //   *it = (2 * (int)(*it)) % 256;
  // }

  ofstream output("lenaBruitSol.pgm"); // récupère le 2ème argument.
  ok = img.exportPGM(output, false);
  if (!ok)
  {
    std::cerr << "Error writing output file." << std::endl;
    return 1;
  }
  output.close();
  return 0;
}

int main(int argc, char **argv)
{
  typedef GrayLevelImage2D::GrayLevel GrayLevel;
  typedef GrayLevelImage2D::Iterator Iterator;
  // if (argc < 3)
  // {
  //   std::cerr << "Usage: double-brightness <input.pgm> <output.pgm>" << std::endl;
  //   return 0;
  // }
  GrayLevelImage2D img;
  ifstream input("lenaBruit.pgm"); // récupère le 1er argument.
  bool ok = img.importPGM(input);
  if (!ok)
  {
    std::cerr << "Error reading input file." << std::endl;
    return 1;
  }
  input.close();

  img.medianFilter(10);

  // for (Iterator it = img.begin(), itE = img.end(); it != itE; ++it)
  // {
  //   *it = (2 * (int)(*it)) % 256;
  // }

  ofstream output("lenaBruitSol.pgm"); // récupère le 2ème argument.
  ok = img.exportPGM(output, false);
  if (!ok)
  {
    std::cerr << "Error writing output file." << std::endl;
    return 1;
  }
  output.close();
  return 0;
}
