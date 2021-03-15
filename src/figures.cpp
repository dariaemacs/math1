#include "figures.hpp"

Flower::Flower(){
  circle1.set_radius(30);
  circle2.set_radius(30);
  circle3.set_radius(30);
  circle4.set_radius(30);
  
  center_circle.set_radius(45);
  
  circle1.set_coords(148, 125);
  circle2.set_coords(21, 20);
  circle3.set_coords(148, 20);
  circle4.set_coords(18, 125);
  
  center_circle.set_coords(70,57);
  
  circle1.set_color(color::aqua);
  circle2.set_color(color::red);
  circle3.set_color(color::blue);    
  circle4.set_color(color::green);
  
  center_circle.set_color(color::coral);
  
  triangle1.set_coords(0.0f, 230.0f, 80.0f, 230.0f, 40.0f,260.0f);
  triangle1.set_color(color::lime);
  
  triangle2.set_coords(140.0f,230.0f,220.0f,230.0f,180.0f,260.0f);
  triangle2.set_color(color::lime);
  
  rectangle.set_coords(105, 160);
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
    int h = 40;
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
