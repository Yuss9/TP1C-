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

bool GrayLevelImage2D::importPGM(std::istream &input)
{
    // read header
    // string magic;
    // input >> magic;


    stringstream ss;    
    string inputLine = "";

    getline(input,inputLine);  


    bool isP5 = false;
    if (inputLine != "P5")
    {
        cerr << "Error: magic number is not P5" << endl;
    }
    else
    {
        isP5 = true;
    }

    getline(input,inputLine);  // read the second line : comment
    if(inputLine[0] == '#'){
        cout << "Comment: " << inputLine << endl;
    }
    else{
        ss << input.rdbuf();
        ss >> m_width >> m_height;
        cout << m_width << " columns and " << m_height << " rows" << endl;
    }


    // string comment = "";
    // getline(input, comment); // read the second line : comment
    // cout << "Comment : " << comment << endl;

    // read width and height
    // input >> m_width >> m_height;
    // cout << "la taille de l'image est " << m_width << " " << m_height << endl;

    ss << input.rdbuf();   //read the third line : width and height
    ss >> m_width >> m_height;
    cout << m_width << " columns and " << m_height << " rows" << endl;


    // read max gray level
    // int max_gray_level;
    // input >> max_gray_level;

    // cout << "le max gray level de l'image est : " << max_gray_level << endl;

    // if (max_gray_level != 255)
    // {
    //     cerr << "Error: max gray level is not 255" << endl;
    //     return false;
    // }

    int max_val;  //maximum intensity value : 255
    ss >> max_val;
    cout<<max_val;

    // read data
    m_data.resize(m_width * m_height);

    if (isP5)
    {
        unsigned char gl;
        for (Iterator it = begin(), itE = end(); it != itE; ++it)
        {
            input >> gl;
            *it = gl;
        }
    }else{
        int gl;
        for (Iterator it = begin(), itE = end(); it != itE; ++it)
        {
            input >> gl;
            *it = gl;
        }
    }


    //print all image
    for (Iterator it = begin(), itE = end(); it != itE; ++it)
    {
        cout << *it << " ";
    }



    return true;
}

bool GrayLevelImage2D::exportPGM(std::ostream &output, bool ascii)
{
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
        //write in file with for loop
        for (int j = 0; j < m_height; ++j)
        {
            for (int i = 0; i < m_width; ++i)
            {
                output << (unsigned char)at(i, j);
            }
        }
    }
    return true;
}

// GrayLevelImage2D filtrageMedian(int dimension);
//  GrayLevelImage2D GrayLevelImage2D::filtrageMedian(int dimension){
//      //Noise removal using Median filter in C++

// }