#include "QuestType10.hpp"
#include "database.hpp"

int QuestType10::getquestionVariantID1() { return 0; }
int QuestType10::getquestionVariantID2() { return 0; }
int QuestType10::getquestionVariantID3() { return 0; }
int QuestType10::getquestionVariantID4() { return 0; }
int QuestType10::getquestionVariantID5() { return 0; }



QuestType10::QuestType10() :
    window(gameClass::getWidth(), gameClass::getHeight(), 0, 9),
    checkbutton(*this)
{

    gameClass::setmarks(9, 0);
    bool first = true;
    question10Variant1ID = rand() % 2;
    question10Variant2ID = rand() % (sizeof(question10Variant2) / sizeof(question10Variant2[0]));

    int question10Variant3ID = rand() % (sizeof(question10VariantForRandom2) / sizeof(question10VariantForRandom2[0]));

    //std::cout << question10Variant3ID << std::endl;

    std::wstring  replaceFrom = L"N";
    //question10Variant2[question10Variant2ID];


    std::wstring replaceTo(question10Variant2[question10Variant2ID][question10VariantForRandom2[question10Variant3ID][0]]
        +
        question10Variant2[question10Variant2ID][question10VariantForRandom2[question10Variant3ID][1]]
        +
        question10Variant2[question10Variant2ID][question10VariantForRandom2[question10Variant3ID][2]]
    );
    std::wstring question = std::to_wstring(getordQuestNumber() + 1) + L". " + question10Text[getQuestNumber()].questionText;
    size_t posn = question.find(replaceFrom);
    if (posn < question.length()) { question.replace(posn, replaceFrom.length(), replaceTo); }

    replaceFrom = L"M";
    replaceTo = question10Variant1[question10Variant1ID];

    posn = question.find(replaceFrom);
    if (posn < question.length()) { question.replace(posn, replaceFrom.length(), replaceTo); }
    checkbutton.SetqudroSize(40);
    textFrame.settext(question);
    textFrame.CalcucateCoordinate(width - width * 5 / 100, textFrame.getHeight());


    std::cout << question10Variant1ID << std::endl;
    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    sf::Event event;
    checkbutton.setTextValue(question10Variant2ID);



    while (win->isOpen()) {
        win->clear();

        win->draw(List);
        win->draw(ArrowButtonSprite);
        if (first) {
            first = false;

            QuestComment.CalcucateCoordinate(height / 3, width / 2);
            QuestComment.setmargin_top((height - (checkbutton.getQudroSize() + 20) * 3) - checkbutton.getSprite()[0].getPosition().y - checkbutton.getQudroSize() - 10);
            //QuestComment.setmargin_top(0);
            checkbutton.Set_margitop((height - (checkbutton.getQudroSize() + 20) * 3) - checkbutton.getSprite()[0].getPosition().y);
        }

        //for (int i = 0; i < 3; i++) {
        //    window->draw(checkbutton.getSprite()[i]);
        //    //question13VariantID
        //    std::wstring tmpStr = question13Variant[question13VariantID][i];
        //    checkbutton.setStrValue(i, tmpStr);
        //    tmpStr = checkbutton.getText()[i].getString();
        //    window->draw(checkbutton.getText()[i]);
        //}

        for (int i = 0; i < 4; i++) {
            win->draw(checkbutton.getSprite()[i]);
            sf::Text tmp1 = checkbutton.getText()[i];
            std::wstring tmpStr = tmp1.getString();
            checkbutton.setStrValue(i, tmpStr, 28);
            win->draw(checkbutton.getText()[i]);
        }

        win->draw(QuestComment.gettext());

        win->draw(textFrame.gettext());



        if (badAnswer) {
           
            checkbutton.getquadroTexture()[checkbutton.getClickID()].loadFromFile(
                "resources/images/select_wrong.png");

            checkbutton.getquadroTexture()[checkbutton.getrightQuestNum()].loadFromFile(
                "resources/images/select_right.png");

            //checkbutton.getClickID()
        }
        DrawGameTime();
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor)) {
                    if (checkbutton.getrightQuestNum() == checkbutton.getClickID())
                    {
                        QuestComment.settext(CommentsDic[1]);
                        gameClass::setmarks(9, 1);
                    }
                    else {
                        QuestComment.settext(CommentsDic[2]);
                        badAnswer = true;
                        gameClass::setmarks(9, 0);
                    }
                    wasAnswer = true;
                }

                if (checkbutton.click()) {

                    ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                }

            }


        }
        if (wasAnswer && afterAsk()) return;
    }

    srand(static_cast<unsigned int>(time(NULL)));

};