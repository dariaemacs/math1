#ifndef setofpictureObject_H1
#define setofpictureObject_H1
#include "PicturetoView.hpp"

class setofpictureObject : public PicturetoView {
    bool isAdd;

public:
    setofpictureObject(window& w);
    void CalcucateCoordinate(int);
    void setisAdd();
    int click(int, setofpictureObject&);

};
#endif //setofpictureObject
