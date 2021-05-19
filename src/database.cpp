#include "database.hpp"
#include "settings.hpp"
#include "color.hpp"
#include "window.hpp"

const std::array<figureQestions,N> questionFigure = 
  {
    figureQestions{L"Сколько кружков на рисунках вы видете ? "       ,circle},
    figureQestions{L"Сколько прямоугольников на рисунках вы видите ? ",rectangle},
    figureQestions{L"Сколько треугольников на рисунках вы видите ? ",triangle},
    figureQestions{L"Лена хочет подарить родным N ракушек. Ей осталось \nнайти M ракушек . Сколько ракушек Лена уже нашла ?",seashell},
    figureQestions{L"В корзине было N ягод клубники. После того , как Игорь съел \nнесколько ягод, осталось M. Сколько ягод съел Игорь ?",berry},
    figureQestions{L"Ване нужно найти N грибов. Ему осталось найти M грибов. \nСколько грибов он уже нашел ?",mashroom},
    figureQestions{L"Паша и Люба поймали 18 рыбок. Паша поймал 14 рыбок. \nСколько рыбок поймала Люба?",fish},
    figureQestions{L"Наташе нужно раскрасить 20 бабочек. Она раскрасила \n14 бабочек. Сколько бабочек осталось раскрасить? ",butterfly},
    figureQestions{L"Саша хочет купить велосипед. Он стоит 16 рублей, \nсейчас у Саши в копилке 9 рублей. Сколько  еще рублей нужно Саше, \nчтобы хватило на велосипед?",bycicle}
  }	;




const std::wstring CommentsDic[] =
{
    {L"Выбери ответ" },
    {L"Верно. Молодец, +1 балл" },
    {L"Неверно. Ошибка :(" }
};






//const std::vector<pica> flower = {
//  // type   r   x0 y0   x1y1 x2y2   FillColor               outlineColor       OutlineThickness    angle
//  {circle, 30, 148,125, 0,0, 0,0, color::aqua, sf::Color(0,0,0), Settings::THICKNESS,   2.0f, 0, 0 },
//  {circle, 30, 21,20,   0,0, 0,0, color::red, sf::Color(0,0,0),  Settings::THICKNESS,   2.0f, 0, 0 },
//  {circle, 30, 148,20,  0,0, 0,0, color::coral, sf::Color(0,0,0),  Settings::THICKNESS,   2.0f, 0, 0 },
//  {circle, 30, 18,125,  0,0, 0,0, sf::Color(181, 72, 213), sf::Color(0,0,0), Settings::THICKNESS,   2.0f, 0, 0 },
//  {circle, 45, 70,57,   0,0, 0,0, sf::Color(255, 220, 156), sf::Color(0,0,0),Settings::THICKNESS,   2.0f, 0, 0 },
//  
//  {triangle,10,0.0f,230.0f,80.0f,230.0f,40.0f,260.0f, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS, 0, 0, 0},
//
//  {triangle,10,140.0f,230.0f,220.0f,230.0f,180.0f,260.0f, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS, 0, 0, 0},
//
//  {rectangle,0,105,160,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,10,180}
//};
//
//
//
//const std::vector<pica> tree = {
//
//
//    {circle, 10, 180,122, 0,0, 0,0, sf::Color(255, 96, 114), sf::Color(0,0,0), Settings::THICKNESS,   2.0f },
//    {circle, 10, 230,122,   0,0, 0,0, sf::Color(107, 177, 0), sf::Color(0,0,0),  Settings::THICKNESS,   2.0f },
//    {circle, 10, 280,122,  0,0, 0,0, sf::Color(107, 177, 0), sf::Color(0,0,0),  Settings::THICKNESS,   2.0f },
//    {rectangle,0,100,110,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,220,50},
//    {rectangle,0,250,170,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,20,90},
//    {rectangle,0,250,8,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,20,90},
//    {triangle,0,330.0f,114.0f,    364.0f,132.0f,    330.0f,155.0f,    sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//    {triangle,12,361,30,393,30,378,96.0f, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//
//    {triangle,12,361,230,393,230,378,164.0f, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//
//    {triangle,12,0,45,85,45,85,169.0f, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS}
//
//
//};
//
//float m1 = 130;
//const std::vector<pica> tower = {
//    // type   r   x0 y0   x1y1 x2y2   FillColor               outlineColor       OutlineThickness    angle
//        {circle, 30, 201,90,  0,0, 0,0, sf::Color(107, 177, 0), sf::Color(0,0,0),  Settings::THICKNESS,   2.0f },
//        {rectangle,0,50,60,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,100,140},
//        {rectangle,0,50 + m1,60,  0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,100,140},
//        {rectangle,0,50 + 2 * m1,60,  0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,100,140},
//        //{rectangle,0,50,60,0,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,100,160},
//
//        {triangle,10,  51,56,  149,56,  103,0, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//        {triangle,10,  51 + m1,56,  149 + m1,56,  103 + m1,0, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//        {triangle,10,  51 + 2 * m1,56,  149 + 2 * m1,56,  103 + 2 * m1,0, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//
//
//
//        //{triangle,10,  59,48,  143,48,  104,0, sf::Color(253, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS}
//};
//
//
//
//
//
//const std::vector<pica> car = {
//
//    {rectangle,0,60,110,0 ,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,250,60},
//    {rectangle,0,100,50,0 ,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,170,50},
//    {triangle,10,  60,110,  90,110,     60  ,140, sf::Color(60, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//    {triangle,10,  310,110,  310,140,     280  ,110, sf::Color(60, 255, 5) , sf::Color(0,0,0) ,Settings::THICKNESS},
//    {circle,35,57 ,184,0,0,0,0,sf::Color(255, 220, 156) , sf::Color(0,0,0) ,Settings::THICKNESS,   0 },
//    {circle,35,245 ,184,0,0,0,0,sf::Color(255, 220, 156) , sf::Color(0,0,0) ,Settings::THICKNESS,   0 },
//
//    {circle,10,80 ,210,0,0,0,0,sf::Color(255, 220, 156) , sf::Color(0,0,0) ,Settings::THICKNESS,   0 },
//    {circle,10,269 ,210,0,0,0,0,sf::Color(255, 220, 156) , sf::Color(0,0,0) ,Settings::THICKNESS,   0},
//
//    {rectangle,0,240,69,0 ,0,0,0,sf::Color(42, 170, 205) , sf::Color(0,0,0) ,Settings::THICKNESS,   0,30,30},
//    {circle,7,248 ,77,0,0,0,0,sf::Color(255, 220, 156) , sf::Color(0,0,0) ,Settings::THICKNESS,   0}
//
//};