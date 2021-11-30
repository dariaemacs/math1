#ifndef FIGURES_HPP
#define FIGURES_HPP

#include "window.hpp"
#include "color.hpp"

#include <memory>
//const float koeff = 1;



    class FrameFigure {
    protected:
        static char number_of_figure;      //0,1
    
        float xmin;
        float xmax;
        float ymin;
        float ymax;
        float koef=1;
        std::shared_ptr<sf::RenderWindow>& window;
        int margin_left;
        int margin_top = 0;
        bool alreadyDraw = false;
        int circleQTY;
        int triangleQTY;
        int rectengleQTY;
        bool checkMode;
        int figuraCode; //
        sf::Clock clock; 
        int QTYofBLINK; //
        bool isNextQuest;

    public:
        //FrameFigure() {}
        FrameFigure(std::shared_ptr<sf::RenderWindow>& w, int c,int t, int r) : window(w), alreadyDraw(false),
            circleQTY(c),
            triangleQTY(t),
            rectengleQTY(r),
            checkMode(false), figuraCode(-100),
            QTYofBLINK(0),
            isNextQuest(false)
        {
      
    
        }
        static void resetnumber_of_figure() { number_of_figure = 0; }
        void calcKoeff();
        void circleQTYinc() { circleQTY++; }
        void triangleQTYinc() { triangleQTY++; }
        void rectengleQTYinc() { rectengleQTY++; }
        void setcheckMode() { checkMode=true; }
        void setfiguraCode(int fc) { figuraCode=fc; }
        float getkoef() { 
            return koef; 
        }

        int getrectengleQTY() { return rectengleQTY; }
        int gettriangleQTY()  { return triangleQTY; }
        int getcircleQTY()       { return circleQTY; }

        float getxmin() { 
            return xmin; 
        }
        float getxmax() { 
            return xmax; 
        }
        float getymin() { 
            return ymin; 
        }
       float getymax() { 
            return ymax; 
        }
        int getmargin_top() { 
            return margin_top; 
        }
        //int getheght() { return ymax - ymin; }
        int getmargin_left() { return margin_left; }
        bool GetisNextQuest() {return isNextQuest;}
        virtual void draw() {}
        ~FrameFigure() {
            
            //int k = 190 + 10;
        }
    };




class Circle{
public:
    static int getcircleQTY() { return QTY; }
  Circle(FrameFigure* owner ): owner(owner)
    , circle{std::make_unique<sf::CircleShape>()}
  {
      owner->circleQTYinc();
    settings();
    
  }
  
  ~Circle(){}

  void draw(std::shared_ptr<sf::RenderWindow>& window){
      
    window->draw(*circle);
  }

  sf::CircleShape getCircle() { 
      return *circle; 
  
  }

  void set_color(sf::Color c){
    circle->setFillColor(c);
  }

  void set_coords(float x, float y){
      int ggg = owner->getmargin_left();
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
    static int QTY;
    FrameFigure* owner;
  std::unique_ptr<sf::CircleShape> circle;
};

class Triangle{
public:
  Triangle(FrameFigure* owner): owner(owner),
    triangle{std::make_unique<sf::ConvexShape>(3)}
  {
      owner->triangleQTYinc();
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
      
      owner->rectengleQTYinc();
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
      x = static_cast<int>(x0) ;
      y = static_cast<int>(y0 );
    rectangle->setPosition((x* owner->getkoef() - (owner->getxmin() * owner->getkoef()))+ owner->getmargin_left(), (y* owner->getkoef() - (owner->getymin() * owner->getkoef())) + owner->getmargin_top());
  }

  void set_size(float width, float height) {
      w = static_cast<int>(width);
      h = static_cast<int>(height);
      rectangle->setSize(sf::Vector2f(width * owner->getkoef(), height * owner->getkoef()));
  };
  
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
    virtual void draw();

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

class ThreePicture0 :public FrameFigure {
    Circle circle1;
    Triangle triangle1;
    Rectangle rectangle1;
    int maxX;//координаты спрайта
    int maxY;
    public:
    ThreePicture0(std::shared_ptr<sf::RenderWindow>& );
    ~ThreePicture0() {}
    virtual void draw();
  
};

class ThreePicture1 :public FrameFigure {
    Circle circle1;
    Triangle triangle1;
    Rectangle rectangle1;
    int maxX;//координаты спрайта
    int maxY;
public:
    ThreePicture1(std::shared_ptr<sf::RenderWindow>&);
    ~ThreePicture1() {}
    virtual void draw();

};

class ThreePicture3 :public FrameFigure {
    Circle circle1;
    Triangle triangle1;
    Rectangle rectangle1;
    int maxX;//координаты спрайта
    int maxY;
public:
    ThreePicture3(std::shared_ptr<sf::RenderWindow>&);
    ~ThreePicture3() {}
    virtual void draw();

};

class ThreePicture2 :public FrameFigure {
    Circle circle1;
    Triangle triangle1;
    Rectangle rectangle1;
    int maxX;//координаты спрайта
    int maxY;
public:
    ThreePicture2(std::shared_ptr<sf::RenderWindow>&);
    ~ThreePicture2() {}
    virtual void draw();

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
    virtual void draw();
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
    virtual void draw();
};


class Car :public FrameFigure
{
public:
    Car(std::shared_ptr<sf::RenderWindow>& window);
    ~Car() {}
    virtual void draw();

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

  virtual void draw();

private:
  Circle circle1;
  Circle circle2;
  Circle circle3;
  Circle circle4;
  Circle center_circle;

  Triangle triangle1;
  Triangle triangle2;
  //Triangle triangle3;
  Rectangle rectangle;
};

class TrainForQuest :public FrameFigure {
    std::vector<Rectangle *>  rectangle;

public:
    TrainForQuest(std::shared_ptr<sf::RenderWindow>&);
    void SetSquareColor(int, bool);
        ~TrainForQuest() {}
    virtual void draw();
};

#endif // FIGURES_HPP
