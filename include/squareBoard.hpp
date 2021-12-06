#ifndef squareBoard_H
#define squareBoard_H
#include "MyVertexArray.hpp"
#include "window.hpp"
#include "point.hpp"
class squareBoard {
    const float NN = 30;//qty of horiz lines
    float MM; // this is qty of vert lines will calculate later
    float w, h, marginTop, marginLeft,
        widthsqareBord,
        heightsqareBord, squareWidth;
    int questFigure;
    bool alreadyDraw;
    int CurrentClickpoint;
    std::vector<sf::RectangleShape> HorizLine;
    std::vector<sf::RectangleShape> VertLine;
    std::vector < MyVertexArray> line;
    std::array<point, 6> CheckPoint;
    std::vector < int> ChekpointInput;
    int firstpointInput_i;
    int firstpointInput_j;
    std::vector<int> i1;
    window& WindowLink;
    unsigned long long result;
    int VARIANT;
public:
    squareBoard(float, float, window&);
    void draw();
    void setMargintop(float);
    float getMargintop();
    float getMarginLeft();
    int getquestFigure();
    unsigned long long getResult();
    float getsquareWidth();
    void setquestFigure(int);
    float getwidthsqareBord();
    int getCurrentClickpoint();
    std::array<point, 6>& getCheckPoint();
    bool clickPoint(bool);
    void addLine(float, float, float, float, sf::Color);
    sf::VertexArray getLastline();
    void dellLastline();
    void sortChekpointInput();
    void printChekpointInput();
    void addChekpointInput(int a, int b);
    void eraseLines();
    bool isfigureInputright(const unsigned long long*);
    bool issegmentexsistinFigure(int);
    int getVariant();
    void viewVariant(const long long figuraCoord);
};
#endif
