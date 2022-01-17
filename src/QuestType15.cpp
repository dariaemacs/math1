#include "QuestType15.hpp"
#include "database.hpp"

QuestType15::QuestType15( int qtyButtons) :
    questionVariantID1(rand() % 3),
    questionVariantID2(rand() % 3),
    window(gameClass::getWidth(), gameClass::getHeight(), 0, 13),
    buttons(qtyButtons, *this),
    tab(*this) {
    gameClass::setmarks(14, 1);
    bool first = true;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    sf::Event event;
    //questanswer[0].loadFromFile("resources/images/arrow_disable.png");

    textFrame.settext(question14Text[0].questionText + L" " + question14Text1[questionVariantID1] + L"\n" +
        question14Text2[questionVariantID1][1]
    );
    textFrame.CalcucateCoordinate(width - width * 10 / 100.0f, height / 3.0f);


    while (win->isOpen()) {
        win->clear();

        win->draw(List);

        if (first) {

            first = false;

            buttons.CalcucateCoordinate((height - 100) / 1.4f);

            QuestComment.setmargin_top(buttons.getMarginTop());
            QuestComment.CalcucateCoordinate(height / 3, width / 2);








        }

        tab.draw();
        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());
        for (int bc = 0; bc < buttons.getButtonCount(); bc++)
            win->draw(*buttons.getButtons()[bc]);
        win->draw(ArrowButtonSprite);


        if (badAnswer) {
            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            sprite.setPosition((width - questanswer.getWidth()) / 2, buttons.getMarginTop() - 2 * questanswer.getWidth() * questanswer.getScale());
            win->draw(sprite);
            gameClass::setmarks(14, 0);
        }
        DrawGameTime();
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor)){
                    if (question15Answer[questionVariantID1] == buttons.GetButtonsClickID() + 1) QuestComment.settext(CommentsDic[13]);
                    else {
                        QuestComment.settext(CommentsDic[2]);
                        badAnswer = true;
                        questanswer.setParams(buttons.getWidth() * 5, buttons.getHeight(), 5, buttons.getScale());

                        questanswer[0].loadFromFile(res_path + "digit" + question14DigitsInTable[questionVariantID1][0][question15AnswerString[questionVariantID1]] + ".jpg");
                        questanswer[1].loadFromFile(res_path + "digit_plus.jpg");
                        questanswer[2].loadFromFile(res_path + "digit" + question14DigitsInTable[questionVariantID1][1][question15AnswerString[questionVariantID1]] + ".jpg");
                        questanswer[3].loadFromFile(res_path + "digit_equal.jpg");
                        questanswer[4].loadFromFile(res_path + "digit" + std::to_string(
                            question15Answer[questionVariantID1]

                        ) + ".jpg");

                        buttons.getButtonTexture()[buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        buttons.getButtonTexture()[question15Answer[questionVariantID1] - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(question15Answer[questionVariantID1]) + "_right.jpg"
                        );

                        questanswer.draw();
                    }
                    wasAnswer = true;
            }
                if (buttons.click()) {
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }

            }


        }
        if (wasAnswer && afterAsk()) return;
    }

    srand(static_cast<unsigned int>(time(NULL)));


}