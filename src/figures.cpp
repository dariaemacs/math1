#include "figures.hpp"




//Flower::Flower() {
//    circle1.set_radius(30);
//    circle2.set_radius(30);
//    circle3.set_radius(30);
//    circle4.set_radius(30);
//
//    center_circle.set_radius(45);
//
//    circle1.set_coords(142, 125);
//    circle2.set_coords(24, 24);
//    circle3.set_coords(144, 22);
//    circle4.set_coords(28, 125);
//
//    center_circle.set_coords(70, 57);
//
//    circle1.set_color(color::aqua);
//    circle2.set_color(color::red);
//    circle3.set_color(color::blue);
//    circle4.set_color(color::green);
//
//    center_circle.set_color(color::coral);
//    int step = 25;
//    int step2 = 15;
//    triangle1.set_coords(0.0f + step, 230.0f, 80.0f + step, 230.0f, 40.0f + step, 260.0f);
//    triangle1.set_color(color::lime);
//
//    triangle2.set_coords(140.0f - step2, 230.0f, 220.0f - step2, 230.0f, 180.0f - step2, 260.0f);
//    triangle2.set_color(color::lime);
//
//    rectangle.set_coords(110, 149);
//    rectangle.set_color(color::lightskyblue);
//    rectangle.set_size(10, 180);
//}

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
    circle1.set_radius(35);
    circle2.set_radius(35);
    circle3.set_radius(15);
    circle4.set_radius(15);

    circle1.set_color(color::aqua);
    circle2.set_color(color::aqua);
    
    circle1.set_coords(190, 145);
    circle2.set_coords(20, 145);
    circle3.set_coords(210, 165);
    circle4.set_coords(39, 165);
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
