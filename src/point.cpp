#include "point.hpp"
point::point(float sz) :x(0), y(0), i(0), j(0), Sb(0), size(sz), sf::RectangleShape() {
    sf::RectangleShape::setPosition(0, 0);
    sf::RectangleShape::setSize(sf::Vector2f(sz, sz));

}

coord point::getPixelCoord() {
    return coord(x, y);
};
coord point::getBoardCoord() {
    return coord(i, j);
};

float point::getSize() { return size; }
void point::setSb(squareBoard* sBB) { Sb = sBB; }
void point::setPosition(float ii, float jj) {
    float tmp = Sb->getsquareWidth();
    float squarefromVertical = Sb->getwidthsqareBord() / Sb->getsquareWidth();
    float point0 = (squarefromVertical - 28) / 2;
    i = ii;
    j = jj;
    x = Sb->getMarginLeft() + (point0 + 14 * jj) * Sb->getsquareWidth() - static_cast<unsigned int>(getSize() / 2);
    y = Sb->getMargintop() + (6 + 14 * ii) * Sb->getsquareWidth() - static_cast<unsigned int>(getSize() / 2);
    sf::RectangleShape::setPosition(x, y);
}
