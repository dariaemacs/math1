#include "infoWin.hpp"
#include "color.hpp"
#include "database.hpp"


infoWin::infoWin() :
    window(gameClass::getWidth(), gameClass::getHeight(), -1, 0),
    startButton(*this),
    resultButton(*this),
    text1(CommentsDic[16]),
    text2(CommentsDic[17]),
    text3(CommentsDic[18]),
    text4(CommentsDic[19]),
    text5(CommentsDic[20]),
    text6(CommentsDic[21])
        {
    sf::Event event;
    bool first = true;
    picresultTexture.loadFromFile("resources/images/ballPica.jpg");
    picresultSprite.setTexture(picresultTexture);
    
    
    float picresultScale = (gameClass::getWidth() / 2)/(picresultTexture.getSize().x+30)  ;
    picresultSprite.setScale(picresultScale, picresultScale);
    picresultSprite.setPosition(gameClass::getWidth() / 2+10, 0);
    text1.ñalcucateCoordinate(gameClass::getWidth()/2- gameClass::getWidth() / 20, gameClass::getHeight() / 2);
    text1.setmargin_top(text1.getheight()*4);
    text1.setmargin_left((gameClass::getWidth()/2  - text1.getwidth())/2 );

    text2.setmargin_top(text1.getheight() * 5);
    
    text2.setSize(text1.getSize());
    text2.setmargin_left(static_cast<float>(static_cast<int>((gameClass::getWidth() / 2 - text2.getwidth()) / 2)));

    text3.setmargin_top(text1.getheight() * 8);
    text3.setSize(text1.getSize());
    text3.setmargin_left(static_cast<float>(static_cast<int>((gameClass::getWidth() / 2 - text3.getwidth()) / 2)));

    text4.setmargin_top(text1.getheight() * 9);
    text4.setSize(text1.getSize());
    text4.setmargin_left(static_cast<float>(static_cast<int>((gameClass::getWidth() / 2 - text4.getwidth()) / 2)));

    text5.setmargin_top(text1.getheight() * 10);
    text5.setSize(text1.getSize());
    text5.setmargin_left(static_cast<float>(static_cast<int>((gameClass::getWidth() / 2 - text5.getwidth()) / 2)));

    text6.setmargin_top(text1.getheight() * 15);
    text6.setSize(text1.getSize());
    text6.setmargin_left(static_cast<float>(static_cast<int>((gameClass::getWidth() / 2 - text6.getwidth()) / 2)));

    startButton.setButtonCount(1);
    resultButton.setButtonCount(1);

    rectangleLeft.setSize(sf::Vector2f(width /2, height-5));
    rectangleLeft.setFillColor(color::lightgray);

    rectangleRight.setSize(sf::Vector2f(width / 2, height - 5));
    rectangleRight.setPosition(sf::Vector2f(width / 2+4, 0));
    rectangleRight.setFillColor(color::lightgray);

    startButton.setpictureFilename("resources/images/begin_work");
    resultButton.setpictureFilename("resources/images/results");

    startButton.CalcucateCoordinate(0);
    resultButton.CalcucateCoordinate(1);

    while (win->isOpen()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && startButton.click()) {
            gameClass::setisGame(true);
            return;
        } else 
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && resultButton.click()) {
                gameClass::setisGame(false);
                return;
            }

        win->clear(color::white);
        
        win->draw(rectangleLeft);
        win->draw(rectangleRight);


        //win->draw(List);
      
        win->draw(*startButton.getButtons()[0]);
        win->draw(*resultButton.getButtons()[0]);
        win->draw(text1);
        win->draw(text2);
        win->draw(text3);
        win->draw(text4);
        win->draw(text5);
        win->draw(text6);
        win->draw(picresultSprite);

        win->display();
      
        while (win->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                win->close();
            }
        }
        

    }
}

int infoWin::getquestionVariantID1() { return 0; }
int infoWin::getquestionVariantID2() { return 0; }
int infoWin::getquestionVariantID3() { return 0; }
int infoWin::getquestionVariantID4(){ return 0; }
int infoWin::getquestionVariantID5(){ return 0; }