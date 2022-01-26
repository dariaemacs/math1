#include "QuestType9.hpp"
#include "database.hpp"

int QuestType9::getquestionVariantID1() { return 0; }
int QuestType9::getquestionVariantID2() { return 0; }
int QuestType9::getquestionVariantID3() { return 0; }
int QuestType9::getquestionVariantID4() { return 0; }
int QuestType9::getquestionVariantID5() { return 0; }



QuestType9::QuestType9(int qtyButtons) :
    window(gameClass::getWidth(), gameClass::getHeight(), ((rand() % 4)), 8),
    Buttons(qtyButtons, *this),
    tab(*this)
{

    bool first = true;
    gameClass::setmarks(8, 0);
    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    sf::Event event;
    //questanswer[0].loadFromFile("resources/images/arrow_disable.png");

    for (int i = 0; i < 13; i++)
    {
        MashTexture[i].loadFromFile(res_path + "mushroom.png");
        MashSprite[i].setTexture(MashTexture[i]);
        BerryTexture[i].loadFromFile(res_path + "berry.png");
        BerrySprite[i].setTexture(BerryTexture[i]);
        if (i < 12) {
            LeafTexture[i].loadFromFile(res_path + "leaf_10.png");
            LeafSprite[i].setTexture(LeafTexture[i]);
        }

    }

    for (int i = 13; i < 16; i++)
    {
        BerryTexture[i].loadFromFile(res_path + "berry.png");
        BerrySprite[i].setTexture(BerryTexture[i]);
    }

    while (win->isOpen()) {
        win->clear();

        win->draw(List);
        tab.draw();
        if (first) {

            first = false;

            Buttons.CalcucateCoordinate((height - tab.gettablemax_y()) / 1.4f);
            first = false;
            QuestComment.setmargin_top(Buttons.getMarginTop());
            QuestComment.CalcucateCoordinate(height / 3, width / 2);
            first = false;
            for (int i = 0; i < 4; i++) {
                MashSprite[i].setScale(tab.getmash_koeff(), tab.getmash_koeff());
                MashSprite[i].setPosition(sf::Vector2f(tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y()));

                BerrySprite[i].setScale(tab.getmash_koeff() + 0.08f, tab.getmash_koeff() + 0.08f);
                BerrySprite[i].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y()));

                LeafSprite[i].setScale(tab.getmash_koeff() + 0.041f, tab.getmash_koeff() + 0.041f);
                LeafSprite[i].setPosition(sf::Vector2f(8 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y()));

                LeafSprite[i + 6].setScale(tab.getmash_koeff() + 0.041f, tab.getmash_koeff() + 0.041f);
                LeafSprite[i + 6].setPosition(sf::Vector2f(8 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + 3 * tab.getmash_height()));

            }

            LeafSprite[4].setScale(tab.getmash_koeff() + 0.041f, tab.getmash_koeff() + 0.041f);
            LeafSprite[4].setPosition(sf::Vector2f(8 * tab.getmash_width() + tab.getmash_x()
                , tab.getmash_y() + tab.getmash_height()));

            LeafSprite[5].setScale(tab.getmash_koeff() + 0.041f, tab.getmash_koeff() + 0.041f);
            LeafSprite[5].setPosition(sf::Vector2f(8 * tab.getmash_width() + tab.getmash_x() +
                tab.getmash_width()
                , tab.getmash_y() + tab.getmash_height()));


            LeafSprite[10].setScale(tab.getmash_koeff() + 0.041f, tab.getmash_koeff() + 0.041f);
            LeafSprite[10].setPosition(sf::Vector2f(8 * tab.getmash_width() + tab.getmash_x()
                , tab.getmash_y() + 4 * tab.getmash_height()));

            LeafSprite[11].setScale(tab.getmash_koeff() + 0.041f, tab.getmash_koeff() + 0.041f);
            LeafSprite[11].setPosition(sf::Vector2f(8 * tab.getmash_width() + tab.getmash_x() +
                tab.getmash_width()
                , tab.getmash_y() + 4 * tab.getmash_height()));


            for (int i = 0; i < 4; i++) {
                MashSprite[i + 4].setScale(tab.getmash_koeff(), tab.getmash_koeff());
                MashSprite[i + 4].setPosition(sf::Vector2f(tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + tab.getmash_height()));

                BerrySprite[i + 4].setScale(tab.getmash_koeff() + 0.08f, tab.getmash_koeff() + 0.08f);
                BerrySprite[i + 4].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + tab.getmash_height()));

            }
            BerrySprite[8].setScale(tab.getmash_koeff() + 0.08f, tab.getmash_koeff() + 0.08f);
            BerrySprite[8].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x()
                , tab.getmash_y() + tab.getmash_height() * 2));


            for (int i = 0; i < 4; i++) {
                MashSprite[i + 8].setScale(tab.getmash_koeff(), tab.getmash_koeff());
                MashSprite[i + 8].setPosition(sf::Vector2f(tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + 3 * tab.getmash_height()));


                BerrySprite[i + 9].setScale(tab.getmash_koeff() + 0.08f, tab.getmash_koeff() + 0.08f);
                BerrySprite[i + 9].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + 3 * tab.getmash_height()));

            }

            MashSprite[12].setScale(tab.getmash_koeff(), tab.getmash_koeff());
            MashSprite[12].setPosition(sf::Vector2f(tab.getmash_x()
                , tab.getmash_y() + 4 * tab.getmash_height()));
            for (int i = 0; i < 3; i++) {
                BerrySprite[13 + i].setScale(tab.getmash_koeff() + 0.08f, tab.getmash_koeff() + 0.08f);
                BerrySprite[13 + i].setPosition(sf::Vector2f(
                    4 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()

                    , tab.getmash_y() + 4 * tab.getmash_height())
                );
            }

        }


        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++) {
            win->draw(*Buttons.getButtons()[bc]);
        }
        win->draw(ArrowButtonSprite);
        for (int i = 0; i < 13; i++) {
            win->draw(MashSprite[i]);
            win->draw(BerrySprite[i]);
            if (i < 12) win->draw(LeafSprite[i]);
        }
        win->draw(BerrySprite[13]);
        win->draw(BerrySprite[14]);
        win->draw(BerrySprite[15]);


        if (badAnswer) {
            gameClass::setmarks(8, 0);
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

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor)) {
                    if (question9AnswersSquare[questNumber] == Buttons.GetButtonsClickID() + 1) { QuestComment.settext(CommentsDic[13]); gameClass::setmarks(8, 1);}
                    else {
                        gameClass::setmarks(8, 0);
                        QuestComment.settext(CommentsDic[2]);
                        badAnswer = true;
                        questanswer.setParams(Buttons.getWidth() * 5, Buttons.getHeight(), 5, Buttons.getScale());

                        questanswer[0].loadFromFile(res_path + "digit" + std::to_string(question9AnswerDetails[questNumber * 2]) + ".jpg");
                        questanswer[1].loadFromFile(res_path + "digit_plus.jpg");
                        questanswer[2].loadFromFile(res_path + "digit" + std::to_string(question9AnswerDetails[questNumber * 2 + 1]) + ".jpg");
                        questanswer[3].loadFromFile(res_path + "digit_equal.jpg");
                        questanswer[4].loadFromFile(res_path + "digit" + std::to_string(question9AnswerDetails[questNumber * 2] +
                            question9AnswerDetails[questNumber * 2 + 1]
                        ) + ".jpg");

                        //questanswer[0].setScale(Buttons.getScale(), Buttons.getScale());
                        questanswer.draw();
                    }
                    wasAnswer = true;
                }
                if (Buttons.click()) {
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }

            }


        }
        if (wasAnswer && afterAsk()) return;
    }

    srand(static_cast<unsigned int>(time(NULL)));

};