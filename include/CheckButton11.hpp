#ifndef CheckButton11_H
#define CheckButton11_H
// ����� ���� ���������� ���� h-����

#include "CheckButton.hpp"
class CheckButton11 : public CheckButton {
protected:
    float spacing;
    unsigned char answerNUMBER;

public:
    CheckButton11(Window& w);
    void resetclickID();
    void SetSpacing(float);
    unsigned char getanswerNUMBER();
    bool click(int);
    bool isAnswerRight(int, int, int);
};

#endif //CheckButton11_H