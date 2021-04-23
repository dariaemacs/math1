#include "game.hpp" 
#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>
using namespace sf; // подключаем пространство имен sf

int main(){
    std::string filename{ "settings.yml" };
    try {




      // int width = sf::VideoMode::getDesktopMode().width;int height = sf::VideoMode::getDesktopMode().height;

      int width   = 640;int height = 360;
      //int width = 854;int height = 480;
      //int width = 1280;int height = 720;
      // int width = 1600;int height = 900;
     // int width = 1920;int height = 1080;
      //int width = 2048;int height = 1152;
      //int width = 2560;int height =1440;
      // int width = 1440;int height = 900;
      //int width = 1536; int height = 960;
      //int width = 1680; int height = 1050;
      //int width = 1920 ; int height = 1200 ;
      //int width = 96; int height = 132;
      //  int width = 352; int height = 240;
      // int width = 352; int height = 240;
      //  int width = 352; int height = 288;
      //  int width = 400; int height = 240;
      //  int width = 480; int height = 576;
      //  int width = 640; int height = 240;
      //  int width = 320; int height = 480;


        srand(time(0));
        //QuestType1 q1(width, height, 1 - (rand() % 2), 0, 1, 17);
        //QuestType1 q2(width, height, 1 - (rand() % 2), 2, 3, 17);
      //  int width = 640; int height = 360;
        QuestType1 q1(width, height, 1 - (rand() % 2), 5);
        /*QuestType1 q2(width, height, 1 - (rand() % 2), 0, 1, 17);
        QuestType1 q3(width, height, 1 - (rand() % 2), 0, 2, 17);
        QuestType1 q4(width, height, 1 - (rand() % 2), 0, 3, 17);
        QuestType1 q5(width, height, 1 - (rand() % 2), 0, 4, 17);
        QuestType1 q6(width, height, 1 - (rand() % 2), 0, 5, 17);
        QuestType1 q7(width, height, 1 - (rand() % 2), 1, 0, 17);
        QuestType1 q8(width, height, 1 - (rand() % 2), 1, 1, 17);
        QuestType1 q9(width, height, 1 - (rand() % 2), 1, 2, 17);
        QuestType1 q10(width, height, 1 - (rand() % 2), 1, 3, 17);
        QuestType1 q11(width, height, 1 - (rand() % 2), 1, 4, 17);
        QuestType1 q12(width, height, 1 - (rand() % 2), 1, 5, 17);
        QuestType1 q13(width, height, 1 - (rand() % 2), 2, 0, 17);
        QuestType1 q14(width, height, 1 - (rand() % 2), 2, 1, 17);
        QuestType1 q15(width, height, 1 - (rand() % 2), 2, 2, 17);
        QuestType1 q16(width, height, 1 - (rand() % 2), 2, 3, 17);
        QuestType1 q17(width, height, 1 - (rand() % 2), 2, 4, 17);
        QuestType1 q18(width, height, 1 - (rand() % 2), 2, 5, 17);
        QuestType1 q19(width, height, 1 - (rand() % 2), 3, 0, 17);
        QuestType1 q20(width, height, 1 - (rand() % 2), 3, 1, 17);
        QuestType1 q21(width, height, 1 - (rand() % 2), 3, 2, 17);
        QuestType1 q22(width, height, 1 - (rand() % 2), 3, 3, 17);
        QuestType1 q23(width, height, 1 - (rand() % 2), 3, 4, 17);
        QuestType1 q24(width, height, 1 - (rand() % 2), 3, 5, 17);
        QuestType1 q25(width, height, 1 - (rand() % 2), 4, 0, 17);
        QuestType1 q26(width, height, 1 - (rand() % 2), 4, 1, 17);
        QuestType1 q27(width, height, 1 - (rand() % 2), 4, 2, 17);
        QuestType1 q28(width, height, 1 - (rand() % 2), 4, 3, 17);
        QuestType1 q29(width, height, 1 - (rand() % 2), 4, 4, 17);
        QuestType1 q30(width, height, 1 - (rand() % 2), 4, 5, 17);
        QuestType1 q31(width, height, 1 - (rand() % 2), 5, 0, 17);
        QuestType1 q32(width, height, 1 - (rand() % 2), 5, 1, 17);
        QuestType1 q33(width, height, 1 - (rand() % 2), 5, 2, 17);
        QuestType1 q34(width, height, 1 - (rand() % 2), 5, 3, 17);
        QuestType1 q35(width, height, 1 - (rand() % 2), 5, 4, 17);
        QuestType1 q36(width, height, 1 - (rand() % 2), 5, 5, 17);*/



        //QuestType1 q2(width, height, 1 - (rand() % 2), tree, tree, 17);

        // Game game(config);
        // game.run();
        // }catch(const YAML::Exception& exc){
       // std::cerr << "EXCEPTION [" << exc.msg << "]" << std::endl;
    }
    catch (const std::exception & exc) {
        std::cerr << "EXCEPTION [" << exc.what() << "]" << std::endl;
    }

    return 0;
}

