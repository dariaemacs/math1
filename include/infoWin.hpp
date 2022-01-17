#ifndef infoWin_H
#define infoWin_H

#include "window.hpp"
#include "menuButton.hpp"
#include "SimpleText.hpp"

class infoWin : public window {

    menuButton  startButton;
    menuButton resultButton;
    SimpleText text1;
    
    sf::Texture picresultTexture;
    sf::Sprite  picresultSprite;
    
    SimpleText text2;
    SimpleText text3;
    SimpleText text4;
    SimpleText text5;
    SimpleText text6;


    sf::RectangleShape rectangleLeft;
    sf::RectangleShape rectangleRight;
public:
    infoWin();
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};
#endif 