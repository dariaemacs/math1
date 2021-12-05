#ifndef PicturetoView_H
#define PicturetoView_H

#include "SimpleButtons.hpp"
#include "QuestType2.hpp"


class PicturetoView : public SimpleButtons {
public:    
    //PicturetoView(QuestType2& , std::string);
    PicturetoView(Window& w);
    void CalcucateCoordinate();
    bool click();
protected:
    std::string pictureFilename;
    std::vector<bool> isblackSide;
};
#endif //PicturetoView_H
