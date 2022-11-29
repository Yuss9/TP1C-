#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include "histogramme.hpp"

int main(int argc, char **argv)
{
    typedef GrayLevelImage2D::GrayLevel GrayLevel;
    typedef GrayLevelImage2D::Iterator Iterator;
    if (argc < 2)
    {
        std::cerr << "Usage: filtre-median <input.pgm>" << std::endl;
        return 0;
    }
    GrayLevelImage2D img;
    ifstream input(argv[1]); // récupère le 1er argument.
    bool ok = img.importPGM(input);
    if (!ok)
    {
        std::cerr << "Error reading input file." << std::endl;
        return 1;
    }
    input.close();

    Histogramme histo;
    histo.init(img);

    // egalisation de l'image
    for (int i = 0; i < img.w(); i++)
    {
        for (int j = 0; j < img.h(); j++)
        {
            img.at(i, j) = histo.egalisation(img.at(i, j));
        }
    }

    // export image
    ofstream output("lenaHistogramme.pgm"); // récupère le 2ème argument.
    ok = img.exportPGM(output, false);
    if (!ok)
    {
        std::cerr << "Error writing output file." << std::endl;
        return 1;
    }
    output.close();
    return 0;
}