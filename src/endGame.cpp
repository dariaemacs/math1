#include "endGame.hpp"
#include "database.hpp"

endGame::endGame():
	window(gameClass::getWidth(), gameClass::getHeight(), -1, 0),
	againButton(*this){

    float time(4);
    long long min = static_cast<long long>(time / 60);
    long long sec = (static_cast<long long>(time - (static_cast<long long>(time / 60)) * 60));
    int minindexText(0);
    int secindexText(0);
    if ((min % 10) == 0 || (min % 10) == 5 || (min % 10) == 0 || (min % 10) == 6 || (min % 10) == 7 || (min % 10) == 8
        || (min % 10) == 9
        ) minindexText = 23; else minindexText = 24;

    if ((sec % 10) == 0 || (sec % 10) == 5 || (sec % 10) == 0 || (sec % 10) == 6 || (sec % 10) == 7 || (sec % 10) == 8
        || (sec % 10) == 9
        ) secindexText = 25; else secindexText = 26;


    sf::Event event;
    
    labels[0].setString(CommentsDic[22]);
    labels[0].ñalcucateCoordinate(gameClass::getWidth() / 3, gameClass::getHeight() / 2);
    labels[0].setString(
        CommentsDic[22] + std::to_wstring(min) + CommentsDic[minindexText] + std::to_wstring(sec) + CommentsDic[secindexText]);
        
//        CommentsDic[23]);
    
    labels[0].setmargin_top(0);
    labels[0].setmargin_left(10 );

    labels[1].setmargin_top(labels[0].getheight() +10);
    labels[1].setmargin_left(10);
    labels[1].setString(CommentsDic[28]);
    labels[1].ñalcucateCoordinate(gameClass::getWidth() / 10, gameClass::getHeight() / 2);
    while (win->isOpen()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ) return;
        win->clear(color::white);

        win->draw(labels[1]);
        win->draw(labels[0]);
        win->display();
       
        while (win->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                win->close();
            }
        }


    }

}


int endGame::getquestionVariantID1() { return 0; }
int endGame::getquestionVariantID2() {return 0;}
int endGame::getquestionVariantID3() {return 0;}
int endGame::getquestionVariantID4() {return 0;}
int endGame::getquestionVariantID5() {return 0;}