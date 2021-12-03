#include "questanswerClass.hpp"

void questanswerClass::setParams(float ww, float hh, int q, float sscale) {
    width = ww;
    height = hh;
    quadroQTY = q;
    scale = sscale;
    miniwindow.create(static_cast<int>(ww), static_cast<int>(hh));

    for (int i = 0; i < quadroQTY; i++) {
        quadroTexture.push_back(sf::Texture());
        quadroSprite.push_back(sf::Sprite());
        quadroSprite[i].setScale(scale, scale);
        quadroSprite[i].setPosition(i * 500 * scale, 0);
        //quadroSprite[i].setPosition(i * 500 * scale, 0);
    }
}
sf::Texture& questanswerClass::operator[](int index) { return quadroTexture[index]; }
void questanswerClass::draw() {
    for (int i = 0; i < quadroQTY; i++) {
        miniwindow.draw(quadroSprite[i]);
        quadroSprite[i].setTexture(quadroTexture[i]);
        miniwindow.draw(quadroSprite[i]);
    }

}
sf::RenderTexture& questanswerClass::getminiwindow() {
    //miniwindow.clear(sf::Color::Red);
    //for (int i = 0; i < quadroQTY; i++) miniwindow.draw(quadroSprite[0]); 
    miniwindow.display();
    return miniwindow;
}
float questanswerClass::getHeight() { return height; }
float questanswerClass::getWidth() {
    return width;
}
float questanswerClass::getScale() {
    return scale;
}