#include "PicturetoView.hpp"
#include "QuestType2.hpp"
#include "window.hpp"
class PicturetAndFilmtoView : public PicturetoView {
    float coinWidth;
    float coinHeight;

public:
    PicturetAndFilmtoView(Window& w) : PicturetoView(w) {}
    void CalcucateCoordinate();
    bool click();
    float getcoinWidth() { return coinWidth; }
    //protected: std::string pictureFilename;
};