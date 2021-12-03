#include <SFML/Graphics.hpp>

class MyVertexArray : public sf::VertexArray {
    bool hold;
public:
    MyVertexArray() ;
    void setHold();
    bool getHold();
};