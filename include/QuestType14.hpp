#ifndef QuestType14_H
#define QuestType14_H
#include "window.hpp"
#include "table3_5.hpp"
#include "questanswerClass.hpp"
#include "CheckButton11.hpp"

class QuestType14 : public window {

    int questionVariantID1;
    int questionVariantID2;
    int questionVariantID3;
    int questionVariantID4;
    int questionVariantID5;
    questanswerClass questanswer;
    CheckButton11 checkbutton;
    table3_5 tab;
public:
    QuestType14(float, float, int);
    int getquestionVariantID1() { return questionVariantID1; }
    int getquestionVariantID2() { return questionVariantID2; }
    int getquestionVariantID3() { return questionVariantID3; }
    int getquestionVariantID4() { return questionVariantID4; }
    int getquestionVariantID5() { return questionVariantID5; }
};
#endif 