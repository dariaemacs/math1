#ifndef FIGURES_HPP
#define FIGURES_HPP

#include "window.hpp"
#include "color.hpp"

#include <memory>
const float koeff = 0.5;


//struct Rotation {
//    const float PI = 3.14159265;
//    float cosGradus(double alpha)
//    {
//        return cos(alpha * PI / 180);
//    }
//    float sinGradus(double alpha)
//    {
//        return sin(alpha * PI / 180);
//    }
//};
struct FrameFigure {
    int xmin;
    int xmax;

    int ymin;
    int ymax;


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

  sf::CircleShape getCircle() { return *circle; }

  void set_color(sf::Color c){
    circle->setFillColor(c);
  }

  void set_coords(float x, float y){
    circle->setPosition(x* koeff, y* koeff);
  }

  void settings(){
    circle->setOutlineThickness(1);
    circle->setOutlineColor(color::black);
  }
  void rotate(float angle) {
      circle->rotate(angle);
  }
  void set_radius(float r) {
    circle->setRadius(r* koeff);
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
  sf::ConvexShape getTriangle() { return *triangle; }

  void set_color(sf::Color c){
    triangle->setFillColor(c);
  }

  void rotate(float angle ) {
      triangle->rotate(angle);
  }

  void set_coords(float x0, float y0, float x1, float y1, float x2, float y2){
    triangle->setPoint(0, sf::Vector2f(x0* koeff, y0* koeff));
    triangle->setPoint(1, sf::Vector2f(x1* koeff, y1* koeff));
    triangle->setPoint(2, sf::Vector2f(x2* koeff, y2* koeff));
  }

  void settings(){
    triangle->setOutlineThickness(2);
    triangle->setOutlineColor(color::black);
  }

private:
  std::unique_ptr<sf::ConvexShape> triangle;
};


class Rectangle  {
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

  sf::RectangleShape getRectangle() { return *rectangle; }




  void set_color(sf::Color c){
    rectangle->setFillColor(c);
  }

  void set_coords(float x0, float y0){
      x = x0 ;
      y = y0 ;
    rectangle->setPosition(x* koeff, y* koeff);
  }

  void set_size(float width, float height){
      w = width;
      h = height;
    rectangle->setSize(sf::Vector2f(width* koeff, height* koeff));
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


class Plane : private FrameFigure
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

class Tower:private FrameFigure
{
private:
    Triangle triangle1;
    Triangle triangle2;
    Triangle triangle3;

    Rectangle rectangle1;
    Rectangle rectangle2;
    Rectangle rectangle3;

    Circle circle1;
    int maxX;//координаты спрайта
    int maxY;

public:
    Tower();
    ~Tower() {}
    void draw(std::shared_ptr<sf::RenderWindow>& window);
};

class Butterfly :private FrameFigure
{
private:
    Triangle triangle1;
    Triangle triangle2;
    Triangle triangle3;
    Triangle triangle4;
    Triangle triangle5;
    Rectangle rectangle1;
    Rectangle rectangle2;
    Rectangle rectangle3;
    Rectangle rectangle4;
    Rectangle rectangle5;
    sf::Texture T;

    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    Circle circle5;


    sf::Texture texture;
    sf::RenderTexture renderTexture;
    const sf::Texture& texture1 = renderTexture.getTexture();
    sf::Sprite sprite;
    int widthScreen;
    int heightScreen;

    int widthSprite ; 
    int heightSprite;
    int  moveSpriteX;
    int  moveSpriteY;
    float  Xfactor; //
    float  Yfactor;


public:
    Butterfly();
    ~Butterfly() {}
    void draw(std::shared_ptr<sf::RenderWindow>& window);
};


class Car :private FrameFigure
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


class Tree :private FrameFigure {
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

class Flower :private FrameFigure {
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
