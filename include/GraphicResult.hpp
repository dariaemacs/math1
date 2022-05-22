#ifndef GraphicResult_H
#define GraphicResult_H


#include "window.hpp"
#include "menuButton.hpp"
#include "SimpleText.hpp"
#include "filesSave.hpp"







class GraphicResult : public window {

    menuButton  BackButton;
    sf::RectangleShape x;
    sf::RectangleShape y;
    sf::Font font;
    std::vector < sf::Text> vertDigit;
    std::vector < sf::Text> horzDigit;
    std::vector <sf::RectangleShape> verticalLabels;
    std::vector <sf::RectangleShape> horizLabels;
    std::vector <sf::CircleShape> pointS;
    sf::Text comment;
    sf::RectangleShape rectangleComment;
    filescontrol filesSaveData;
public:
    GraphicResult();
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};
#endif 