#include "window.hpp"
#include "SimpleButtons.hpp"
#include "questanswerClass.hpp"

class QuestType4 : public window {


    SimpleButtons Buttons;

    int questionVariantID1;
    int questionVariantID2;
    questanswerClass questanswer;

public:
    QuestType4(float, float, int);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();

};
