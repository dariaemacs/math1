#ifndef setofpictureObject_H
#define setofpictureObject_H
#include "PicturetoView.hpp";

class setofpictureObject : public PicturetoView {
    bool isAdd;

public:
    setofpictureObject(Window& w)
    void CalcucateCoordinate(int);
    void setisAdd();
    int click(int, setofpictureObject&);

};
#endif //setofpictureObject
