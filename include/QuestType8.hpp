#ifndef QuestType8_H
#define QuestType8_H

#include "window.hpp"
#include "setofpictureObject.hpp"

class QuestType8 : public window {
    setofpictureObject setofpic0;
    setofpictureObject setofpic1;
    setofpictureObject setofpic2;
    setofpictureObject setofpic3;

    setofpictureObject plus;
    setofpictureObject minus;
    int thingsCount;

    //setofpictureObject setofpic4;
    //setofpictureObject setofpic5;


public:
    QuestType8();
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};
#endif