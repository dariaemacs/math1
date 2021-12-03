#include <SFML/Graphics.hpp>
class Mysf_text : public  sf::Text {
    int size;
public:
    Mysf_text(int s);
    void CalcucateCoordinate(float, float);
    int getSize();
};
