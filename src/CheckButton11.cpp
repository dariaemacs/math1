#include "CheckButton11.hpp"
#include "database.hpp"
CheckButton11::CheckButton11(window& w) :CheckButton(w), answerNUMBER(0) {}

unsigned char CheckButton11::getanswerNUMBER() {
    return answerNUMBER;
};
bool CheckButton11::isAnswerRight(int i, int question11Variant3ID, int question11Variant1ID) {

    if (question11Variant1ID == 0)  //увеличение
    {
        if (question11ALLVariants[question11Variant3ID][i] == 0 || question11ALLVariants[question11Variant3ID][i] == 3) return true;
    }
    else {
        if (question11ALLVariants[question11Variant3ID][i] == 1 || question11ALLVariants[question11Variant3ID][i] == 2) return true;
    }

    return false;
}

bool CheckButton11::click(int question11Variant3ID) {
    for (int i = 0; i < 4; ++i) {
        const sf::Vector2f& position = getSprite()[i].getPosition();
        const sf::IntRect& rect = getSprite()[i].getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * coeff;
        float y1 = (float)y0 + (float)rect.height * coeff;
        const sf::Vector2i& M = sf::Mouse::getPosition(*wLnk.getWindow());
        if (M.x >= x0 && M.x <= x1 + getWidthText(i) + textmarginleft && M.y >= y0 && M.y <= y1) {
            getSprite()[i].setActive();
            getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + getSprite()[i].getFN());
            unsigned char tmp = question11ALLVariants[question11Variant3ID][i];
            answerNUMBER = ((1 << tmp)) ^ answerNUMBER;
            clickID = ((1 << i)) ^ clickID;
            std::cout << "clickID=" << clickID << std::endl;
            return true;
        }
    };

    return false;
};
void CheckButton11::resetclickID() { clickID = 0; };


void CheckButton11::SetSpacing(float space) {
    for (int i = 1; i < 4; i++)
    {
        float left = getSprite()[i].getPosition().x;;
        float wi = getSprite()[i].getLocalBounds().width;
        float top = getSprite()[i - 1].getPosition().y + qudroSize + space;

        getSprite()[i].setPosition(left, top - space);
    }
}
