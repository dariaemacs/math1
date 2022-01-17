#include "menuButton.hpp"
class window;
menuButton::menuButton(window& w) : PicturetoView(w) {}
void menuButton::CalcucateCoordinate(int numer) {

    using namespace std;
    sf::Texture tmp;

    float button_margin_left = margin_left;
    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y && PICTURESIZE.x / PICTURESIZE.y >= 2)  PICTURESIZE.x /= 2;
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    unsigned int PICTURESIZE_W = PICTURESIZE.x;
    width = static_cast<float>(PICTURESIZE.x);
    unsigned int PICTURESIZE_H = PICTURESIZE.y;
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = static_cast<float>(PICTURESIZE_W) / (PICTURESIZE_W - 5);


        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = static_cast<unsigned int>(PICTURESIZE.x * scale);
            PICTURESIZE_H = static_cast<unsigned int>(PICTURESIZE.y * scale);


        } while ((PICTURESIZE_W * ButtonCount) > WindowLink.getWidth()/2 || PICTURESIZE_H + 5 > WindowLink.getHeight()/5);
        if (numer == 0)
            margin_left = button_margin_left = (WindowLink.getWidth() / 4 - PICTURESIZE_W);
        else
            margin_left = button_margin_left = WindowLink.getWidth()/2 + (WindowLink.getWidth() / 3 - PICTURESIZE_W)/2+10;

        margin_top = WindowLink.getHeight() - PICTURESIZE_H-10;

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png");
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, margin_top);
            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;
            
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
    

    //setScale(scale);

};