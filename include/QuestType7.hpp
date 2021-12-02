#include "window.hpp"
class QuestType7 : public Window {
    squareBoard sB;
    sf::Texture    EraseButtonTexture;
    sf::Sprite     EraseButtonSprite;

public:
    QuestType7(float, float);
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