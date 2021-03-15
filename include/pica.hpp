#ifndef PICA_H
#define PICA_H

#include <SFML/Graphics.hpp>

enum types {

    square = 4, 
    circle = 0, 
    rectangle = 40, 
    triangle = 3, 

};

struct pica {
    enum types type;

    int r;

    float x0;
    float y0;

    float x1;
    float y1;

    float x2;
    float y2;

    sf::Color FillColor;
    sf::Color outlineColor;

    float OutlineThickness;
    float angle;
    float width;
    float height;
};

#endif //PICA_H
