#include "gameClass.hpp"

gameClass* gameClass::get_instance() {
    static gameClass instance;
    return &instance;
}

float gameClass::get_time() {
    sf::Time elapsed1 =  get_instance()->clock.getElapsedTime();
    return elapsed1.asSeconds();
}
gameClass::gameClass() { 
    quit = false;
}

void gameClass::clockRestart() {
    get_instance()->clock.restart();
}

void gameClass::setquit() { get_instance()->quit = true; }
bool gameClass::getquit() { return get_instance()->quit; }
//void gameClass::setMarks(int index, int value) { get_instance()->marks[index] = value; }


char gameClass::getMarks(int index) { return get_instance()->marks[index]; }
void gameClass::setmarks(int index, char value) { get_instance()->marks[index]=value; }



void gameClass::setwinParams(float w, float h) {
    get_instance()->width = w;
    get_instance()->height = h;
}

float gameClass::getHeight() {
    return get_instance()->height;
}

float gameClass::getWidth() {
    return get_instance()->width;
}