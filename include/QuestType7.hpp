#ifndef QuestType7_H
#define QuestType7_H
#include "window.hpp"
#include "squareBoard.hpp"
class QuestType7 : public window {
    squareBoard sB;
    sf::Texture    EraseButtonTexture;
    sf::Sprite     EraseButtonSprite;

public:
    QuestType7();
    squareBoard& getsB() { return sB; };
    int getLinefromVariant(char ln, const long figuraCoord);
    void ViewRightAnswer(int figura);
    //int getLinefromVariant(char ln, const long figuraCoord);
    bool IsclearButtonClick();
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};

#endif //QuestType7_H