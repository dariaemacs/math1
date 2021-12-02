#include "window.hpp"
class QuestType5 : public Window {
    Buttons Buttons;
    questanswerClass questanswer;
public:
    QuestType5(float, float, int);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};