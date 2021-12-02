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

#define maximal(a, b) (((a)>(b))?(a):(b))
#define minimal(a, b) (((a)<(b))?(a):(b))
#define three_minimal(a, b, c) minimal(minimal(a, b), c)

class Window;


class mySpriteCheckButton : public sf::Sprite {
    float top;
    float left;
    std::string fn;
    bool active;
public:
    mySpriteCheckButton() : fn("empty.jpg"), active(false) {};
    void setActive() {
        if (!active) fn = "select.png"; else fn = "empty.jpg";
        active = !active;
    };
    void setPicturefnm(std::string fnn) {
        fn = fnn;
        };

    std::string getFN();
    bool getActive();
    void setTop(float t);
    void setLeft(float l);
};
class CheckButton {
    int qty;
 
 
    sf::Font font;
    std::array<sf::Text, 4> str;
    std::array<sf::Texture,4>   quadroTexture;
    std::array<mySpriteCheckButton,4>   quadroSprite;
protected:
    int textmarginleft;
    int clickID;
    Window& wLnk;
    
    float margin_top;
    int rightQuestNum;
    protected:
    float qudroSize;
    float coeff;
    public:

    CheckButton(Window&);
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
    void setStrValue(int, std::wstring,int);
    int getrightQuestNum() { return rightQuestNum; }
    int getClickID() { return clickID; }
    std::array<sf::Texture, 4>& getquadroTexture();

};
class CheckButton11 : public CheckButton {
protected :
    float spacing; 
    unsigned char answerNUMBER;
    
public:
    CheckButton11(Window& w) :CheckButton( w),  answerNUMBER(0){}
    void resetclickID();
        void SetSpacing(float);
    unsigned char getanswerNUMBER();
    bool click(int);
    bool isAnswerRight(int , int , int);
};
class MyVertexArray : public sf::VertexArray {
    bool hold;
public:
    MyVertexArray() : hold(false), sf::VertexArray() { int uu = 90; };
    void setHold() { hold=true; }
    bool getHold() { return hold; }
};

class questanswerClass {
    sf::RenderTexture miniwindow;
    sf::Text text;
    std::vector <sf::Texture> quadroTexture;
    std::vector <sf::Sprite>  quadroSprite;
    int quadroQTY;
    float width;
    float height ;
    float scale;
public:
    void setParams(float ww, float hh, int q, float sscale) {
        width = ww;
        height = hh;
        quadroQTY = q;
        scale = sscale;
        miniwindow.create(static_cast<int>(ww), static_cast<int>(hh));
        
        for (int i = 0; i < quadroQTY; i++) {
            quadroTexture.push_back(sf::Texture());
            quadroSprite.push_back(sf::Sprite());
            quadroSprite[i].setScale(scale,scale);
            quadroSprite[i].setPosition(i * 500 * scale, 0);
            //quadroSprite[i].setPosition(i * 500 * scale, 0);
        }
    }
    sf::Texture& operator[](int index) { return quadroTexture[index]; }
    void draw() {
        for (int i = 0; i < quadroQTY; i++) {
            miniwindow.draw(quadroSprite[i]);
            quadroSprite[i].setTexture(quadroTexture[i]);
            miniwindow.draw(quadroSprite[i]);
        }
    
    }
    sf::RenderTexture& getminiwindow() {  
        //miniwindow.clear(sf::Color::Red);
        //for (int i = 0; i < quadroQTY; i++) miniwindow.draw(quadroSprite[0]); 
        miniwindow.display();
        return miniwindow; }
    float getHeight() { return height; }
    float getWidth() { 
        return width; 
    }
    float getScale() {
        return scale;
    }

};
class Buttons {
  bool touched{ false };
  bool pressed{ false };
  bool released{ true };

protected:
    Window& WindowLink;
    float scale;
    int ButtonCount;
    int ButtonPressID = -1;
    float margin_top;
    float margin_left;
    float height;
    float width;
    std::vector<std::shared_ptr<sf::Texture>> MyTexture;
    std::vector<std::unique_ptr<sf::Sprite>> ButtonsList;
        
public:
  Buttons(int , Window&);
  Buttons( Window&);
  void setButtonCount(int bc) { 
      ButtonCount = bc; 
  }
  void CalcucateCoordinate();
  void CalcucateCoordinate(float);
  void setMargin_top(float margin) { 
      margin_top = margin; 
  }



  void setMargin_left(float margin) {
      margin_left = margin;
  }

  std::vector<std::unique_ptr<sf::Sprite>>& getButtons() { return 
      ButtonsList;
  }
  bool  click();
  int getButtonCount() { return ButtonCount; }
  std::vector<std::shared_ptr<sf::Texture>>& getButtonTexture() { return MyTexture; }
  int GetButtonsClickID() { return ButtonPressID; }

float getMarginTop() {
      return margin_top; 
  }
  float getScale() {
      return scale;
  }

  void setScale(float s) {
      scale = s;
  }
 float getHeight() {
            return height;
  }

  float getWidth() {
      return width;
  }

 float getMarginLeft() { 
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
  float size;
  float w;
  float h;
  float margin_top;
  Window& WindowLink;
protected: 
    int questionNumber;

public: 
  TextFrameBase(float ,  Window& winLink,char); //delegate
  TextFrameBase(float ,int , int,int, Window& ) ;
  TextFrameBase(float s, std::wstring str, float, float , Window&);
  sf::Text gettext(){ 
      return text; 
  }
 // void setwinLink(Window &w) { WindowLink = w; }
  void settext(std::wstring a) { text.setString(a);}
  void setmargin_top(float m);
  float getmargin_top() {
      return margin_top; 
  }
  void CalcucateCoordinate(float, float);
  void setWidth(int);
  float getHeight();
  void setN_M(int,int);
  void setquestionNumber(int qn) { questionNumber=qn; }
  float getSize() { 
      return size; 
  }


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
  

  
   float width;  
   float height; 
  double coef;
  int space;
  int number; 
  int ordQuestNumber;


 
protected:
  bool badAnswer;
  int questNumber;
  TextFrameBase textFrame;
  bool checkandnextQuest(float);
  std::shared_ptr<sf::RenderWindow> window; 
  sf::Texture ArrowButtonTexture;
  sf::Sprite ArrowButtonSprite;
  sf::RectangleShape List;
  TextFrameBase QuestComment;
  int countofBALL;
  bool readyforCheck; 
public:
    //friend  std::wstring get_wstr(int questvariantIndex);
  
  Window(float w, float h, int questNumber, int);
  float getWidth() { return width; }
  float getHeight() { return height; }
  int getQuestNumber(){ return questNumber; }
  int getordQuestNumber() { return ordQuestNumber; }
  TextFrameBase gettextFrame() { return textFrame; }
  std::shared_ptr<sf::RenderWindow> getWindow() { return window; }

  virtual   int getquestionVariantID1() = 0;
  virtual   int getquestionVariantID2() = 0;
  virtual   int getquestionVariantID3() = 0;
  virtual   int getquestionVariantID4() = 0;
  virtual   int getquestionVariantID5() = 0;

  ~Window() {




  }
  friend Buttons;
  friend TextFrameBase;
  
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
    PicturetoView(Window& w) : Buttons(0, w) {}
    PicturetoView(QuestType2&, std::string);
    void CalcucateCoordinate();
    void setpictureFilename(std::string fn) { pictureFilename = fn; }
    bool click();
};


class PicturetoView11 : public PicturetoView {

public:
    PicturetoView11(Window& w) : PicturetoView(w) {
    
    }
    void CalcucateCoordinate(float w);
    bool click();
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



class TrainContainer {


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

class setofpictureObject : public PicturetoView {
    bool isAdd;

public:
    setofpictureObject(Window& w) : PicturetoView(w), isAdd(false){}
    void CalcucateCoordinate(int);
    void setisAdd() { isAdd = true; }
    int click(int, setofpictureObject&);
    
};


class squareBoard;
struct coord { float x, y; coord(float xx, float yy) :x(xx), y(yy) {}; coord() :x(0), y(0) {}; };
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
    int CurrentClickpoint; 
    std::vector<sf::RectangleShape> HorizLine;
    std::vector<sf::RectangleShape> VertLine;
    std::vector < MyVertexArray> line;
    std::array<point,6> CheckPoint;    
    std::vector < int> ChekpointInput;
    int firstpointInput_i;
    int firstpointInput_j;

    std::vector<int> i1;
    Window& WindowLink;
    unsigned long long result;
    int VARIANT ;
    public:
        squareBoard(float , float , Window&);
       void draw();
       void setMargintop(float);
       float getMargintop();
       float getMarginLeft();
       int getquestFigure() {
           return questFigure;
       }
       unsigned long long getResult() { return result; }
       float getsquareWidth();
       void setquestFigure(int);
       float getwidthsqareBord() { return widthsqareBord; };
       int getCurrentClickpoint(){ return CurrentClickpoint; };
       std::array<point, 6>& getCheckPoint() { return CheckPoint; }
       //std::vector<sf::VertexArray>& getUserInputLine() {return  UserInputLine;}
       bool clickPoint(bool);
       void addLine(float , float, float, float,sf::Color);
       sf::VertexArray getLastline() {  return line[line.size()-1]; };
       void dellLastline() {
           if (line.size()>5 && (!line[line.size()-1].getHold())) for (int i = 0; i < 5; i++) line.pop_back();
       };
       void sortChekpointInput(){
       sort(ChekpointInput.begin(), ChekpointInput.end());
       ChekpointInput.erase(unique(ChekpointInput.begin(), ChekpointInput.end()), ChekpointInput.end());
       }
       void printChekpointInput() {
           result = 0;
           if (ChekpointInput.size() > 0) 
               for (unsigned int i = 0; i < ChekpointInput.size(); i++) {
               result = result * 100 + ChekpointInput[i] ;
           }
               
               std::cout<< result <<",";
           //std::cout << std::endl;
       };
       void addChekpointInput(int a,int b) {
           if ((a == 0 && b == 2) || (a == 2 && b == 0)) { addChekpointInput(0, 1); addChekpointInput(1, 2); return; }
           if ((a == 3 && b == 5) || (a == 5 && b == 3)) { addChekpointInput(5, 4); addChekpointInput(4, 3); return; }
           ChekpointInput.push_back(maximal(a, b) * 10 + minimal(a, b));
       };
       void eraseLines();
       bool isfigureInputright(const unsigned long long*);
       bool issegmentexsistinFigure(int);
       int getVariant() { return VARIANT; };

       void viewVariant(const long long figuraCoord);
};







class table {

    float mash_koeff;
    float mash_width;
    float mash_height;
    float mash_x;
    float mash_y;
    float tablemax_y;

protected:

    std::array < sf::VertexArray, 5> verticalline;
    std::array < sf::VertexArray, 5> horizline;
    std::array < sf::Text, 6> text;
    sf::Font font;
    Window& WindowLink;
    public:
        table(Window&);
        void draw();
        float getmash_koeff() { 
            return mash_koeff; 
};

        float getmash_width() {
            return mash_width;
        };
        float getmash_height() {
            return mash_height;
        };
        float gettablemax_y() {
            return tablemax_y;
        };
        float getmash_x() { return  mash_x; }
        float getmash_y() { return  mash_y; }

};


class table3_5  {
    std::array < sf::Text, 6> Celltext;
    float mash_koeff;
    float mash_width;
    float mash_height;
    float mash_x;
    float mash_y;
    float tablemax_y;
    float fontSize;
    float height0Row;
    float margintop;
protected:

    std::array < sf::VertexArray, 5> verticalline;
    std::array < sf::VertexArray, 5> horizline;
    std::array < sf::Text, 6> text;
    sf::Font font;
    Window& WindowLink;
public:
    float getheight0Row() {
        return height0Row;
    };
    float getmash_koeff() {
        return mash_koeff;
    };
    float getmargintop() {
        return margintop;
    };
    float getmash_width() {
        return mash_width;
    };
    float getmash_height() {
        return mash_height;
    };
    float gettablemax_y() {
        return tablemax_y;
    };
    float getmash_x() { return  mash_x; }
    float getmash_y() { return  mash_y; }

    public: 
        table3_5(Window&);
        void calcFontSize(const int w, const int h);
        void draw();

};
#endif 
