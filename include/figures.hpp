#ifndef FIGURES_HPP
#define FIGURES_HPP

#include "window.hpp"
#include "color.hpp"

#include <memory>


struct Rotation {
    const float PI = 3.14159265;
    float cosGradus(double alpha)
    {
        return cos(alpha * PI / 180);
    }
    float sinGradus(double alpha)
    {
        return sin(alpha * PI / 180);
    }
};


class Circle{
public:
  Circle()
    : circle{std::make_unique<sf::CircleShape>()}
  {
    settings();
  }
  
  ~Circle(){}

  void draw(std::shared_ptr<sf::RenderWindow>& window){
    window->draw(*circle);
  }

  void set_color(sf::Color c){
    circle->setFillColor(c);
  }

  void set_coords(float x, float y){
    circle->setPosition(x+25, y+150);
  }

  void settings(){
    circle->setOutlineThickness(2);
    circle->setOutlineColor(color::black);
  }
  void rotate(float angle) {
      circle->rotate(angle);
  }
  void set_radius(float r) {
    circle->setRadius(r);
  }

private:
  std::unique_ptr<sf::CircleShape> circle;
};

class Triangle{
public:
  Triangle()
    : triangle{std::make_unique<sf::ConvexShape>(3)}
  {
    settings();
  }
  
  ~Triangle(){}

  void draw(std::shared_ptr<sf::RenderWindow>& window){
    window->draw(*triangle);
  }

  void set_color(sf::Color c){
    triangle->setFillColor(c);
  }

  void rotate(float angle ) {
      triangle->rotate(angle);
  }

  void set_coords(float x0, float y0, float x1, float y1, float x2, float y2){
    triangle->setPoint(0, sf::Vector2f(x0+25, y0+150));
    triangle->setPoint(1, sf::Vector2f(x1+25, y1+150));
    triangle->setPoint(2, sf::Vector2f(x2+25, y2+150));
  }

  void settings(){
    triangle->setOutlineThickness(2);
    triangle->setOutlineColor(color::black);
  }

private:
  std::unique_ptr<sf::ConvexShape> triangle;
};


class Rectangle : private Rotation {
    public:
  Rectangle()
    : rectangle{std::make_unique<sf::RectangleShape>()}
  {
    settings();
  }
  
  ~Rectangle(){}

  void draw(std::shared_ptr<sf::RenderWindow>& window){
    window->draw(*rectangle);
  }

  void rotateCoord(int& x, int& y, int angle) {
      int xCenter = 0;
      int yCenter = 0;
      //        result.x = (x - x0) * cosGradus(angle) - (y - y0) * sinGradus(angle) + x0;
      //        result.y = (x - x0) * sinGradus(angle) + (y - y0) * cosGradus(angle) + y0;


      int Newx = ((x- xCenter) * cosGradus(angle) - (y-yCenter ) * sinGradus(angle))-x;
      int Newy = ((x - xCenter) * sinGradus(angle) + (y-yCenter) * cosGradus(angle)) - y;


   x = Newx;
     y = Newy;
  }

  void rotate(float angle) {
      this->angle = angle;
      rectangle->rotate(angle);
      rotateCoord(x, y, angle);
      set_coords(x, y);
      
    }


  void set_color(sf::Color c){
    rectangle->setFillColor(c);
  }

  void set_coords(float x0, float y0){
      x = x0 + 25;
      y = y0 + 150;
    rectangle->setPosition(x+25, y+150);
  }

  void set_size(float width, float height){
      w = width;
      h = height;
    rectangle->setSize(sf::Vector2f(width, height));
  }
  
  void settings(){
    rectangle->setOutlineThickness(2);
    rectangle->setOutlineColor(color::black);
  }

private:
    int x;
    int y;
    float angle;
    int w;
    int h;

  std::unique_ptr<sf::RectangleShape> rectangle;
};


class Plane 
{
public:
    Plane();
    ~Plane() {}
    void draw(std::shared_ptr<sf::RenderWindow>& window);

private:
    Circle circle1;
    Circle circle2;
    Circle circle3;


    Triangle triangle1;
    Triangle triangle2;
    Triangle triangle3;
    Triangle triangle4;

    Rectangle rectangle1;
    Rectangle rectangle2;
    Rectangle rectangle3;
};

class Tower
{
private:
    Triangle triangle1;
    Triangle triangle2;
    Triangle triangle3;

    Rectangle rectangle1;
    Rectangle rectangle2;
    Rectangle rectangle3;

    Circle circle1;

public:
    Tower();
    ~Tower() {}
    void draw(std::shared_ptr<sf::RenderWindow>& window);
};

class Butterfly
{
private:
    Triangle triangle1;
    Triangle triangle2;
    Triangle triangle3;

    Rectangle rectangle1;
    Rectangle rectangle2;
    Rectangle rectangle3;
    Rectangle rectangle4;
    Rectangle rectangle5;
    sf::Texture T;

    Circle circle1;
    Circle circle2;
    Circle circle3;

public:
    Butterfly();
    ~Butterfly() {}
    void draw(std::shared_ptr<sf::RenderWindow>& window);
};


class Car
{
public:
    Car();
    ~Car() {}
    void draw(std::shared_ptr<sf::RenderWindow>& window);

private:
    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    Circle circle5;
    Triangle triangle1;
    Triangle triangle2;
    Rectangle rectangle1;
    Rectangle rectangle2;
    Rectangle rectangle3;
};


class Tree {
public:
    Tree();
    ~Tree() {}
    void draw(std::shared_ptr<sf::RenderWindow>& window);

private:
    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    Circle center_circle;

    Triangle triangle1;
    Triangle triangle2;
    Triangle triangle3;

    Rectangle rectangle;
};

class Flower{
public:
  Flower();
  ~Flower(){}

  void draw(std::shared_ptr<sf::RenderWindow>& window);

private:
  Circle circle1;
  Circle circle2;
  Circle circle3;
  Circle circle4;
  Circle center_circle;

  Triangle triangle1;
  Triangle triangle2;
  Triangle triangle3;
  Rectangle rectangle;
};



#endif // FIGURES_HPP
