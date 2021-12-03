#include "MyVertexArray.hpp"
MyVertexArray::MyVertexArray() : hold(false), sf::VertexArray() { int uu = 90; };
void MyVertexArray::setHold() { hold = true; }
bool MyVertexArray::getHold() { return hold; }