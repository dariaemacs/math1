#include "game.hpp" 
#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>
using namespace sf; // подключаем пространство имен sf

int main(){
    std::string filename{ "settings.yml" };
    try {
        //    YAML::Node config = YAML::LoadFile(filename);


        int width = 1000;// sf::VideoMode::getDesktopMode().width;
        int height = 800;//sf::VideoMode::getDesktopMode().height;
        srand(time(0));
        QuestType1 q(width, height, 1 - (rand() % 2), tree, tree, 17);

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

    /*
  std::string filename {"settings.yml"};
  try{
    //    YAML::Node config = YAML::LoadFile(filename);


    int width = 1000;// sf::VideoMode::getDesktopMode().width;
    int height = 800;//sf::VideoMode::getDesktopMode().height;
    srand(time(0));
    QuestType1 q(width, height, 1-(rand() % 2), tree, tree, 17);

    // Game game(config);
    // game.run();
    // }catch(const YAML::Exception& exc){
   // std::cerr << "EXCEPTION [" << exc.msg << "]" << std::endl;
  }catch(const std::exception& exc){
    std::cerr << "EXCEPTION [" << exc.what() << "]" << std::endl;
  }
  */

  
