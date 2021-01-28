#include "database.hpp"
#include "settings.hpp"
//#include "pica.hpp"



const std::array<figureQestions,N> questionFigure = 
{
	figureQestions{L"How many circles are there in the drawing?"       ,circle},
	figureQestions{L"How many triangles are there in the drawing?",triangle}
}	;







const std::vector<pica> flower = {
    // type   r   x0 y0   x1y1 x2y2   FillColor               outlineColor       OutlineThickness    angle
  {circle, 30, 148,125, 0,0, 0,0, sf::Color(255, 96, 114), sf::Color(0,0,0), Settings::THICKNESS,   2.0f, 0, 0 },
  {circle, 30, 21,20,   0,0, 0,0, sf::Color(107, 177, 0), sf::Color(0,0,0),  Settings::THICKNESS,   2.0f, 0, 0 },
  {circle, 30, 148,20,  0,0, 0,0, sf::Color(107, 177, 0), sf::Color(0,0,0),  Settings::THICKNESS,   2.0f, 0, 0 },
  {circle, 30, 18,125,  0,0, 0,0, sf::Color(181, 72, 213), sf::Color(0,0,0), Settings::THICKNESS,   2.0f, 0, 0 },
  {circle, 45, 70,57,   0,0, 0,0, sf::Color(255, 220, 156), sf::Color(0,0,0),Settings::THICKNESS,   2.0f, 0, 0 },
  
  {triangle,10,0.0f,230.0f,80.0f,230.0f,40.0f,260.0f, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS, 0, 0, 0},

  {triangle,10,140.0f,230.0f,220.0f,230.0f,180.0f,260.0f, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS, 0, 0, 0},

  {rectangle,0,105,160,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,10,180}
};

const std::vector<pica> tree = {
  {circle, 10,15,155,0,0,0,0,sf::Color(255, 96, 114) , sf::Color(0,0,0) ,Settings::THICKNESS,   2.0f, 0,0 },
  {circle, 10,245,155,0,0,0,0,sf::Color(107, 177, 0) , sf::Color(0,0,0) ,Settings::THICKNESS,   2.0f, 0,0 },
  {circle, 10,-45,224,0,0,0,0,sf::Color(107, 177, 0) , sf::Color(0,0,0) ,Settings::THICKNESS,   2.0f, 0,0},
  {circle,10,315,224,0,0,0,0,sf::Color(181, 72, 213) , sf::Color(0,0,0) ,Settings::THICKNESS,   2.0f, 0,0 },
  {circle,10,131,10,0,0,0,0,sf::Color(255, 220, 156) , sf::Color(0,0,0) ,Settings::THICKNESS,   2.0f, 0,0 },
  
  {triangle,10,0.0f  ,150.0f + 60.0f,290.0f  ,150.0f + 60.0f,145.50f ,90.0f + 60.0f, sf::Color(60, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS, 0,0,0},
  {triangle,10,50.0f ,80.0f + 60.0f,230.0f  ,80.0f + 60.0f,140.0f   ,30.0f + 60.0f, sf::Color(60, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS, 0,0,0},
  {triangle,10,80.0f ,23.0f + 60.0f,200.0f  ,23.0f + 60.0f,140.0f   ,0.0f + 40.0f, sf::Color(60, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS, 0,0,0},
  {rectangle,0,137,100,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,10,180}
};
