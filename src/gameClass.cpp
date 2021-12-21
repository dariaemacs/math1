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


//void gameClass::setMarks(int index, int value) { get_instance()->marks[index] = value; }


char gameClass::getMarks(int index) { return get_instance()->marks[index]; }
void gameClass::setmarks(int index, char value) { get_instance()->marks[index]=value; }
