#ifndef _HISTOGRAMME_HPP
#define _HISTOGRAMME_HPP

#include <iostream>
#include <vector>
#include <exception>
#include "GrayLevelImage2D.hpp"
#include "GrayLevelImage2D.cpp"

using namespace std;

class Histogramme
{
public:
    Histogramme();
    void init( GrayLevelImage2D & img );
    int egalisation( int j ) const;

private:
    //histogramme normal
    vector<double> h;
    //histogramme cumulée
    vector<double> H;
};

#endif // #ifndef _HISTOGRAMME_HPP
