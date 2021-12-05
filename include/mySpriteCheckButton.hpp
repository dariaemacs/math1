#ifndef mySpriteCheckButton_H
#define mySpriteCheckButton_H
// здесь идет собственно тело h-ника

#include <SFML/Graphics.hpp>

class mySpriteCheckButton : public sf::Sprite {
    float top;
    float left;
    std::string fn;
    bool active;
public:
    mySpriteCheckButton() ;
    void setActive();
    void setPicturefnm(std::string fnn);
    std::string getFN();
    bool getActive();
    void setTop(float t);
    void setLeft(float l);
};

#endif //mySpriteCheckButton_H