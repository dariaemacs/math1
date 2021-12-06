#ifndef PicturetoView_H
#define PicturetoView_H

#include "SimpleButtons.hpp"
class QuestType2;


class PicturetoView : public SimpleButtons {
public:    
    PicturetoView(window& , std::string);
    PicturetoView(window&);
    void CalcucateCoordinate();
    bool click();
    void setpictureFilename(std::string);
protected:
    std::string pictureFilename;
    std::vector<bool> isblackSide;
};
#endif //PicturetoView_H
