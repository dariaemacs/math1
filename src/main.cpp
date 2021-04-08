#include "game.hpp" 
#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>
using namespace sf; // подключаем пространство имен sf

int main(){
    std::string filename{ "settings.yml" };
    try {




       int width = sf::VideoMode::getDesktopMode().width;int height = sf::VideoMode::getDesktopMode().height;

        //int width   = 640;int height = 360;
        //int width = 854;int height = 480;
        //int width = 1280;int height = 720;
       // int width = 1600;int height = 900;
       //int width = 1920;int height = 1080;
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

