#include <iostream>
#include <vector>
#include <exception>
#include <fstream>
#include <sstream>
#include "GrayLevelImage2D.hpp"
using namespace std;

// pas besoin d'ecrire les constructeurs par copie et d'affectation car ils sont generes automatiquement

// mise en place du type
typedef unsigned char GrayLevel; // le type pour les niveaux de gris.

// declare method of class GrayLevelImage2d.hpp
GrayLevelImage2D::GrayLevelImage2D()
{
    m_width = 0;
    m_height = 0;
}

GrayLevelImage2D::GrayLevelImage2D(int w, int h, GrayLevel g)
{
    m_width = w;
    m_height = h;
    // resize rempoli automatiquement de 0
    m_data.resize(w * h, g);
}

void GrayLevelImage2D::fill(GrayLevel g)
{
    m_data.assign(m_width * m_height, g);
}

int GrayLevelImage2D::w() const
{
    return m_width;
}

int GrayLevelImage2D::h() const
{
    return m_height;
}

GrayLevel GrayLevelImage2D::at(int i, int j) const
{
    return m_data[i + j * m_width];
}

GrayLevel &GrayLevelImage2D::at(int i, int j)
{
    return m_data[i + j * m_width];
}

// index function
int GrayLevelImage2D::index(int i, int j) const
{
    return i + j * m_width;
}

GrayLevelImage2D::Iterator::Iterator(GrayLevelImage2D &image, int x, int y)
    : Container::iterator(image.m_data.begin() + image.index(x, y))
{
}

GrayLevelImage2D::Iterator GrayLevelImage2D::begin()
{
    return Iterator(*this, 0, 0);
}

GrayLevelImage2D::Iterator GrayLevelImage2D::end()
{
    return Iterator(*this, 0, m_height);
    // ou return Iterator(*this, m_width, m_height-1);
}

GrayLevelImage2D::Iterator GrayLevelImage2D::start(int x, int y)
{
    return Iterator(*this, x, y);
}

std::pair<int, int> GrayLevelImage2D::position(Iterator it) const
{
    int x = it - m_data.begin();
    int y = x / m_width;
    x = x % m_width;
    return std::make_pair(x, y);
}


string readline(std::istream &input) {
    string str;
    do {
        getline( input, str );
    } while (str != ""  && str[0]=='#');
    return str;
}

bool GrayLevelImage2D::importPGM(std::istream &input) {
    if ( ! input.good() ) return false;
    std::string format = readline(input);
    std::string line = readline(input);
    std::string delim = " ";
    m_width = std::stoi(line.substr(0, line.find(delim)));
    line.erase(0, line.find(delim) + delim.length());
    m_height = std::stoi(line);
    std::cout << m_width << " " << m_height << " " << format << std::endl;
    std::cout << readline(input) << std::endl; // grayscale range
    fill(0);
    if (format == "P5") {
        input >> std::noskipws;
        unsigned char v;
        for ( Iterator it = begin(), itE = end(); it != itE; ++it ) {
            input >> v;
            *it = v;
        }
    } else {
        input >> std::skipws;
        int v;
        for ( Iterator it = begin(), itE = end(); it != itE; ++it ) {
            input >> v;
            *it = v;
        }
    }
    return true;
}

bool 
GrayLevelImage2D::exportPGM( ostream & output, bool ascii ) {
    // write header
    output << "P5" << endl;
    output << m_width << " " << m_height << endl;
    output << "255" << endl;
    // write data
    if (ascii)
    {
        for (int j = 0; j < m_height; ++j)
        {
            for (int i = 0; i < m_width; ++i)
            {
                output << (int)at(i, j) << " ";
            }
            output << endl;
        }
    }
    else
    {
        for ( Iterator it = begin(), itE = end(); it != itE; ++it ) {
            output << *it;
        }
    }
    return true;
}