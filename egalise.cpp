#include <iostream>
#include <vector>
#include <exception>
#include "Histogramme.hpp"
#include "Histogramme.cpp"

int main()
{
    GrayLevelImage2D img;
    ifstream input("lena.pgm"); // récupère le 1er argument.
    bool ok = img.importPGM(input);
    if (!ok)
    {
        std::cerr << "Error reading input file." << std::endl;
        return 1;
    }
    input.close();

    Histogramme histo;
    histo.init(img);


    //egalisation de l'image
    for (int i = 0; i < img.w(); i++)
    {
        for (int j = 0; j < img.h(); j++)
        {
            img.at(i,j) = histo.egalisation(img.at(i,j));
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