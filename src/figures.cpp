#include "figures.hpp"

#include <ctime>

#define PI 3.14159265
std::vector<const sf::Color*> wheels = { &color::aliceblue, &color::skyblue, &color::salmon };

std::vector<const sf::Color*> roof = { &color::red, &color::purple, &color::salmon };


//#define koeff 0.5





void Car::draw(std::shared_ptr<sf::RenderWindow>& window) {
    rectangle1.draw(window);
    rectangle2.draw(window);
    rectangle3.draw(window);
    circle1.draw(window);
    circle2.draw(window);
    circle3.draw(window);
    circle4.draw(window);
    circle5.draw(window);
    triangle1.draw(window);
    triangle2.draw(window);

}

Car::Car() {
    srand((unsigned int)time(NULL));
    static int indexColor1 = rand() % wheels.size();
    static int indexColor2 = rand() % wheels.size();
    circle1.set_radius(35);
    circle2.set_radius(35);
    circle3.set_radius(15);
    circle4.set_radius(15);

    //int colorwheelsSize = sizeof(wheels) / sizeof(wheels*);

   
    circle1.set_color(*wheels[indexColor1]);
    circle2.set_color(*wheels[indexColor1]);
    

    srand((unsigned int)time(NULL));
    
    circle3.set_color(*wheels[indexColor2]);
    circle4.set_color(*wheels[indexColor2]);

    circle1.set_coords(190, 142);
    circle2.set_coords(20, 142);
    circle3.set_coords(210, 162);
    circle4.set_coords(39, 162);
    circle5.set_coords(162, 60);
    rectangle1.set_coords(70, 41);
    rectangle1.set_size(120, 60);
    circle5.set_radius(13);
    rectangle2.set_coords(10, 91);
    rectangle2.set_size(250, 50);
    triangle1.set_coords(10, 91, 40, 91, 10, 121);
    triangle2.set_coords(260, 91, 260, 121, 230, 91);
    rectangle3.set_coords(160, 59);
    rectangle3.set_size(30, 30);





}

void Plane::draw(std::shared_ptr<sf::RenderWindow>& window) {
    triangle1.draw(window);
    triangle2.draw(window);
    triangle3.draw(window);
    triangle4.draw(window);
    rectangle1.draw(window);
    rectangle2.draw(window);
    rectangle3.draw(window);
    circle1.draw(window);
    circle2.draw(window);
    circle3.draw(window);

}
 Plane::Plane() {
     circle1.set_radius(15);
     circle2.set_radius(15);
     circle3.set_radius(15);

     circle1.set_color(color::aqua);
     circle2.set_color(color::aqua);
     circle3.set_color(color::aqua);

     circle1.set_coords(155, 145);
     circle2.set_coords(115, 145);
     circle3.set_coords(75, 145);

     


      triangle1.set_coords(241, 80, 273, 80, 258, 146);
      triangle2.set_coords(241, 230, 273, 230, 258, 164.0f);
      triangle3.set_coords(253 , 155.0f, 195, 130, 195, 194.0f);
      triangle4.set_coords(0, 90, 58, 90, 58,195);

     rectangle1.set_coords(60, 129);
     rectangle1.set_color(color::lightskyblue);
     rectangle1.set_size(132, 65);

     rectangle2.set_coords(145, 0);
     rectangle2.set_size(20, 126);
     rectangle3.set_coords(145, 197);
     rectangle3.set_size(20, 126);


}

Flower::Flower(){
  circle1.set_radius(30);
  circle2.set_radius(30);
  circle3.set_radius(30);
  circle4.set_radius(30);
  
  center_circle.set_radius(45);
  
  circle1.set_coords(142, 125);
  circle2.set_coords(24, 24);
  circle3.set_coords(144, 22);
  circle4.set_coords(28, 125);
  
  center_circle.set_coords(70,57);
  
  circle1.set_color(color::aqua);
  circle2.set_color(color::red);
  circle3.set_color(color::blue);    
  circle4.set_color(color::green);
  
  center_circle.set_color(color::coral);
  int step = 25;
  int step2 = 15;
  triangle1.set_coords(25, 230.0f, 105, 230.0f, 65,260.0f);
  triangle1.set_color(color::lime);
  
  triangle2.set_coords(125,230.0f,205,230.0f,165,260.0f);
  triangle2.set_color(color::lime);
  
  rectangle.set_coords(110, 149);
  rectangle.set_color(color::lightskyblue);
  rectangle.set_size(10, 180);
}

void Flower::draw(std::shared_ptr<sf::RenderWindow>& window) {
  circle1.draw(window);
  circle2.draw(window);
  circle3.draw(window);
  circle4.draw(window);
  
  center_circle.draw(window);
  
  triangle1.draw(window);
  triangle2.draw(window);
  
  rectangle.draw(window);
}

Tower::Tower() {
    static int indexColor = rand() % roof.size();
    triangle1.set_coords(17,88,62,42,113 ,88);
    int x = 14;
    triangle2.set_coords(112+x, 88, 157+x, 42, 208+x, 88);
    x = 124;
    triangle3.set_coords(112 + x, 88, 157 + x, 42, 208 + x, 88);

    circle1.set_coords(145, 110);
    circle1.set_radius(30);

    rectangle1.set_coords(20, 90);
    rectangle1.set_size(90, 110);
    rectangle1.set_color(color::lightskyblue);

    rectangle2.set_coords(130, 90);
    rectangle2.set_size(90, 110);
    rectangle2.set_color(color::lightskyblue);

    rectangle3.set_coords(240, 90);
    rectangle3.set_size(90, 110);
    rectangle3.set_color(color::lightskyblue);
    srand((unsigned int)time(NULL));
    triangle1.set_color(*wheels[indexColor]);
    triangle2.set_color(*wheels[indexColor]);
    triangle3.set_color(*wheels[indexColor]);

};
void Tower::draw(std::shared_ptr<sf::RenderWindow>& window) {
    triangle1.draw(window);
    triangle2.draw(window);
    triangle3.draw(window);

     rectangle1.draw(window);
     rectangle2.draw(window);
     rectangle3.draw(window);

    circle1.draw(window);
    
    
}


Tree::Tree() {
    circle1.set_radius(15);
    circle2.set_radius(15);
    circle3.set_radius(15);
    circle4.set_radius(15);

    center_circle.set_radius(15);

    circle1.set_coords(46, 142);
    circle2.set_coords(285, 142);
    circle3.set_coords(325, 197);
    circle4.set_coords(3, 197);
    //int h = 40;
    center_circle.set_coords(170, 0);

    circle1.set_color(color::aqua);
    circle2.set_color(color::red);
    circle3.set_color(color::blue);
    circle4.set_color(color::green);

    center_circle.set_color(color::red);
    
    triangle1.set_coords(185, 33.0f, 260, 83.0f, 102, 83.0f);
    triangle1.set_color(color::lime);

    triangle2.set_coords(185, 88.0f, 295, 138, 67, 138);
    triangle2.set_color(color::lime);

    triangle3.set_coords(185, 143, 335, 193, 27, 193);
    triangle3.set_color(color::lime);

    rectangle.set_coords(178, 195);
    rectangle.set_color(color::lightskyblue);
    rectangle.set_size(10, 60);
}

void Tree::draw(std::shared_ptr<sf::RenderWindow>& window) {
    circle1.draw(window);
    circle2.draw(window);
    circle3.draw(window);
    circle4.draw(window);

    center_circle.draw(window);

    triangle1.draw(window);
    triangle2.draw(window);
    triangle3.draw(window);

    rectangle.draw(window);
}



Butterfly::Butterfly() {
    xmin = 8;
    xmax = 416;
    ymin = 2;
    ymax = 303;
    //int  widthFigure = xmax - xmin;
    //int  heightFigure = ymax - ymin;


                
    rectangle1.set_coords(192, 137);
    
    rectangle1.set_color(color::lightskyblue);
    rectangle1.set_size(40, 150);
    rectangle2.set_coords(202, 177);
    rectangle2.set_color(color::lightskyblue);
    rectangle2.set_size(20, 15);
    rectangle3.set_coords(202, 207);
    rectangle3.set_color(color::lightskyblue);
    rectangle3.set_size(20, 15);
    rectangle4.set_coords(202, 237);
    rectangle4.set_color(color::lightskyblue);
    rectangle4.set_size(20, 15);
    rectangle5.set_coords(202, 288);
    rectangle5.set_color(color::green);
    rectangle5.set_size(20, 15);


    heightSprite = 309;

    triangle1.set_coords(8, 2, 192, 177,  12,132);

    
    widthSprite = 426;
    triangle2.set_coords(416,  2 , 234, 177, 395, 132);


    triangle4.set_coords(391, 152, 234, 180, 411, 292);
   triangle5.set_coords(36, 152, 191, 180, 16, 292);

    circle1.set_coords(184, 80);
    circle1.set_radius(28);


    circle2.set_coords(76, 177 );
    circle2.set_radius(22);

    circle3.set_coords(311, 177 );
    circle3.set_radius(22);

    circle4.set_coords( 31, 87);
    circle4.set_radius(22);

    circle5.set_coords(341, 87);
    circle5.set_radius(22);

    triangle3.set_coords(196, 58, 226, 58 ,211,79 );





   

}

void Butterfly::draw(std::shared_ptr<sf::RenderWindow>& window) {

    circle1.draw(window);


   triangle4.draw(window);
   triangle5.draw(window);
   rectangle1.draw(window);
   rectangle2.draw(window);
   rectangle3.draw(window);
   rectangle4.draw(window);
   rectangle5.draw(window);
   triangle1.draw(window);
   triangle2.draw(window);
   triangle3.draw(window);
   circle1.draw(window);
   circle2.draw(window);
   circle3.draw(window);
   circle4.draw(window);
   circle5.draw(window);


    
   // window->draw(sprite);
}
