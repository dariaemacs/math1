#ifndef timerClass_H
#define timerClass_H
#include <SFML/Graphics.hpp>
class timerClass {
private:
    sf::Clock clock;
    int yy;

    timerClass();
    timerClass(const timerClass&) = default;
    timerClass(timerClass&&) = default;

    timerClass& operator=(const timerClass&) = default;
    timerClass& operator=(timerClass&&) = default;

    ~timerClass() = default;

public:
    static float  get_time();
    static timerClass* get_instance();
    
};
#endif 