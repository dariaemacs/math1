#ifndef QuestType10_H
#define QuestType10_H
#include "window.hpp"
#include "CheckButton.hpp"

class QuestType10 : public window {
    CheckButton checkbutton;
    int question10Variant1ID;
    int question10Variant2ID;

public:
    QuestType10();
    int getquestion10Variant1ID() { return question10Variant1ID; }
    int getquestion10Variant2ID() { return question10Variant2ID; }

    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};
#endif 