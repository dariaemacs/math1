#include "window.hpp"
#include "PicturetoView11.hpp"
#include "CheckButton11.hpp"

class QuestType11 : public window {
    CheckButton11 checkbutton;
    PicturetoView11 picture1;
    PicturetoView11 picture2;
    int question11Variant1ID;
    int question11Variant2ID;
    int question11Variant3ID;

public:
    QuestType11(float, float);
    int getquestion11Variant1ID() { return question11Variant1ID; }
    int getquestion11Variant2ID() { return question11Variant2ID; }
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};