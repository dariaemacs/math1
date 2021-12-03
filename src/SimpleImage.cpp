#include "SimpleImage.hpp"

int SimpleImage::getCircleBaseFigureQTY() { return CircleBaseFigureQTY; }
int SimpleImage::getRectangleFigureQTY() { return RectangleFigureQTY; }
int SimpleImage::getGetTriangleFigureQTY() { return TriangleBaseFigureQTY; }
std::vector<sf::CircleShape>& SimpleImage::GetCircle() { return CircleBaseFigure; }
std::vector<sf::RectangleShape>& SimpleImage::GetRectangleFigure() { return RectangleFigure; }
std::vector<sf::ConvexShape>& SimpleImage::GetTriangleFigure() { return TriangleFigure; }
