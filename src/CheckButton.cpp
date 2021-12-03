#include "CheckButton.hpp"
#include "database.hpp"
std::array<mySpriteCheckButton, 4>& CheckButton::getSprite() {
    return quadroSprite;
}
std::array<sf::Text, 4>& CheckButton::getText() {
    std::wstring tmp = str[3].getString();
    return str;
};

float CheckButton::getcoeff() {
    return coeff;
}

int CheckButton::GenerateRandomSetNumber() {
    int SIZE = sizeof(question10VariantForRandom1) / sizeof(*question10VariantForRandom1);
    return rand() % SIZE;
}
float CheckButton::getHeightText() {
    return str[0].getLocalBounds().height;
}
float CheckButton::getWidthText(int index) {
    return str[index].getLocalBounds().width;
}

bool CheckButton::click() {
    for (int i = 0; i < 4; ++i) {
        const sf::Vector2f& position = quadroSprite[i].getPosition();
        const sf::IntRect& rect = quadroSprite[i].getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * coeff;
        float y1 = (float)y0 + (float)rect.height * coeff;
        const sf::Vector2i& M = sf::Mouse::getPosition(*wLnk.getWindow());
        if (M.x >= x0 && M.x <= x1 + getWidthText(i) + textmarginleft && M.y >= y0 && M.y <= y1) {
            std::cout << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 << std::endl;
            if (clickID >= 0) {
                quadroSprite[clickID].setActive();
                quadroTexture[clickID].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + quadroSprite[i].getFN());
            }
            clickID = i;
            quadroSprite[i].setActive();
            quadroTexture[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + quadroSprite[i].getFN());
            if (!quadroSprite[i].getActive()) clickID = -1;

            return true;
        }
    }

    return false;
}