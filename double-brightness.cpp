// double-brightness.cpp
#include <iostream>
#include <fstream>
#include "GrayLevelImage2D.hpp"
#include "GrayLevelImage2D.cpp"
using namespace std;

// void filtrageMedian(int dimension, string fileName)
// {
//   GrayLevelImage2D img;
//   ifstream input(fileName); // récupère le 1er argument.
//   bool ok = img.importPGM(input);
//   if (!ok)
//   {
//     std::cerr << "Error reading input file." << std::endl;
//   }
//   input.close();


//   //on applique le filtrage median sur l'image entree
//   GrayLevelImage2D imgFiltree = img.filtrageMedian(dimension);
// }

int main(int argc, char **argv)
{
  // typedef GrayLevelImage2D::GrayLevel GrayLevel;
  // typedef GrayLevelImage2D::Iterator Iterator;

  // GrayLevelImage2D img;
  // ifstream input("lena-input.pgm"); // récupère le 1er argument.
  // bool ok = img.importPGM(input);
  // if (!ok)
  // {
  //   std::cerr << "Error reading input file." << std::endl;
  //   return 1;
  // }
  // input.close();
  // // for (Iterator it = img.begin(), itE = img.end(); it != itE; ++it)
  // {
  //   *it = (2 * (int)(*it)) % 256;
  // }

  //make copy of img
  // GrayLevelImage2D img2 = GrayLevelImage2D(img);

  // for (Iterator it = img2.begin(), itE = img2.end(); it != itE; ++it)
  // {
  //   *it = (2 * (int)(*it)) % 256;
  // }

  // ofstream output( "lenalena.pgm" ); // récupère le 2ème argument.
  // ok = img.exportPGM( output, false );
  // if ( !ok )
  //   {
  //     std::cerr << "Error writing output file." << std::endl;
  //      return 1;
  //   }
  // output.close();
  // return 0;



  typedef GrayLevelImage2D::GrayLevel GrayLevel;
  typedef GrayLevelImage2D::Iterator  Iterator;
  // if ( argc < 3 ) 
  //   { 
  //     std::cerr << "Usage: double-brightness <input.pgm> <output.pgm>" << std::endl;
  //     return 0;
  //   }
  GrayLevelImage2D img;
  ifstream input( "lena.pgm"); // récupère le 1er argument.
  bool ok = img.importPGM( input );
  if ( !ok )
    {
      std::cerr << "Error reading input file." << std::endl;
       return 1;
    }
  input.close();
  // for ( Iterator it = img.begin(), itE = img.end(); it != itE; ++it )
  //   {
  //     *it = ( 2 * (int)(*it) ) % 256;
  //   }
  // ofstream output( "lenalena.pgm" ); // récupère le 2ème argument.
  // ok = img.exportPGM( output, false );
  // if ( !ok )
  //   {
  //     std::cerr << "Error writing output file." << std::endl;
  //      return 1;
  //   }
  // output.close();
  return 0;

}
