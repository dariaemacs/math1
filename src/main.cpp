#include "game.hpp" 
#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <fstream>
using namespace sf; // подключаем пространство имен sf

int main(){
    std::string filename{ "settings.yml" };
    try {




       //int width = sf::VideoMode::getDesktopMode().width;int height = sf::VideoMode::getDesktopMode().height;

        //int width   = 640;int height = 360;
        //int width = 854;int height = 480;
        //int width = 1280;int height = 720;
       // int width = 1600;int height = 900;
       //int width = 1920;int height = 1080;
        //int width = 2048;int height = 1152;
        //int width = 2560;int height =1440;
      // int width = 1440;int height = 900;
      int width = 1536; int height = 960;
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

//#include <SFML/Graphics.hpp>
//
//using namespace sf;
//
//
//sf::RenderTexture renderTexture;
//const sf::Texture& texture1 = renderTexture.getTexture();
//
//int main()
//{
//    int angle = 700;
//    RenderWindow window(VideoMode(1500, 1000), "SFML Works!");
//
//
//    while (window.isOpen())
//    {
//
//        Event event;
//        while (window.pollEvent(event))
//        {
//
//            if (event.type == Event::Closed)
//
//                window.close();
//            if (event.type == Event::MouseButtonPressed) angle++;
//        }
//
//        window.clear(Color::White);
//
//
//        Texture texture;
//
//        sf::RenderTexture renderTexture;
//        const sf::Texture& texture1 = renderTexture.getTexture();
//        if (!renderTexture.create(100, 100))
//        {
//
//        }
//       
//
//
//        sf::CircleShape square0(20);
//        square0.setFillColor(Color::Blue);
//        square0.move(20, 15);
//
//
//        CircleShape square1(60.f, 4);
//        square1.setPosition(5, 0);
//        square1.setFillColor(Color::Red);
//
//        CircleShape square2(30.f, 4);
//        square2.setPosition(5, 0);
//        square2.setFillColor(Color::Green);
//
//
//
//        //renderTexture.clear(Color::Black);
//        renderTexture.draw(square1);
//        renderTexture.draw(square2);
//
//        renderTexture.display();
//        
//        sf::Sprite sprite(texture1);
//        sprite.move(20, 20);
//        sprite.rotate(angle);
//
//
//        window.draw(sprite);
//        window.draw(square0);
//
//        window.display();
//
//    }
//
//    return 0;
//}
//
//  
