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

bool GrayLevelImage2D::importPGM( istream & input ) {
     // read header
    string str;
    getline( input, str );
    if (str != "P5")
    {
        cerr << endl << "Error: str number is not P5" << endl;
        return false;
    }

    getline( input, str );
    if (( str != "" ) && (str[0]=='#')) 
        cout << endl << "Commentaire : " << str << endl;
    // read width and height
    input >> m_width >> m_height;
    cout<<"la taille de l'image est "<<m_width<<" "<<m_height<<endl;
    // read max gray level
    int max_gray_level;
    input >> max_gray_level;

    cout<<"le max gray level de l'image est : "<<max_gray_level<<endl;

    if (max_gray_level != 255)
    {
        cerr << "Error: max gray level is not 255" << endl;
        return false;
    }
    // read data
    m_data.resize(m_width * m_height);

    //read data with unsigned char 
    input.read((char *)&m_data[0], m_width * m_height);

    //print pixel
    /*for (int i = 0; i < m_width * m_height; i++)
    {
        cout << (int)m_data[i] << " ";
    }*/

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
        output.write((char *)&m_data[0], m_width * m_height);
    }
    return true;
}