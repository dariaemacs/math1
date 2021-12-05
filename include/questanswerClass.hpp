#ifndef questanswerClass_H
#define questanswerClass_H
// здесь идет собственно тело h-ника

#include <SFML/Graphics.hpp>
#include "CheckButton11.hpp"

class questanswerClass {
    sf::RenderTexture miniwindow;
    sf::Text text;
    std::vector <sf::Texture> quadroTexture;
    std::vector <sf::Sprite>  quadroSprite;
    int quadroQTY;
    float width;
    float height;
    float scale;
public:
    void setParams(float ww, float hh, int q, float sscale);
    sf::Texture& operator[](int index);
    void draw(); 
   
sf::RenderTexture& getminiwindow() ;
float getHeight();
float getWidth();
float getScale();

};
#endif //questanswerClass_H