#include <iostream>
#include <vector>
#include <exception>
#include <fstream>
#include <sstream>
#include "histogramme.hpp"
using namespace std;


Histogramme::Histogramme()
{
    h.resize(256);
    H.resize(256);
}


// Cette classe aura une méthode void init( GrayLevelImage2D & img ), qui parcourera l'image pour calculer son histogramme et son histogramme cummulé.
void Histogramme::init(GrayLevelImage2D & img)
{
    for (int i = 0; i < img.w(); i++)
    {
        for (int j = 0; j < img.h(); j++)
        {
            h[img.at(i,j)]++;
        }
    }
    H[0] = h[0];
    for (int i = 1; i < 256; i++)
    {
        H[i] = H[i-1] + h[i];
    }
}


int Histogramme::egalisation( int j ) const
{
    return 255 * H[j]/(double) H[255];
}



