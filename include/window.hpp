#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "settings.hpp"
#include "pica.hpp"
#include "figures.hpp"

#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class NumberButtons {
  int ButtonCount;
  float scale;
  std::vector<std::shared_ptr<sf::Texture>> MyTexture;
  std::vector<std::unique_ptr<sf::Sprite>> Buttons;
  int ButtonPressID=-1;
  int margin_top;
  int margin_left;
  int height;
  int width;

         
  bool touched  {false};
  bool pressed  {false};
  bool released {true};
        
public:
  NumberButtons(int qtyButton);
  void CalcucateCoordinate();
  void setMargin_top(int margin) { 
      margin_top = margin; 
  }
  std::vector<std::unique_ptr<sf::Sprite>>& getButtons() { return Buttons; }
  bool  click(std::shared_ptr<sf::RenderWindow>&);
  int getButtonCount() { return ButtonCount; }
  std::vector<std::shared_ptr<sf::Texture>>& getButtonTexture() { return MyTexture; }
  int GetButtonsClickID() { return ButtonPressID; }
  int getMarginTop() {
      return margin_top; 
  }
  int getHeight() {
      return height;
  }

  int getMarginLeft() { 
      return margin_left; 
  }
};


class SimpleImage {
  int padding;
  std::vector<sf::CircleShape>    CircleBaseFigure;
  std::vector<sf::RectangleShape> RectangleFigure;
  std::vector<sf::ConvexShape>    TriangleFigure; 

  int CircleBaseFigureQTY;
  int RectangleFigureQTY;
  int TriangleBaseFigureQTY;

public: 
   
  int getCircleBaseFigureQTY() { return CircleBaseFigureQTY; }
  int getRectangleFigureQTY()  { return RectangleFigureQTY; }
  int getGetTriangleFigureQTY() { return TriangleBaseFigureQTY; }
  std::vector<sf::CircleShape>& GetCircle() { return CircleBaseFigure; }
  std::vector<sf::RectangleShape>& GetRectangleFigure() { return RectangleFigure; }
  std::vector<sf::ConvexShape>& GetTriangleFigure() { return TriangleFigure; }

};


class TextFrameBase {
  

  sf::Text text;
  sf::Font font;
//protected:
  int size;
  int w;
  int h;
protected: 
    int questionNumber;

public: 
  TextFrameBase(int ,char); //delegate
  TextFrameBase(int ,int , int,int) ;
  TextFrameBase(int s, std::wstring str, int w, int h);
  sf::Text gettext(){ 
      return text; 
  }
  void settext(std::wstring a) { text.setString(a);}
  void setmargin_top(int m);
  void CalcucateCoordinate(int, int);
  void setWidth(int);
  void setN_M(int,int);
  void setquestionNumber(int qn) { questionNumber=qn; }


};

class Window {
   bool first;
  

  
  static int width;  
  static int height; 
  double coef;
  int space;
  int number; 




  
protected:
    int questNumber;
  TextFrameBase textFrame;
  bool checkandnextQuest();
  std::shared_ptr<sf::RenderWindow> window; 
  sf::Texture CheckButtonTexture;
  sf::Sprite CheckButtonSprite;
  sf::RectangleShape List;
  TextFrameBase QuestComment;

  bool readyforCheck; 
public:

  
  Window(int w, int h, int questNumber);
  ~Window() {
      int yyy = 0;
  }
  friend NumberButtons;
  friend TextFrameBase;
  
};



class QuestType1: public Window { 
   
    static int QTY;
  NumberButtons Buttons;

  int check(int,int,int);
public:
    QuestType1(int w, int h,  int qtyButtons);
    QuestType1(int fig1, int fig2,  int w, int h,  int qtyButtons);
    //~QuestType1();
};


class QuestionBase {
  TextFrameBase txt;
};

class QuestType2 : public Window {

    static int QTY;
    NumberButtons Buttons;   
    //int check(int, int, int);
public:
    QuestType2(int w, int h,  int qtyButtons);

};


#endif // WINDOW_HPP
