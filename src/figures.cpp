#include "figures.hpp"

#include <ctime>

#define PI 3.14159265
//std::vector<const sf::Color*> wheels = { &color::aliceblue, &color::skyblue, &color::salmon };

std::vector<const sf::Color*> Colors = { 
&color::aliceblue                ,
&color::antiquewhite             ,
&color::aqua                     ,
&color::aquamarine               ,
&color::azure                    ,
&color::beige                    ,
&color::bisque                   ,
&color::black                    ,
&color::blanchedalmond           ,
&color::blue                     ,
&color::blueviolet               ,
&color::brown                    ,
&color::burlywood                ,
&color::cadetblue                ,
&color::chartreuse               ,
&color::chocolate                ,
&color::coral                    ,
&color::cornflowerblue           ,
&color::cornsilk                 ,
&color::crimson                  ,
&color::cyan                     ,
&color::darkblue                 ,
&color::darkcyan                 ,
&color::darkgoldenrod            ,
&color::darkgray                 ,
&color::darkgreen                ,
&color::darkgrey                 ,
&color::darkkhaki                ,
&color::darkmagenta              ,
&color::darkolivegreen           ,
&color::darkorange               ,
&color::darkorchid               ,
&color::darkred                  ,
&color::darksalmon               ,
&color::darkseagreen             ,
&color::darkslateblue            ,
&color::darkslategray            ,
&color::darkslategrey            ,
&color::darkturquoise            ,
&color::darkviolet               ,
&color::deeppink                 ,
&color::deepskyblue              ,
&color::dimgray                  ,
&color::dimgrey                  ,
&color::dodgerblue               ,
&color::firebrick                ,
&color::floralwhite              ,
&color::forestgreen              ,
&color::fuchsia                  ,
&color::gainsboro                ,
&color::ghostwhite               ,
&color::gold                     ,
&color::goldenrod                ,
&color::gray                     ,
&color::green                    ,
&color::greenyellow              ,
&color::grey                     ,
&color::honeydew                 ,
&color::hotpink                  ,
&color::indianred                ,
&color::indigo                   ,
&color::ivory                    ,
&color::khaki                    ,
&color::lavender                 ,
&color::lavenderblush            ,
&color::lawngreen                ,
&color::lemonchiffon             ,
&color::lightblue                ,
&color::lightcoral               ,
&color::lightcyan                ,
&color::lightgoldenrodyellow     ,
&color::lightgray                ,
&color::lightgreen               ,
&color::lightgrey                ,
&color::lightpink                ,
&color::lightsalmon              ,
&color::lightseagreen            ,
&color::lightskyblue             ,
&color::lightslategray           ,
&color::lightslategrey           ,
&color::lightsteelblue           ,
&color::lightyellow              ,
&color::lime                     ,
&color::limegreen                ,
&color::linen                    ,
&color::magenta                  ,
&color::maroon                   ,
&color::mediumaquamarine         ,
&color::mediumblue               ,
&color::mediumorchid             ,
&color::mediumpurple             ,
&color::mediumseagreen           ,
&color::mediumslateblue          ,
&color::mediumspringgreen        ,
&color::mediumturquoise          ,
&color::mediumvioletred          ,
&color::midnightblue             ,
&color::mintcream                ,
&color::mistyrose                ,
&color::moccasin                 ,
&color::navajowhite              ,
&color::navy                     ,
&color::oldlace                  ,
&color::olive                    ,
&color::olivedrab                ,
&color::orange                   ,
&color::orangered                ,
&color::orchid                   ,
&color::palegoldenrod            ,
&color::palegreen                ,
&color::paleturquoise            ,
&color::palevioletred            ,
&color::papayawhip               ,
&color::peachpuff                ,
&color::peru                     ,
&color::pink                     ,
&color::plum                     ,
&color::powderblue               ,
&color::purple                   ,
&color::red                      ,
&color::rosybrown                ,
&color::royalblue                ,
&color::saddlebrown              ,
&color::salmon                   ,
&color::sandybrown               ,
&color::seagreen                 ,
&color::seashell                 ,
&color::sienna                   ,
&color::silver                   ,
&color::skyblue                  ,
&color::slateblue                ,
&color::slategray                ,
&color::slategrey                ,
&color::snow                     ,
&color::springgreen              ,
&color::steelblue                ,
&color::tan                      ,
&color::teal                     ,
&color::thistle                  ,
&color::tomato                   ,
&color::turquoise                ,
&color::violet                   ,
&color::wheat                    ,
&color::white                    ,
&color::whitesmoke               ,
&color::yellow                   ,
&color::yellowgreen              ,



};

char FrameFigure::number_of_figure = 0;
int Circle::QTY = 0;


void FrameFigure::calcKoeff() {
    alreadyDraw = true;
    float step = 0;
    float frameWidth = getxmax() - getxmin();
    float frameHeight = getymax() - getymin();
    float frameWidthNew = window->getSize().x / 2;
    int winHeigt = window->getSize().y;
    int winWidth = window->getSize().x;
    koef = frameWidthNew / frameWidth;
    float frameHeightNew = (getymax() - getymin()) * koef;
    do  {
        koef = koef - 0.01;
        frameHeightNew = frameWidth * koef;
        frameWidthNew = frameHeight * koef;
    } while (frameHeightNew > (int)((float)winHeigt / 2.8) || frameWidth > winWidth / 2);
     
     margin_left = number_of_figure * winWidth / 2 + abs((winWidth / 2 - frameWidthNew) / 2);
     margin_top = winHeigt / 3;

     std::cout << "picture size :" << frameWidthNew <<"x" << frameWidthNew  << std::endl;

     //int fw = (number_of_figure == 0 ? frameWidth / 2 : frameWidth);
     //margin_left = number_of_figure * window->getSize().x / 2 + abs((window->getSize().x / 2 - frameWidthNew ) / 2);
     //while (margin_left + frameWidthNew > fw) {
     //    koef = koef - 0.01;
     //    frameWidthNew = (getxmax() - getxmin()) * koef;
     //    if (margin_left < 10) margin_left = 10; //left picture
     //    if (margin_left + frameWidthNew* koef > window->getSize().y) margin_left -= 10; //left picture
     //    koef = koef - 0.01;
     //}
     ////std::cout << "margin_left=" << margin_left <<  std::endl;

     //float f = window->getSize().y / 3;
     //margin_top = (window->getSize().y - frameHeightNew)/2;
     number_of_figure++;
    /*koef = 1;
    margin_left = 0;
    margin_top = 0; */
}


void Car::draw() {
if (!alreadyDraw) {
    calcKoeff();

    srand((unsigned int)time(NULL));
    int indexColor1 = rand() % Colors.size();
    int indexColor2 = rand() % Colors.size();
    int indexColor3 = rand() % Colors.size();
    int indexColor4 = rand() % Colors.size();
    int indexColor5 = rand() % Colors.size();
    int indexColor6 = rand() % Colors.size();
    int indexColor7 = rand() % Colors.size();
    int indexColor8 = rand() % Colors.size();
    //int indexColor9 = rand() % Colors.size();
    circle1.set_radius(35);
    circle2.set_radius(35);
    circle3.set_radius(15);
    circle4.set_radius(15);

    //int colorwheelsSize = sizeof(wheels) / sizeof(wheels*);
    int y = 41;

    circle1.set_color(*Colors[indexColor1]);
    circle2.set_color(*Colors[indexColor1]);


    srand((unsigned int)time(NULL));

    circle3.set_color(*Colors[indexColor2]);
    circle4.set_color(*Colors[indexColor2]);


    rectangle1.set_color(*Colors[indexColor3]);
    rectangle2.set_color(*Colors[indexColor4]);
    rectangle3.set_color(*Colors[indexColor5]);

    circle1.set_color(*Colors[indexColor1]);
    circle2.set_color(*Colors[indexColor1]);
    circle3.set_color(*Colors[indexColor2]);
    circle4.set_color(*Colors[indexColor2]);

    circle5.set_color(*Colors[indexColor6]);
    triangle1.set_color(*Colors[indexColor7]);
    triangle2.set_color(*Colors[indexColor8]);

    circle1.set_coords(190, 101);
    circle2.set_coords(20, 101);
    circle3.set_coords(210, 121);
    circle4.set_coords(39, 121);
    circle5.set_coords(162, 19);
    rectangle1.set_coords(70, 0);
    rectangle1.set_size(120, 60);
    circle5.set_radius(13);
    rectangle2.set_coords(10, 50);
    rectangle2.set_size(250, 50);
    triangle1.set_coords(10, 50, 40, 50, 10, 80);
    triangle2.set_coords(260, 50, 260, 80, 230, 50);
    rectangle3.set_coords(160, 18);
    rectangle3.set_size(30, 30);
}

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

Car::Car(std::shared_ptr<sf::RenderWindow>& win):
circle1(this),
circle2(this),
circle3(this),
circle4(this),
circle5(this),
triangle1(this),
triangle2(this),
rectangle1(this),
rectangle2(this),
rectangle3(this),
FrameFigure(win,0,0,0)

{

    xmin = 10;
    xmax = 260;
    ymin = 0;
    ymax = 200;

    
}

void Plane::draw() {
    if (!alreadyDraw) {
        calcKoeff();

        int indexColor1 = rand() % Colors.size();
        int indexColor2 = rand() % Colors.size();
        int indexColor3 = rand() % Colors.size();
        int indexColor4 = rand() % Colors.size();
        int indexColor5 = rand() % Colors.size();
        int indexColor6 = rand() % Colors.size();
        int indexColor7 = rand() % Colors.size();
        int indexColor8 = rand() % Colors.size();

        circle1.set_radius(15);
        circle2.set_radius(15);
        circle3.set_radius(15);

        circle1.set_color(*Colors[indexColor1]);
        circle2.set_color(*Colors[indexColor1]);
        circle3.set_color(*Colors[indexColor1]);

        circle1.set_coords(155, 145);
        circle2.set_coords(115, 145);
        circle3.set_coords(75, 145);




        triangle1.set_coords(241, 80, 273, 80, 258, 146);
        triangle2.set_coords(241, 230, 273, 230, 258, 164.0f);
        triangle3.set_coords(253, 155.0f, 195, 130, 195, 194.0f);
        triangle4.set_coords(0, 90, 58, 90, 58, 195);

        rectangle1.set_coords(60, 129);
        rectangle1.set_color(color::lightskyblue);
        rectangle1.set_size(132, 65);

        rectangle2.set_coords(145, 0);
        rectangle2.set_size(20, 126);
        rectangle3.set_coords(145, 197);
        rectangle3.set_size(20, 126);


        triangle1.set_color(*Colors[indexColor2]);
        triangle2.set_color(*Colors[indexColor3]);
        triangle3.set_color(*Colors[indexColor4]);
        triangle4.set_color(*Colors[indexColor5]);
        rectangle1.set_color(*Colors[indexColor6]);
        rectangle2.set_color(*Colors[indexColor7]);
        rectangle3.set_color(*Colors[indexColor8]);
    }



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
 Plane::Plane(std::shared_ptr<sf::RenderWindow>& win) :

 circle1(this),
 circle2(this),
 circle3(this),


 triangle1(this),
 triangle2(this),
 triangle3(this),
 triangle4(this),
 rectangle1(this),
 rectangle2(this),
 rectangle3(this),
     FrameFigure(win,0,0,0)
 
 {

     xmin = 0;
     xmax = 280;
     ymin = 0;
     ymax = 370;

    

}

ThreePicture1::ThreePicture1(std::shared_ptr<sf::RenderWindow>& win):
     circle1(this),
     triangle1(this),
     rectangle1(this),
    FrameFigure(win, 0, 0, 0){
 };

void ThreePicture1::draw() {
    if (!alreadyDraw) {
        calcKoeff();
        int y = 20;
        int x = -55;
        circle1.set_radius(23);
        circle1.set_coords(30, 30);
        circle1.set_color(color::blue);
        triangle1.set_coords(100, 100, 150, 150, 200, 200);
        rectangle1.set_coords(500 , 500);
        rectangle1.set_color(color::lightskyblue);
        rectangle1.set_size(10, 80);

    }
    circle1.draw(window);
    triangle1.draw(window);
    rectangle1.draw(window);
}


Flower::Flower(std::shared_ptr<sf::RenderWindow>& win)
    :circle1(this),
    circle2(this),
    circle3(this),
    circle4(this),
    center_circle(this),

    triangle1(this),
    triangle2(this),
    //triangle3(this),
    rectangle(this),
    FrameFigure(win,0,0,0)
{

    xmin = 0;
    xmax = 243;
    ymin = 0;
    ymax = 264;

   
 
}

void Flower::draw() {
    if (!alreadyDraw) {
        calcKoeff();
        int y = 20;
        int x = -55;
        circle1.set_radius(23);
        circle2.set_radius(23);
        circle3.set_radius(23);
        circle4.set_radius(23);

        center_circle.set_radius(45);
        int step = 15;
        circle2.set_coords(25 - x + step, 0 + step);

        circle1.set_coords(130 - x + step, 0 + step);
        
        circle3.set_coords(25 - x + step, 90 + step);
        circle4.set_coords(130 - x + step, 90 + step);

        center_circle.set_coords(70-x, 17+y);

        circle1.set_color(color::aqua);
        circle2.set_color(color::red);
        circle3.set_color(color::blue);
        circle4.set_color(color::green);

        center_circle.set_color(color::coral);
   
        int step2 = -40;
        triangle1.set_coords(25-x, 190+y+ step2, 105-x,190+y + step2, 65-x,220+y + step2);
        triangle1.set_color(color::lime);

        triangle2.set_coords(125-x, 190+y + step2, 205-x, 190+y + step2, 165-x, 220+y + step2);
        triangle2.set_color(color::lime);

        rectangle.set_coords(110-x, 109+y);
        rectangle.set_color(color::lightskyblue);
        rectangle.set_size(10, 80);

        int indexColor1 = rand() % Colors.size();
        int indexColor2 = rand() % Colors.size();
        int indexColor3 = rand() % Colors.size();
        int indexColor4 = rand() % Colors.size();
        int indexColor5 = rand() % Colors.size();
        int indexColor6 = rand() % Colors.size();
        int indexColor7 = rand() % Colors.size();
        int indexColor8 = rand() % Colors.size();
        int indexColor9 = rand() % Colors.size();


        circle1.set_color(*Colors[indexColor1]);
        circle2.set_color(*Colors[indexColor2]);
        circle3.set_color(*Colors[indexColor3]);
        circle4.set_color(*Colors[indexColor4]);

        center_circle.set_color(*Colors[indexColor5]);

        triangle1.set_color(*Colors[indexColor6]);
        triangle2.set_color(*Colors[indexColor7]);

        rectangle.set_color(*Colors[indexColor8]);
    }

  circle1.draw(window);
  circle2.draw(window);
  circle3.draw(window);
  circle4.draw(window);
  
  center_circle.draw(window);
  
  triangle1.draw(window);
  triangle2.draw(window);
  
  rectangle.draw(window);
}

Tower::Tower(std::shared_ptr<sf::RenderWindow>& win):
    triangle1(this),
triangle2(this),
triangle3(this),
 rectangle1(this),
 rectangle2(this),
 rectangle3(this),
circle1(this), 
FrameFigure(win,0,0,0)
{

    
    xmin = 0;
    xmax = 330;
    ymin = 0;
    ymax = 160;
   
    
};
void Tower::draw() {
    if (!alreadyDraw) {
        calcKoeff();

        int indexColor1 = rand() % Colors.size();
        int indexColor2 = rand() % Colors.size();
        int indexColor3 = rand() % Colors.size();
        int indexColor4 = rand() % Colors.size();
        int indexColor5 = rand() % Colors.size();
        int indexColor6 = rand() % Colors.size();
        int indexColor7 = rand() % Colors.size();
        int indexColor8 = rand() % Colors.size();
        int indexColor9 = rand() % Colors.size();

        int y = -40;
        int x = -15;
        triangle1.set_coords(17 + x, 88 + y, 62 + x, 42 + y, 113 + x, 88 + y);

        //triangle2.set_coords(112+x, 88, 157+x, 42, 208+x, 88);
        triangle2.set_coords(126 + x, 88 + y, 171 + x, 42 + y, 222 + x, 88 + y);

        triangle3.set_coords(236 + x, 88 + y, 281 + x, 42 + y, 332 + x, 88 + y);

        circle1.set_coords(145 + x, 110 + y);
        circle1.set_radius(30);

        rectangle1.set_coords(20 + x, 90 + y);
        rectangle1.set_size(90, 110);
        rectangle1.set_color(color::lightskyblue);

        rectangle2.set_coords(130 + x, 90 + y);
        rectangle2.set_size(90, 110);
        rectangle2.set_color(color::lightskyblue);

        rectangle3.set_coords(240 + x, 90 + y);
        rectangle3.set_size(90, 110);
        rectangle3.set_color(color::lightskyblue);
        srand((unsigned int)time(NULL));


        triangle1.set_color(*Colors[indexColor1]);
        triangle2.set_color(*Colors[indexColor2]);
        triangle3.set_color(*Colors[indexColor3]);

        rectangle1.set_color(*Colors[indexColor4]);
        rectangle2.set_color(*Colors[indexColor5]);
        rectangle3.set_color(*Colors[indexColor6]);

        circle1.set_color(*Colors[indexColor8]);
    }


    triangle1.draw(window);
    triangle2.draw(window);
    triangle3.draw(window);

     rectangle1.draw(window);
     rectangle2.draw(window);
     rectangle3.draw(window);

    circle1.draw(window);
    
    
}


Tree::Tree(std::shared_ptr<sf::RenderWindow>& win):
    circle1(this),
    circle2(this),
    circle3(this),
    circle4(this),
    center_circle(this),
    triangle1(this), 
    triangle2(this), 
    triangle3(this), 
    rectangle(this),
    FrameFigure(win,0,0,0)
{

    xmin = 0;
    xmax = 340;
    ymin = 0;
    ymax = 264;

    
   
}

void Tree::draw() {
    if (!alreadyDraw) {
        int indexColor1 = rand() % Colors.size();
        int indexColor2 = rand() % Colors.size();
        int indexColor3 = rand() % Colors.size();
        int indexColor4 = rand() % Colors.size();
        int indexColor5 = rand() % Colors.size();
        int indexColor6 = rand() % Colors.size();
        int indexColor7 = rand() % Colors.size();
        int indexColor8 = rand() % Colors.size();
        int indexColor9 = rand() % Colors.size();

        calcKoeff();

        circle1.set_radius(15);
        circle2.set_radius(15);
        circle3.set_radius(15);
        circle4.set_radius(15);

        center_circle.set_radius(15);

        circle1.set_coords(46, 142);
        circle2.set_coords(285, 142);
        circle3.set_coords(325, 197);
        circle4.set_coords(3, 197);

        center_circle.set_coords(170, 0);


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

        circle1.set_color(*Colors[indexColor1]);
        circle2.set_color(*Colors[indexColor2]);
        circle3.set_color(*Colors[indexColor3]);
        circle4.set_color(*Colors[indexColor4]);
    }
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



Butterfly::Butterfly(std::shared_ptr<sf::RenderWindow>& win) :
    triangle1(this),
    triangle2(this),
    triangle3(this),
    triangle4(this),
    triangle5(this),
    rectangle1(this),
    rectangle2(this),
    rectangle3(this),
    rectangle4(this),
    rectangle5(this),
    circle1(this),
    circle2(this),
    circle3(this),
    circle4(this),
    circle5(this),
    FrameFigure(win,0,0,0)
{
    //window = win;
    xmin = 8;
    xmax = 416;
    ymin = 2;
    ymax = 303;

    

 




   

}
TrainForQuest::TrainForQuest(std::shared_ptr<sf::RenderWindow>& win):
    rectangle({
        new Rectangle(this),
        new Rectangle(this),
        new Rectangle(this),
        new Rectangle(this),
        new Rectangle(this),
        new Rectangle(this) }),
    FrameFigure(win, 0, 0, 0){

    xmin = 0;
    xmax = 304;
    ymin = 0;
    ymax = 50;

}
void TrainForQuest::SetSquareColor(int index , bool _switch) {
    if (_switch)  rectangle[index]->set_color(color::lightskyblue);
    else rectangle[index]->set_color(color::white);
    
};


void TrainForQuest::draw() {
    if (!alreadyDraw) {
        calcKoeff();
        rectangle[0]->set_coords(0, 0);  
        //rectangle[0]->set_color(color::lightskyblue);
        rectangle[0]->set_size(50, 50);

        rectangle[1]->set_coords(51, 0);
        rectangle[1]->set_size(50, 50);

        rectangle[2]->set_coords(102, 0);
        rectangle[2]->set_size(50, 50);

        rectangle[3]->set_coords(153, 0);
        rectangle[3]->set_size(50, 50);

        rectangle[4]->set_coords(203, 0);
        rectangle[4]->set_size(50, 50);
        rectangle[5]->set_coords(254, 0);
        rectangle[5]->set_size(50, 50);


    }
    rectangle[0]->draw(window);
    rectangle[1]->draw(window);
    rectangle[2]->draw(window);
    rectangle[3]->draw(window);
    rectangle[4]->draw(window);
    rectangle[5]->draw(window);
    

}

void Butterfly::draw() {
    if (!alreadyDraw) {
        calcKoeff();

        int indexColor1 = rand() % Colors.size();
        int indexColor2 = rand() % Colors.size();
        int indexColor3 = rand() % Colors.size();
        int indexColor4 = rand() % Colors.size();
        int indexColor5 = rand() % Colors.size();
        int indexColor6 = rand() % Colors.size();
        int indexColor7 = rand() % Colors.size();
        int indexColor8 = rand() % Colors.size();
        int indexColor9 = rand() % Colors.size();
        int indexColor10 = rand() % Colors.size();
        int indexColor11 = rand() % Colors.size();
        int indexColor12 = rand() % Colors.size();
        int indexColor13 = rand() % Colors.size();
        int indexColor14 = rand() % Colors.size();
        int indexColor15 = rand() % Colors.size();
        int indexColor16 = rand() % Colors.size();

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

        triangle1.set_coords(8, 2, 192, 177, 12, 132);


        widthSprite = 426;
        triangle2.set_coords(416, 2, 234, 177, 395, 132);


        triangle4.set_coords(391, 152, 234, 180, 411, 292);
        triangle5.set_coords(36, 152, 191, 180, 16, 292);

        circle1.set_coords(184, 80);
        circle1.set_radius(28);


        circle2.set_coords(76, 177);
        circle2.set_radius(22);

        circle3.set_coords(311, 177);
        circle3.set_radius(22);

        circle4.set_coords(31, 87);
        circle4.set_radius(22);

        circle5.set_coords(341, 87);
        circle5.set_radius(22);

        triangle3.set_coords(196, 58, 226, 58, 211, 79);

        circle1.set_color(*Colors[indexColor1]);
        triangle4.set_color(*Colors[indexColor2]);
        triangle5.set_color(*Colors[indexColor3]);
        rectangle1.set_color(*Colors[indexColor4]);
        rectangle2.set_color(*Colors[indexColor5]);
        rectangle3.set_color(*Colors[indexColor6]);
        rectangle4.set_color(*Colors[indexColor7]);
        rectangle5.set_color(*Colors[indexColor8]);
        triangle1.set_color(*Colors[indexColor9]);
        triangle2.set_color(*Colors[indexColor10]);
        triangle3.set_color(*Colors[indexColor11]);
        circle1.set_color(*Colors[indexColor12]);
        circle2.set_color(*Colors[indexColor13]);
        circle3.set_color(*Colors[indexColor14]);
        circle4.set_color(*Colors[indexColor15]);
        circle5.set_color(*Colors[indexColor16]);
    }
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


    

}
