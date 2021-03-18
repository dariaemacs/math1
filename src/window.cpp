#include "window.hpp"
#include "database.hpp"
#include "figures.hpp"

#include <iostream>
#include <sstream>
#include <locale>

#include <vector>
#include "settings.hpp"
#include <SFML/Graphics.hpp>
#include "database.hpp"
#include <fstream>
#include <locale>


bool Window::first = false;
extern const int ELAPSED_TIME;
//extern const std::array<figureQestions, N> questionFigure;


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
    int x1 = x0 + rect.width * Settings::ButtonFactor;
    int y1 = y0 + rect.height * Settings::ButtonFactor;



    const sf::Vector2i& M = sf::Mouse::getPosition(*w);
    x1 = x1;
    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
      std::string fileName = "";
      /*sf::Texture CheckButtonTexture;
        sf::Sprite CheckButtonSprite;*/

      if (ButtonPressID >= 0) {
        fileName = "resources/images/digit" + std::to_string(ButtonPressID + 1) + ".jpg";
        MyTexture[ButtonPressID]->loadFromFile(fileName); ButtonPressID = -1;
      }
      fileName = "resources/images/digit" + std::to_string(i + 1) + "_select.jpg";
      ButtonPressID = i;

      MyTexture[i]->loadFromFile(fileName);
      return true;

    }
    //Buttons = Buttons.get()+1;

  }
  return false;
}

NumberButtons::NumberButtons(int ButtonCount, int windowheight) {
  this->ButtonCount = ButtonCount;
  using namespace std;
  int ButtonMarginTop = 0;
  //ofstream fout;
  //  fout.open("out.txt");


  if (ButtonCount<11) {
    //fout<< "test"<<  std::endl;
  
    for (int i = 0; i < ButtonCount; i++) {
      std::string fileName = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
      std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
      txt->loadFromFile(fileName);

      std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
      sprite->setTexture(*txt.get());
      sprite->setScale(Settings::ButtonFactor, Settings::ButtonFactor);
    
      const sf::IntRect& rect = sprite->getTextureRect();
      ButtonMarginTop = windowheight - (rect.height * Settings::ButtonFactor);
      sprite->move(100 * i, ButtonMarginTop);
      MyTexture.emplace_back(std::move(txt));
      Buttons.emplace_back(std::move(sprite));
    
    }
  }
  else {
    int ButtonCountString1LastIndex = 10;
    int ButtonCountString2FirstIndex = ButtonCountString1LastIndex ;
    int ButtonCountString2LastIndex = ButtonCount ;
    
    int i=0;
    for (i = 0; i < ButtonCountString1LastIndex; i++) {
      std::string fileName = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
      std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
      txt->loadFromFile(fileName);
    
      //fout<< "ButtonCountString2="<<ButtonCountString2 << std::endl;
      std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
      sprite->setTexture(*txt.get());
      sprite->setScale(Settings::ButtonFactor, Settings::ButtonFactor);
    
      const sf::IntRect& rect = sprite->getTextureRect();
      ButtonMarginTop = windowheight - (10+2*(rect.height * Settings::ButtonFactor));
      //fout<< "i="<<i <<" " <<ButtonMarginTop<< std::endl;
      sprite->move(100 * i, ButtonMarginTop);
      MyTexture.emplace_back(std::move(txt));
      Buttons.emplace_back(std::move(sprite));
    }
    //string #2
    int c = 0 ;
    for (int i =  ButtonCountString2FirstIndex; i < ButtonCountString2LastIndex; i++) {
      std::string fileName = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
      std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
      txt->loadFromFile(fileName);
    
      //fout<< "ButtonCountString2="<<ButtonCountString2 << std::endl;
      std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
      sprite->setTexture(*txt.get());
      sprite->setScale(Settings::ButtonFactor, Settings::ButtonFactor);
    
      const sf::IntRect& rect = sprite->getTextureRect();
      ButtonMarginTop = windowheight - (10+(rect.height * Settings::ButtonFactor));

  
  
      sprite->move(100 * c++, ButtonMarginTop);
      MyTexture.emplace_back(std::move(txt));
      Buttons.emplace_back(std::move(sprite));
      //fout<< "i="<<i <<" " <<ButtonMarginTop<< std::endl;
    }

  
  }
  //fout.close();  
}




SimpleImage::SimpleImage(const std::vector<pica>& fig, int paddingleft) {
  //(*fig)[0]
  CircleBaseFigureQTY = 0; RectangleFigureQTY = 0; TriangleBaseFigureQTY = 0;


  for (size_t i = 0; i < fig.size(); ++i)
    {
      switch (fig[i].type)
        {
        case circle:  CircleBaseFigure.emplace_back(sf::CircleShape(fig[i].r)); CircleBaseFigureQTY++;
          CircleBaseFigure.back().move(fig[i].x0 + paddingleft, fig[i].y0 + Settings::TEXTFRAMHEIGHT);
          CircleBaseFigure.back().setFillColor(fig[i].FillColor);
          CircleBaseFigure.back().setOutlineColor(fig[i].outlineColor);
          CircleBaseFigure.back().setOutlineThickness(fig[i].OutlineThickness);
          CircleBaseFigure.back().rotate(fig[i].angle);
          break;

        case triangle:  TriangleFigure.emplace_back(sf::ConvexShape(3)); TriangleBaseFigureQTY++;
          TriangleFigure.back().setPoint(0, sf::Vector2f(fig[i].x0, fig[i].y0));
          TriangleFigure.back().setPoint(1, sf::Vector2f(fig[i].x1, fig[i].y1));
          TriangleFigure.back().setPoint(2, sf::Vector2f(fig[i].x2, fig[i].y2));
          TriangleFigure.back().setFillColor(fig[i].FillColor);
          TriangleFigure.back().setOutlineColor(fig[i].outlineColor);
          TriangleFigure.back().setOutlineThickness(fig[i].OutlineThickness);
          TriangleFigure.back().move(paddingleft, Settings::TEXTFRAMHEIGHT);
          break;

        case rectangle:  RectangleFigure.emplace_back(sf::RectangleShape(sf::Vector2f(fig[i].width, fig[i].height))); RectangleFigureQTY++;
          RectangleFigure.back().move(fig[i].x0 + paddingleft, fig[i].y0 + Settings::TEXTFRAMHEIGHT);
          //RectangleFigure.back().move(fig[i].x + paddingleft, fig[i].y + Settings::TEXTFRAMHEIGHT);
          RectangleFigure.back().setFillColor(fig[i].FillColor);
          RectangleFigure.back().setOutlineColor(fig[i].outlineColor);
          RectangleFigure.back().setOutlineThickness(fig[i].OutlineThickness);

          RectangleFigure.back().rotate(fig[i].angle);
          break;


        default:
          break;
        }


    }

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
  : width(w), height(h),
    textFrame(Settings::QUESTFONTSIZE, numberQuest) {


  double xcoef = width / Settings::WIDTH;
  double ycoef = height / Settings::HEIGHT;
  coef = xcoef > ycoef ? xcoef : ycoef;




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
  //sf::Time time_since_last_click = sf::Time::Zero;

  if (!first) {
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w, h), "Game");//, sf::Style::Fullscreen);
    window->setFramerateLimit(Settings::FPS);

    first = true;
  }

}


bool QuestType1::check() {
  switch (questionFigure[questNumber].key)
    {
    case circle:
      if ((img1.getCircleBaseFigureQTY() + img2.getCircleBaseFigureQTY()) == Buttons.GetButtonsClickID() + 1)
        return true;
      break;
    case triangle:
      if ((img1.getGetTriangleFigureQTY() + img2.getGetTriangleFigureQTY()) == Buttons.GetButtonsClickID() + 1)
        return true;
      break;
    case square:
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

QuestType1::QuestType1(int w, int h, int questNumber, const std::vector<pica>& fig1, const std::vector<pica>& fig2, int qtyButtons) :
  Window(w, h, questNumber),
  img1(fig1, 30), img2(fig2, Settings::IMGPADDINGLEFT),
  Buttons(qtyButtons, h),
  questNumber(questNumber)
{
  sf::Clock clock;
  sf::Time time_since_last_click = sf::Time::Zero;
    
  int cQTY1 = img1.getCircleBaseFigureQTY();
  int rQTY1 = img1.getRectangleFigureQTY();
  int tQTY1 = img1.getGetTriangleFigureQTY();
  int cQTY2 = img2.getCircleBaseFigureQTY();
  int rQTY2 = img2.getRectangleFigureQTY();
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
    }
    window->clear();
    window->draw(List);
    window->draw(textFrame.gettext());


    
    std::vector<sf::CircleShape>& C1 = img1.GetCircle();

        

    //button click: 
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      time_since_last_click = clock.restart();
      sf::Int32 milli = time_since_last_click.asMilliseconds();
      milli = milli;
      if (readyforCheck && checkandnextQuest()) {//íàæàòà êíîïêà äàëåå
        if (check())  textFrame.settext("Good");   else  textFrame.settext("Not good"); 
      }
      if (milli > ELAPSED_TIME) {

        milli = milli;
        if (Buttons.click(window)) { CheckButtonTexture.loadFromFile("resources/images/arrow_down.png"); readyforCheck = true; }

      }
    }

    // for (int i = 0; i < cQTY1; i++)
    //   window->draw(C1[i]);
    // std::vector<sf::RectangleShape>& R1 = img1.GetRectangleFigure();


    // for (int i = 0; i < rQTY1; i++)
    //   window->draw(R1[i]);

      
    // std::vector<sf::ConvexShape> G1 = img1.GetTriangleFigure();
    // for (int i = 0; i < tQTY1; i++)
    //   window->draw(G1[i]);
    std::vector<sf::CircleShape>& C2 = img2.GetCircle();
        
    for (int i = 0; i < cQTY2; i++)
      window->draw(C2[i]);
       
    std::vector<sf::RectangleShape>& R2 = img2.GetRectangleFigure();
    for (int i = 0; i < rQTY2; i++)
      window->draw(R2[i]);
    int tQTY2 = img2.getGetTriangleFigureQTY();
    std::vector<sf::ConvexShape> G2 = img2.GetTriangleFigure();
    for (int i = 0; i < tQTY2; i++)
      window->draw(G2[i]);

    std::vector<std::unique_ptr<sf::Sprite>>& B = Buttons.getButtons();
    for (int i = 0; i < Buttons.getButtonCount(); i++)
      window->draw(*B[i]);
    window->draw(CheckButtonSprite);
    //    window->draw(Buttons.getButtons()[i]);

    Car car;
    
    car.draw(window);
    //Flower flower;
    //flower.draw(window);
    //Tree tree;
    //tree.draw(window);
    window->display();
  }
}
