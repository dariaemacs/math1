#include  "PicturetoView11.hpp"
PicturetoView11::PicturetoView11(window& w) : PicturetoView(w) {

}

void PicturetoView11::CalcucateCoordinate(float w) {

    using namespace std;
    sf::Texture tmp;

    float button_margin_left = margin_left;
    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y&& PICTURESIZE.x / PICTURESIZE.y >= 2)  PICTURESIZE.x /= 2;
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    int PICTURESIZE_W = PICTURESIZE.x;
    width = static_cast<float>(PICTURESIZE.x);
    int PICTURESIZE_H = PICTURESIZE.y;
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = static_cast<float>(PICTURESIZE_W / (PICTURESIZE_W - 5));

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = static_cast<int>(PICTURESIZE.x * scale);
            PICTURESIZE_H = static_cast<int>(PICTURESIZE.y * scale);
        } while ((PICTURESIZE_W * round(ButtonCount)) > WindowLink.getWidth() / 2);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, margin_top);
            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
    }

    height = static_cast<float>(PICTURESIZE_H);


}

