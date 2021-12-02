#include "window.hpp"
class QuestType15 : public Window {
    Buttons buttons;
    int questionVariantID1;
    int questionVariantID2;
    int questionVariantID3;
    int questionVariantID4;
    int questionVariantID5;
    questanswerClass questanswer;
    table3_5 tab;
public:
    QuestType15(float, float, int);
    int getquestionVariantID1() { return questionVariantID1; }
    int getquestionVariantID2() { return questionVariantID2; }
    int getquestionVariantID3() { return questionVariantID3; }
    int getquestionVariantID4() { return questionVariantID4; }
    int getquestionVariantID5() { return questionVariantID5; }
};