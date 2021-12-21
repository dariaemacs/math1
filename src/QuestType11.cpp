#include "QuestType11.hpp"
#include "database.hpp"

int QuestType11::getquestionVariantID1() { return 0; }
int QuestType11::getquestionVariantID2() { return 0; }
int QuestType11::getquestionVariantID3() { return 0; }
int QuestType11::getquestionVariantID4() { return 0; }
int QuestType11::getquestionVariantID5() { return 0; }





QuestType11::QuestType11(float w, float h) :
    window(w, h, 0, 10),
    checkbutton(*this),
    picture1(*this),
    picture2(*this)
{
    gameClass::setmarks(10, 1);
    bool first = true;
    srand(static_cast<unsigned int>(time(NULL)));
    question11Variant1ID = rand() % 2;
    question11Variant2ID = rand() % (sizeof(question11pictureFN) / sizeof(question11pictureFN[0]));
    question11Variant3ID = rand() % (sizeof(question11ALLVariants) / sizeof(question11ALLVariants[0]));
    //sizeof(question10VariantForRandom1) / sizeof(question10VariantForRandom1[0])
    //int question10Variant3ID = rand() % (sizeof(question10VariantForRandom2) / sizeof(question10VariantForRandom2[0]));

    std::cout << question11Variant2ID << std::endl;


    std::wstring question = question11Text[0].questionText;

    std::wstring replaceFrom = L"N";
    std::wstring replaceTo = question11Variant1[question11Variant1ID];

    size_t posn = question.find(replaceFrom);
    if (posn < question.length()) { question.replace(posn, replaceFrom.length(), replaceTo); }

    textFrame.settext(question);
    textFrame.CalcucateCoordinate(w - w * 5 / 100, textFrame.getHeight());


    std::cout << question11Variant1ID << std::endl;
    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    sf::Event event;
    checkbutton.SetqudroSize(35);

    picture1.setButtonCount(4);
    picture2.setButtonCount(6);

    picture1.setpictureFilename(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + question11pictureFN[question11Variant2ID][0]);
    picture1.setMargin_left(10);
    picture2.setpictureFilename(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + question11pictureFN[question11Variant2ID][1]);
    picture2.setMargin_left(10);

    picture1.setMargin_top(h / 3);


    while (win->isOpen()) {
        win->clear();

        win->draw(List);
        win->draw(ArrowButtonSprite);
        if (first) {

            first = false;
            picture1.CalcucateCoordinate(2);
            picture2.setMargin_top(h / 3 + picture1.getHeight()
                //    textFrame.getHeight() + 15 + picture1.getHeight()+h/10
            );
            picture2.CalcucateCoordinate(12);



            QuestComment.CalcucateCoordinate(h / 3, w / 2);
            QuestComment.settext(L"");
            checkbutton.SetSpacing(11);

            checkbutton.Set_margitop(
                ((h - (checkbutton.getQudroSize() + 10) * 4) - checkbutton.getSprite()[0].getPosition().y)
            );
            //QuestComment.setmargin_top((h - (checkbutton.getQudroSize() + 20) * 4) - checkbutton.getSprite()[0].getPosition().y - checkbutton.getQudroSize() - 10);
            checkbutton.resetclickID();
        }


        for (int i = 0; i < 4; i++) {
            win->draw(checkbutton.getSprite()[i]);

            std::wstring tmpStr = question11Variant2[question11Variant2ID][question11Variant1ID][question11ALLVariants[question11Variant3ID][i]];
            checkbutton.setStrValue(i, tmpStr,28);
            //const sf::Font F = tmp1.getFont();

            tmpStr = checkbutton.getText()[i].getString();

            win->draw(checkbutton.getText()[i]);

        }
        //QuestComment.setmargin_top(h - (checkbutton.getQudroSize() + 20) * 4);
        QuestComment.setmargin_top(textFrame.getHeight() + 15);
        win->draw(QuestComment.gettext());


        win->draw(textFrame.gettext());
        for (int bc = 0; bc < picture1.getButtonCount(); bc++) {

            win->draw(*picture1.getButtons()[bc]);
        }
        for (int bc = 0; bc < picture2.getButtonCount(); bc++) {

            win->draw(*picture2.getButtons()[bc]);
        }




        DrawGameTime();
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor))
                {

                    countofBALL = question11BALL[question11Variant1ID][checkbutton.getanswerNUMBER()];
                    for (int i = 0; i < 4; i++) {
                        if (checkbutton.isAnswerRight(i, question11Variant3ID, question11Variant1ID) && checkbutton.getSprite()[i].getActive())
                            checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_right.png");
                        else
                            if (!checkbutton.isAnswerRight(i, question11Variant3ID, question11Variant1ID) && checkbutton.getSprite()[i].getActive())
                                checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_wrong.png");
                            else
                                if (checkbutton.isAnswerRight(i, question11Variant3ID, question11Variant1ID) && !checkbutton.getSprite()[i].getActive())
                                    checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_right.png");

                    }
                    //std::cout << checkbutton.isAnswerRight(i, question11Variant3ID, question11Variant1ID);
                    switch (countofBALL) {
                    case 0: QuestComment.settext(CommentsDic[11]); gameClass::setmarks(10, 0); break; //L"Ошибка. Баллы не засчитаны :(" 
                    case 1: QuestComment.settext(CommentsDic[10]); gameClass::setmarks(10, 1); break; //
                    case 2: QuestComment.settext(CommentsDic[9]);  gameClass::setmarks(10, 2); break;  //
                    }


                    wasAnswer = true;
                }

                if (checkbutton.click(question11Variant3ID)) {

                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png");
                    readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }

            }


        }
        if (wasAnswer && afterAsk()) return;
    }

    srand(static_cast<unsigned int>(time(NULL)));

}