#include "QuestType3.hpp"
#include "database.hpp"
//#include "window.hpp"

int QuestType3::getquestionVariantID1() { return 0; }
int QuestType3::getquestionVariantID2() { return 0; }
int QuestType3::getquestionVariantID3() { return 0; }
int QuestType3::getquestionVariantID4() { return 0; }
int QuestType3::getquestionVariantID5() { return 0; }


QuestType3::QuestType3(float w, float h, int qtyButtons) :

    window(w, h,

        ((rand() % 6))

        ,

        2)

    ,
    Buttons(qtyButtons, *this),
    PictureAndBasket(PicturetoViewQuestWithBasket(*this))


{


    bool first = true;
    int margintopSlideButton = 0;
    ////std::cout << qtyButtons << std::endl;
    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    gameClass::setmarks(2, 0);

    int N = (rand() % 10);
    int M = 0;
    while ((M = (rand() % 10) + 1) >= N) {
        N = (rand() % 10);
    }
    //N = 10;

    textFrame.setN_M(N, M);
    PictureAndBasket.setButtonCount(N);

    PictureAndBasket.setpictureFilename("resources/images/" + filenamesforPicaQuest3[getQuestNumber()]);
    PictureAndBasket.setMargin_left(10);
    PictureAndBasket.setMargin_top(textFrame.getHeight() * 2);

    PictureAndBasket.CalcucateCoordinate();

    //Buttons.setButtonCount(N);

    sf::Event event;
    while (win->isOpen()) {
        win->clear();

        if (badAnswer) {
            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            sprite.setPosition(0, Buttons.getMarginTop() - questanswer.getHeight());

            win->draw(sprite);

        }
        win->draw(List);

        if (first) {
            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getHeight());
            //Buttons.setMargin_top(100);

            Buttons.CalcucateCoordinate(); first = false;





        }
        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());
        win->draw(ArrowButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            win->draw(*Buttons.getButtons()[bc]);

        }

        for (int bc = 0; bc < PictureAndBasket.getButtonCount(); bc++) {

            win->draw(*PictureAndBasket.getButtons()[bc]);
        }
        win->draw(PictureAndBasket.getBasketSprite());

        if (badAnswer) {
            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            sprite.setPosition(0, Buttons.getMarginTop() - questanswer.getHeight());

            win->draw(sprite);

        }
        DrawGameTime();
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {

                    int rightfigurCount = 0;
                    ////std::cout << Buttons.GetButtonsClickID()+1 = N- << std::endl;
                    if (Buttons.GetButtonsClickID() + 1 == N + M)  QuestComment.settext(CommentsDic[1]);    else {
                        gameClass::setmarks(2, 1);
                        badAnswer = true;
                        questanswer.setParams(Buttons.getWidth() * 5, Buttons.getHeight(), 5, Buttons.getScale());

                        questanswer[0].loadFromFile(res_path + "digit" + std::to_string(N) + ".jpg");
                        questanswer[1].loadFromFile(res_path + "digit_plus.jpg");
                        questanswer[2].loadFromFile(res_path + "digit" + std::to_string(M) + ".jpg");
                        questanswer[3].loadFromFile(res_path + "digit_equal.jpg");
                        questanswer[4].loadFromFile(res_path + "digit" + std::to_string(N +
                            M
                        ) + ".jpg");

                        //questanswer[0].setScale(Buttons.getScale(), Buttons.getScale());
                        questanswer.draw();


                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[N + M - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(N + M) + "_right.jpg"
                        );
                    }
                    wasAnswer = true;
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());
                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }
                if (PictureAndBasket.click()) {
                    ////std::cout << "Picture.click" << std::endl;
                }


            }
        }
        if (wasAnswer && afterAsk()) return;
    }

    srand(static_cast<unsigned int>(time(0)));
}