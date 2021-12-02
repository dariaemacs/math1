#include "window.hpp"
class QuestType6 : public Window {
    Buttons Buttons;
    PicturetAndFilmtoView coin1;
    PicturetAndFilmtoView coin2;
    questanswerClass questanswer;
public:
    QuestType6(float, float, int);
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();

};