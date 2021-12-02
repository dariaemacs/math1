#include "QuestType2.hpp"
#include "database.hpp"

int QuestType2::getquestionVariantID1() { return 0; }
int QuestType2::getquestionVariantID2() { return 0; }
int QuestType2::getquestionVariantID3() { return 0; }
int QuestType2::getquestionVariantID4() { return 0; }
int QuestType2::getquestionVariantID5() { return 0; }

QuestType2::QuestType2(float w, float h, int qtyButtons) :

    Window(w, h,

        ((rand() % 6))

        ,

        1),
    Buttons(qtyButtons, *this),
    Picture(*this)
{


    bool first = true;
    int margintopSlideButton = 0;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);


    questionVariantID1 = (rand() % 20);
    questionVariantID2 = 0;
    while ((questionVariantID2 = (rand() % 20) + 1) >= questionVariantID1) {
        questionVariantID1 = (rand() % 20);
    }


    textFrame.setN_M(questionVariantID1, questionVariantID2);
    Picture.setButtonCount(questionVariantID1);

    Picture.setpictureFilename("resources/images/" + filenamesforPicaQuest2[getQuestNumber()]);
    Picture.setMargin_left(10);
    Picture.setMargin_top(textFrame.getHeight() * 2);

    Picture.CalcucateCoordinate();

    Buttons.setButtonCount(questionVariantID1);

    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {
            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getHeight());
            //Buttons.setMargin_top(100);

            Buttons.CalcucateCoordinate(); first = false;





        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(ArrowButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            window->draw(*Buttons.getButtons()[bc]);

        }

        for (int bc = 0; bc < Picture.getButtonCount(); bc++) {

            window->draw(*Picture.getButtons()[bc]);
        }

        if (badAnswer) {
            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            sprite.setPosition(0, Buttons.getMarginTop() - questanswer.getHeight());

            window->draw(sprite);

        }
        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {

                    int rightfigurCount = 0;
                    ////std::cout << Buttons.GetButtonsClickID()+1 = N- << std::endl;
                    if (Buttons.GetButtonsClickID() + 1 == questionVariantID1 - questionVariantID2)  QuestComment.settext(CommentsDic[1]);    else {
                        QuestComment.settext(CommentsDic[2]);

                        badAnswer = true;
                        questanswer.setParams(Buttons.getWidth() * 5, Buttons.getHeight(), 5, Buttons.getScale());

                        questanswer[0].loadFromFile(res_path + "digit" + std::to_string(questionVariantID1) + ".jpg");
                        questanswer[1].loadFromFile(res_path + "digit_minus.jpg");
                        questanswer[2].loadFromFile(res_path + "digit" + std::to_string(questionVariantID2) + ".jpg");
                        questanswer[3].loadFromFile(res_path + "digit_equal.jpg");
                        questanswer[4].loadFromFile(res_path + "digit" + std::to_string(questionVariantID1 - questionVariantID2
                        ) + ".jpg");

                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[questionVariantID1 - questionVariantID2 - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(questionVariantID1 - questionVariantID2) + "_right.jpg"
                        );
                        questanswer.draw();
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());
                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }
                if (Picture.click()) {
                    ////std::cout << "Picture.click" << std::endl;
                }


            }
        }
    }

    srand(static_cast<unsigned int>(time(0)));
}