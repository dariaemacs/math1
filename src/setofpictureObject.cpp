#include "setofpictureObject.hpp"
#include "database.hpp"

void setofpictureObject::CalcucateCoordinate(int where) {
    using namespace std;
    sf::Texture tmp;


    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y&& PICTURESIZE.x / PICTURESIZE.y >= 2) { PICTURESIZE.x /= 3; }
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
    float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);


    do {
        scale = scale - 0.01f;
        PICTURESIZE_W = PICTURESIZE.x * scale;
        PICTURESIZE_H = PICTURESIZE.y * scale;
    } while (((PICTURESIZE_W * 6 + 6 * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);


    std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
    txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
    ////std::cout << "first loadFromFile" << std::endl;
    std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*txt.get());
    sprite->setScale(scale, scale);
    if (where == 1) sprite->move(margin_left, ButtonSlideHeght); else
        if (where == 2) {
            if (isAdd) margin_left = (WindowLink.getWidth() - PICTURESIZE_W * 2) / 2;
            sprite->move(margin_left, WindowLink.getHeight() - PICTURESIZE_H);
        }
    MyTexture.emplace_back(std::move(txt));
    ButtonsList.emplace_back(std::move(sprite));
    isblackSide.push_back(true);
    width = PICTURESIZE_W;
    height = PICTURESIZE_H;
};
setofpictureObject::setofpictureObject(window& w) : PicturetoView(w), isAdd(false) {};
void setofpictureObject::setisAdd() { isAdd = true; }
int setofpictureObject::click(int qty, setofpictureObject& lastpic) {
    const int speedRotation = 100;
    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = static_cast<float>(x0) + static_cast<float>(rect.width )* scale;
        float y1 = static_cast<float>(y0) + static_cast<float>(rect.height) * scale;

        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;

        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            sf::Texture ArrowButtonTexture;
            sf::Sprite ArrowButtonSprite(ArrowButtonTexture);
            //std::cout << "**" << std::to_string(qty) << std::endl;
            if (isAdd && qty < 5) qty++;
            if (qty > 0 && !isAdd) qty--;
            if (qty >= 0) {
                fileName = "resources/images/" + filenamesforPicaQuest8[WindowLink.getQuestNumber()] + std::to_string(qty);
                //WindowLink.setofpic3.loadFromFile(fileName + ".png"); //ButtonPressID = -1;
                // std::cout << std::to_string(qty) << std::endl;
                (lastpic.getButtonTexture()[0])->loadFromFile(fileName + ".png"); //ButtonPressID = -1;;

            }


        }
    }
    return qty;
}
