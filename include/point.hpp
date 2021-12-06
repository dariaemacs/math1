#ifndef point_H
#define point_H

#include <SFML/Graphics.hpp>
class squareBoard;
struct coord { float x, y; coord(float xx, float yy) :x(xx), y(yy) {}; coord() :x(0), y(0) {}; };

class point : public sf::RectangleShape {

    float x, y; //coord in pixel
    float i, j;  //coord in board 
    float size; //size of point 
    squareBoard* Sb;
    public:
    point(float);
    float getSize();
    void setSb(squareBoard* sBB);
    void setPosition(float, float);
    coord getPixelCoord();
    coord getBoardCoord();


};



#endif




