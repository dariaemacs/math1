#include "mySpriteCheckButton.hpp"

mySpriteCheckButton::mySpriteCheckButton() : fn("empty.jpg"), active(false) {};
void mySpriteCheckButton::setActive() {
    if (!active) fn = "select.png"; else fn = "empty.jpg";
    active = !active;
};
void mySpriteCheckButton::setPicturefnm(std::string fnn) {
    fn = fnn;
};


void mySpriteCheckButton::setTop(float t) { top = t; }
void mySpriteCheckButton::setLeft(float l) { left = l; }

std::string mySpriteCheckButton::getFN() { return fn; };
bool mySpriteCheckButton::getActive() { return active; }