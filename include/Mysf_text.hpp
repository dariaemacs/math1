#ifndef Mysf_text_H
#define Mysf_text_H
#include <SFML/Graphics.hpp>
class Mysf_text : public  sf::Text {
    int size;
public:
    Mysf_text(int s);
    void CalcucateCoordinate(float, float);
    int getSize();
};

#endif 
