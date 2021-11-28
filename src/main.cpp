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





        float width = 1024; float height = 600;

        srand(static_cast<unsigned int>(time(NULL)));
 
    width = 1024.0f;  height = 600.0f;   
    QuestType7(width, height);
    QuestType7(width, height);
    QuestType7(width, height);
    QuestType7(width, height);
    QuestType7(width, height);
    QuestType7(width, height);

     QuestType1(width, height,25);
    width = 1200.0f; height = 600.0f;
     QuestType2(width, height,25);
    width = 1280.0f; height = 720.0f;
    QuestType3(width, height, 25);
    width = 1280.0f; height = 768.0f;
    QuestType4(width, height, 25);
    width = 1280.0f; height = 1024.0f;
    QuestType5(width, height, 25);
    width = 1408.0f; height = 1152.0f;
    QuestType6(width, height, 25);
    width = 1440.0f; height = 900.0f;
     QuestType7(width, height);
    width = 1400.0f; height = 1050.0f;
    QuestType8(width, height);
    width = 1440.0f; height = 1080.0f;
    QuestType9(width, height, 25);
    width = 1536.0f; height = 960.0f;
    QuestType10(width, height);
    width = 1536.0f; height = 1024.0f;
    QuestType11(width, height);
    width = 1600.0f; height = 900.0f;
    QuestType12(width, height, 25);
    width = 1600.0f; height = 1024.0f;
     QuestType13(width, height);
    width = 1600.0f; height = 1200.0f;
     QuestType14(width, height,25);
    width = 1680.0f; height = 1050.0f;
     QuestType15(width, height,25);
    width = 1920.0f; height = 1080.0f;
     QuestType16(width, height,25);
/*    width = 1920.0f; height = 1200.0f;;
     QuestType15(width, height,25);
    width = 2048; height = 1080;
    QuestType15(width, height,25);
    */
    
    



     
    }
    catch (const std::exception& exc) {
        std::cerr << "EXCEPTION [" << exc.what() << "]" << std::endl;
    }

    return 0;
}



