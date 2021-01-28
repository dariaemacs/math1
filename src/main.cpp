#include "window.hpp"
#include "database.hpp"

#include <iostream>
#include <sstream>
#include <locale>





int main(int , char* []) {
    int width = 1000;// sf::VideoMode::getDesktopMode().width;
    int height = 800;//sf::VideoMode::getDesktopMode().height;


    srand(time(0));

    QuestType1 q(width, height, 1-(rand() % 2), flower, tree, 17);

        
    
}

