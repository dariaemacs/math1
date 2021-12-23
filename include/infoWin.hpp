#ifndef infoWin_H
#define infoWin_H

#include "window.hpp"
#include "SimpleButtons.hpp"
class infoWin : public window {


    SimpleButtons Buttons;
    //float check(float, float, float);
    //int questionVariantID1;
    //int questionVariantID2;

public:
    infoWin(float w, float h);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};
#endif 