#include "window.hpp"
#include "SimpleButtons.hpp"
#include "questanswerClass.hpp"
class QuestType5 : public window {
    SimpleButtons Buttons;
    questanswerClass questanswer;
public:
    QuestType5(float, float, int);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};