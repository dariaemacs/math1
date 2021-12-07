#include "QuestType14.hpp"
#include "database.hpp"

QuestType14::QuestType14(float w, float h, int qtyButtons) :
    questionVariantID1(rand() % 3),
    questionVariantID2(rand() % 3),
    window(w, h, 0, 13),
    tab(*this),
    checkbutton(*this)
{

    bool first = true;


    sf::Event event;
    checkbutton.SetqudroSize(35);

    textFrame.settext(question14Text[0].questionText + L" " + question14Text1[questionVariantID1] + L"\n" +
        question14Text2[questionVariantID1][0]
    );
    textFrame.CalcucateCoordinate(w - w * 10 / 100.0f, h / 3.0f);


    while (win->isOpen()) {
        win->clear();

        win->draw(List);

        if (first) {

            first = false;


            ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
            ArrowButtonSprite.setTexture(ArrowButtonTexture);
            QuestComment.setmargin_top(100);

            checkbutton.Set_margitop(tab.getmargintop() + tab.getheight0Row() * 6);
            QuestComment.CalcucateCoordinate(h / 3.0f, w / 2.0f);
            //QuestComment.
           //checkbutton.SetSpacing(200);
            QuestComment.setmargin_top(tab.getmargintop() + tab.getheight0Row() * 4);
            checkbutton.resetclickID();
            for (int i = 0; i < 3; i++) {
                std::wstring tmpStr = question14TextVariant[questionVariantID1][i];
                checkbutton.setStrValue(i, tmpStr,28);
                tmpStr = checkbutton.getText()[i].getString();
            }

        }

        for (int i = 0; i < 3; i++) {
            win->draw(checkbutton.getSprite()[i]);
            win->draw(checkbutton.getText()[i]);
        }
        tab.draw();
        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());

        win->draw(ArrowButtonSprite);


        if (badAnswer) {
            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            sprite.setPosition(0, 0);
            win->draw(sprite);
        }
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor))
                {

                    countofBALL = 0;

                    unsigned char result_int = 0;
                    int dec = 1;
                    //std::cout << std::endl;
                    //std::cout << " getClickID="<<checkbutton.getClickID()<< " questionVariantID1="<<questionVariantID1 << " questionVariantID=" << questionVariantID2 << std::endl;
                    if (question14AnswerString[questionVariantID1] == checkbutton.getClickID()) { QuestComment.settext(CommentsDic[1]); }
                    else {

                        QuestComment.settext(CommentsDic[2]);
                        for (int i = 0; i < 3; i++) {

                            if (((checkbutton.getClickID() & (1 << i)) >> i) > 0 && ((checkbutton.getClickID() & (1 << i)) >> i) != ((question14AnswerString[questionVariantID1] & (1 << i)) >> i))
                                checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_wrong.png");

                            if (((checkbutton.getClickID() & (1 << i)) >> i) == 0 && (((question14AnswerString[questionVariantID1] & (1 << i)) >> i)) > 0)
                                checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_right.png");

                            if (((checkbutton.getClickID() & (1 << i)) >> i) > 0 && ((checkbutton.getClickID() & (1 << i)) >> i) == ((question14AnswerString[questionVariantID1] & (1 << i)) >> i))
                                checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_right.png");


                        }

                    };
                    wasAnswer = true;
                }
                if (checkbutton.click(0)) {
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }

            }

        }
        if (wasAnswer && afterAsk()) return;
    }
    srand(static_cast<unsigned int>(time(NULL)));


}