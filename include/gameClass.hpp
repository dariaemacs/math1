#ifndef gameClass_H
#define gameClass_H
#include <SFML/Graphics.hpp>
#include <array>

class gameClass {
private:
    sf::Clock clock;
    std::array<char, 16> marks;
    //int yy;
    float width;
    float  height ;
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

    static gameClass* get_instance();
    static float getHeight();
    static float getWidth();
};
#endif 