#ifndef gameClass_H
#define gameClass_H
#include <SFML/Graphics.hpp>
#include <array>

class gameClass {
private:
    sf::Clock clock;
    std::array<char, 16> marks;
    bool quit;
    float width;
    float  height ;
    bool   isGame; //game or graphic
    gameClass();
    gameClass(const gameClass&) = default;
    gameClass(gameClass&&) = default;

    gameClass& operator=(const gameClass&) = default;
    gameClass& operator=(gameClass&&) = default;
    ~gameClass() = default;

public:
    static float  get_time();
    static char getMarks(int);
    static void setmarks(int, char);
    static void setwinParams(float, float);
    static void clockRestart();
    static void setisGame(bool);
    static void setquit();

    static bool getquit();
    static gameClass* get_instance();
    static float getHeight();
    static float getWidth();
    static bool getisGame();
};
#endif 