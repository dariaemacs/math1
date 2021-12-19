#include "gameClass.hpp"

gameClass* gameClass::get_instance() {
    static gameClass instance;
    return &instance;
}

float gameClass::get_time() {
    sf::Time elapsed1 =  get_instance()->clock.getElapsedTime();
    return elapsed1.asSeconds();
}
gameClass::gameClass() { clock.restart(); }