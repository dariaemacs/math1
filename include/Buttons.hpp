#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>


class Buttons {
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
    Buttons(int, Window&);
    Buttons(Window&);
    void setButtonCount(int bc) {
        ButtonCount = bc;
    }
    void CalcucateCoordinate();
    void CalcucateCoordinate(float);
    void setMargin_top(float margin) {
        margin_top = margin;
    }



    void setMargin_left(float margin) {
        margin_left = margin;
    }

    std::vector<std::unique_ptr<sf::Sprite>>& getButtons() {
        return
            ButtonsList;
    }
    bool  click();
    int getButtonCount() { return ButtonCount; }
    std::vector<std::shared_ptr<sf::Texture>>& getButtonTexture() { return MyTexture; }
    int GetButtonsClickID() { return ButtonPressID; }

    float getMarginTop() {
        return margin_top;
    }
    float getScale() {
        return scale;
    }

    void setScale(float s) {
        scale = s;
    }
    float getHeight() {
        return height;
    }

    float getWidth() {
        return width;
    }

    float getMarginLeft() {
        return margin_left;
    }
};