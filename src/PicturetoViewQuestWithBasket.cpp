#include "PicturetoViewQuestWithBasket.hpp"

PicturetoViewQuestWithBasket::PicturetoViewQuestWithBasket(window& w) : PicturetoView(w) {};

void PicturetoViewQuestWithBasket::CalcucateCoordinate() {

    using namespace std;
    sf::Texture tmp;

    int button_margin_left = 0;
    tmp.loadFromFile(pictureFilename + ".png");
    ////std::cout << "picture" << std::endl;
    sf::Vector2u PICTURESIZE = tmp.getSize();

    ////std::cout << PICTURESIZE.x << std::endl;
    float PICTURESIZEy = static_cast<float>(PICTURESIZE.y);
    if (PICTURESIZE.x > PICTURESIZE.y && ((float)PICTURESIZE.x / (float)PICTURESIZE.y) >= 1.5) {
        PICTURESIZE.x /= 2;
    }

    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
    float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
    float BASKETPICTURESIZE_W = 0;
    float BASKETPICTURESIZE_H = 0;
    float BASKETSCALE = 1;

    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round(ButtonCount + 2) + round((ButtonCount + 2)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(static_cast<float>(button_margin_left), static_cast<float>(ButtonSlideHeght));
            button_margin_left = static_cast<int>(button_margin_left + 5 + PICTURESIZE.x * scale);
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
        //calc for basket
        //basketTexture.loadFromFile(pictureFilename + "_basket.png");
        //sf::Vector2u BASKETPICTURESIZE = basketTexture.getSize();
        //do {
        //    BASKETSCALE = BASKETSCALE - 0.01;
        //    BASKETPICTURESIZE_W = BASKETPICTURESIZE.x * BASKETSCALE;
        //    BASKETPICTURESIZE_H = BASKETPICTURESIZE.y * BASKETSCALE;
        //    ////std::cout << "k=" << scale << std::endl;
        //    ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        //} while (((BASKETPICTURESIZE_W *  +  5)) > WindowLink.getWidth() || BASKETPICTURESIZE_H + 5 > ButtonSlideHeght);
        //

        //basketSprite.setTexture(basketTexture);
        //basketSprite.setScale(BASKETSCALE, BASKETSCALE);
        //basketSprite.move(button_margin_left , ButtonSlideHeght);
    }
    else
    {
        ////std::cout << PICTURESIZE.x << std::endl;
        //2 rows

        float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
        float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) > WindowLink.getWidth() || 2 * PICTURESIZE_H + 5 > ButtonSlideHeght);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(static_cast<float>(button_margin_left), static_cast<float>(ButtonSlideHeght));


            button_margin_left = static_cast<int>(button_margin_left + 5 + PICTURESIZE.x * scale);

            //const sf::Vector2f& position = ButtonsList[i]->getPosition();
            //const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
            if (i + 1 == (int)(ButtonCount / 2)) {
                button_margin_left = 0; ButtonSlideHeght = ButtonSlideHeght + PICTURESIZE.y * scale + 5;
            }
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);

        }
    }

    basketTexture.loadFromFile(pictureFilename + "_basket.png");
    sf::Vector2u BASKETPICTURESIZE = basketTexture.getSize();
    do {
        BASKETSCALE = BASKETSCALE - 0.01f;
        BASKETPICTURESIZE_W = BASKETPICTURESIZE.x * BASKETSCALE;
        BASKETPICTURESIZE_H = BASKETPICTURESIZE.y * BASKETSCALE;
    } while (((BASKETPICTURESIZE_W * +5)) > WindowLink.getWidth() || BASKETPICTURESIZE_H + 5 > ButtonSlideHeght);


    basketSprite.setTexture(basketTexture);
    basketSprite.setScale(BASKETSCALE, BASKETSCALE);
    basketSprite.move(static_cast<float>(button_margin_left), static_cast<float>((BASKETPICTURESIZE_H / BASKETPICTURESIZE_W >= 1.5 ?
        (WindowLink.getHeight() - BASKETPICTURESIZE_H) / 2 : WindowLink.getHeight() / 3)));
}

