#include "window.hpp"


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


//int QuestType1::QTY = 1;
extern const int ELAPSED_TIME;





std::wstring get_wstr(int i) {
  std::stringstream ss;
  //ss << (i + 1) << ". ";
  ss << 1 << ". ";
  std::string str = ss.str();

  std::wstring ws(str.begin(), str.end());
  ws += questionFigure[i].questionText.c_str();

  return ws;
}

void PicturetoVeiw::CalcucateCoordinate( ) {
    using namespace std;
    int ButtonSlideHeght = WindowLink.getHeight()   - margin_top;
    int step = 0;
    int  ButtonSize = (WindowLink.getWidth() / 11) * 2 / 3;
    height = ButtonSize;
    while (ButtonSize + 10 > ButtonSlideHeght / 2) ButtonSize--;
    step = ButtonSize / 5;
    if (ButtonCount > 10) margin_top = WindowLink.getHeight() - (ButtonSize + step) * 2; else margin_top = WindowLink.getHeight() - (ButtonSize + step);
    margin_left = WindowLink.getWidth() - 11 * (ButtonSize + step);
    int margin_left_button = margin_left;
    int margin_top_button = margin_top;
    //heght = 
    for (int i = 0; i < ButtonCount; i++) {
        //std::cout << "here2" << std::endl;
        std::string pictureFilename = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
        //if (pictureFilename == "") std::string pictureFilename = picaFilename;

        std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
        txt->loadFromFile(pictureFilename);
        static sf::Vector2u PICTURESIZE = txt->getSize();
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*txt.get());
        scale = (float)ButtonSize / PICTURESIZE.y;
        sprite->setScale(scale, scale);

        sprite->move(margin_left_button, margin_top_button);
        if (i % 10 == 0 && i > 0) {
            margin_top_button = margin_top_button + ButtonSize + step - 15; margin_left_button = WindowLink.getWidth() - 11 * (ButtonSize + step);
        }
        else margin_left_button = margin_left_button + ButtonSize + step;
        MyTexture.emplace_back(std::move(txt));
        ButtonsList.emplace_back(std::move(sprite));
    };
    margin_left += -10;


}

bool Buttons::click(std::shared_ptr<sf::RenderWindow>& w) {
  //    int x, y, width, height;




  for (int i = 0; i < ButtonCount; ++i) {
    const sf::Vector2f& position = ButtonsList[i]->getPosition();
    const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
    int x0 = position.x;
    int y0 = position.y;
    int x1 = x0 + rect.width* scale;
    int y1 = y0 + rect.height * scale;



    const sf::Vector2i& M = sf::Mouse::getPosition(*w);
    x1 = x1;
    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
      std::string fileName = "";
      //std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
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

    } //else std::cout << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 << std::endl;
    //Buttons = Buttons.get()+1;

  }
  return false;

}
Buttons::Buttons( int qtyButton, Window& w) :WindowLink(w), ButtonCount(qtyButton){}


void TextFrameBase::setWidth(int) {
    //text.se
}
void TextFrameBase::CalcucateCoordinate(const int w, const int h) {
    
    
    size = 50;
    text.setCharacterSize(size);
    int width = text.getLocalBounds().width; int height = text.getLocalBounds().height;
    while (width  > w || height > h)
    {  
        if (size > 0) text.setCharacterSize(size--); else return; 
        width = text.getLocalBounds().width;
        height = text.getLocalBounds().height;
    }
}

PicturetoVeiw::PicturetoVeiw(QuestType2& qtl, std::string fn) : Buttons(0, qtl), pictureFilename(fn){};
//PicturetoVeiw(QuestType2&, std::string)
void Buttons::CalcucateCoordinate() {
    using namespace std;
    int ButtonSlideHeght = WindowLink.getHeight() - margin_top;
    int step = 0;
    int  ButtonSize = (WindowLink.getWidth() / 11) * 2 / 3;
    height = ButtonSize; 
    while (ButtonSize + 10 > ButtonSlideHeght / 2) ButtonSize--;
    step = ButtonSize / 5;
    if (ButtonCount > 10) margin_top = WindowLink.getHeight() - (ButtonSize + step) * 2; else margin_top = WindowLink.getHeight() - (ButtonSize + step);
    margin_left = WindowLink.getWidth() - 11 * (ButtonSize + step);
    int margin_left_button = margin_left;
    int margin_top_button = margin_top;
    //heght = 
    for (int i = 0; i < ButtonCount; i++) {
        //std::cout << "here2" << std::endl;
        std::string pictureFilename = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
        //if (pictureFilename == "") std::string pictureFilename = picaFilename;
            
        std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
        txt->loadFromFile(pictureFilename);
        static sf::Vector2u PICTURESIZE = txt->getSize();
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*txt.get());
        scale = (float)ButtonSize / PICTURESIZE.y;
        sprite->setScale(scale, scale);
        
        sprite->move(margin_left_button, margin_top_button);
        if (i % 10 == 0 && i > 0) {
            margin_top_button = margin_top_button + ButtonSize+ step - 15; margin_left_button = WindowLink.getWidth() - 11 * (ButtonSize + step);
        } else margin_left_button = margin_left_button + ButtonSize + step;
        MyTexture.emplace_back(std::move(txt));
        ButtonsList.emplace_back(std::move(sprite));
    };
    margin_left += -10;

}


TextFrameBase::TextFrameBase(int s, char):size(s) { //delegate
    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    text = sf::Text("", font, s);
    text.setFillColor(sf::Color::Black);
    text.setPosition(Settings::PADDING, Settings::PADDING);
}

TextFrameBase::TextFrameBase(int s, std::wstring str, int w1, int h1) :TextFrameBase(s, 'c') {
    w= w1;
    h = h1;
    text.setString(str); 
    
}

void TextFrameBase::setmargin_top(int m) {
    sf::Vector2f pos = text.getPosition();
    text.setPosition(pos.x, m);
}

TextFrameBase::TextFrameBase(int s, int quest, int w,  int h) 
    :TextFrameBase(s, 'c'){
    questionNumber = quest;
  text.setString(get_wstr(quest));
  //  text.setStyle(sf::Text::Bold);

  CalcucateCoordinate(w * 18 / 19, h);
  


}

void TextFrameBase::setN_M(int N, int M) {
    
    
    size_t posn;
    std::wstring question = text.getString();

    std::wstring replaceFrom = L"N";
    std::wstring replaceTo = std::to_wstring(N);
    posn = question.find(replaceFrom);
    question.replace(posn, replaceFrom.length(), replaceTo);


    replaceFrom = L"M";
    replaceTo = std::to_wstring(M);
    posn = question.find(replaceFrom);
    question.replace(posn, replaceFrom.length(), replaceTo);
    text.setString(question);
  
    for (int x = 0; x<X - 1;x++) {
        replaceFrom = phrasestoReplace[questionNumber - beginQuestion2Index][x].find;
        replaceTo = phrasestoReplace[questionNumber - beginQuestion2Index][x].replace;
        posn = question.find(replaceFrom);
        if (posn < question.length()) { question.replace(posn, replaceFrom.length(), replaceTo); }
        
    }
    
        text.setString(question);

}

Window::Window(int w, int h, int numberQuest)
  :  questNumber(numberQuest),
    readyforCheck(false),
    first(true),
    textFrame(Settings::QUESTFONTSIZE, numberQuest,w,h),   
    QuestComment(Settings::QUESTFONTSIZE, CommentsDic[0] , w , h)
{
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

QuestType1::QuestType1(int w, int h,  int qtyButtons) :
    
  Window(w, h, (rand() % 3)),
  Buttons(qtyButtons,*this)
{
    bool first = true;
    int margintopSlideButton = 0;
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
    int circleQTY = figures[fig1]->getcircleQTY() + figures[fig2]->getcircleQTY();
    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);
        figures[fig1]->draw();
        figures[fig2]->draw();
        if (first) {
            margintopSlideButton =
                (
                (figures[fig1]->getymax() * figures[fig1]->getkoef() > figures[fig2]->getymax()* figures[fig2]->getkoef() ? figures[fig1]->getymax() * figures[fig1]->getkoef() : figures[fig2]->getymax() * figures[fig2]->getkoef())
                    ) + (figures[fig1]->getmargin_top() > figures[fig2]->getmargin_top() ? figures[fig1]->getmargin_top() : figures[fig2]->getmargin_top());
            Buttons.setMargin_top(margintopSlideButton + 10);
            Buttons.CalcucateCoordinate(); first = false;
            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++) {
            window->draw(*Buttons.getButtons()[bc]);
        }
        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (readyforCheck && checkandnextQuest()) {
                    int rightfigurCount = check(circleQTY, triangleQTY, rectengleQTY);
                    if (rightfigurCount < 0)  QuestComment.settext(CommentsDic[1]);    else {
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[rightfigurCount - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(rightfigurCount) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
                }
                if (Buttons.click(window)) {
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
            }
        }
    }
}

QuestType2::QuestType2( int w, int h,  int qtyButtons):
    Window(w, h, ((rand() % 3+3))),
    Buttons(qtyButtons,*this),
    Picture(*this)
   {
    //std::cout << "rand() % 3="<<rand() % 3 <<std::endl ;

    bool first = true;
    int margintopSlideButton = 0;
   
    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);
    
    int N = (rand() % 20);
    int M = 0;
    while ((M = (rand() % 20) + 1) >= N) {
        N = (rand() % 20);
        
    }
   textFrame.setN_M(N, M);
   Picture.setButtonCount(N-1);
   Picture.setpictureFilename("resources/images/berry.png");
   Picture.setMargin_top(50);
   Picture.CalcucateCoordinate();
   
   
   sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {           
            Buttons.CalcucateCoordinate(); first = false;
            
            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
            //Buttons.setMargin_top(100);

            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());


            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());


            
        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            window->draw(*Buttons.getButtons()[bc]);
            std::cout << "bc =" << bc << std::endl;
        }
       
        for (int bc = 0; bc < Picture.getButtonCount(); bc++) {
            std::cout << "I am here " << bc<< std::endl;
            window->draw(*Picture.getButtons()[bc]);
        }


        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (readyforCheck && checkandnextQuest()) {
                    int rightfigurCount = 0;
                    if (rightfigurCount < 0)  QuestComment.settext(CommentsDic[1]);    else {
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[rightfigurCount - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(rightfigurCount) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
                }
                if (Buttons.click(window)) {
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
            }
        }
    }


}

QuestType1::QuestType1(int fig1, int fig2,int w, int h,  int qtyButtons) :
    Window(w, h, (rand() % 3)),
    Buttons(qtyButtons,*this)
{
    bool first = true;
    int margintopSlideButton = 0;
    FrameFigure::resetnumber_of_figure();
    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);
    std::cout << fig1 << "," << fig2 << std::endl;

    const std::vector<FrameFigure*> figures =
    {
        new Car(window),
        new Flower(window),
        new Tree(window),
        new Butterfly(window),
        new Plane(window),
        new Tower(window),
    };
    

    int rectengleQTY = figures[fig1]->getrectengleQTY() + figures[fig2]->getrectengleQTY();
    int triangleQTY = figures[fig1]->gettriangleQTY() + figures[fig2]->gettriangleQTY();
    int circleQTY = figures[fig1]->getcircleQTY() + figures[fig2]->getcircleQTY();

    sf::Event event;
    while (window->isOpen()) {

        //std::cout << "yyy" << std::endl;

     




        window->clear();

        window->draw(List);





        
        figures[fig1]->draw();
        figures[fig2]->draw();
        //if (first) std::cout << "*QTY=" << QTY++ << std::endl;
        if (first) {

            margintopSlideButton =
                (

                (figures[fig1]->getymax() * figures[fig1]->getkoef() > figures[fig2]->getymax()* figures[fig2]->getkoef() ? figures[fig1]->getymax() * figures[fig1]->getkoef() : figures[fig2]->getymax() * figures[fig2]->getkoef())
                    ) + (figures[fig1]->getmargin_top() > figures[fig2]->getmargin_top() ? figures[fig1]->getmargin_top() : figures[fig2]->getmargin_top());
            Buttons.setMargin_top(margintopSlideButton + 10);
      
            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h-Buttons.getHeight());

        
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() ,  Buttons.getMarginTop());
        

        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        
       for (int bc = 0; bc < Buttons.getButtonCount(); bc++) {
       
           window->draw(*Buttons.getButtons()[bc]);
       }


  
        window->display();

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window->close();

            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                 
                if (readyforCheck && checkandnextQuest()) {
                    int rightfigurCount = check(circleQTY, triangleQTY, rectengleQTY);
                    
                    if (rightfigurCount < 0)  QuestComment.settext(CommentsDic[1]);    else {
                        QuestComment.settext(CommentsDic[2]);
                        
                 
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[rightfigurCount - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(rightfigurCount) + "_right.jpg"
                        );

                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());

                }

                if (Buttons.click(window)) {

                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);


                }
            }



        }






    }
}

