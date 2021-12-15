#include "timerClass.hpp"

 timerClass* timerClass::get_instance() {
    static timerClass instance;
    return &instance;
}

float  timerClass::get_time() {
    sf::Time elapsed1 =  get_instance()->clock.getElapsedTime();
    return elapsed1.asSeconds();
}
timerClass::timerClass() { clock.restart(); }