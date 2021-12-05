#include "PicturetoView.hpp"

PicturetoView::PicturetoView(Window& w) : Buttons(0, w) {};
PicturetoView::PicturetoView(QuestType2& qtl, std::string fn) : Buttons(0, qtl), pictureFilename(fn) {};

void Buttons::CalcucateCoordinate(float hieght) {
    float ButtonSize = (WindowLink.getWidth() * 2 / 3 - 50) / 10;
    float step = 5;
    float margin_left_button;
    float margin_top_button;
    if (ButtonCount >= 10)
    {
        while (ButtonSize + 10 > hieght / 2) ButtonSize--;
        margin_left_button = WindowLink.getWidth() - (ButtonSize * 10 + 50);
        margin_top_button = WindowLink.getHeight() - ButtonSize * 2 - 5;
    }
    else {
        while (ButtonSize + 10 > hieght) ButtonSize--;
        margin_left_button = WindowLink.getWidth() - (ButtonSize * ButtonCount + 50);
        margin_top_button = WindowLink.getHeight() - hieght;
    };
    margin_left = margin_left_button;
    margin_top = margin_top_button;
    for (int i = 0; i < ButtonCount; i++) {
        std::string pictureFilename = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
        std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
        txt->loadFromFile(pictureFilename);
        static sf::Vector2u PICTURESIZE = txt->getSize();
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*txt.get());
        if (i == 0) scale = (float)ButtonSize / PICTURESIZE.y;
        sprite->setScale(scale, scale);

        sprite->move(margin_left_button, margin_top_button);
        if ((i + 1) % 10 == 0 && i + 1 > 0) {
            margin_left_button = margin_left;
            margin_top_button += (ButtonSize + 5);
        }
        else
            margin_left_button += (5 + ButtonSize);
        MyTexture.emplace_back(std::move(txt));
        ButtonsList.emplace_back(std::move(sprite));
    }
    height = ButtonSize;
    width = ButtonSize;
}


void PicturetoView::CalcucateCoordinate() {
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

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = static_cast<unsigned int>(PICTURESIZE.x * scale);
            PICTURESIZE_H = static_cast<unsigned int>(PICTURESIZE.y * scale);
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round(ButtonCount) + round((ButtonCount)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, ButtonSlideHeght);
            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
    }
    else
    {
        ////std::cout<<"here"<<std::endl;
        //2 rows

        int PICTURESIZE_W = PICTURESIZE.x;
        int PICTURESIZE_H = PICTURESIZE.y;
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = static_cast<float>(PICTURESIZE_W) / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = static_cast<unsigned int>(PICTURESIZE.x * scale);
            PICTURESIZE_H = static_cast<unsigned int>(PICTURESIZE.y * scale);
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) > WindowLink.getWidth() || 2 * PICTURESIZE_H + 5 > ButtonSlideHeght);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, ButtonSlideHeght);


            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;


            if (i + 1 == (int)(ButtonCount / 2)) {
                button_margin_left = 0; ButtonSlideHeght = ButtonSlideHeght + PICTURESIZE.y * scale + 5;
            }
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);

        }
    }

    //setScale(scale);

}

bool PicturetoView::click() {





    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * scale;
        float y1 = (float)y0 + (float)rect.height * scale;


        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());

        x1 = x1;
        ////std::cout << "pica: scale=" << scale << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<" " <<(x1 - x0) << "x"<<(y1 - y0) << std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture ArrowButtonTexture;
            sf::Sprite ArrowButtonSprite(ArrowButtonTexture);

            //if (ButtonPressID >= 0) {
            if (isblackSide[i])
                fileName = pictureFilename + "_black.png"; else fileName = pictureFilename + ".png";
            MyTexture[i]->loadFromFile(fileName); //ButtonPressID = -1;
            isblackSide[i] = !isblackSide[i];
            return true;
        }

    }
    return false;

}


