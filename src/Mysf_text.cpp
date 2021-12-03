#include "Mysf_text.hpp"
void Mysf_text::CalcucateCoordinate(float w, float h) {

    sf::String  tmp = getString();
    setString("99");
    setCharacterSize(size);
    float width = getLocalBounds().width;
    float height = getLocalBounds().height;
    while (width >= w || height >= h)
    {
        if (size > 0) setCharacterSize(size--); else return;
        width = getLocalBounds().width;
        height = getLocalBounds().height;
    }
    setString(tmp);
};

int Mysf_text::getSize() { return size; }

Mysf_text::Mysf_text(int s) : size(s) {}

