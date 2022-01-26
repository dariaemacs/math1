#include "QuestType7.hpp"
#include "database.hpp"

int QuestType7::getquestionVariantID1() { return 0; }
int QuestType7::getquestionVariantID2() { return 0; }
int QuestType7::getquestionVariantID3() { return 0; }
int QuestType7::getquestionVariantID4() { return 0; }
int QuestType7::getquestionVariantID5() { return 0; }

bool QuestType7::IsclearButtonClick() {
    const sf::Vector2i& M = sf::Mouse::getPosition(*getWindow());
    const sf::Vector2f& position = EraseButtonSprite.getPosition();
    const sf::IntRect& rect = EraseButtonSprite.getTextureRect();
    ////std::cout << scale << rect.width << std::endl;
    float x0 = position.x;
    float y0 = position.y;
    float x1 = x0 + rect.width;
    float y1 = y0 + rect.height;


    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
        ////std::cout << "rect height = " << rect.height << " " << M.x << "*" << x0 << " " << M.x << "*" << x1 << " " << M.y << "*" << y0 << " " << M.y << "*" << y1 << std::endl;
        return true;
    }
    return false;

}

void QuestType7::ViewRightAnswer(int figura) {
    switch (figura)
    {
    case triangle:

        for (int i = 0; i < sizeof(question7AnswersTriangle) / sizeof(*question7AnswersTriangle); i++)
            if (getLinefromVariant(question7trianglevariantOfFirstLine[sB.getVariant()].i * 10 +
                question7trianglevariantOfFirstLine[sB.getVariant()].j
                , question7AnswersTriangle[i]) > 0) {

                //draw Variant
                std::cout << question7trianglevariantOfFirstLine[sB.getVariant()].i * 10 +
                    question7trianglevariantOfFirstLine[sB.getVariant()].j << " draw Variant " << question7AnswersTriangle[i] << std::endl;
                sB.viewVariant(question7AnswersTriangle[i]);
                break;
            }
        break;


    case rectangle:
        for (int i = 0; i < sizeof(question7AnswersRectangle) / sizeof(*question7AnswersRectangle); i++)
            if (getLinefromVariant(question7rectanglevariantOfFirstLine[sB.getVariant()].i * 10 +
                question7rectanglevariantOfFirstLine[sB.getVariant()].j
                , question7AnswersRectangle[i]) > 0) {

                //draw Variant
                std::cout << question7rectanglevariantOfFirstLine[sB.getVariant()].i * 10 +
                    question7rectanglevariantOfFirstLine[sB.getVariant()].j << " draw Variant " << question7AnswersRectangle[i] << std::endl;
                sB.viewVariant(question7AnswersRectangle[2]);
                break;
            }
        break;


    case square:
        //getLinefromVariant(question7squarevariantOfFirstLine[sB.getVariant()].i * 10 +
        //    question7squarevariantOfFirstLine[sB.getVariant()].j
        //    , question7AnswersRectangle[0]);

        for (int i = 0; i < sizeof(question7AnswersSquare) / sizeof(*question7AnswersSquare); i++)
            if (getLinefromVariant(question7rectanglevariantOfFirstLine[sB.getVariant()].i * 10 +
                question7rectanglevariantOfFirstLine[sB.getVariant()].j
                , question7AnswersSquare[i]) > 0) {
                std::cout << question7rectanglevariantOfFirstLine[sB.getVariant()].i * 10 +
                    question7rectanglevariantOfFirstLine[sB.getVariant()].j << " draw Variant " << question7AnswersSquare[0] << std::endl;
                sB.viewVariant(question7AnswersSquare[i]);
                break;
                //draw Variant
            }

        break;
    }
}

QuestType7::QuestType7() :
    window(gameClass::getWidth(), gameClass::getHeight(), ((rand() % 3)), 6),
    sB(gameClass::getWidth(), gameClass::getHeight(), *this) {
    bool first = true;
    int margintopSlideButton = 0;
    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);

    EraseButtonTexture.loadFromFile("resources/images/clear.png");
    EraseButtonSprite.setTexture(EraseButtonTexture);
    EraseButtonSprite.setPosition(sf::Vector2f(width - 128, height - 128));

    sB.setquestFigure(question7Text[getQuestNumber()].key);
    QuestComment.settext(L"");

    gameClass::setmarks(6, 0);

    sf::Event event;
    bool trydrawLine = false;
    while (win->isOpen()) {

        win->clear();



        win->draw(List);


        win->draw(textFrame.gettext());
        win->draw(ArrowButtonSprite);
        win->draw(EraseButtonSprite);
        win->draw(QuestComment.gettext());
        sB.draw();





        DrawGameTime();
        win->display();

        while (win->pollEvent(event)) {

            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor)) {
                    sB.sortChekpointInput();
                    sB.printChekpointInput();
                    switch (sB.getquestFigure())
                    {
                    case triangle:
                        if (sB.isfigureInputright(question7AnswersTriangle)) { QuestComment.settext(CommentsDic[1]);  gameClass::setmarks(6, 1); }
                        else { QuestComment.settext(CommentsDic[2]); ViewRightAnswer(sB.getquestFigure()); gameClass::setmarks(6, 0); }
                        break;


                    case rectangle:
                        if (sB.isfigureInputright(question7AnswersRectangle)) QuestComment.settext(CommentsDic[1]);
                        else {
                            QuestComment.settext(CommentsDic[2]); ViewRightAnswer(sB.getquestFigure());
                            gameClass::setmarks(6, 0);
                        }
                        break;


                    case square:
                        if (sB.isfigureInputright(question7AnswersSquare)) QuestComment.settext(CommentsDic[1]);
                        else {
                            QuestComment.settext(CommentsDic[2]); ViewRightAnswer(sB.getquestFigure());
                            gameClass::setmarks(6, 0);
                        }
                        break;
                    };
                    QuestComment.setmargin_top(height - QuestComment.getHeight() - 50);

                    wasAnswer = true;
                }
                if (IsclearButtonClick()) {

                    sB.eraseLines();

                };
                sB.clickPoint(trydrawLine); trydrawLine = false;
                ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png");
                readyforCheck = true;
                ArrowButtonSprite.setTexture(ArrowButtonTexture);



            }
            int CurrentClickpointID = sB.getCurrentClickpoint();
            if (CurrentClickpointID >= 0) {
                coord XY;
                XY = sB.getCheckPoint()[CurrentClickpointID].getPixelCoord();
                const sf::Vector2i& M = sf::Mouse::getPosition(*win);
                sf::VertexArray VA = sB.getLastline();

                sB.dellLastline();
                float szPoint = sB.getCheckPoint()[0].getSize() / 2;
                sB.addLine(XY.x + szPoint, XY.y + szPoint, M.x + szPoint, M.y + szPoint, sf::Color::Green);
                trydrawLine = true;

            }
        }
        if (wasAnswer && afterAsk()) return;
    }

    //srand(time(0));
}

int QuestType7::getLinefromVariant(char ln, const long figuraCoord) {
    //while (figuraCoord>0)

    long long currentLine = 0;
    int length = log10(figuraCoord) + 1;
    long long Tentodegree;

    for (int i = 0; (Tentodegree = pow(10, static_cast<int>(log10(figuraCoord) + 1) - 2 * (i + 1))) >= 1; i++) {

        currentLine = figuraCoord / Tentodegree;
        currentLine = currentLine - (static_cast<long long>(currentLine / 100)) * 100;
        if (currentLine == ln) return 555;
    }
    return 0;
}