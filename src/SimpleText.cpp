#include "SimpleText.hpp"
#include "gameClass.hpp"
SimpleText::SimpleText(std::wstring s) :str(s),margin_left(0),margin_top(0) {

	font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
	setString(s);
	setFont(font);
	setCharacterSize(50);
	setFillColor(sf::Color::Black);


};

SimpleText::SimpleText() :SimpleText::SimpleText(L"") {}

void SimpleText::ñalcucateCoordinate() {
    ñalcucateCoordinate(gameClass::getWidth(), gameClass::getWidth());
}

void SimpleText::setSize(float s) {
    setCharacterSize(static_cast<unsigned int>(s));
}

float SimpleText::getSize() {
    return getCharacterSize();
}
void SimpleText::ñalcucateCoordinate(float w, float h) {

    float size = 50;
    setCharacterSize(static_cast<unsigned int>(size));
    float width  = getLocalBounds().width; 
    float height = getLocalBounds().height;
    while (width > w|| height > h) {
        if (size > 0) { size--;  setCharacterSize(static_cast<unsigned int>(size)); }
        else return;
        width  = getLocalBounds().width;
        height =getLocalBounds().height;
    }



}

float SimpleText::getmargin_top() { return margin_top; }
float SimpleText::getmargin_left() { return margin_left; };

float SimpleText::getwidth() { 
    return getLocalBounds().width;
}
float SimpleText::getheight() { 
    return getLocalBounds().height; 
};



void SimpleText::setmargin_top(float t)  { 
    setPosition(margin_left, t);
    margin_top = t;
}
void SimpleText::setmargin_left(float l) { 
    setPosition(l, margin_top) ;
    margin_left = l;

}