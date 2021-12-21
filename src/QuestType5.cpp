#include "QuestType5.hpp"
#include "database.hpp"

int QuestType5::getquestionVariantID1() { return 0; }
int QuestType5::getquestionVariantID2() { return 0; }
int QuestType5::getquestionVariantID3() { return 0; }
int QuestType5::getquestionVariantID4() { return 0; }
int QuestType5::getquestionVariantID5() { return 0; }


QuestType5::QuestType5(float w, float h, int qtyButtons) :
    window(w, h,

        ((rand() % 6))

        ,

        4),
    Buttons(qtyButtons, *this)
{
    gameClass::setmarks(4, 1);

    bool first = true;
    int margintopSlideButton = 0;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);






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



                    if (Buttons.GetButtonsClickID() + 1 == question5Answers[questNumber])  QuestComment.settext(CommentsDic[1]); //right
                    else { //wrong
                        QuestComment.settext(CommentsDic[2]);

                        badAnswer = true;
                        questanswer.setParams(Buttons.getWidth() * 5, Buttons.getHeight(), 5, Buttons.getScale());

                        questanswer[0].loadFromFile(res_path + "digit" + std::to_string(question5Variants[questNumber][0]) + ".jpg");
                        if (question5Znak[questNumber] == '+') questanswer[1].loadFromFile(res_path + "digit_plus.jpg"); else
                            questanswer[1].loadFromFile(res_path + "digit_minus.jpg");
                        questanswer[2].loadFromFile(res_path + "digit" + std::to_string(question5Variants[questNumber][1]) + ".jpg");
                        questanswer[3].loadFromFile(res_path + "digit_equal.jpg");
                        if (question5Znak[questNumber] == '+')
                            questanswer[4].loadFromFile(res_path + "digit" + std::to_string(
                                question5Variants[questNumber][0]
                                +
                                question5Variants[questNumber][1]

                            ) + ".jpg");
                        else
                            questanswer[4].loadFromFile(res_path + "digit" + std::to_string(
                                question5Variants[questNumber][0]
                                -
                                question5Variants[questNumber][1]
                            ) + ".jpg");

                        //questanswer[0].setScale(Buttons.getScale(), Buttons.getScale());
                        questanswer.draw();

                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[question5Answers[questNumber] - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(question5Answers[questNumber]) + "_right.jpg"
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



            }
        }
        srand(static_cast<unsigned int>(time(0)));
        if (wasAnswer && afterAsk()) return;
    }
}