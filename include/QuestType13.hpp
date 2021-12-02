#include "window.hpp"

class QuestType13 : public Window {
    CheckButton11 checkbutton;
    int questionVariantID1;
    int questionVariantID2;
    int questionVariantID3;
public:
    QuestType13(float, float);
    QuestType13(int w, int h, int a, int b);
    int getquestionVariantID1() { return questionVariantID1; }
    int getquestionVariantID2() { return questionVariantID2; }
    int getquestionVariantID3() { return questionVariantID3; }
    int getquestionVariantID4() { return 0; }
    int getquestionVariantID5() { return 0; }
};