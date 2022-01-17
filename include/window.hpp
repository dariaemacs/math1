#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "settings.hpp"
#include "pica.hpp"
#include "figures.hpp"
#include "TextFrameBase.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "gameClass.hpp"




float maximal(float , float );
float minimal(float , float );
float three_minimal(float , float , float );

std::wstring get_wstr(int, int);

class window {
   bool first;
  


  double coef;
  int space;
  int number; 
  int ordQuestNumber;

  sf::Clock clock;
  int QTYofBLINK; 
  bool isNextQuest;

 
protected:

    float width;
    float height;
  bool badAnswer;
  int questNumber;
  TextFrameBase textFrame;
  bool checkandnextQuest(float);
  std::shared_ptr<sf::RenderWindow> win; 
  sf::Texture ArrowButtonTexture;
  sf::Sprite ArrowButtonSprite;
  sf::RectangleShape List;
  TextFrameBase QuestComment;
  sf::Sprite  TimeSpriteRect;
  sf::Texture TimeTextureRect;
  sf::Text timestringView;
  sf::Font timestringViewFont;

  int countofBALL;
  bool readyforCheck;
  bool wasAnswer;
public:
    //friend  std::wstring get_wstr(int questvariantIndex);
  
  window(float w, float h, int questNumber, int);
  float getWidth();
  float getHeight();
  int getQuestNumber();
  int getordQuestNumber();
  TextFrameBase gettextFrame();
  std::shared_ptr<sf::RenderWindow> getWindow();
  void refreshGameTime();
  bool afterAsk();
  void DrawGameTime();

  virtual   int getquestionVariantID1() = 0;
  virtual   int getquestionVariantID2() = 0;
  virtual   int getquestionVariantID3() = 0;
  virtual   int getquestionVariantID4() = 0;
  virtual   int getquestionVariantID5() = 0;



  
};

#endif 
