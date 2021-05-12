#include "game.hpp" 
#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>
using namespace sf; // подключаем пространство имен sf

int main(){
    std::string filename{ "settings.yml" };
    try {




        /*
        int width = 1024; int height = 600;
 
        srand(time(0));
        QuestType1 q1(width, height, (rand() % 3),20);
      */

        int width = 1024;  int height = 768;
      srand(time(0));
      QuestType1 q2(width, height, (rand() % 3), 21);
      /*
      width = 1152; height = 864;
      srand(time(0));
      QuestType1 q3(width, height, (rand() % 3), 20);
      
      width = 1200; height = 600;
       srand(time(0));
       QuestType1 q4(width, height, (rand() % 3), 20);

       width = 1280; height = 720;
      srand(time(0));
      QuestType1 q5(width, height, (rand() % 3), 20);
      
      width = 1280; height = 768;
      srand(time(0));
      QuestType1 q6(width, height, (rand() % 3), 20);

      width = 1280; height = 1024;
      srand(time(0));
      QuestType1 q7(width, height, (rand() % 3), 20);

      width = 1408; height = 1152;
       srand(time(0));
       QuestType1 q8(width, height, (rand() % 3), 20);

       width = 1440; height = 900;
      srand(time(0));
      QuestType1 q9(width, height, (rand() % 3), 20);

      width = 1400; height = 1050;
      srand(time(0));
      QuestType1 q10(width, height, (rand() % 3), 20);

      width = 1440; height = 1080;
      srand(time(0));
      QuestType1 q11(width, height, (rand() % 3), 20);

      width = 1536; height = 960;
      srand(time(0));
      QuestType1 q12(width, height, (rand() % 3), 20);

      width = 1536; height = 1024;
        srand(time(0));
        QuestType1 q13(width, height, (rand() % 3), 20);

        width = 1600; height = 900;
       srand(time(0));
       QuestType1 q14(width, height, (rand() % 3), 20);

       width = 1600; height = 1024;
        srand(time(0));
        QuestType1 q15(width, height, (rand() % 3), 20);

        width = 1600; height = 1200;
        srand(time(0));
        QuestType1 q16(width, height, (rand() % 3), 20);

        width = 1680; height = 1050;
        srand(time(0));
        QuestType1 q17(width, height, (rand() % 3), 20);

        width = 1920; height = 1080;
        srand(time(0));
        QuestType1 q18(width, height, (rand() % 3), 20);

        width = 1920; height = 1200;
        srand(time(0));
        QuestType1 q19(width, height, (rand() % 3), 20);

        width = 2048; height = 1080;
            srand(time(0));
        QuestType1 q20(width, height, (rand() % 3), 20);*/

        //QuestType1 q1(width, height, 1 - (rand() % 2), 0, 1, 17);
        //QuestType1 q2(width, height, 1 - (rand() % 3), 2, 3, 17);
      //  int width = 640; int height = 360;
        //int o;
        //while ((o = rand() % 3 )>= 0) std::cout << o << std::endl;
        
        



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

