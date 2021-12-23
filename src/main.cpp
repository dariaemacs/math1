#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>

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


//#include "gameClass.hpp"



int main() {
    gameClass::get_time();
    std::string filename{ "settings.yml" };
    try {
    srand(static_cast<unsigned int>(time(NULL)));
    float width = 1024.0f;  float  height = 600.0f;

     QuestType1(width, height,25);     
  
     QuestType2(width, height,25);
  
    QuestType3(width, height, 25);    
  
    QuestType4(width, height, 25);    
    QuestType5(width, height, 25);
 
    QuestType6(width, height, 25);    
     QuestType7(width, height);    
    QuestType8(width, height);    
    QuestType9(width, height, 25);    
    QuestType10(width, height);    
    QuestType11(width, height);    
    QuestType12(width, height, 25);    
     QuestType13(width, height);    
     QuestType14(width, height,25);    
     QuestType15(width, height,25);     
     QuestType16(width, height,25);
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



