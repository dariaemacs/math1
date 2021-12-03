#include "Buttons.hpp"

void Buttons::setButtonCount(int bc) {
    ButtonCount = bc;
};
void Buttons::CalcucateCoordinate() {
    using namespace std;
    float ButtonSlideHeght = WindowLink.getHeight() / 3;
    float step = 0;
    float  ButtonSize = (WindowLink.getWidth() / 11) * 2 / 3;
    height = ButtonSize;
    while (ButtonSize + 10 > ButtonSlideHeght / 2) ButtonSize--;
    step = ButtonSize / 5;
    if (ButtonCount > 11) margin_top = WindowLink.getHeight() - (ButtonSize + step) * 2; else margin_top = WindowLink.getHeight() - (ButtonSize + step);
    margin_left = WindowLink.getWidth() - 11 * (ButtonSize + step);
    float margin_left_button = margin_left;
    float margin_top_button = margin_top;
    //heght = 
    for (int i = 0; i < ButtonCount; i++) {
        ////std::cout << "here2" << std::endl;
        std::string pictureFilename = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
        //if (pictureFilename == "") std::string pictureFilename = picaFilename;

        std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
        txt->loadFromFile(pictureFilename);
        static sf::Vector2u PICTURESIZE = txt->getSize();
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*txt.get());
        scale = (float)ButtonSize / PICTURESIZE.y;
        sprite->setScale(scale, scale);
        cout << i % 10 << std::endl;
        sprite->move(margin_left_button, margin_top_button);
        if (i % 10 == 0 && i > 0) {
            //cout << "here***rr" << ButtonCount << std::endl;
            margin_top_button = margin_top_button + ButtonSize + 10; margin_left_button = WindowLink.getWidth() - 11 * (ButtonSize + step);
        }
        else margin_left_button = margin_left_button + ButtonSize + step;
        MyTexture.emplace_back(std::move(txt));
        ButtonsList.emplace_back(std::move(sprite));
    };
    height = ButtonSize;
    width = ButtonSize;

}

void Buttons::setMargin_top(float margin) {
    margin_top = margin;
}



void Buttons::setMargin_left(float margin) {
    margin_left = margin;
}

std::vector<std::unique_ptr<sf::Sprite>>& Buttons::getButtons() {
    return
        ButtonsList;
}
bool  click();
int Buttons::getButtonCount() { return ButtonCount; }
std::vector<std::shared_ptr<sf::Texture>>& Buttons::getButtonTexture() { return MyTexture; }
int Buttons::GetButtonsClickID() { return ButtonPressID; }

float Buttons::getMarginTop() {
    return margin_top;
}
float Buttons::getScale() {
    return scale;
}

void Buttons::setScale(float s) {
    scale = s;
}
float Buttons::getHeight() {
    return height;
}

float Buttons::getWidth() {
    return width;
}

float Buttons::getMarginLeft() {
    return margin_left;
}