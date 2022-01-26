#ifndef endGame_H
#define endGame_H


#include "window.hpp"
#include "menuButton.hpp"
#include "SimpleText.hpp"


class endGame : public window {

    menuButton  againButton;
    menuButton  exitButton;
    

    //std::array <std::shared_ptr<SimpleText>, 34> labels;
    std::array <SimpleText, 34> labels;
    

    sf::RectangleShape rectangleLeft;
    sf::RectangleShape rectangleRight;
public:
    endGame();
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};
#endif 