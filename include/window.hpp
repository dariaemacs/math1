#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "settings.hpp"
#include "pica.hpp"
#include "figures.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <array>

#include <SFML/Graphics.hpp>

class Window;



class Buttons {
  bool touched{ false };
  bool pressed{ false };
  bool released{ true };

protected:
    Window& WindowLink;
    float scale;
    int ButtonCount;
    int ButtonPressID = -1;
    int margin_top;
    int margin_left;
    int height;
    int width;
    std::vector<std::shared_ptr<sf::Texture>> MyTexture;
    std::vector<std::unique_ptr<sf::Sprite>> ButtonsList;
        
public:
  Buttons(int , Window&);
  Buttons( Window&);
  void setButtonCount(int bc) { 
      ButtonCount = bc; 
  }
  void CalcucateCoordinate();
  void setMargin_top(int margin) { 
      margin_top = margin; 
  }

  void setMargin_left(int margin) {
      margin_left = margin;
  }

  std::vector<std::unique_ptr<sf::Sprite>>& getButtons() { return 
      ButtonsList;
  }
  bool  click();
  int getButtonCount() { return ButtonCount; }
  std::vector<std::shared_ptr<sf::Texture>>& getButtonTexture() { return MyTexture; }
  int GetButtonsClickID() { return ButtonPressID; }

  int getMarginTop() {
      return margin_top; 
  }
  float getScale() {
      return scale;
  }

  void setScale(float s) {
      scale = s;
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
  int size;
  int w;
  int h;
  Window& WindowLink;
protected: 
    int questionNumber;

public: 
  TextFrameBase(int ,  Window& w ,char); //delegate
  TextFrameBase(int ,int , int,int, Window& ) ;
  TextFrameBase(int s, std::wstring str, int w, int h, Window&);
  sf::Text gettext(){ 
      return text; 
  }
 // void setwinLink(Window &w) { WindowLink = w; }
  void settext(std::wstring a) { text.setString(a);}
  void setmargin_top(int m);
  void CalcucateCoordinate(int, int);
  void setWidth(int);
  int getHeight();
  void setN_M(int,int);
  void setquestionNumber(int qn) { questionNumber=qn; }


};

class Mysf_text : public  sf::Text {
    int size;
    public:
        Mysf_text(int s) : size(s) {}
    void CalcucateCoordinate(float,float);
    int getSize() {return size;}
};


class Window {
   bool first;
  

  
   int width;  
   int height; 
  double coef;
  int space;
  int number; 
  int ordQuestNumber;
  


  
protected:
    
  int questNumber;
  TextFrameBase textFrame;
  bool checkandnextQuest(float);
  std::shared_ptr<sf::RenderWindow> window; 
  sf::Texture CheckButtonTexture;
  sf::Sprite CheckButtonSprite;
  sf::RectangleShape List;
  TextFrameBase QuestComment;

  bool readyforCheck; 
public:
    friend  std::wstring get_wstr(int questvariantIndex);
  
  Window(int w, int h, int questNumber, int);
  int getWidth() { return width; }
  int getHeight() { return height; }
  int getQuestNumber(){ return questNumber; }
  int getordQuestNumber() { return ordQuestNumber; }
  std::shared_ptr<sf::RenderWindow> getWindow() { return window; }
  ~Window() {
      int yyy = 0;
  }
  friend Buttons;
  friend TextFrameBase;
  
};



class QuestType1: public Window { 
   

  Buttons Buttons;

  int check(int,int,int);
public:
    QuestType1(int w, int h,  int qtyButtons);
    QuestType1(int fig1, int fig2,  int w, int h,  int qtyButtons);
    //~QuestType1();
};


class QuestionBase {
  TextFrameBase txt;
};

class QuestType2;
class PicturetoView : public Buttons {
protected:
    std::string pictureFilename;
    std::vector<bool> isblackSide;

public:
    PicturetoView(Window& w) :  Buttons(0, w) {}
    PicturetoView(QuestType2&, std::string);
    void CalcucateCoordinate();
    void setpictureFilename(std::string fn) { pictureFilename = fn; }
    bool click();
};




class QuestType2 : public Window {

    //int QTY;
    Buttons Buttons;   
    PicturetoView Picture;
    
    //int check(int, int, int);
public:
    QuestType2(int w, int h,  int qtyButtons);

};

class PicturetoViewQuestWithBasket : public  PicturetoView {
    sf::Texture basketTexture;
    sf::Sprite basketSprite;
public:
    PicturetoViewQuestWithBasket(Window&);
    void CalcucateCoordinate();
    sf::Texture getBasketTexture() {
        return basketTexture;
    }
    sf::Sprite getBasketSprite() {
        return basketSprite;
    }

};

class QuestType3 : public Window {


    Buttons Buttons;
    PicturetoViewQuestWithBasket  PictureAndBasket;
    

public:
    QuestType3(int , int , int );

};

class TrainContainer {


};


class QuestType4 : public Window {


    Buttons Buttons;



public:
    QuestType4(int, int, int);

};
class QuestType5 : public Window {
    Buttons Buttons;
public:
    QuestType5(int, int, int);
};
//class QuestType6;
class PicturetAndFilmtoView : public PicturetoView {
    float coinWidth;
    float coinHeight;

public:
    PicturetAndFilmtoView(Window& w) : PicturetoView(w){}
    void CalcucateCoordinate();
    bool click();
    float getcoinWidth() { return coinWidth; }
//protected: std::string pictureFilename;
};

class QuestType6 : public Window {
    Buttons Buttons;
    PicturetAndFilmtoView coin1;
    PicturetAndFilmtoView coin2;
public:
    QuestType6(int, int, int);

};
class squareBoard;
struct coord { float x, y; coord(float xx, float yy) :x(xx), y(yy) {} };
class point : public sf::RectangleShape {
    
    float x, y; //coord in pixel
    float i, j;  //coord in board 
    float size; //size of point 
    squareBoard* Sb;
public:
    point(float);
    float getSize();
    void setSb(squareBoard* sBB);
    void setPosition(float, float);
    coord getPixelCoord();
    coord getBoardCoord();

};

class squareBoard {
    const float NN =30;//qty of horiz lines
          float MM; // this is qty of vert lines will calculate later
    float w, h , marginTop, marginLeft,
     widthsqareBord,
     heightsqareBord, squareWidth;
    int questFigure;
    bool alreadyDraw;
    std::vector<sf::RectangleShape> HorizLine;
    std::vector<sf::RectangleShape> VertLine;
    //sf::VertexArray * UserInputLine(sf::Lines, 2);
    std::vector < sf::VertexArray> line;
    std::vector<sf::RectangleShape> Line1;
   // sf::VertexArray lines(sf::Lines, 16);
    std::array<point,6> CheckPoint;
    std::vector<int> i1;
    Window& WindowLink;
    public:
        squareBoard(float , float , Window&);
       void draw();
       void setMargintop(float);
       float getMargintop();
       float getMarginLeft();
       float getsquareWidth();
       void setquestFigure(int);
       int getwidthsqareBord() { return widthsqareBord; }
       //std::vector<sf::VertexArray>& getUserInputLine() {return  UserInputLine;}
       int clickPoint();
       
};



class QuestType7 : public Window {
    squareBoard sB;

public:
    QuestType7(int, int);
    squareBoard& getsB() { return sB; }

};



#endif 
