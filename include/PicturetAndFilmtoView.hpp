#include "PicturetoView.hpp"
#include "QuestType2.hpp"
#include "window.hpp"
class PicturetAndFilmtoView : public PicturetoView {
    float coinWidth;
    float coinHeight;

public:
    PicturetAndFilmtoView(window& w);
    void CalcucateCoordinate();
    bool click();
    float getcoinWidth();
    //protected: std::string pictureFilename;
};