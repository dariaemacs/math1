#include "Buttons.hpp"
#include "QuestType2.hpp"

class Window;


class PicturetoView : public Buttons {
protected:
    std::string pictureFilename;
    std::vector<bool> isblackSide;

public:
    PicturetoView(Window& w);
    PicturetoView(QuestType2&, std::string);
    void CalcucateCoordinate();
    void setpictureFilename(std::string fn);
    bool click();
};
