#include "QuestType12.hpp"
#include "database.hpp"

int QuestType12::getquestionVariantID1() { return 0; }
int QuestType12::getquestionVariantID2() { return 0; }
int QuestType12::getquestionVariantID3() { return 0; }
int QuestType12::getquestionVariantID4() { return 0; }
int QuestType12::getquestionVariantID5() { return 0; }

QuestType12::QuestType12(float w, float h, int qtyButtons) :
    Window(w, h,

        (rand() % 6)

        ,

        11),
    Buttons(qtyButtons, *this)
{


    bool first = true;
    int margintopSlideButton = 0;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);


    sf::Sprite sprite(questanswer.getminiwindow().getTexture());




    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {
            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getHeight());


            Buttons.CalcucateCoordinate(); first = false;





        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(ArrowButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            window->draw(*Buttons.getButtons()[bc]);

        }

        if (badAnswer) {

            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            sprite.setPosition((w - questanswer.getWidth()) / 2, (h - questanswer.getHeight()) / 2);
            window->draw(sprite);
        }



        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {



                    if (Buttons.GetButtonsClickID() + 1 == question12Answers[questNumber])  QuestComment.settext(CommentsDic[1]); //right
                    else { //wrong

                        badAnswer = true;
                        //std::cout << "badAnswer" << std::endl;
                        questanswer.setParams(Buttons.getWidth() * 7, Buttons.getHeight(), 7, Buttons.getScale());

                        questanswer[0].loadFromFile(res_path + "digit" + std::to_string(question12AnswerParts[questNumber][0]) + ".jpg");
                        questanswer[1].loadFromFile(res_path + "digit_plus.jpg");
                        questanswer[2].loadFromFile(res_path + "digit" + std::to_string(question12AnswerParts[questNumber][1]) + ".jpg");
                        questanswer[3].loadFromFile(res_path + "digit_plus.jpg");
                        questanswer[4].loadFromFile(res_path + "digit" + std::to_string(question12AnswerParts[questNumber][2]) + ".jpg");
                        questanswer[5].loadFromFile(res_path + "digit_equal.jpg");
                        questanswer[6].loadFromFile(res_path + "digit" + std::to_string(question12Answers[questNumber]) + ".jpg");
                        questanswer.draw();

                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[question5Answers[questNumber] - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(question5Answers[questNumber]) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());
                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }



            }
        }
        srand(static_cast<unsigned int>(time(NULL)));
    }
}