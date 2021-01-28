#ifndef PICA_H
#define PICA_H

#include <SFML/Graphics.hpp>

enum types {

    square = 4, //квадрат
    circle = 0, //круг
    rectangle = 40, //прямоугольник
    triangle = 3, //треугольник по трем вершинам

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
#pragma once
