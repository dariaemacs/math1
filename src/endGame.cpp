#include <ctime>
#include "endGame.hpp"
#include "database.hpp"
#include "filesSave.hpp"


int ballWord(int ballQty) {
    switch (ballQty) {
    case 0: return 31;
    case 1: return 29;
    case 2: return 30;
    case 3: return 30;
    case 4: return 30;
    }
    if (ballQty>4) return 31;
}

int qtyofBall() {
    int sum(0);
    for (int i = 0; i < 15; i++)
        sum = sum + gameClass::getMarks(i);

    return sum;
}

endGame::endGame():
	window(gameClass::getWidth(), gameClass::getHeight(), -1, 0),
    againButton(*this),
    exitButton(*this) {

    filescontrol filetoSave("data.dat");
    //std::tm now_time1 = std::chrono::system_clock::now();
    time_t now_time1 = time(NULL);
    tm ltm;
    localtime_s(&ltm, &now_time1);
    dataPoint currentgameData;

    currentgameData.day = ltm.tm_mday;
    currentgameData.month = 1 + ltm.tm_mon;
    currentgameData.year = 1900 + ltm.tm_year;
    currentgameData.qtyBall = qtyofBall();
    //currentgameData.qtyBall = 10;
    filetoSave.addoneRecordtoFile(currentgameData);

    againButton.setpictureFilename("resources/images/again");
    againButton.setButtonCount(1);
    againButton.CalcucateCoordinate(0);

    exitButton.setpictureFilename("resources/images/exit");    
    exitButton.setButtonCount(1);
    exitButton.CalcucateCoordinate(1);
    
    float mytime(gameClass::get_time());
    long long min = static_cast<long long>(mytime / 60);
    long long sec = (static_cast<long long>(mytime - (static_cast<long long>(mytime / 60)) * 60));
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
    int charSize = labels[0].getCharacterSize();
    int stepX = 0;
    int stepY = 0;

    labels[1].setString(CommentsDic[22]);
    labels[1].ñalcucateCoordinate(gameClass::getWidth() / 3, gameClass::getHeight() / 2);
    
    
    labels[1].setString(
        CommentsDic[32] + L" "+ std::to_wstring(qtyofBall()) + L" " + CommentsDic[ballWord(qtyofBall()%10)]);

    /*labels[1].setString(
        CommentsDic[32] + L" " + std::to_wstring(10) + L" " + CommentsDic[ballWord(10 % 10)]);*/


    labels[1].setmargin_top(labels[0].getheight()+10);
    labels[1].setmargin_left(10);
    for (int i = 2; i < 18; i++) {
        labels[i].setmargin_left(10);
        labels[i].setString(CommentsDic[28]+L" "+ std::to_wstring(i-1));
        labels[i].setCharacterSize(charSize - 6);
        if (i == 2) {
            stepX = labels[i].getwidth();
            stepY = labels[i].getheight();
        }
        labels[i].setmargin_left(questLabelBall[i-2].i* (stepX+50));
        labels[i].setmargin_top(questLabelBall[i-2].j * (stepY+50)+50);
        labels[i + 16].setCharacterSize(charSize - 6);
        labels[i+16].setmargin_left(questLabelBall[i - 2].i * (stepX + 50));
        labels[i+16].setString(std::to_wstring(gameClass::getMarks(i - 2)) + L" "+CommentsDic[ballWord(gameClass::getMarks(i - 2))]);
        labels[i+16].setmargin_top((questLabelBall[i - 2].j )* (stepY+50)+ stepY+50);

    }

    while (win->isOpen()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { 
            if (againButton.click()) return; 
            if (exitButton.click()) { gameClass::setquit(); return; }
        }
        win->clear(color::white);
        win->draw(labels[0]);
        win->draw(labels[1]);
        win->draw(*againButton.getButtons()[0]);
        win->draw(*exitButton.getButtons()[0]);
        for (int i = 2; i < 18; i++) {
            win->draw(labels[i]);
            win->draw(labels[i + 16]);
        }
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
