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


        int width = sf::VideoMode::getDesktopMode().width;
        int height = sf::VideoMode::getDesktopMode().height;
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
