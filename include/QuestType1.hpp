#include "window.hpp"
#include "SimpleButtons.hpp"
class QuestType1 : public Window {


    SimpleButtons Buttons;
    float check(float, float, float);
    int questionVariantID1;
    int questionVariantID2;

public:
    QuestType1(float w, float h, int qtyButtons);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};