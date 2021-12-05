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
#include "TextFrameBase.hpp";

#define maximal(a, b) (((a)>(b))?(a):(b))
#define minimal(a, b) (((a)<(b))?(a):(b))
#define three_minimal(a, b, c) minimal(minimal(a, b), c)


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



  
};

#endif 
