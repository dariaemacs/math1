#include "game.hpp" 
#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>
using namespace sf; // подключаем пространство имен sf


int main() {
    std::string filename{ "settings.yml" };
    //int Window::ordQuestNumber = 0;

    try {





        int width = 1024; int height = 600;

        srand(time(0));
        //QuestType15(width, height,20);
        //QuestType9(width, height, 21);
/*        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);
        QuestType13(width, height);*/
    
    width = 1024;  height = 600;
    QuestType1( width ,height,25);
    QuestType2(width, height,25);
    QuestType3(width, height, 25);
    QuestType4(width, height, 25);
    QuestType5(width, height, 25);
    //width = 1024;  height = 600;
    // QuestType14( width ,height,25);

     width = 1200; height = 600;
     QuestType14( width ,height,25);

     width = 1280; height = 720;
     QuestType14( width ,height,25);

     width = 1280; height = 768;
     QuestType14( width ,height,25);
     width = 1280; height = 1024;
     QuestType14( width ,height,25);

     width = 1408; height = 1152;
     QuestType14( width ,height,25);
     width = 1440; height = 900;
     QuestType14( width ,height,25);
     width = 1400; height = 1050;
     QuestType14( width ,height,25);


     width = 1440; height = 1080;
     QuestType14( width ,height,25);

     width = 1536; height = 960;
     QuestType14( width ,height,25);
     width = 1536; height = 1024;
     QuestType14( width ,height,25);

     width = 1600; height = 900;
     QuestType14( width ,height,25);
     width = 1600; height = 1024;
     QuestType14( width ,height,25);
     width = 1600; height = 1200;
     QuestType14( width ,height,25);

     width = 1680; height = 1050;
     QuestType14( width ,height,25);
    
     width = 1920; height = 1080;
     QuestType14( width ,height,25);
     
     width = 1920; height = 1200;
     QuestType14( width ,height,25);
     
     width = 2048; height = 1080;
     QuestType14( width ,height,25);
     
    



     /* QuestType1(1, 2, width, height, (rand() % 3), 21);
      QuestType1(5, 2, width, height, (rand() % 3), 21);
      QuestType1(1, 5, width, height, (rand() % 3), 21);*/


      /* QuestType1(0, 1, width, height, (rand() % 3), 21);

       QuestType1(2, 1, width, height, (rand() % 3), 21);
       QuestType1(3, 1, width, height, (rand() % 3), 21);
       QuestType1(4, 1, width, height, (rand() % 3), 21);
       QuestType1(5, 1, width, height, (rand() % 3), 21);
       QuestType1(0, 2, width, height, (rand() % 3), 21);
       QuestType1(1, 2, width, height, (rand() % 3), 21);

       QuestType1(3, 2, width, height, (rand() % 3), 21);
       QuestType1(4, 2, width, height, (rand() % 3), 21);
       QuestType1(5, 2, width, height, (rand() % 3), 21);
       QuestType1(0, 3, width, height, (rand() % 3), 21);
       QuestType1(1, 3, width, height, (rand() % 3), 21);
       QuestType1(2, 3, width, height, (rand() % 3), 21);

       QuestType1(4, 3, width, height, (rand() % 3), 21);
       QuestType1(5, 3, width, height, (rand() % 3), 21);
       QuestType1(0, 4, width, height, (rand() % 3), 21);
       QuestType1(1, 4, width, height, (rand() % 3), 21);
       QuestType1(2, 4, width, height, (rand() % 3), 21);
       QuestType1(3, 4, width, height, (rand() % 3), 21);

       QuestType1(5, 4, width, height, (rand() % 3), 21);
       QuestType1(0, 5, width, height, (rand() % 3), 21);
       QuestType1(1, 5, width, height, (rand() % 3), 21);
       QuestType1(2, 5, width, height, (rand() % 3), 21);
       QuestType1(3, 5, width, height, (rand() % 3), 21);
       QuestType1(4, 5, width, height, (rand() % 3), 21);

       QuestType1 q1(width, height, (rand() % 3), 21);*/


       // Game game(config);
       // game.run();
       // }catch(const YAML::Exception& exc){
      // std::cerr << "EXCEPTION [" << exc.msg << "]" << std::endl;
    }
    catch (const std::exception& exc) {
        std::cerr << "EXCEPTION [" << exc.what() << "]" << std::endl;
    }

    return 0;
}



