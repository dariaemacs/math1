#include "QuestType6.hpp"
#include "database.hpp"

int QuestType6::getquestionVariantID1() { return 0; }
int QuestType6::getquestionVariantID2() { return 0; }
int QuestType6::getquestionVariantID3() { return 0; }
int QuestType6::getquestionVariantID4() { return 0; }
int QuestType6::getquestionVariantID5() { return 0; }

QuestType6::QuestType6(float w, float h, int qtyButtons)
    :window(w, h, ((rand() % 4)), 5),
    Buttons(qtyButtons, *this),
    coin1(*this),
    coin2(*this) {



    bool first = true;
    int margintopSlideButton = 0;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);

    int coinRandomIndex = rand() % 2;
    coin1.setButtonCount(1);
    coin2.setButtonCount(1);
    if (coinRandomIndex == 0) {
        coin1.setpictureFilename("resources/images/moneta10");
        coinRandomIndex = rand() % 3;
        switch (coinRandomIndex)
        {
        case 0:coin2.setpictureFilename("resources/images/moneta01"); break;
        case 1:coin2.setpictureFilename("resources/images/moneta02"); break;
        case 2:coin2.setpictureFilename("resources/images/moneta05"); break;
        default:
            break;
        }
    }
    else {

        coinRandomIndex = rand() % 3;
        switch (coinRandomIndex)
        {
        case 0:coin1.setpictureFilename("resources/images/moneta01"); break;
        case 1:coin1.setpictureFilename("resources/images/moneta02"); break;
        case 2:coin1.setpictureFilename("resources/images/moneta05"); break;
        default:
            break;
        }
        coin2.setpictureFilename("resources/images/moneta10");
    }

    coin1.setMargin_left(0);
    coin1.setMargin_top(textFrame.getHeight() * 2);
    coin1.CalcucateCoordinate();

    coin2.setMargin_left(coin1.getcoinWidth() + 10);
    coin2.setMargin_top(textFrame.getHeight() * 2);
    coin2.CalcucateCoordinate();
    sf::Event event;
    while (win->isOpen()) {
        win->clear();
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

        win->draw(*coin1.getButtons()[0]);
        win->draw(*coin2.getButtons()[0]);




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



                    if (Buttons.GetButtonsClickID() + 1 == question6Answers[questNumber])  QuestComment.settext(CommentsDic[1]); //right
                    else { //wrong
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[10 - question6Variants[questNumber] - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(10 - question6Variants[questNumber]) + "_right.jpg"
                        );
                        badAnswer = true;
                        /**/

                        questanswer.setParams(Buttons.getWidth() * 5, Buttons.getHeight(), 5, Buttons.getScale());

                        questanswer[0].loadFromFile(res_path + "digit" + std::to_string(10) + ".jpg");
                        questanswer[1].loadFromFile(res_path + "digit_minus.jpg");
                        questanswer[2].loadFromFile(res_path + "digit" + std::to_string(question6Variants[questNumber]) + ".jpg");
                        questanswer[3].loadFromFile(res_path + "digit_equal.jpg");
                        questanswer[4].loadFromFile(res_path + "digit" + std::to_string(10 - question6Variants[questNumber]) + ".jpg");


                        //questanswer[0].setScale(Buttons.getScale(), Buttons.getScale());
                        questanswer.draw();

                        /**/

                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());
                    wasAnswer = true;


                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }
                if (coin1.click() || coin2.click()) {

                }


            }
        }
        if (wasAnswer && afterAsk()) return;
    }

    srand(static_cast<unsigned int>(time(NULL)));
}