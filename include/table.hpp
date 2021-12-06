#ifndef table_H
#define table_H
#include <array>
#include <SFML/Graphics.hpp>
#include "window.hpp"

class table {

    float mash_koeff;
    float mash_width;
    float mash_height;
    float mash_x;
    float mash_y;
    float tablemax_y;

protected:

    std::array < sf::VertexArray, 5> verticalline;
    std::array < sf::VertexArray, 5> horizline;
    std::array < sf::Text, 6> text;
    sf::Font font;
    window& WindowLink;
public:
    table(window&);
    void draw();
    float getmash_koeff();
    float getmash_width();
    float getmash_height();
    float gettablemax_y();
    float getmash_x();
    float getmash_y();

};

#endif