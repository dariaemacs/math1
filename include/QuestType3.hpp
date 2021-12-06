#ifndef QuestType3_H
#define QuestType3_H
#include "window.hpp"
#include "SimpleButtons.hpp"
#include "PicturetoViewQuestWithBasket.hpp"
#include "questanswerClass.hpp"

class QuestType3 : public window {


    SimpleButtons Buttons;
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
#endif 