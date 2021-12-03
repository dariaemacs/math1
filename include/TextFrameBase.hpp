#include <SFML/Graphics.hpp>
class Window;
class TextFrameBase {


    sf::Text text;
    sf::Font font;
    float size;
    float w;
    float h;
    float margin_top;
    Window& WindowLink;
protected:
    int questionNumber;

public:
    TextFrameBase(float, Window& winLink, char); //delegate
    TextFrameBase(float, int, int, int, Window&);
    TextFrameBase(float s, std::wstring str, float, float, Window&);
    sf::Text gettext();
    // void setwinLink(Window &w) { WindowLink = w; }
    void settext(std::wstring a);
    void setmargin_top(float m);
    float getmargin_top() {
        return margin_top;
    }
    void CalcucateCoordinate(float, float);

    float getHeight();
    void setN_M(int, int);
    void setquestionNumber(int qn) { questionNumber = qn; }
    float getSize() {
        return size;
    }


};
