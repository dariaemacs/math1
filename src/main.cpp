#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>
#include "infoWin.hpp"
#include "QuestType1.hpp"
#include "QuestType2.hpp"
#include "QuestType3.hpp"
#include "QuestType4.hpp"
#include "QuestType5.hpp"
#include "QuestType6.hpp"
#include "QuestType7.hpp"
#include "QuestType8.hpp"
#include "QuestType9.hpp"
#include "QuestType10.hpp"
#include "QuestType11.hpp"
#include "QuestType12.hpp"
#include "QuestType13.hpp"
#include "QuestType14.hpp"
#include "QuestType15.hpp"
#include "QuestType16.hpp"
#include "endGame.hpp"


//#include "gameClass.hpp"



int main() {
    
    std::string filename{ "settings.yml" };
    try {
    srand(static_cast<unsigned int>(time(NULL)));
    
    gameClass::setwinParams(1024.0f, 600.0f);
    endGame();
    infoWin();
    gameClass::clockRestart();
    gameClass::get_time();
    
   QuestType1(25);
   QuestType2(25);  
    QuestType3(25);    
  
    QuestType4(25);    
    QuestType5(25);
 
    QuestType6(25);    
     QuestType7();    
    QuestType8();    
    QuestType9(25);    
    QuestType10();    
    QuestType11();    
    QuestType12(25);    
     QuestType13();    
     QuestType14(25);    
     QuestType15(25);     
     QuestType16(25);
   
     /*QuestType16(width, height, 25);
     QuestType16(width, height, 25);
     QuestType16(width, height, 25);
     QuestType16(width, height, 25);
     QuestType16(width, height, 25);*/

 
     }
    catch (const std::exception& exc) {
        std::cerr << "EXCEPTION [" << exc.what() << "]" << std::endl;
    }
    return 0;
}



