#ifndef SimpleButtons_H
#define SimpleButtons_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#include  "window.hpp"
class SimpleButtons {
    bool touched{ false };
    bool pressed{ false };
    bool released{ true };

protected:
    Window& WindowLink;
    float scale;
    int ButtonCount;
    int ButtonPressID = -1;
    float margin_top;
    float margin_left;
    float height;
    float width;
    std::vector<std::shared_ptr<sf::Texture>> MyTexture;
    std::vector<std::unique_ptr<sf::Sprite>> ButtonsList;

public:
    SimpleButtons(int, Window&);
    SimpleButtons(Window&);
    void setButtonCount(int bc);
    void CalcucateCoordinate();
    void CalcucateCoordinate(float);
    void setMargin_top(float margin);



    void setMargin_left(float margin);

    std::vector<std::unique_ptr<sf::Sprite>>& getButtons();
   
    int getButtonCount();
    std::vector<std::shared_ptr<sf::Texture>>& getButtonTexture();
    int GetButtonsClickID();

    float getMarginTop();
    float getScale();

    void setScale(float s);
    float getHeight();

    float getWidth();

    float getMarginLeft();
};

#endif 