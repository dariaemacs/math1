#include "PicturetAndFilmtoView.hpp"
PicturetAndFilmtoView::PicturetAndFilmtoView(window& w) : PicturetoView(w) {}

void PicturetAndFilmtoView::CalcucateCoordinate() {
    using namespace std;
    sf::Texture tmp;


    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y && PICTURESIZE.x / PICTURESIZE.y >= 2) { PICTURESIZE.x /= 3; coinWidth = static_cast<float>(PICTURESIZE.x); coinHeight = static_cast<float>(PICTURESIZE.y); }
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
    float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
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
        } while (((PICTURESIZE_W * round(ButtonCount) + round((ButtonCount)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            ////std::cout << "first loadFromFile" << std::endl;
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(margin_left, ButtonSlideHeght);
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
    }
    else
    {
        ////std::cout<<"here"<<std::endl;
        //2 rows

        float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
        float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
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
            sprite->move(margin_left, ButtonSlideHeght);
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);

        }
    }

    //setScale(scale);

}
bool PicturetAndFilmtoView::click() {
    const int speedRotation = 100;
    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * scale;
        float y1 = (float)y0 + (float)rect.height * scale;

        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;
        ////std::cout << "scale" <<scale << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture ArrowButtonTexture;
            sf::Sprite ArrowButtonSprite(ArrowButtonTexture);


            //for film coin rotate
            clock_t start_time1 = 0;
            clock_t end_time1 = 0;
            bool frame1 = false;
            clock_t start_time2 = 0;
            clock_t end_time2 = 0;
            bool frame2 = false;

            if (ButtonPressID < 0) {
                while (true) {
                    start_time1 = clock();
                    if (!frame1) {
                        end_time1 = speedRotation + start_time1;
                        frame1 = true;

                    }
                    if (frame1 && start_time1 > end_time1) {
                        ////std::cout << "testFilm2" << std::endl;

                        MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(static_cast<int>(coinWidth), 0, static_cast<int>(coinWidth * 2), static_cast<int>(coinHeight)));
                        ButtonsList[0]->setTexture(*MyTexture[0]);
                        WindowLink.getWindow()->draw(*ButtonsList[0]);
                        WindowLink.getWindow()->display();
                        start_time2 = clock();
                        if (!frame2) {
                            end_time2 = speedRotation + start_time2;
                            frame2 = true;

                        }
                        if (frame2 && start_time2 > end_time2) {
                            ////std::cout << "testFilm3" << std::endl;
                            MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(static_cast<int>(coinWidth * 2), 0, static_cast<int>(coinWidth * 3), static_cast<int>(coinHeight)));
                            ButtonsList[0]->setTexture(*MyTexture[0]);
                            WindowLink.getWindow()->draw(*ButtonsList[0]);
                            WindowLink.getWindow()->display();
                            break;
                        }
                    }
                }
                ButtonPressID = 1;

            }
            else
            {
                while (true) {
                    start_time1 = clock();
                    if (!frame1) {
                        end_time1 = speedRotation + start_time1;
                        frame1 = true;

                    }
                    if (frame1 && start_time1 > end_time1) {
                        ////std::cout << "testFilm2" << std::endl;
                        MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(static_cast<int>(coinWidth), 0, static_cast<int>(coinWidth * 2), static_cast<int>(coinHeight)));
                        ButtonsList[0]->setTexture(*MyTexture[0]);
                        WindowLink.getWindow()->draw(*ButtonsList[0]);
                        WindowLink.getWindow()->display();
                        start_time2 = clock();
                        if (!frame2) {
                            end_time2 = speedRotation + start_time2;
                            frame2 = true;

                        }
                        if (frame2 && start_time2 > end_time2) {
                            ////std::cout << "testFilm3" << std::endl;
                            MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, static_cast<int>(coinWidth), static_cast<int>(coinHeight)));
                            ButtonsList[0]->setTexture(*MyTexture[0]);
                            WindowLink.getWindow()->draw(*ButtonsList[0]);
                            WindowLink.getWindow()->display();
                            break;
                        }
                    }
                }
                ButtonPressID = -1;
            }



        }

    }
    return false;
}

float PicturetAndFilmtoView::getcoinWidth() { return coinWidth; }
