#include "window.hpp"

class QuestType10 : public Window {
    CheckButton checkbutton;
    int question10Variant1ID;
    int question10Variant2ID;

public:
    QuestType10(float, float);
    int getquestion10Variant1ID() { return question10Variant1ID; }
    int getquestion10Variant2ID() { return question10Variant2ID; }

    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};