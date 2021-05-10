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


//bool Window::first = false;
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

    } else std::cout << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 << std::endl;
    //Buttons = Buttons.get()+1;

  }
  return false;

}

NumberButtons::NumberButtons(int BC):ButtonCount(BC){}
void NumberButtons::CalcucateCoordinate() {
    using namespace std;
    int ButtonSlideHeght = Window::height - margin_top;
    int step = 0;
    

    int  ButtonSize = Window::width / 11;
    ButtonSize = (Window::width / 11) * 2 / 3;
    step = ButtonSize / 5;
  
    while (ButtonSize + 10 > ButtonSlideHeght / 2) ButtonSize--;
    int marginLeft = Window::width - 11 * (ButtonSize + step);
    for (int i = 0; i < ButtonCount; i++) {
        std::string fileName = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
        std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
        txt->loadFromFile(fileName);
        static sf::Vector2u PICTURESIZE = txt->getSize();
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*txt.get());
        scale = (float)ButtonSize / PICTURESIZE.y;
        sprite->setScale(scale, scale);
        
        sprite->move(marginLeft, margin_top);
        if (i % 10 == 0 && i > 0) {
            margin_top = margin_top + ButtonSize+ step - 15; marginLeft = Window::width - 11 * (ButtonSize + step);
        } else marginLeft = marginLeft + ButtonSize + step;
        MyTexture.emplace_back(std::move(txt));
        Buttons.emplace_back(std::move(sprite));
    };

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
  : first(true),
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
  std::string comment = std::string("Game "  )+ std::to_string(w) + "x" + std::to_string(h);
  window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w, h), comment);//,  sf::Style::Fullscreen);
    window->setFramerateLimit(Settings::FPS);

    //window->~RenderWindow();


  
}


int QuestType1::check(int c,int t, int r ) {
  switch (questionFigure[questNumber].key)
    {
    case circle:
        
        if (c == Buttons.GetButtonsClickID() + 1)
            return -1; else  return c;
      break;
    case triangle:
      if (t  == Buttons.GetButtonsClickID() + 1)
          return -1; else  return t;
      break;
    case rectangle:
        if (r == Buttons.GetButtonsClickID() + 1)
            return -1; else  return r;
        break;
    default:
      break;
    }



  return -1;
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
  Buttons(qtyButtons),
  questNumber(questNumber)
{
    bool first = true;
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

  sf::Event event;
  while (window->isOpen()) {
    
    //std::cout << "yyy" << std::endl;
    while (window->pollEvent(event)) {
        
        if (event.type == sf::Event::Closed) {
            std::cout << "yyy888" << std::endl;
            window->close();
            
        }
        
        //button click: 
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "yyy1234" << std::endl;
            std::cout << "yyy111" << std::endl;
            if (readyforCheck && checkandnextQuest()) {
                int rightfigurCount = check(circleQTY, triangleQTY, rectengleQTY);
                if (rightfigurCount < 0)  textFrame.settext("Good");   else {
                    textFrame.settext("Not good");

                    Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                        "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                    Buttons.getButtonTexture()[rightfigurCount - 1]->loadFromFile(
                        "resources/images/digit" + std::to_string(rightfigurCount) + "_right.jpg"
                    );

                }

            }

            if (Buttons.click(window)) {
                std::cout << "test" << std::endl;
                CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                CheckButtonSprite.setTexture(CheckButtonTexture);
               

            }
        }






        //CheckButtonTexture.de;


        window->clear();

        window->draw(List);
        window->draw(textFrame.gettext());


        figures[fig1]->draw();
        figures[fig2]->draw();

        int margintopSlideButton =
            (
            (figures[fig1]->getymax() * figures[fig1]->getkoef() > figures[fig2]->getymax()* figures[fig2]->getkoef() ? figures[fig1]->getymax() * figures[fig1]->getkoef() : figures[fig2]->getymax() * figures[fig2]->getkoef())
                ) + (figures[fig1]->getmargin_top() > figures[fig2]->getmargin_top() ? figures[fig1]->getmargin_top() : figures[fig2]->getmargin_top());
        Buttons.setMargin_top(margintopSlideButton + 10);
        if (first) Buttons.CalcucateCoordinate(); first = false;
       for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
            window->draw(*Buttons.getButtons()[bc]);
        window->draw(CheckButtonSprite);

        window->display();

    }

    




  }
}
