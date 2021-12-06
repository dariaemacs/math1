#include "QuestType16.hpp"
#include "database.hpp"

QuestType16::QuestType16(float w, float h, int qtyButtons) :
    questionVariantID1(rand() % 3),
    questionVariantID2(rand() % 3),
    window(w, h, 0, 13),
    buttons(qtyButtons, *this),
    tab(*this) {

    bool first = true;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    sf::Event event;
    //questanswer[0].loadFromFile("resources/images/arrow_disable.png");

    textFrame.settext(question14Text[0].questionText + L" " + question14Text1[questionVariantID1] + L"\n" +
        question14Text2[questionVariantID1][2]
    );
    textFrame.CalcucateCoordinate(w - w * 10 / 100, h / 3);


    while (win->isOpen()) {
        win->clear();

        win->draw(List);

        if (first) {

            first = false;

            buttons.CalcucateCoordinate((h - 100) / 1.4f);

            QuestComment.setmargin_top(buttons.getMarginTop());
            QuestComment.CalcucateCoordinate(h / 3, w / 2);








        }

        tab.draw();
        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());
        for (int bc = 0; bc < buttons.getButtonCount(); bc++)
            win->draw(*buttons.getButtons()[bc]);
        win->draw(ArrowButtonSprite);


        if (badAnswer) {
            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            sprite.setPosition((w - questanswer.getWidth()) / 2, buttons.getMarginTop() - 2 * questanswer.getWidth() * questanswer.getScale());
            win->draw(sprite);

        }
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor))
                    if (question15Answer[questionVariantID1] == buttons.GetButtonsClickID() + 1) QuestComment.settext(CommentsDic[13]);
                    else {
                        QuestComment.settext(CommentsDic[2]);
                        badAnswer = true;
                        questanswer.setParams(buttons.getWidth() * 5, buttons.getHeight(), 5, buttons.getScale());
                        int a = atoi(question14DigitsInTable[questionVariantID1][0][question16AnswerString[questionVariantID1]].c_str());
                        int b = atoi(question14DigitsInTable[questionVariantID1][1][question16AnswerString[questionVariantID1]].c_str());
                        if (a > b) {
                            questanswer[0].loadFromFile(res_path + "digit" + std::to_string(a) + ".jpg");
                            questanswer[2].loadFromFile(res_path + "digit" + std::to_string(b) + ".jpg");
                        }
                        else
                        {
                            questanswer[0].loadFromFile(res_path + "digit" + std::to_string(b) + ".jpg");
                            questanswer[2].loadFromFile(res_path + "digit" + std::to_string(a) + ".jpg");
                        }

                        questanswer[1].loadFromFile(res_path + "digit_minus.jpg");

                        questanswer[3].loadFromFile(res_path + "digit_equal.jpg");
                        questanswer[4].loadFromFile(res_path + "digit" + std::to_string(
                            question16Answer[questionVariantID1]

                        ) + ".jpg");

                        buttons.getButtonTexture()[buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        buttons.getButtonTexture()[question15Answer[questionVariantID1] - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(question15Answer[questionVariantID1]) + "_right.jpg"
                        );

                        questanswer.draw();
                    }

                if (buttons.click()) {
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }

            }


        }
    }

    srand(static_cast<unsigned int>(time(NULL)));


}