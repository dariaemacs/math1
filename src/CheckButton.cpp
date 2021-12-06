#include "CheckButton.hpp"
#include "database.hpp"

CheckButton::CheckButton(window& wl) :wLnk(wl), textmarginleft(10), clickID(-1), margin_top(0) {
    coeff = (452.0f / ((wl.getHeight() - wl.gettextFrame().getHeight()))) / 5;
    coeff = 25.0f / wl.getHeight();
    float tmp = wl.gettextFrame().getHeight();
    tmp = wl.getHeight();
    qudroSize = coeff * 452.0f;
    float margin = qudroSize / 6;
    for (int i = 0; i < quadroTexture.size(); i++) {
        quadroTexture[i].loadFromFile(res_path + "empty.jpg");
        quadroSprite[i].setTexture(quadroTexture[i]);
        quadroSprite[i].setScale(coeff, coeff);
        //quadroSprite[i].setPosition(10, ( wl.gettextFrame().getHeight())+30 + (qudroSize+ margin) *i );


    }


}

void CheckButton::setTextValue(int index) {

    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");

    sf::RectangleShape rectangle;
    //std::cout << wLnk.gettextFrame().getSize() << std::endl;
    int question10Variant1IDRandom1 = rand() % (sizeof(question10VariantForRandom1) / sizeof(question10VariantForRandom1[0]));

    for (int i = 0; i < 4; i++) {

        str[i] = sf::Text(

            question10Variant2[index][question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][0]]
            +
            question10Variant2[index][question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][1]]
            +
            question10Variant2[index][question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][2]]

            , font, 35);

        if (question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][0] == 0 &&
            question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][1] == 1 &&
            question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][2] == 2) rightQuestNum = i;


        float x = quadroSprite[i].getPosition().x; // +qudroSize;
        float tmiii = quadroSprite[i].getLocalBounds().width;
        str[i].setLineSpacing(0.001f);
        float huuu = str[i].getLineSpacing();

        float y = quadroSprite[i].getPosition().y + (qudroSize - getHeightText()) / 2;
        str[i].setPosition(x + qudroSize + textmarginleft, y - 10);
        str[i].setFillColor(sf::Color::Black);
        str[i].setOutlineColor(sf::Color::Red);

    }




}
sf::Font& CheckButton::getFont() { return font; }

std::array<mySpriteCheckButton, 4>& CheckButton::getSprite() {
    return quadroSprite;
}
float CheckButton::getTextmarginleft() { return static_cast<float>(textmarginleft); }
std::array<sf::Text, 4>& CheckButton::getText() {
    std::wstring tmp = str[3].getString();
    return str;
};

float CheckButton::getcoeff() {
    return coeff;
}

float CheckButton::getQudroSize() {
    return qudroSize;
}

void CheckButton::SetqudroSize(float q) {
    qudroSize = q;
    coeff = qudroSize / 500;
    for (int i = 0; i < 4; i++)
        getSprite()[i].setScale(coeff, coeff);
};

std::array<sf::Texture, 4>& CheckButton::getquadroTexture() { return quadroTexture; }

void CheckButton::setStrValue(int index, std::wstring str1, int SIZE = 28) {
    getFont().loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    getText()[index] = sf::Text(str1, getFont(), 28);
    float x = getSprite()[index].getPosition().x; // +qudroSize;
    float y = getSprite()[index].getPosition().y + (getQudroSize() - getHeightText()) / 2;
    getText()[index].setPosition(x + getQudroSize() + getTextmarginleft(), y - 5);
    getText()[index].setFillColor(sf::Color::Black);
    getText()[index].setOutlineColor(sf::Color::Red);

};



void  CheckButton::Set_margitop(float mt) {
    margin_top = mt;
    for (int i = 0; i < getSprite().size(); i++)
        getSprite()[i].setPosition(getSprite()[i].getPosition().x, i * getQudroSize() + margin_top);
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