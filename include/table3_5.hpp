#ifndef table3_5_H1
#define table3_5_H1
#include <array>
#include <SFML/Graphics.hpp>
class window;
class table3_5 {
    std::array < sf::Text, 6> Celltext;
    float mash_koeff;
    float mash_width;
    float mash_height;
    float mash_x;
    float mash_y;
    float tablemax_y;
    float fontSize;
    float height0Row;
    float margintop;
protected:

    std::array < sf::VertexArray, 5> verticalline;
    std::array < sf::VertexArray, 5> horizline;
    std::array < sf::Text, 6> text;
    sf::Font font;
    window& WindowLink;
public:
    float getheight0Row();
    float getmash_koeff();
    float getmargintop();
    float getmash_width();
    float getmash_height();
    float gettablemax_y();
    float getmash_x();
    float getmash_y();
    table3_5(window&);
    void calcFontSize(const int w, const int h);
    void draw();
};
#endif