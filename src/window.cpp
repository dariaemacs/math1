#include "window.hpp"


#include <iostream>
#include <sstream>
#include <locale>

#include <vector>
#include "settings.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "database.hpp"
#include <fstream>
#include <locale>
#include <algorithm>
#include <math.h>
#include "figures.hpp"
#include "QuestType2.hpp"



#define maximal(a, b) (((a)>(b))?(a):(b))
#define minimal(a, b) (((a)<(b))?(a):(b))
#define three_minimal(a, b, c) minimal(minimal(a, b), c)

//int QuestType1::QTY = 1;
extern const int ELAPSED_TIME;
extern std::vector< std::vector<int>> numSeries;

inline void delay(clock_t sec)
{
    clock_t start_time = clock();
    clock_t end_time = sec + start_time;
    while (clock() != end_time);
};



float window::getWidth() { return width; }
float window::getHeight() { return height; }
int window::getQuestNumber() { return questNumber; }
int window::getordQuestNumber() { return ordQuestNumber; }
TextFrameBase window::gettextFrame() { return textFrame; }
std::shared_ptr<sf::RenderWindow> window::getWindow() { return win; }

bool window::afterAsk() {
    sf::Time elapsed1 = clock.getElapsedTime();
    if (elapsed1.asSeconds() >= 1) { QTYofBLINK++; clock.restart(); }
    std::cout << QTYofBLINK << std::endl;
       
        return  (QTYofBLINK > 8);
   
}



std::wstring get_wstr(int questvariantIndex, int ordNumber) {
    //    setlocale(LC_ALL, "Russian");
    std::stringstream ss;
    ss << (ordNumber + 1) << ". ";
    std::string str = ss.str();

    std::wstring ws(str.begin(), str.end());
    ws += qestionarrayList[ordNumber][questvariantIndex].questionText.c_str();

    return ws;
};
window::window(float w, float h, int numberQuest, int ord)

    : badAnswer(false),
    ordQuestNumber(ord),
    questNumber(numberQuest),
    readyforCheck(false),
    first(true),
    textFrame(Settings::QUESTFONTSIZE, numberQuest, static_cast<unsigned int>(w), static_cast<unsigned int>(h), *this),
    QuestComment(Settings::QUESTFONTSIZE, CommentsDic[0], w, h, *this),
    countofBALL(0),
    wasAnswer(false),
    QTYofBLINK(0),
    isNextQuest(false)

{

    TimeRect.setSize(sf::Vector2f(120, 50));
    TimeRect.setFillColor(sf::Color(255, 255, 255, 128));
    timestringView.setString("test");
    timestringViewFont.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    timestringView.setFont(timestringViewFont);
    timestringView.setCharacterSize(10);
    timestringView.setColor(sf::Color(255, 255, 255, 128));


    TimeRect.setOutlineColor(sf::Color::Red);
    TimeRect.setOutlineThickness(5);
    TimeRect.setPosition(10, 20);

    width = w;
    height = h;
    std::string CheckButtonPictureFileName = "resources/images/arrow_disable.png";
    ArrowButtonTexture.loadFromFile(CheckButtonPictureFileName);
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    ArrowButtonSprite.scale(Settings::ButtonFactor, Settings::ButtonFactor);
    const sf::IntRect& CheckButtonRect = ArrowButtonSprite.getTextureRect();
    float CheckButtonWidth = CheckButtonRect.width * Settings::ButtonFactor;
    ArrowButtonSprite.move(width - CheckButtonWidth, 0);
    //
    List.setSize(sf::Vector2f(width, height));
    List.setPosition(0, 0);
    List.setFillColor(sf::Color::White);
    sf::Clock clock;




    //if (!first) {
    std::string comment = std::string("Game ") + std::to_string(static_cast<unsigned int>(w)) + "x" + std::to_string(static_cast<unsigned int>(h));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    win = std::make_unique<sf::RenderWindow>(sf::VideoMode(static_cast<unsigned int>(w), static_cast<unsigned int>(h)), comment, sf::Style::Default, settings);//,  sf::Style::Fullscreen);
    win->setFramerateLimit(static_cast<unsigned int>(Settings::FPS));




}




bool window::checkandnextQuest(float scale) {

    const sf::Vector2i& M = sf::Mouse::getPosition(*win);
    const sf::Vector2f& position = ArrowButtonSprite.getPosition();
    const sf::IntRect& rect = ArrowButtonSprite.getTextureRect();
    ////std::cout << scale << rect.width << std::endl;
    float x0 = position.x;
    float y0 = position.y;
    float x1 = x0 + rect.width * Settings::ButtonFactor;
    float y1 = y0 + rect.height * Settings::ButtonFactor;


    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
        ////std::cout << "rect height = "<< rect.height <<" "<< M.x <<"*"<< x0 << " " << M.x <<"*"<< x1 <<" " << M.y <<"*"<< y0 <<" " << M.y <<"*"<< y1<< std::endl;
        return true;
    }
    return false;
}






















