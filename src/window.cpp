#include "window.hpp"
#include "database.hpp"
//#include "figures.hpp"

#include <iostream>
#include <sstream>
#include <locale>

#include <vector>
#include "settings.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "database.hpp"
#include <fstream>
#include <locale>


bool Window::first = false;
extern const int ELAPSED_TIME;


int Window::width=0;
int Window::height=0;


std::wstring get_wstr(int i) {
  std::stringstream ss;
  //ss << (i + 1) << ". ";
  ss << 1 << ". ";
  std::string str = ss.str();

  std::wstring ws(str.begin(), str.end());
  ws += questionFigure[i].questionText.c_str();

  return ws;
}

bool NumberButtons::click(std::shared_ptr<sf::RenderWindow>& w) {
  //    int x, y, width, height;
  for (int i = 0; i < ButtonCount; ++i) {
    const sf::Vector2f& position = Buttons[i]->getPosition();
    const sf::IntRect& rect = Buttons[i]->getTextureRect();
    int x0 = position.x;
    int y0 = position.y;
    int x1 = x0 + rect.width* scale;
    int y1 = y0 + rect.height * scale;



    const sf::Vector2i& M = sf::Mouse::getPosition(*w);
    x1 = x1;
    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
      std::string fileName = "";
      std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
      sf::Texture CheckButtonTexture;
        sf::Sprite CheckButtonSprite(CheckButtonTexture);

      if (ButtonPressID >= 0) {
        fileName = "resources/images/digit" + std::to_string(ButtonPressID + 1) + ".jpg";
        MyTexture[ButtonPressID]->loadFromFile(fileName); ButtonPressID = -1;
      }
      fileName = "resources/images/digit" + std::to_string(i + 1) + "_select.jpg";
      ButtonPressID = i;

      MyTexture[i]->loadFromFile(fileName);
      
          //w->draw(*Buttons[i]);
          //w->display();
      return true;

    }
    //Buttons = Buttons.get()+1;

  }
  return false;

}

NumberButtons::NumberButtons(int ButtonCount, int windowheight) {
  this->ButtonCount = ButtonCount;
  using namespace std;
  int ButtonSlideHeght = Window::height / 3;

  

  //ButtonSlideHeght =  Window::height / 3;


  int ButtonSlideWidth = Window::width * 2 / 3;
  int ButtonSize = 0;
  int marginLeft = 0;
  int step = 0;



      //one row of button 
  
      ButtonSize = ButtonSlideWidth / ButtonCount ;
      step = ButtonSize / 4;
      ButtonSize = ButtonSize - step;
      while (ButtonSize + 10 > ButtonSlideHeght)  ButtonSize--;
      
      int ButtonMarginTop = (Window::height - ButtonSize)-5;
      if (ButtonCount > 10) ButtonMarginTop = Window::height - (ButtonSize * 2 + step);
     
    for (int i = 0; i < ButtonCount; i++) {
      std::string fileName = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
      std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
      txt->loadFromFile(fileName);
      static sf::Vector2u PICTURESIZE = txt->getSize();
      std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
      sprite->setTexture(*txt.get());
      scale = (float)ButtonSize / PICTURESIZE.y;
      sprite->setScale(scale, scale);
    
      const sf::IntRect& rect = sprite->getTextureRect();
      //ButtonMarginTop = windowheight - (rect.height * Settings::ButtonFactor);
      
      sprite->move(marginLeft, ButtonMarginTop);
      marginLeft = marginLeft + ButtonSize + step  ;
      if (i % 10 == 0 && i > 0) {
          ButtonMarginTop = ButtonMarginTop + ButtonSize + step; marginLeft= 0;
      }
      MyTexture.emplace_back(std::move(txt));
      Buttons.emplace_back(std::move(sprite));
    
    }
 
  
  //fout.close();  
}






TextFrameBase::TextFrameBase(int s, int quest) {
  size = s;

  font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
  text = sf::Text("", font, s);
  text.setFillColor(sf::Color::Black);
  text.setString(get_wstr(quest));
  //  text.setStyle(sf::Text::Bold);
  text.setPosition(Settings::PADDING, Settings::PADDING);
}



Window::Window(int w, int h, int numberQuest)
  : 
    textFrame(Settings::QUESTFONTSIZE, numberQuest) {
    width = w;
    height = h;






  std::string CheckButtonPictureFileName = "resources/images/arrow_disable.png";
  CheckButtonTexture.loadFromFile(CheckButtonPictureFileName);
  CheckButtonSprite.setTexture(CheckButtonTexture);
  CheckButtonSprite.scale(Settings::ButtonFactor, Settings::ButtonFactor);
  const sf::IntRect& CheckButtonRect = CheckButtonSprite.getTextureRect();
  int CheckButtonWidth = CheckButtonRect.width * Settings::ButtonFactor;
  CheckButtonSprite.move(width - CheckButtonWidth, 0);
  //
  List.setSize(sf::Vector2f(width, height));
  List.setPosition(0, 0);
  List.setFillColor(sf::Color::White);
  sf::Clock clock;
  
  sf::ContextSettings settings(0,0,8);
  

  //if (!first) {
  window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w, h), "Game");//,  sf::Style::Fullscreen);
    window->setFramerateLimit(Settings::FPS);


  
}


bool QuestType1::check(int c,int t, int r ) {
  switch (questionFigure[questNumber].key)
    {
    case circle:
        
      if (c == Buttons.GetButtonsClickID() + 1)
        return true;
      break;
    case triangle:
      if (t  == Buttons.GetButtonsClickID() + 1)
        return true;
      break;
    case square:
        if (r == Buttons.GetButtonsClickID() + 1)
            return true;
        break;
    default:
      break;
    }



  return false;
}

bool Window::checkandnextQuest() {
    
  const sf::Vector2f& position = CheckButtonSprite.getPosition();
  const sf::IntRect& rect =      CheckButtonSprite.getTextureRect();
  int x0 = position.x;
  int y0 = position.y;
  int x1 = x0 + rect.width * Settings::ButtonFactor;
  int y1 = y0 + rect.height * Settings::ButtonFactor;
  const sf::Vector2i& M = sf::Mouse::getPosition(*window);
  if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {

    return true;
  }
  return false;
}

QuestType1::QuestType1(int w, int h, int questNumber, int qtyButtons) :
  Window(w, h, questNumber),
  Buttons(qtyButtons, h),
  questNumber(questNumber)
{
  sf::Clock clock;
  sf::Time time_since_last_click = sf::Time::Zero;
  FrameFigure::resetnumber_of_figure();
  CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png"); 
  CheckButtonSprite.setTexture(CheckButtonTexture);
  
  const std::vector<FrameFigure*> figures =
  {
      new Car(window), 
      new Flower(window),
      new Tree(window),
      new Butterfly(window),
      new Plane(window),
      new Tower(window),
  };

  int fig1 = (rand() % figures.size());
  int fig2 = 0;
  while ((fig2 = (rand() % figures.size())) == fig1);
 
  int rectengleQTY = figures[fig1]->getrectengleQTY() + figures[fig2]->getrectengleQTY();
  int triangleQTY = figures[fig1]->gettriangleQTY() + figures[fig2]->gettriangleQTY();
  int circleQTY = figures[fig1]->getcircleQTY()+ figures[fig2]->getcircleQTY();


  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        //button click: 
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            time_since_last_click = clock.restart();
            sf::Int32 milli = time_since_last_click.asMilliseconds();
            milli = milli;
            if (readyforCheck && checkandnextQuest()) {
                if (check(circleQTY, triangleQTY, rectengleQTY))  textFrame.settext("Good");   else  textFrame.settext("Not good");
            }
            if (milli > ELAPSED_TIME) {

                milli = milli;
                if (Buttons.click(window)) { 
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }

            }
        }


       
    
    }

    //CheckButtonTexture.de;
    
    
    window->clear();
    
    window->draw(List);
    window->draw(textFrame.gettext());
    for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        window->draw(*Buttons.getButtons()[bc]);
    
    figures[fig1]->draw();
    figures[fig2]->draw();
    window->draw(CheckButtonSprite);
    window->display();



    




  }
}
