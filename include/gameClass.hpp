#ifndef gameClass_H
#define gameClass_H
#include <SFML/Graphics.hpp>
#include <array>

class gameClass {
private:
    sf::Clock clock;
    std::array<char, 16> marks;
    int yy;

    gameClass();
    gameClass(const gameClass&) = default;
    gameClass(gameClass&&) = default;

    gameClass& operator=(const gameClass&) = default;
    gameClass& operator=(gameClass&&) = default;
    ~gameClass() = default;

public:
    static float  get_time();
    //char& operator[](const char);
    static char getMarks(int);
    static void setmarks(int, char);
    static gameClass* get_instance();
    
};
#endif 