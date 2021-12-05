squareBoard::squareBoard(float ww, float hh, Window& wl) : w(ww), h(hh), questFigure(wl.getQuestNumber()), squareWidth(0), alreadyDraw(false),
CheckPoint{ 10,10,10,10,10,10 },
WindowLink(wl), CurrentClickpoint(-1)

{
    marginLeft = ww * 5 / 100;
    marginTop = hh / 9;
    squareWidth = (h - marginTop) / NN;
    for (int i = 0; i < 6; i++) {
        CheckPoint[i].setSb(this);
        CheckPoint[i].setFillColor(color::blue);
    }
    for (int i = 0; i < NN + 1; i++)
    {
        HorizLine.push_back(sf::RectangleShape());
        HorizLine[i].setSize(sf::Vector2f(ww - 2 * marginLeft, 1));
        HorizLine[i].setFillColor(color::slategray);
    }
    widthsqareBord = w - marginLeft * 2;
    heightsqareBord = h - marginTop;
    MM = widthsqareBord / ((h - marginTop) / NN);
    for (int i = 0; i < MM; i++)
    {
        VertLine.push_back(sf::RectangleShape());
        VertLine[i].setSize(sf::Vector2f(1, 8 * hh / 9));
        VertLine[i].setFillColor(color::slategray);
    };


    for (unsigned int i = 0; i < CheckPoint.size(); i++)
        CheckPoint[i].setFillColor(sf::Color::Blue);

    CheckPoint[0].setPosition(0, 0);
    CheckPoint[1].setPosition(0, 1);
    CheckPoint[2].setPosition(0, 2);

    CheckPoint[3].setPosition(1, 0);
    CheckPoint[4].setPosition(1, 1);
    CheckPoint[5].setPosition(1, 2);
    ////std::cout << question7Text[questFigure].key << std::endl;
    float ax, bx;
    float ay, by;
    int fig = question7Text[questFigure].key;
    //
    switch (fig) {


    case triangle:
        VARIANT = rand() % 13;

        ax = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getPixelCoord().x + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        ay = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getPixelCoord().y + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        //(int)(getSize() / 2)
        bx = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].j].getPixelCoord().x + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        by = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].j].getPixelCoord().y + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        firstpointInput_i = question7trianglevariantOfFirstLine[VARIANT].i;
        firstpointInput_j = question7trianglevariantOfFirstLine[VARIANT].j;



        break;

    case rectangle:
        VARIANT = rand() % 7;
        ax = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        ay = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);

        bx = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        by = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        firstpointInput_i = question7rectanglevariantOfFirstLine[VARIANT].i;
        firstpointInput_j = question7rectanglevariantOfFirstLine[VARIANT].j;


        break;

    case square:
        VARIANT = rand() % 7;
        ax = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        ay = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);

        bx = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        by = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
        firstpointInput_i = question7rectanglevariantOfFirstLine[VARIANT].i;
        firstpointInput_j = question7rectanglevariantOfFirstLine[VARIANT].j;
        break;


    }
    addLine(ax, ay, bx, by, sf::Color::Green);
    addChekpointInput(firstpointInput_i, firstpointInput_j);

};
//void squareBoard::(float ax, float ay, float bx, float by) {
void squareBoard::viewVariant(const long long figuraCoord) {


    int i = 0;
    long long currentLine = 0;
    int length = log10(figuraCoord) + 1;
    long long Tentodegree;
    float ax, bx;
    float ay, by;
    for (int i = 0; (Tentodegree = pow(10, static_cast<int>(log10(figuraCoord) + 1) - 2 * (i + 1))) >= 1; i++) {
        currentLine = figuraCoord / Tentodegree;
        currentLine = currentLine - (static_cast<long long>(currentLine / 100)) * 100;
        ax = CheckPoint[currentLine / 10].getPixelCoord().x + (CheckPoint[currentLine / 10].getSize() / 2);
        ay = CheckPoint[currentLine / 10].getPixelCoord().y + (CheckPoint[currentLine / 10].getSize() / 2);
        bx = CheckPoint[(currentLine % 10)].getPixelCoord().x + (CheckPoint[(currentLine % 10)].getSize() / 2);
        by = CheckPoint[(currentLine % 10)].getPixelCoord().y + (CheckPoint[(currentLine % 10)].getSize() / 2);
        addLine(ax, ay, bx, by, sf::Color::Red);
    }
}
void squareBoard::addLine(float ax, float ay, float bx, float by, sf::Color Color) {
    line.push_back(MyVertexArray());
    size_t size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax, ay);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx, by);
    line[size][1].color = Color;


    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax + 0.5f, ay + 0.5f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx + 0.5f, by + 0.5f);
    line[size][1].color = Color;

    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax - 0.5f, ay - 0.5f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx - 0.5f, by - 0.5f);
    line[size][1].color = Color;

    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax + 1.0f, ay + 1.0f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx + 1.0f, by + 1.0f);
    line[size][1].color = Color;

    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax - 1.0f, ay - 1.0f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx - 1.0f, by - 1.0f);
    line[size][1].color = Color;


}

void squareBoard::setMargintop(float mt) {
    marginTop = mt;
}

float squareBoard::getMargintop() { return marginTop; }
float squareBoard::getMarginLeft() { return marginLeft; }
float squareBoard::getsquareWidth() { return squareWidth; }
void squareBoard::setquestFigure(int qf) { questFigure = qf; }


int squareBoard::getquestFigure() {
    return questFigure;
}
unsigned long long squareBoard::getResult() { return result; }
float squareBoard::getwidthsqareBord() { return widthsqareBord; };
int squareBoard::getCurrentClickpoint() { return CurrentClickpoint; };
std::array<point, 6>& squareBoard::getCheckPoint() { return CheckPoint; }
sf::VertexArray squareBoard::getLastline() { return line[line.size() - 1]; };
void squareBoard::dellLastline() {
    if (line.size() > 5 && (!line[line.size() - 1].getHold())) for (int i = 0; i < 5; i++) line.pop_back();
};
void squareBoard::sortChekpointInput() {
    sort(ChekpointInput.begin(), ChekpointInput.end());
    ChekpointInput.erase(unique(ChekpointInput.begin(), ChekpointInput.end()), ChekpointInput.end());
}
void squareBoard::printChekpointInput() {
    result = 0;
    if (ChekpointInput.size() > 0)
        for (unsigned int i = 0; i < ChekpointInput.size(); i++) {
            result = result * 100 + ChekpointInput[i];
        }

    std::cout << result << ",";
    //std::cout << std::endl;
};
void squareBoard::addChekpointInput(int a, int b) {
    if ((a == 0 && b == 2) || (a == 2 && b == 0)) { addChekpointInput(0, 1); addChekpointInput(1, 2); return; }
    if ((a == 3 && b == 5) || (a == 5 && b == 3)) { addChekpointInput(5, 4); addChekpointInput(4, 3); return; }
    ChekpointInput.push_back(maximal(a, b) * 10 + minimal(a, b));
};
int squareBoard::getVariant() { return VARIANT; };

