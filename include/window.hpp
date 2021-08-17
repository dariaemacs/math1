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
    
    std::array<sf::Texture, 4>& getquadroTexture();

};
class CheckButton11 : public CheckButton {
protected :
    float spacing; 
    float margin_top;
    unsigned char answerNUMBER;
    
public:
    CheckButton11(Window& w) :CheckButton( w), margin_top(0), answerNUMBER(0){}
    void resetclickID();
    void setStrValue(int, std::wstring);
    void SetqudroSize(float);
    void SetSpacing(float);
    void Set_margitop(float);
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
    void setParams(float ww, float hh, int q, float scale) {
        width = ww;
        height = hh;
        quadroQTY = q;
        scale = scale;
        miniwindow.create(ww, hh);
        
        for (int i = 0; i < quadroQTY; i++) {
            quadroTexture.push_back(sf::Texture());
            quadroSprite.push_back(sf::Sprite());
            quadroSprite[i].setScale(scale,scale);
            quadroSprite[i].setPosition(i * 500 * scale, 0);
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
    float getWidth() { return width; }

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
  void CalcucateCoordinate(float);
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
      std::cout<< "hhhhhhhh=" << height << std::endl;
      return height;
  }

  int getWidth() {
      return width;
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
  float margin_top;
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
  float getmargin_top() {
      return margin_top; 
  }
  void CalcucateCoordinate(int, int);
  void setWidth(int);
  int getHeight();
  void setN_M(int,int);
  void setquestionNumber(int qn) { questionNumber=qn; }
  int getSize() { 
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
  

  
   int width;  
   int height; 
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
  sf::Texture CheckButtonTexture;
  sf::Sprite CheckButtonSprite;
  sf::RectangleShape List;
  TextFrameBase QuestComment;
  int countofBALL;
  bool readyforCheck; 
public:
    friend  std::wstring get_wstr(int questvariantIndex);
  
  Window(int w, int h, int questNumber, int);
  int getWidth() { return width; }
  int getHeight() { return height; }
  int getQuestNumber(){ return questNumber; }
  int getordQuestNumber() { return ordQuestNumber; }
  TextFrameBase gettextFrame() { return textFrame; }
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

class PicturetoView11 : public PicturetoView {

public:
    PicturetoView11(Window& w) : PicturetoView(w) {
    
    }
    void CalcucateCoordinate(float w);
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

class setofpictureObject : public PicturetoView {
    bool isAdd;

public:
    setofpictureObject(Window& w) : PicturetoView(w), isAdd(false){}
    void CalcucateCoordinate(int);
    void setisAdd() { isAdd = true; }
    int click(int, setofpictureObject&);
    
};

class QuestType6 : public Window {
    Buttons Buttons;
    PicturetAndFilmtoView coin1;
    PicturetAndFilmtoView coin2;
public:
    QuestType6(int, int, int);

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
    public:
        squareBoard(float , float , Window&);
       void draw();
       void setMargintop(float);
       float getMargintop();
       float getMarginLeft();
       int getquestFigure() {
           return questFigure;
       }
       int getResult() { return result; }
       float getsquareWidth();
       void setquestFigure(int);
       int getwidthsqareBord() { return widthsqareBord; };
       int getCurrentClickpoint(){ return CurrentClickpoint; };
       std::array<point, 6>& getCheckPoint() { return CheckPoint; }
       //std::vector<sf::VertexArray>& getUserInputLine() {return  UserInputLine;}
       bool clickPoint(bool);
       void addLine(float , float, float, float);
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
           if (ChekpointInput.size() > 0) for (int i = 0; i < ChekpointInput.size(); i++) {
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
       
};



class QuestType7 : public Window {
    squareBoard sB;
    sf::Texture    EraseButtonTexture;
    sf::Sprite     EraseButtonSprite;

public:
    QuestType7(int, int);
    squareBoard& getsB() { return sB; }
    bool IsclearButtonClick();
};


class QuestType8 : public Window {
    setofpictureObject setofpic0;
    setofpictureObject setofpic1;
    setofpictureObject setofpic2;
    setofpictureObject setofpic3;

    setofpictureObject plus;
    setofpictureObject minus;
    int thingsCount;

    //setofpictureObject setofpic4;
    //setofpictureObject setofpic5;
    
    
public:
    QuestType8(int, int);
  
};
class table {
    std::array < sf::VertexArray,5> verticalline;
    std::array < sf::VertexArray,4> horizline;
    std::array < sf::Text, 6> text;
    sf::Font font;
    Window& WindowLink;
    float mash_koeff;
    float mash_width;
    float mash_height;
    float mash_x;
    float mash_y;
    float tablemax_y;
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
class QuestType9 : public Window {
    table tab;
    Buttons Buttons;
    std::array<sf::Texture,13> MashTexture;
    std::array<sf::Sprite,13>  MashSprite;

    std::array<sf::Texture, 16> BerryTexture;
    std::array<sf::Sprite, 16>  BerrySprite;

    std::array<sf::Texture, 12> LeafTexture;
    std::array<sf::Sprite, 12>  LeafSprite;
    questanswerClass questanswer;
public:
    QuestType9(int, int, int);
    std::array<sf::Sprite,13> getMashsprite() { return MashSprite; }
    std::array<sf::Sprite,16> getMBerryprite() { return BerrySprite; }
    std::array<sf::Sprite,12> getLeafsprite() { return LeafSprite; }
};

class QuestType10 : public Window {
    CheckButton checkbutton;
    int question10Variant1ID;
    int question10Variant2ID;

public:
    QuestType10(int, int);
    int getquestion10Variant1ID() { return question10Variant1ID; }
    int getquestion10Variant2ID() { return question10Variant2ID; }
};

class QuestType11 : public Window {
    CheckButton11 checkbutton;
    PicturetoView11 picture1;
    PicturetoView11 picture2;
    int question11Variant1ID;
    int question11Variant2ID;
    int question11Variant3ID;

public:
    QuestType11(int, int);
    int getquestion11Variant1ID() { return question11Variant1ID; }
    int getquestion11Variant2ID() { return question11Variant2ID; }
};

#endif 
