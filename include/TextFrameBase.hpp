#ifndef TextFrameBase_H1
#define TextFrameBase_H1
#include <SFML/Graphics.hpp>
class window;
class TextFrameBase {


    sf::Text text;
    sf::Font font;
    float size;
    float w;
    float h;
    float margin_top;
    window& WindowLink;
protected:
    int questionNumber;

public:
    TextFrameBase(float, window& winLink, char); //delegate
    TextFrameBase(float, int, int, int, window&);
    TextFrameBase(float s, std::wstring str, float, float, window&);
    sf::Text gettext();
    void settext(std::wstring a);
    void setmargin_top(float m);
    float getmargin_top();
    void CalcucateCoordinate(float, float);

    float getHeight();
    void setN_M(int, int);
    void setquestionNumber(int qn);
    float getSize();


};

#endif