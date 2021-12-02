#include "window.hpp"
class QuestType3 : public Window {


    Buttons Buttons;
    PicturetoViewQuestWithBasket  PictureAndBasket;
    questanswerClass questanswer;

public:
    QuestType3(float, float, int);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};