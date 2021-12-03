#include <vector>
#include <SFML/Graphics.hpp>

class SimpleImage {
    int padding;
    std::vector<sf::CircleShape>    CircleBaseFigure;
    std::vector<sf::RectangleShape> RectangleFigure;
    std::vector<sf::ConvexShape>    TriangleFigure;

    int CircleBaseFigureQTY;
    int RectangleFigureQTY;
    int TriangleBaseFigureQTY;

public:

    int getCircleBaseFigureQTY()                            ;
    int getRectangleFigureQTY()                             ;
    int getGetTriangleFigureQTY()                           ;
    std::vector<sf::CircleShape>& GetCircle()               ;
    std::vector<sf::RectangleShape>& GetRectangleFigure()   ;
    std::vector<sf::ConvexShape>& GetTriangleFigure()       ;

};