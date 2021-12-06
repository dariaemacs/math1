#ifndef CheckButton_H
#define CheckButton_H



#include <SFML/Graphics.hpp>
#include "mySpriteCheckButton.hpp"
#include <array>




class window;
class CheckButton {
    int qty;
    sf::Font font;
    std::array<sf::Text, 4> str;
    std::array<sf::Texture, 4>   quadroTexture;
    std::array<mySpriteCheckButton, 4>   quadroSprite;
protected:
    int textmarginleft;
    int clickID;
    window& wLnk;

    float margin_top;
    int rightQuestNum;
protected:
    float qudroSize;
    float coeff;
public:

    CheckButton(window&);
    int GenerateRandomSetNumber();

    //int GenerateRandomSet();
    void setTextValue(int);
    std::array<mySpriteCheckButton, 4>& getSprite();
    std::array<sf::Text, 4>& getText();
    float getTextmarginleft();
    float getHeightText();
    float getWidthText(int);
    bool  click();
    sf::Font& getFont();
    float getQudroSize();
    float getcoeff();
    void Set_margitop(float);
    void SetqudroSize(float);
    void setStrValue(int, std::wstring, int);
    int getrightQuestNum() { return rightQuestNum; }
    int getClickID() { return clickID; }
    std::array<sf::Texture, 4>& getquadroTexture();

};
#endif //CheckButton_H