#ifndef FIGURES_HPP
#define FIGURES_HPP

#include "window.hpp"
#include "color.hpp"

#include <memory>
//const float koeff = 1;



class FrameFigure {
protected:
    static int width_last_figure  ;
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    float koef=1;
    std::shared_ptr<sf::RenderWindow>& window;
    int margin_left;
    int margin_top = 0;


public:
    //FrameFigure() {}
    FrameFigure(std::shared_ptr<sf::RenderWindow>& w) : window(w) { 
        //number_of_figure_on_screen = number_of_figure_on_screen==0?1:6;
    
    }
    void calcKoeff();
    float getkoef() { return koef; }
    int getxmin() { return xmin; }
    int getxmax() { return xmax; }
    int getymin() { return ymin; }
    int getymax() { return ymax; }
    int getmargin_top() { 
        return margin_top; 
    }
    int getmargin_left() { return margin_left; }

 

};




class Circle{
public:
  Circle(FrameFigure* owner ): owner(owner)
    , circle{std::make_unique<sf::CircleShape>()}
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
    circle->setPosition((x* owner->getkoef()-(owner->getxmin()   *owner->getkoef()))+ owner->getmargin_left(), (y* owner->getkoef()-(owner->getymin() * owner->getkoef())) + owner->getmargin_top());
  }

  void settings(){
    circle->setOutlineThickness(1);
    circle->setOutlineColor(color::black);
  }
  void rotate(float angle) {
      circle->rotate(angle);
  }
  void set_radius(float r) {
    circle->setRadius(r* owner->getkoef());
  }

private:
    FrameFigure* owner;
  std::unique_ptr<sf::CircleShape> circle;
};

class Triangle{
public:
  Triangle(FrameFigure* owner): owner(owner),
    triangle{std::make_unique<sf::ConvexShape>(3)}
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
    triangle->setPoint(0, sf::Vector2f((x0* owner->getkoef() - (owner->getxmin() * owner->getkoef())) + owner->getmargin_left(),(y0* owner->getkoef() - (owner->getymin() * owner->getkoef()))+ owner->getmargin_top()));
    triangle->setPoint(1, sf::Vector2f((x1* owner->getkoef() - (owner->getxmin() * owner->getkoef())) + owner->getmargin_left(),(y1* owner->getkoef() - (owner->getymin() * owner->getkoef()))+ owner->getmargin_top()));
    triangle->setPoint(2, sf::Vector2f((x2* owner->getkoef() - (owner->getxmin() * owner->getkoef())) + owner->getmargin_left(),(y2* owner->getkoef() - (owner->getymin() * owner->getkoef()))+ owner->getmargin_top()));
  }

  void settings(){
    triangle->setOutlineThickness(2);
    triangle->setOutlineColor(color::black);
  }

private:
   FrameFigure* owner;

  std::unique_ptr<sf::ConvexShape> triangle;
};


class Rectangle  {
    public:
  Rectangle(FrameFigure* owner)
    :owner(owner), rectangle{std::make_unique<sf::RectangleShape>()}
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
    rectangle->setPosition((x* owner->getkoef() - (owner->getxmin() * owner->getkoef()))+ owner->getmargin_left(), (y* owner->getkoef() - (owner->getymin() * owner->getkoef())) + owner->getmargin_top());
  }

  void set_size(float width, float height){
      w = width;
      h = height;
    rectangle->setSize(sf::Vector2f(width* owner->getkoef(), height* owner->getkoef()));
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
    FrameFigure* owner;
  std::unique_ptr<sf::RectangleShape> rectangle;
};

/**/
class Plane : public FrameFigure
{
public:
    Plane(std::shared_ptr<sf::RenderWindow>& window);
    ~Plane() {}
    void draw();

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

class Tower:public FrameFigure
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
    Tower(std::shared_ptr<sf::RenderWindow>& window);
    ~Tower() {}
    void draw();
};

class Butterfly :public FrameFigure
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
    Butterfly(std::shared_ptr<sf::RenderWindow>& window);
    ~Butterfly() {}
    void draw();
};


class Car :public FrameFigure
{
public:
    Car(std::shared_ptr<sf::RenderWindow>& window);
    ~Car() {}
    void draw();

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


class Tree :public FrameFigure {
public:
    Tree(std::shared_ptr<sf::RenderWindow>& window);
    ~Tree() {}
    void draw();

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

class Flower :public FrameFigure {
public:
    Flower(std::shared_ptr<sf::RenderWindow>&   );
  ~Flower(){}

  void draw();

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
