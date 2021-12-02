#include "window.hpp"

class QuestType2 : public Window {


    Buttons Buttons;
    PicturetoView Picture;
    int questionVariantID1;
    int questionVariantID2;
    questanswerClass questanswer;
public:
    QuestType2(float w, float h, int qtyButtons);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();

};
