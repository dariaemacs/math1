#ifndef QuestType2_H
#define QuestType2_H

#include "window.hpp"



#include "PicturetoView.hpp";
#include "SimpleButtons.hpp";
#include "questanswerClass.hpp";

class QuestType2 : public Window {


    SimpleButtons Buttons;
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
#endif //QuestType2_H