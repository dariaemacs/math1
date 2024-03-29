#include "QuestType1.hpp"
#include "window.hpp"
#include "database.hpp"
#include "gameClass.hpp"
float QuestType1::check(float c, float t, float r) {
    switch (question1Text[questNumber].key)
    {
    case circle:

        if (c == Buttons.GetButtonsClickID() + 1)
            return -1; else  return c;
        break;
    case triangle:
        if (t == Buttons.GetButtonsClickID() + 1)
            return -1; else  return t;
        break;
    case rectangle:
        if (r == Buttons.GetButtonsClickID() + 1)
            return -1; else  return r;
        break;
    default:
        break;
    }



    return -1;
}

QuestType1::QuestType1( int qtyButtons) :

    window(gameClass::getWidth(), gameClass::getHeight(), (rand() % 3), 0),
    Buttons(qtyButtons, *this)
{
    gameClass::setmarks(0, 0);
    bool first = true;
    float margintopSlideButton = 0;
    FrameFigure::resetnumber_of_figure();
    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);

    const std::vector<FrameFigure*> figures =
    {
        new Car(win), //+
        new Flower(win),//+
        new Tree(win),
        new Butterfly(win),
        new Plane(win), //+
        new Tower(win), //+
    };

    questionVariantID1 = (rand() % figures.size());
    while ((questionVariantID2 = (rand() % figures.size())) == questionVariantID1);

    int rectengleQTY = figures[questionVariantID1]->getrectengleQTY() + figures[questionVariantID2]->getrectengleQTY();
    int triangleQTY = figures[questionVariantID1]->gettriangleQTY() + figures[questionVariantID2]->gettriangleQTY();
    int circleQTY = figures[questionVariantID1]->getcircleQTY() + figures[questionVariantID2]->getcircleQTY();
    sf::Event event;
    while (win->isOpen()) {
        win->clear(color::white);
      
        
        
        win->draw(List);
        figures[questionVariantID1]->draw();
        figures[questionVariantID2]->draw();



        if (figures[questionVariantID1]->GetisNextQuest() || figures[questionVariantID2]->GetisNextQuest())
        {
            delete(figures[0]);
            delete(figures[1]);
            delete(figures[2]);
            delete(figures[3]);
            delete(figures[4]);
            delete(figures[5]);
            return;
        }
        if (first) {
            margintopSlideButton =
                (
                    (figures[questionVariantID1]->getymax() * figures[questionVariantID1]->getkoef() > figures[questionVariantID2]->getymax() * figures[questionVariantID2]->getkoef() ? figures[questionVariantID1]->getymax() * figures[questionVariantID1]->getkoef() : figures[questionVariantID2]->getymax() * figures[questionVariantID2]->getkoef())
                    ) + (figures[questionVariantID1]->getmargin_top() > figures[questionVariantID2]->getmargin_top() ? figures[questionVariantID1]->getmargin_top() : figures[questionVariantID2]->getmargin_top());
            Buttons.setMargin_top(margintopSlideButton + 10);
            Buttons.CalcucateCoordinate(); first = false;
            QuestComment.setmargin_top(height - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());
        }
       
        
        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());
        win->draw(ArrowButtonSprite);

        for (int bc = 0; bc < Buttons.getButtonCount(); bc++) {
            win->draw(*Buttons.getButtons()[bc]);
        }
        DrawGameTime();
        win->display();
        
        while (win->pollEvent(event)) {
            
            if (event.type == sf::Event::Closed) {
                win->close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {

                    float rightfigurCount = check(static_cast<float>(circleQTY), static_cast<float>(triangleQTY), static_cast<float>(rectengleQTY));
                    if (rightfigurCount < 0) { QuestComment.settext(CommentsDic[1]); gameClass::setmarks(0, 1);
                    }
                    else {
                        gameClass::setmarks(0,0) ;
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[static_cast<int>(rightfigurCount) - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(rightfigurCount) + "_right.jpg"
                        );
                        figures[questionVariantID1]->setfiguraCode(questNumber);
                        figures[questionVariantID2]->setfiguraCode(questNumber);
                        figures[questionVariantID1]->setcheckMode();
                        figures[questionVariantID2]->setcheckMode();
                        



                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
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


}


int QuestType1::getquestionVariantID1() { return questionVariantID1; }
int QuestType1::getquestionVariantID2() { return questionVariantID2; }
int QuestType1::getquestionVariantID3() { return 0; }
int QuestType1::getquestionVariantID4() { return 0; }
int QuestType1::getquestionVariantID5() { return 0; }