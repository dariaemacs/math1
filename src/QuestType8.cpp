#include "QuestType8.hpp"
#include "database.hpp"
int QuestType8::getquestionVariantID1() { return 0; }
int QuestType8::getquestionVariantID2() { return 0; }
int QuestType8::getquestionVariantID3() { return 0; }
int QuestType8::getquestionVariantID4() { return 0; }
int QuestType8::getquestionVariantID5() { return 0; }



QuestType8::QuestType8(float w, float h)
    :window(w, h, ((rand() % 4)), 7),
    setofpic0(*this),
    setofpic1(*this),
    setofpic2(*this),
    setofpic3(*this),

    plus(*this),
    minus(*this),
    thingsCount(0)
{




    bool first = true;
    int margintopSlideButton = 0;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);


    setofpic0.setButtonCount(1);
    setofpic1.setButtonCount(1);
    setofpic2.setButtonCount(1);
    setofpic3.setButtonCount(1);
    plus.setButtonCount(1);
    minus.setButtonCount(1);




    setofpic0.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "1");
    setofpic1.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "2");
    setofpic2.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "3");
    setofpic3.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "0");

    plus.setpictureFilename("resources/images/" + filenamesforPicaQuestPlus8[getQuestNumber()]);
    minus.setpictureFilename("resources/images/" + filenamesforPicaQuestMinus8[getQuestNumber()]);

    setofpic0.setMargin_left(0);
    setofpic0.CalcucateCoordinate(1);
    setofpic1.setMargin_left(setofpic0.getWidth());
    setofpic1.CalcucateCoordinate(1);
    setofpic2.setMargin_left(2 * (setofpic1.getWidth()));
    setofpic2.CalcucateCoordinate(1);
    setofpic3.setMargin_left(3 * (setofpic2.getWidth()));
    setofpic3.CalcucateCoordinate(1);

    plus.setMargin_left(0);
    plus.setisAdd();
    plus.CalcucateCoordinate(2);
    minus.setMargin_left(plus.getMarginLeft() + plus.getWidth());

    minus.setMargin_top(500);
    minus.CalcucateCoordinate(2);

    sf::Event event;
    while (win->isOpen()) {
        win->clear();
        win->draw(List);

        if (first) {

            first = false;


            QuestComment.CalcucateCoordinate(h / 3, w / 2);
            QuestComment.settext(L"");
            first = false;
            QuestComment.setmargin_top(h - minus.getHeight());
        }
        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());
        win->draw(*setofpic0.getButtons()[0]);
        win->draw(*setofpic1.getButtons()[0]);
        win->draw(*setofpic2.getButtons()[0]);
        win->draw(*setofpic3.getButtons()[0]);
        win->draw(*plus.getButtons()[0]);
        win->draw(*minus.getButtons()[0]);
        win->draw(ArrowButtonSprite);
        DrawGameTime();
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor)) {
                    if (thingsCount == 4) QuestComment.settext(CommentsDic[1]);
                    else //wrong
                    {
                        QuestComment.settext(CommentsDic[2]);
                        setofpic3.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "4");
                        (setofpic3.getButtonTexture()[0])->loadFromFile("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "4" + ".png");
                    }
                    wasAnswer = true;
                }
                int thingsCounttmp = thingsCount;
                thingsCount = minus.click(thingsCount, setofpic3);


                thingsCount = plus.click(thingsCount, setofpic3);
                if (thingsCounttmp != thingsCount) {
                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png");
                    readyforCheck = true;
                }

                win->draw(*setofpic3.getButtons()[0]);


            }
        }
        if (wasAnswer && afterAsk()) return;
    }

    srand(static_cast<unsigned int>(time(NULL)));
}