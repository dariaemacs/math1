#include "window.hpp"
#include "questanswerClass.hpp"
#include "SimpleButtons.hpp"

class QuestType12 : public window {
    SimpleButtons Buttons;
    questanswerClass questanswer;
public:
    QuestType12(float, float, int);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};