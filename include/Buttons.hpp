#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "window.hpp"

class Buttons {
    bool touched{ false };
    bool pressed{ false };
    bool released{ true };

protected:
    window& WindowLink;
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
    Buttons(int, window&);
    Buttons(window&);
    void setButtonCount(int bc);
    void CalcucateCoordinate();
    void CalcucateCoordinate(float);
    void setMargin_top(float);



    void setMargin_left(float);

    std::vector<std::unique_ptr<sf::Sprite>>& getButtons();
    bool  click();
    int getButtonCount();
    std::vector<std::shared_ptr<sf::Texture>>& getButtonTexture();
    int GetButtonsClickID();

    float getMarginTop();
    float getScale();

    void setScale(float );
    float getHeight();

    float getWidth();

    float getMarginLeft();
};