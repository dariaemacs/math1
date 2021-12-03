#include "CheckButton.hpp"
class CheckButton11 : public CheckButton {
protected:
    float spacing;
    unsigned char answerNUMBER;

public:
    CheckButton11(Window& w) :CheckButton(w), answerNUMBER(0) {}
    void resetclickID();
    void SetSpacing(float);
    unsigned char getanswerNUMBER();
    bool click(int);
    bool isAnswerRight(int, int, int);
};