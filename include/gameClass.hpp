#ifndef gameClass_H
#define gameClass_H
#include <SFML/Graphics.hpp>
class gameClass {
private:
    sf::Clock clock;
    int yy;

    gameClass();
    gameClass(const gameClass&) = default;
    gameClass(gameClass&&) = default;

    gameClass& operator=(const gameClass&) = default;
    gameClass& operator=(gameClass&&) = default;

    ~gameClass() = default;

public:
    static float  get_time();
    static gameClass* get_instance();
    
};
#endif 