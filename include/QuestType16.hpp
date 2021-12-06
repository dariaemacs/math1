#include "window.hpp"
#include "SimpleButtons.hpp"
#include "questanswerClass.hpp"
#include "table3_5.hpp"

class QuestType16 : public window {
    SimpleButtons buttons;
    int questionVariantID1;
    int questionVariantID2;
    int questionVariantID3;
    int questionVariantID4;
    int questionVariantID5;
    questanswerClass questanswer;
    table3_5 tab;
public:
    QuestType16(float, float, int);
    int getquestionVariantID1() { return questionVariantID1; }
    int getquestionVariantID2() { return questionVariantID2; }
    int getquestionVariantID3() { return questionVariantID3; }
    int getquestionVariantID4() { return questionVariantID4; }
    int getquestionVariantID5() { return questionVariantID5; }
};