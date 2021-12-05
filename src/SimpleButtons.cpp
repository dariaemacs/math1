#include "SimpleButtons.hpp"

void SimpleButtons::setButtonCount(int bc) {
    ButtonCount = bc;
};
void SimpleButtons::CalcucateCoordinate() {
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

void SimpleButtons::setMargin_top(float margin) {
    margin_top = margin;
}



void SimpleButtons::setMargin_left(float margin) {
    margin_left = margin;
}

std::vector<std::unique_ptr<sf::Sprite>>& SimpleButtons::getButtons() {
    return
        ButtonsList;
}

int SimpleButtons::getButtonCount() { return ButtonCount; }
std::vector<std::shared_ptr<sf::Texture>>& SimpleButtons::getButtonTexture() { return MyTexture; }
int SimpleButtons::GetButtonsClickID() { return ButtonPressID; }

float SimpleButtons::getMarginTop() {
    return margin_top;
}
float SimpleButtons::getScale() {
    return scale;
}

void SimpleButtons::setScale(float s) {
    scale = s;
}
float SimpleButtons::getHeight() {
    return height;
}

float SimpleButtons::getWidth() {
    return width;
}

float SimpleButtons::getMarginLeft() {
    return margin_left;
}

SimpleButtons::SimpleButtons(int qtyButton, Window& w) :WindowLink(w), ButtonCount(qtyButton) {

}
SimpleButtons::SimpleButtons(Window& w) : WindowLink(w) {}
