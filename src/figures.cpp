#include "figures.hpp"

#include <ctime>

#define PI 3.14159265
std::vector<const sf::Color*> wheels = { &color::aliceblue, &color::skyblue, &color::salmon };

std::vector<const sf::Color*> roof = { &color::red, &color::purple, &color::salmon };








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



Butterfly::Butterfly(int w, int h) {
    widthScreen=w ;
    heightScreen = h;
    srand(time(NULL));

    static int angle = rand() % 90;
                
   
    int x = 101;
    int y = 37;
    int y1 = 150;
    int x1 = 26;
  
    rectangle1.set_coords(x1+65+x, -50+y+y1);
    rectangle1.set_color(color::lightskyblue);
    rectangle1.set_size(40, 150);
    rectangle2.set_coords(x1 + 75+x, -10 +y + y1);
    rectangle2.set_color(color::lightskyblue);
    rectangle2.set_size(20, 15 );
    rectangle3.set_coords(x1 + 75+x, 20 +y + y1);
    rectangle3.set_color(color::lightskyblue);
    rectangle3.set_size(20, 15);
    rectangle4.set_coords(x1 + 75 + x, 50+y + y1);
    rectangle4.set_color(color::lightskyblue);
    rectangle4.set_size(20, 15);
    rectangle5.set_coords(x1 + 75 + x, 102 +y + y1);
    rectangle5.set_color(color::green);
    rectangle5.set_size(20, 15);
    heightSprite = 102 + y + y1+20;

    triangle1.set_coords(-93 + x, -35+y , 86 + x, 140+y,  -89 + x,95+y );

    
    widthSprite = 325+x;
    triangle2.set_coords(315 + x,  -35+y , 137 + x, 140+y, 310 + x, 95+y);//**


    triangle4.set_coords(290 + x, 115+y, 137 + x, 143+y, 310 + x, 255+y);
   triangle5.set_coords(-65+ x, 115+y, 85 + x, 143+y, -85 + x, 255+y);

    circle1.set_coords(83 + x, 40 +y);
    circle1.set_radius(28);


    circle2.set_coords(-25 +x, 140+y );
    circle2.set_radius(22);

    circle3.set_coords(210 + x, 140+y );
    circle3.set_radius(22);

    circle4.set_coords( -70+x, 50+y);
    circle4.set_radius(22);

    circle5.set_coords(240 + x, 50+y);
    circle5.set_radius(22);

    triangle3.set_coords(95 + x, 21+y , 125 + x, 21+y , 110 + x,36+y );
     //Xfactor =(float)widthScreen/2.0/ (float)widthSprite;
     Xfactor = (float)heightScreen / 2.9 / (float)heightSprite;
    if (!renderTexture.create(widthSprite , heightSprite ))
    {

    }
    renderTexture.clear(sf::Color::Green);
    

    renderTexture.display();
    texture.setSmooth(true);
    renderTexture.setSmooth(true);
    sprite.setTexture(texture1);



    sprite.scale(Xfactor, Xfactor);
    sprite.rotate(angle);
    //sprite.move(moveSpriteX, moveSpriteY);
    //sprite.move(-moveSpriteX, -moveSpriteY);
    float test = cos((90 - angle) * PI / 180);
    moveSpriteX= abs(Xfactor*heightSprite*cos((90 - angle) * PI / 180));
    
    sprite.move(moveSpriteX, moveSpriteY);



   

}

void Butterfly::draw(std::shared_ptr<sf::RenderWindow>& window) {




    renderTexture.draw(triangle4.getTriangle());
    renderTexture.draw(triangle5.getTriangle());
    renderTexture.draw(rectangle1.getRectangle());
    renderTexture.draw(rectangle2.getRectangle());
    renderTexture.draw(rectangle3.getRectangle());
    renderTexture.draw(rectangle4.getRectangle());
    renderTexture.draw(rectangle5.getRectangle());
    renderTexture.draw(triangle1.getTriangle());
    renderTexture.draw(triangle2.getTriangle());
    renderTexture.draw(triangle3.getTriangle());
    renderTexture.draw(circle1.getCircle());
    renderTexture.draw(circle2.getCircle());
    renderTexture.draw(circle3.getCircle());
    renderTexture.draw(circle4.getCircle());
    renderTexture.draw(circle5.getCircle());


    renderTexture.display();
    window->draw(sprite);
}
