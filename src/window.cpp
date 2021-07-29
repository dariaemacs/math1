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
#include <algorithm>

#define maximal(a, b) (((a)>(b))?(a):(b))
#define minimal(a, b) (((a)<(b))?(a):(b))
#define three_minimal(a, b, c) minimal(minimal(a, b), c)

//int QuestType1::QTY = 1;
extern const int ELAPSED_TIME;
extern std::vector< std::vector<int>> numSeries;

inline void delay(clock_t sec)
{
    clock_t start_time = clock();
    clock_t end_time = sec + start_time;
    while (clock() != end_time);
}
/*
template <size_t N>
std::wstring get_wstr(const std::array<figureQestions, N>& arr, int questvariantIndex){
    std::stringstream ss;
    ss << 1 << ". ";
    std::string str = ss.str();

    std::wstring ws(str.begin(), str.end());
    ws += arr[questvariantIndex].questionText.c_str();

    return ws;
}
*/

std::wstring get_wstr(int questvariantIndex,int ordNumber) {
//    setlocale(LC_ALL, "Russian");
  std::stringstream ss;
  ss << 1 << ". ";
  std::string str = ss.str();

  std::wstring ws(str.begin(), str.end());
  ws += qestionarrayList[ordNumber][questvariantIndex].questionText.c_str();

  return ws;
}
int TextFrameBase::getHeight() {
    return text.getLocalBounds().height;
}
void PicturetoView::CalcucateCoordinate( ) {
    using namespace std;
    sf::Texture tmp;

    int button_margin_left = margin_left;
    tmp.loadFromFile(pictureFilename+".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y && PICTURESIZE.x / PICTURESIZE.y >= 2)  PICTURESIZE.x /=  2;
    int ButtonSlideHeght = WindowLink.getHeight() / 3;
    
    float PICTURESIZE_W = PICTURESIZE.x;
    width = PICTURESIZE.x;
    float PICTURESIZE_H = PICTURESIZE.y;
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round(ButtonCount ) + round((ButtonCount)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename+".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, ButtonSlideHeght);
            button_margin_left = button_margin_left + 5 + PICTURESIZE.x* scale;
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
    }
    else
    {
        ////std::cout<<"here"<<std::endl;
        //2 rows
        
        float PICTURESIZE_W = PICTURESIZE.x;
        float PICTURESIZE_H = PICTURESIZE.y;
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
         scale = PICTURESIZE_W  / (PICTURESIZE_W - 5);
        cout << "scale = "<<scale << endl;
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount ) / 2) * 5)) > WindowLink.getWidth() || 2 * PICTURESIZE_H + 5 > ButtonSlideHeght);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename+".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, ButtonSlideHeght);
            

            button_margin_left = button_margin_left + 5 + PICTURESIZE.x* scale;


            if (i+1 == (int)(ButtonCount / 2)) {
                button_margin_left = 0; ButtonSlideHeght = ButtonSlideHeght + PICTURESIZE.y * scale + 5;
            }
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);

        }
    }
       
    //setScale(scale);

}

bool PicturetoView::click() {



    

    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        int x0 = position.x;
        int y0 = position.y;
        int x1 = (float)x0 + (float)rect.width * scale;
        int y1 = (float)y0 + (float)rect.height * scale;

        
        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        
        x1 = x1;
        ////std::cout << "pica: scale=" << scale << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<" " <<(x1 - x0) << "x"<<(y1 - y0) << std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture CheckButtonTexture;
            sf::Sprite CheckButtonSprite(CheckButtonTexture);

            //if (ButtonPressID >= 0) {
            if (isblackSide[i])
                fileName = pictureFilename + "_black.png"; else fileName = pictureFilename + ".png";
                MyTexture[i]->loadFromFile(fileName); //ButtonPressID = -1;
                isblackSide[i] = !isblackSide[i];
            return true;
        } 

    }
    return false;

}


bool Buttons::click() {





  for (int i = 0; i < ButtonCount; ++i) {
    const sf::Vector2f& position = ButtonsList[i]->getPosition();
    const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
    int x0 = position.x;
    int y0 = position.y;
    int x1 = (float)x0 + (float)rect.width* scale;
    int y1 = (float)y0 + (float)rect.height * scale;



    const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
    x1 = x1;
    ////std::cout << "scale" <<scale << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
      std::string fileName = "";
      ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
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

    } //else //std::cout << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 << std::endl;
    //Buttons = Buttons.get()+1;

  }
  return false;

}
Buttons::Buttons( int qtyButton, Window& w) :WindowLink(w), ButtonCount(qtyButton){
 
}
Buttons::Buttons( Window& w) : WindowLink(w){}

void TextFrameBase::setWidth(int) {
    //text.se
}

void Mysf_text::CalcucateCoordinate(float w, float h) {

    sf::String  tmp = getString();
    setString("99");
    setCharacterSize(size);
    float width = getLocalBounds().width; 
    float height = getLocalBounds().height;
    while (width >= w || height >= h)
    {
        if (size > 0) setCharacterSize(size--); else return;
        width = getLocalBounds().width;
        height = getLocalBounds().height;
    }

    ////std::cout << "text size=" << width << "x" << height << " size=" << size <<std::endl;
    setString(tmp);
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
    margin_top = text.getLocalBounds().top;
}

PicturetoView::PicturetoView(QuestType2& qtl, std::string fn) : Buttons(0, qtl), pictureFilename(fn){};
//PicturetoView(QuestType2&, std::string)
void Buttons::CalcucateCoordinate() {
    using namespace std;
    int ButtonSlideHeght = WindowLink.getHeight()/3;
    int step = 0;
    int  ButtonSize = (WindowLink.getWidth() / 11) * 2 / 3;
    height = ButtonSize; 
    while (ButtonSize + 10 > ButtonSlideHeght / 2) ButtonSize--;
    step = ButtonSize / 5;
    if (ButtonCount > 11) margin_top = WindowLink.getHeight() - (ButtonSize + step) * 2; else margin_top = WindowLink.getHeight() - (ButtonSize + step);
    margin_left = WindowLink.getWidth() - 11 * (ButtonSize + step);
    int margin_left_button = margin_left;
    int margin_top_button = margin_top;
    //heght = 
    for (int i = 0; i < ButtonCount; i++) {
        ////std::cout << "here2" << std::endl;
        std::string pictureFilename = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
        //if (pictureFilename == "") std::string pictureFilename = picaFilename;
            
        std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
        txt->loadFromFile(pictureFilename);
        static sf::Vector2u PICTURESIZE = txt->getSize();
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*txt.get());
        scale = (float)ButtonSize / PICTURESIZE.y;
        sprite->setScale(scale, scale);
        cout << i % 10 << std::endl;
        sprite->move(margin_left_button, margin_top_button);
        if (i % 10 == 0 && i > 0 ) {
            //cout << "here***rr" << ButtonCount << std::endl;
            margin_top_button = margin_top_button + ButtonSize+ 10; margin_left_button = WindowLink.getWidth() - 11 * (ButtonSize + step);
        } else margin_left_button = margin_left_button + ButtonSize + step;
        MyTexture.emplace_back(std::move(txt));
        ButtonsList.emplace_back(std::move(sprite));
    };
   

}


TextFrameBase::TextFrameBase(int s, Window& winLink,char ):size(s), WindowLink(winLink) { //delegate
    ////std::cout << Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf" << std::endl;
    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    
    text = sf::Text("", font, s);
    text.setFillColor(sf::Color::Black);
    text.setPosition(Settings::PADDING, Settings::PADDING);
}

TextFrameBase::TextFrameBase(int s, std::wstring str, int w1, int h1, Window& winLink) :TextFrameBase(s, winLink, 'c') {
    w= w1;
    h = h1;
    text.setString(str); 
    
}

void TextFrameBase::setmargin_top(int m) {
    sf::Vector2f pos = text.getPosition();
    text.setPosition(pos.x, m);
    margin_top = m;
}

TextFrameBase::TextFrameBase(int s, int quest, int w,  int h, Window& winLink)
    :TextFrameBase(s,  winLink,'c'){
    questionNumber = quest;
  text.setString(get_wstr(quest, winLink.getordQuestNumber()));


  CalcucateCoordinate(w * 18 / 19, h);
  


}

void TextFrameBase::setN_M(int N, int M) {
    
    
    size_t posn;
    std::wstring question = text.getString();

    std::wstring replaceFrom = L"N";
    std::wstring replaceTo = std::to_wstring(N);
    posn = question.find(replaceFrom);
    if (posn < question.length()) question.replace(posn, replaceFrom.length(), replaceTo);
    

    replaceFrom = L"M";
    replaceTo = std::to_wstring(M);
    posn = question.find(replaceFrom);
    if (posn < question.length()) question.replace(posn, replaceFrom.length(), replaceTo);
    text.setString(question);
    ////std::cout << questionNumber << " "<< beginQuestion2Index << std::endl;
    for (int x = 0; x<X - 1;x++) {
        replaceFrom = phrasestoReplace[questionNumber][x].find;
        replaceTo = phrasestoReplace[questionNumber ][x].replace;
        posn = question.find(replaceFrom);
        if (posn < question.length()) { question.replace(posn, replaceFrom.length(), replaceTo); }
        
    }
    
        text.setString(question);

}

Window::Window(int w, int h, int numberQuest,int ord)
  :  
    ordQuestNumber(ord),
    questNumber(numberQuest),
    readyforCheck(false),
    first(true),
    textFrame(Settings::QUESTFONTSIZE, numberQuest,w,h,*this),   
    QuestComment(Settings::QUESTFONTSIZE, CommentsDic[0] , w , h,*this)
{

    width = w;
    height = h;
    ////std::cout << "numberQuest="<<numberQuest << std::endl;
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
  
  //sf::ContextSettings settings(0,0,8);
  

  //if (!first) {
  std::string comment = std::string("Game "  )+ std::to_string(w) + "x" + std::to_string(h);
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w, h), comment, sf::Style::Default, settings);//,  sf::Style::Fullscreen);
    window->setFramerateLimit(Settings::FPS);
    ////std::cout<<"Check point" << std::endl;
    //window->~RenderWindow();


  
}


int QuestType1::check(int c,int t, int r ) {
  switch (question1Text[questNumber].key)
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

bool Window::checkandnextQuest(float scale) {
    
    const sf::Vector2i& M = sf::Mouse::getPosition(*window);
  const sf::Vector2f& position = CheckButtonSprite.getPosition();
  const sf::IntRect& rect =      CheckButtonSprite.getTextureRect();
  ////std::cout << scale << rect.width << std::endl;
  int x0 = position.x;
  int y0 = position.y;
  int x1 = x0 + rect.width * Settings::ButtonFactor;
  int y1 = y0 + rect.height * Settings::ButtonFactor;
 
  
  if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
      ////std::cout << "rect height = "<< rect.height <<" "<< M.x <<"*"<< x0 << " " << M.x <<"*"<< x1 <<" " << M.y <<"*"<< y0 <<" " << M.y <<"*"<< y1<< std::endl;
    return true;
  }
  return false;
}

QuestType1::QuestType1(int w, int h,  int qtyButtons) :
    
  Window(w, h, (rand() % 3),0),
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
        //*Buttons.
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {
                   
                    int rightfigurCount = check(circleQTY, triangleQTY, rectengleQTY);
                    if (rightfigurCount < 0)  QuestComment.settext(CommentsDic[1]);    else {
                        QuestComment.settext(CommentsDic[2]);
                        ////std::cout << Buttons.GetButtonsClickID() << std::endl;
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[rightfigurCount - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(rightfigurCount) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
                }
                if (Buttons.click()) {
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
            }
        }
    }
}

QuestType2::QuestType2( int w, int h,  int qtyButtons):
    
    Window(w, h,  
   
   ((rand() % 6))
        
        ,
        
        1),
    Buttons(qtyButtons,*this),
    Picture(*this)
   {

   
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
   Picture.setButtonCount(N);
 
   Picture.setpictureFilename("resources/images/"+filenamesforPicaQuest2[getQuestNumber()]);
   Picture.setMargin_left(10);
   Picture.setMargin_top(textFrame.getHeight()*2);

   Picture.CalcucateCoordinate();

Buttons.setButtonCount(N);
   
   sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {           
            Buttons.CalcucateCoordinate(); first = false;
            
            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft()-10, Buttons.getHeight());
            //Buttons.setMargin_top(100);
            
            Buttons.CalcucateCoordinate(); first = false;




            
        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            window->draw(*Buttons.getButtons()[bc]);
            
        }
       
        for (int bc = 0; bc < Picture.getButtonCount(); bc++) {
            
            window->draw(*Picture.getButtons()[bc]);
        }


        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }
           
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
               
                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {
                   
                    int rightfigurCount = 0;
                    ////std::cout << Buttons.GetButtonsClickID()+1 = N- << std::endl;
                    if (Buttons.GetButtonsClickID()+1 == N-M)  QuestComment.settext(CommentsDic[1]);    else {
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[N - M-1]->loadFromFile(
                            "resources/images/digit" + std::to_string(N - M) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft()-10, Buttons.getMarginTop());
                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
                if (Picture.click()) {
                    ////std::cout << "Picture.click" << std::endl;
                }


            }
        }
    }

    srand(time(0));
}

QuestType1::QuestType1(int fig1, int fig2,int w, int h,  int qtyButtons) :
    Window(w, h, (rand() % 3),0),
    Buttons(qtyButtons,*this)
{
    bool first = true;
    int margintopSlideButton = 0;
    FrameFigure::resetnumber_of_figure();
    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);
    ////std::cout << fig1 << "," << fig2 << std::endl;

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

        ////std::cout << "yyy" << std::endl;

     




        window->clear();

        window->draw(List);





        
        figures[fig1]->draw();
        figures[fig2]->draw();
        //if (first) //std::cout << "*QTY=" << QTY++ << std::endl;
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
           
                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {
                    
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

                if (Buttons.click()) {

                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);


                }
            }



        }






    }
}

PicturetoViewQuestWithBasket::PicturetoViewQuestWithBasket(Window& w) : PicturetoView(w) {};

void PicturetoViewQuestWithBasket::CalcucateCoordinate() {

    using namespace std;
    sf::Texture tmp;

    int button_margin_left = 0;
    tmp.loadFromFile(pictureFilename + ".png");
    ////std::cout << "picture" << std::endl;
    sf::Vector2u PICTURESIZE = tmp.getSize();
    
    ////std::cout << PICTURESIZE.x << std::endl;
    float PICTURESIZEy = PICTURESIZE.y;
    if (PICTURESIZE.x > PICTURESIZE.y && ((float)PICTURESIZE.x / (float)PICTURESIZE.y) >= 1.5) {
        PICTURESIZE.x /= 2;
    }
  
    int ButtonSlideHeght = WindowLink.getHeight() / 3;
  
    float PICTURESIZE_W = PICTURESIZE.x;
    float PICTURESIZE_H = PICTURESIZE.y;
    float BASKETPICTURESIZE_W = 0;
    float BASKETPICTURESIZE_H = 0;
    float BASKETSCALE = 1;

    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
 
    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round(ButtonCount+2) + round((ButtonCount+2)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, ButtonSlideHeght);
            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
        //calc for basket
        //basketTexture.loadFromFile(pictureFilename + "_basket.png");
        //sf::Vector2u BASKETPICTURESIZE = basketTexture.getSize();
        //do {
        //    BASKETSCALE = BASKETSCALE - 0.01;
        //    BASKETPICTURESIZE_W = BASKETPICTURESIZE.x * BASKETSCALE;
        //    BASKETPICTURESIZE_H = BASKETPICTURESIZE.y * BASKETSCALE;
        //    ////std::cout << "k=" << scale << std::endl;
        //    ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        //} while (((BASKETPICTURESIZE_W *  +  5)) > WindowLink.getWidth() || BASKETPICTURESIZE_H + 5 > ButtonSlideHeght);
        //

        //basketSprite.setTexture(basketTexture);
        //basketSprite.setScale(BASKETSCALE, BASKETSCALE);
        //basketSprite.move(button_margin_left , ButtonSlideHeght);
    }
    else
    {
        ////std::cout << PICTURESIZE.x << std::endl;
        //2 rows

        float PICTURESIZE_W = PICTURESIZE.x;
        float PICTURESIZE_H = PICTURESIZE.y;
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) > WindowLink.getWidth() || 2 * PICTURESIZE_H + 5 > ButtonSlideHeght);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, ButtonSlideHeght);


            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;

            //const sf::Vector2f& position = ButtonsList[i]->getPosition();
            //const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
            if (i + 1 == (int)(ButtonCount / 2)) {
                button_margin_left = 0; ButtonSlideHeght = ButtonSlideHeght + PICTURESIZE.y * scale + 5;
            }
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);

        }
    }

    basketTexture.loadFromFile(pictureFilename + "_basket.png");
    sf::Vector2u BASKETPICTURESIZE = basketTexture.getSize();
    do {
        BASKETSCALE = BASKETSCALE - 0.01;
        BASKETPICTURESIZE_W = BASKETPICTURESIZE.x * BASKETSCALE;
        BASKETPICTURESIZE_H = BASKETPICTURESIZE.y * BASKETSCALE;
    } while (((BASKETPICTURESIZE_W * +5)) > WindowLink.getWidth() || BASKETPICTURESIZE_H + 5 > ButtonSlideHeght);


    basketSprite.setTexture(basketTexture);
    basketSprite.setScale(BASKETSCALE, BASKETSCALE);
    basketSprite.move(button_margin_left, (BASKETPICTURESIZE_H / BASKETPICTURESIZE_W>=1.5? 
        (WindowLink.getHeight() - BASKETPICTURESIZE_H)/2 : WindowLink.getHeight() / 3) );
}

QuestType3::QuestType3(int w, int h, int qtyButtons) :

    Window(w, h,
        
        ((rand() % 6))

        ,

        2)
    
    ,
    Buttons(qtyButtons, *this),
    PictureAndBasket(PicturetoViewQuestWithBasket(*this) )
    

{


    bool first = true;
    int margintopSlideButton = 0;
    ////std::cout << qtyButtons << std::endl;
    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);


    int N = (rand() % 10);
    int M = 0;
    while ((M = (rand() % 10) + 1) >= N) {
        N = (rand() % 10);
    }
    //N = 10;

    textFrame.setN_M(N, M);
    PictureAndBasket.setButtonCount(N);

    PictureAndBasket.setpictureFilename("resources/images/" + filenamesforPicaQuest3[getQuestNumber()]);
    PictureAndBasket.setMargin_left(10);
    PictureAndBasket.setMargin_top(textFrame.getHeight() * 2);

    PictureAndBasket.CalcucateCoordinate();

    //Buttons.setButtonCount(N);

    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {
            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getHeight());
            //Buttons.setMargin_top(100);

            Buttons.CalcucateCoordinate(); first = false;





        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            window->draw(*Buttons.getButtons()[bc]);

        }

        for (int bc = 0; bc < PictureAndBasket.getButtonCount(); bc++) {

            window->draw(*PictureAndBasket.getButtons()[bc]);
        }
        window->draw(PictureAndBasket.getBasketSprite());

        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {

                    int rightfigurCount = 0;
                    ////std::cout << Buttons.GetButtonsClickID()+1 = N- << std::endl;
                    if (Buttons.GetButtonsClickID() + 1 == N + M)  QuestComment.settext(CommentsDic[1]);    else {
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[N + M - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(N + M) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());
                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
                if (PictureAndBasket.click()) {
                    ////std::cout << "Picture.click" << std::endl;
                }


            }
        }
    }

    srand(time(0));
}

QuestType4::QuestType4(int w, int h, int qtyButtons) :
    Window(w, h, 0, 3),
    Buttons(qtyButtons, *this){

    bool first = true;
    bool firstPrintTrain = true;
    int margintopSlideButton = 0;
    int numberInTrainCharactersize = 0;
    FrameFigure::resetnumber_of_figure();
    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);
    float squareWidth = 0;
    int opennumbaerCount = 0;
    TrainForQuest  TrainForQuest(window);
    //sf::CircleShape shape(1);
    
    //shape.setFillColor(sf::Color::Red);
    
    int numSeriesIndex = rand() % numSeries.size();
    struct closenumberStruct { int index; int closeNumber; };
    std::array< int, 3> closeNumber;
    std::array< closenumberStruct, 3 > usercloseNumberEnter;

    
        
    sf::Texture trainpictureTexture;
    sf::Sprite trainpictureSprite;

    trainpictureTexture.loadFromFile("resources/images/train.jpg");
    trainpictureSprite.setTexture(trainpictureTexture);
    //trainpictureSprite.
    do {
        closeNumber[0] = rand() % 6;
        closeNumber[1] = rand() % 6;
        closeNumber[2] = rand() % 6;
    } while (closeNumber[0] == closeNumber[1] || closeNumber[1] == closeNumber[2] || closeNumber[0] == closeNumber[2]);
    std::sort(closeNumber.begin(), closeNumber.end());

   int currentusercloseNumberIndex = 0;
    //currentusercloseNumberIndex = three_minimal(closeNumber1, closeNumber2, closeNumber3);
    //closeNumber.
    std::vector <Mysf_text*> numberInTrain;

    sf::Font font;
    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");


    
    for (int i = 0; i < numSeries[0].size(); i++) {
        numberInTrain.push_back(new Mysf_text(50));
        numberInTrain[i]->setString(std::to_string(numSeries[numSeriesIndex][i]));

        numberInTrain[i]->setFont(font);
        
        numberInTrain[i]->setFillColor(sf::Color::Black);
   

    }
    
    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);
        if (first) {
            margintopSlideButton = 20;
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

        TrainForQuest.draw();
        float YnumberInTrain = TrainForQuest.getmargin_top();

        YnumberInTrain = TrainForQuest.getmargin_top() + 
            TrainForQuest.getymin() * TrainForQuest.getkoef();

       // //std::cout << "closeNumber1 " << closeNumber1 << " " << closeNumber2 << " " << closeNumber3 << std::endl;
        
     
        for (int i = 0; i < numSeries[0].size(); i++) {

           squareWidth = (float)(TrainForQuest.getxmax() - TrainForQuest.getxmin()) * (float)TrainForQuest.getkoef()
                / (float)TrainForQuest.getrectengleQTY();
            numberInTrain[i]->setPosition(
                TrainForQuest.getxmin() * TrainForQuest.getkoef() + TrainForQuest.getmargin_left()+
                
                
                squareWidth *
                i   , YnumberInTrain );
            //*numberInTrain[i]->
            //if (i==1) shape.setPosition(TrainForQuest.getxmin() + TrainForQuest.getmargin_left() +
            //    squareWidth *
            //    i , YnumberInTrain);
            if ((!(i == closeNumber[0] ||
                i == closeNumber[1] || i == closeNumber[2]
                )) || i == usercloseNumberEnter[0].index || i == usercloseNumberEnter[1].index || i == usercloseNumberEnter[2].index){
                if (firstPrintTrain) {
                    numberInTrain[i]->CalcucateCoordinate(squareWidth - 10, squareWidth - 10);
                    numberInTrainCharactersize = numberInTrain[i]->getSize();
                    
                }
                firstPrintTrain = false;
                numberInTrain[i]->setCharacterSize(numberInTrainCharactersize);
                window->draw(*numberInTrain[i]);
            }; 
            
            

            TrainForQuest.SetSquareColor(closeNumber[currentusercloseNumberIndex], true);


        }
        float scaletrainpicture =  squareWidth / 185+0.1;
            trainpictureSprite.setScale(scaletrainpicture, scaletrainpicture);
            trainpictureSprite.setPosition(
                TrainForQuest.getxmin()* TrainForQuest.getkoef() + TrainForQuest.getmargin_left() +


                squareWidth *
                6+3, (float)YnumberInTrain-185* scaletrainpicture+ squareWidth+3);

        window->draw(trainpictureSprite);
        
        window->display();
        

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window->close();

            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {

                    if ((numSeries[numSeriesIndex][closeNumber[0]] == usercloseNumberEnter[0].closeNumber) &&
                        (numSeries[numSeriesIndex][closeNumber[1]] == usercloseNumberEnter[1].closeNumber) &&
                        (numSeries[numSeriesIndex][closeNumber[2]] == usercloseNumberEnter[2].closeNumber))
                    QuestComment.settext(CommentsDic[1]);    
                    else QuestComment.settext(CommentsDic[2]);
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
                }

                if (Buttons.click()) {
                    TrainForQuest.SetSquareColor(closeNumber[currentusercloseNumberIndex], false);

                    usercloseNumberEnter[currentusercloseNumberIndex].closeNumber = Buttons.GetButtonsClickID()+1;
                    usercloseNumberEnter[currentusercloseNumberIndex].index = closeNumber[currentusercloseNumberIndex];
                    //closeNumber[currentusercloseNumberIndex] = -90;
                    //window->draw(*numberInTrain[i]);
                    ////std::cout << "TUTA: " <<usercloseNumberEnter[currentusercloseNumberIndex].closeNumber << " " << usercloseNumberEnter[currentusercloseNumberIndex].index<<std::endl;
                    numberInTrain[closeNumber[currentusercloseNumberIndex]]->setString(std::to_string(Buttons.GetButtonsClickID() + 1));
                    //numberInTrain[closeNumber[currentusercloseNumberIndex]]->CalcucateCoordinate(squareWidth - 10, squareWidth - 10);
                    //numberInTrainCharactersize = numberInTrain[closeNumber[currentusercloseNumberIndex]]->getSize();
                    numberInTrain[closeNumber[currentusercloseNumberIndex]]->setCharacterSize(numberInTrainCharactersize);
                    currentusercloseNumberIndex++;
                    if (currentusercloseNumberIndex > 2) currentusercloseNumberIndex = 0;                    
                                                     CheckButtonSprite.setTexture(CheckButtonTexture);
                    opennumbaerCount++;
                    if (opennumbaerCount == 3) {
                        readyforCheck = true;
                        CheckButtonTexture.loadFromFile("resources/images/arrow_up.png");
                    }

                }
            }



        }






    }
}

QuestType5::QuestType5(int w, int h, int qtyButtons) :
    Window(w, h,

    ((rand() % 6))

        ,

        4),
    Buttons(qtyButtons, *this)
{


    bool first = true;
    int margintopSlideButton = 0;

    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);






    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {
            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getHeight());
            //Buttons.setMargin_top(100);

            Buttons.CalcucateCoordinate(); first = false;





        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            window->draw(*Buttons.getButtons()[bc]);

        }




        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {



                    if (Buttons.GetButtonsClickID() + 1 == question5Answers[questNumber])  QuestComment.settext(CommentsDic[1]); //right
                    else { //wrong
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[question5Answers[questNumber] - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(question5Answers[questNumber]) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());
                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }



            }
        }
        srand(time(0));
    }
}

void PicturetAndFilmtoView::CalcucateCoordinate() {
    using namespace std;
    sf::Texture tmp;

    
    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y && PICTURESIZE.x / PICTURESIZE.y >= 2) { PICTURESIZE.x /= 3; coinWidth = PICTURESIZE.x; coinHeight = PICTURESIZE.y; }
    int ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = PICTURESIZE.x;
    float PICTURESIZE_H = PICTURESIZE.y;
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round(ButtonCount) + round((ButtonCount)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            ////std::cout << "first loadFromFile" << std::endl;
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(margin_left, ButtonSlideHeght);
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
    }
    else
    {
        ////std::cout<<"here"<<std::endl;
        //2 rows

        float PICTURESIZE_W = PICTURESIZE.x;
        float PICTURESIZE_H = PICTURESIZE.y;
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) > WindowLink.getWidth() || 2 * PICTURESIZE_H + 5 > ButtonSlideHeght);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(margin_left, ButtonSlideHeght);
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);

        }
    }

    //setScale(scale);

}

void setofpictureObject::CalcucateCoordinate(int where) {
    using namespace std;
    sf::Texture tmp;


    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y&& PICTURESIZE.x / PICTURESIZE.y >= 2) { PICTURESIZE.x /= 3; }
    int ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = PICTURESIZE.x;
    float PICTURESIZE_H = PICTURESIZE.y;
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);


        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * 6 + 6* 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);


            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            ////std::cout << "first loadFromFile" << std::endl;
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            if (where == 1) sprite->move(margin_left, ButtonSlideHeght); else
                if (where == 2) { 
                    if (isAdd) margin_left = (WindowLink.getWidth() - PICTURESIZE_W * 2) / 2;
                    sprite->move(margin_left, WindowLink.getHeight() - PICTURESIZE_H); }
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
            width  = PICTURESIZE_W;
            height = PICTURESIZE_H;
}

bool PicturetAndFilmtoView::click() {
    const int speedRotation = 100;
    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        int x0 = position.x;
        int y0 = position.y;
        int x1 = (float)x0 + (float)rect.width * scale;
        int y1 = (float)y0 + (float)rect.height * scale;

        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;
        ////std::cout << "scale" <<scale << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture CheckButtonTexture;
            sf::Sprite CheckButtonSprite(CheckButtonTexture);


            //for film coin rotate
            clock_t start_time1 = 0;
            clock_t end_time1 = 0;
            bool frame1 = false;
            clock_t start_time2 = 0;
            clock_t end_time2 = 0;
            bool frame2 = false;

            if (ButtonPressID < 0) {
                while (true) {
                    start_time1 = clock();
                    if (!frame1) {
                        end_time1 = speedRotation + start_time1;
                        frame1 = true;

                    }
                    if (frame1 && start_time1 > end_time1) {
                        ////std::cout << "testFilm2" << std::endl;

                        MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(coinWidth, 0, coinWidth * 2, coinHeight));
                        ButtonsList[0]->setTexture(*MyTexture[0]);
                        WindowLink.getWindow()->draw(*ButtonsList[0]);
                        WindowLink.getWindow()->display();
                        start_time2 = clock();
                        if (!frame2) {
                            end_time2 = speedRotation + start_time2;
                            frame2 = true;

                        }
                        if (frame2 && start_time2 > end_time2) {
                            ////std::cout << "testFilm3" << std::endl;
                            MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(coinWidth * 2, 0, coinWidth * 3, coinHeight));
                            ButtonsList[0]->setTexture(*MyTexture[0]);
                            WindowLink.getWindow()->draw(*ButtonsList[0]);
                            WindowLink.getWindow()->display();
                            break;
                        }
                    }
                }
                ButtonPressID = 1;

            }
            else
            {
                while (true) {
                    start_time1 = clock();
                    if (!frame1) {
                        end_time1 = speedRotation + start_time1;
                        frame1 = true;

                    }
                    if (frame1 && start_time1 > end_time1) {
                        ////std::cout << "testFilm2" << std::endl;
                        MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(coinWidth, 0, coinWidth * 2, coinHeight));
                        ButtonsList[0]->setTexture(*MyTexture[0]);
                        WindowLink.getWindow()->draw(*ButtonsList[0]);
                        WindowLink.getWindow()->display();
                        start_time2 = clock();
                        if (!frame2) {
                            end_time2 = speedRotation + start_time2;
                            frame2 = true;

                        }
                        if (frame2 && start_time2 > end_time2) {
                            ////std::cout << "testFilm3" << std::endl;
                            MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, coinWidth , coinHeight));
                            ButtonsList[0]->setTexture(*MyTexture[0]);
                            WindowLink.getWindow()->draw(*ButtonsList[0]);
                            WindowLink.getWindow()->display();
                            break;
                        }
                    }
                }
            ButtonPressID = -1;
        }

          

        } 

    }
    return false;
}
QuestType6::QuestType6(int w, int h, int qtyButtons)
:Window(w, h,((rand() % 4)),5),
    Buttons(qtyButtons, *this),
    coin1(*this),
    coin2(*this){



    bool first = true;
    int margintopSlideButton = 0;

    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);

    int coinRandomIndex = rand() % 2;
    coin1.setButtonCount(1);
    coin2.setButtonCount(1);
    if (coinRandomIndex == 0) {
        coin1.setpictureFilename("resources/images/moneta10");
        coinRandomIndex = rand() % 3;
        switch (coinRandomIndex)
        {
        case 0:coin2.setpictureFilename("resources/images/moneta01"); break;
        case 1:coin2.setpictureFilename("resources/images/moneta02"); break;
        case 2:coin2.setpictureFilename("resources/images/moneta05"); break;
        default:
            break;
        }
    }
    else {
     
        coinRandomIndex = rand() % 3;
        switch (coinRandomIndex)
        {            
            case 0:coin1.setpictureFilename("resources/images/moneta01"); break;
            case 1:coin1.setpictureFilename("resources/images/moneta02"); break;
            case 2:coin1.setpictureFilename("resources/images/moneta05"); break;
        default:
            break;
        }
        coin2.setpictureFilename("resources/images/moneta10");
    }

    coin1.setMargin_left(0);
    coin1.setMargin_top(textFrame.getHeight() * 2);
    coin1.CalcucateCoordinate();
  
    coin2.setMargin_left(coin1.getcoinWidth()+10);
    coin2.setMargin_top(textFrame.getHeight() * 2);
    coin2.CalcucateCoordinate();
    
  


    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {
            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getHeight());
            //Buttons.setMargin_top(100);

            Buttons.CalcucateCoordinate(); first = false;





        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++)
        {
            window->draw(*Buttons.getButtons()[bc]);

        }

            window->draw(*coin1.getButtons()[0]);
            window->draw(*coin2.getButtons()[0]);


        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {
                    


                    if (Buttons.GetButtonsClickID() + 1 == question6Answers[questNumber])  QuestComment.settext(CommentsDic[1]); //right
                    else { //wrong
                        QuestComment.settext(CommentsDic[2]);
                        Buttons.getButtonTexture()[Buttons.GetButtonsClickID()]->loadFromFile(
                            "resources/images/digit" + std::to_string(Buttons.GetButtonsClickID() + 1) + "_wrong.jpg");

                        Buttons.getButtonTexture()[question5Answers[questNumber] - 1]->loadFromFile(
                            "resources/images/digit" + std::to_string(question5Answers[questNumber]) + "_right.jpg"
                        );
                    }
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());



                }
                if (Buttons.click()) {
                    ////std::cout << "Button.click" << std::endl;
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
                if (coin1.click() || coin2.click()) {
                    
                }


            }
        }
    }

    srand(time(0));
}

point::point(float sz) :x(0), y(0), i(0), j(0), Sb(0), size(sz), sf::RectangleShape(){
    sf::RectangleShape::setPosition(0,0);
    sf::RectangleShape::setSize(sf::Vector2f(sz, sz));

}
//void QuestType8::loadfromfileforSetofpic3(std::string fn) {
//    setofpic3.loadFromFile(fn);
//}
int setofpictureObject::click(int qty, setofpictureObject& lastpic) {
    const int speedRotation = 100;
    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        int x0 = position.x;
        int y0 = position.y;
        int x1 = (float)x0 + (float)rect.width * scale;
        int y1 = (float)y0 + (float)rect.height * scale;

        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;

        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            sf::Texture CheckButtonTexture;
            sf::Sprite CheckButtonSprite(CheckButtonTexture);
            std::cout <<"**" << std::to_string(qty) << std::endl;
            if (isAdd ) qty++; else qty--;
            if (qty >= 0) {
            fileName = "resources/images/" + filenamesforPicaQuest8[WindowLink.getQuestNumber()] + std::to_string(qty);
            //WindowLink.setofpic3.loadFromFile(fileName + ".png"); //ButtonPressID = -1;
            std::cout << std::to_string(qty) << std::endl;
            (lastpic.getButtonTexture()[0])->loadFromFile(fileName + ".png"); //ButtonPressID = -1;;
         
        }


        }
    }
    return qty;
}

squareBoard::squareBoard(float ww, float hh, Window& wl) : w(ww), h(hh),  questFigure(wl.getQuestNumber()), squareWidth(0), alreadyDraw(false), 
CheckPoint{ 10,10,10,10,10,10 },
WindowLink(wl), CurrentClickpoint(-1)

{
    marginLeft = ww * 5 / 100;
    marginTop = hh / 9;
    squareWidth = (h - marginTop) / NN;
    for (int i = 0; i < 6; i++) {
        CheckPoint[i].setSb(this);
        CheckPoint[i].setFillColor(color::blue);
    }
    for (int i = 0; i < NN+1; i++)
    {
        HorizLine.push_back(sf::RectangleShape());
        HorizLine[i].setSize(sf::Vector2f(ww- 2* marginLeft, 1));
        HorizLine[i].setFillColor(color::slategray);
    }
    widthsqareBord = w - marginLeft * 2;
    heightsqareBord = h - marginTop;
    MM = widthsqareBord / ((h - marginTop) / NN);
    for (int i = 0; i < MM; i++)
    {
        VertLine.push_back(sf::RectangleShape());
        VertLine[i].setSize(sf::Vector2f(1, 8 * hh / 9));
        VertLine[i].setFillColor(color::slategray);
    };
    int VARIANT = 0;
    
    for (int i = 0; i < CheckPoint.size(); i++)
    CheckPoint[i].setFillColor(sf::Color::Blue);

    CheckPoint[0].setPosition(0, 0);
    CheckPoint[1].setPosition(0, 1);
    CheckPoint[2].setPosition(0, 2);

    CheckPoint[3].setPosition(1, 0);
    CheckPoint[4].setPosition(1, 1);
    CheckPoint[5].setPosition(1, 2);
    ////std::cout << question7Text[questFigure].key << std::endl;
    float ax,bx;
    float ay,by;
    int fig = question7Text[questFigure].key;
    //
    switch (fig) {
       

        case triangle:
            VARIANT = rand() % 13;

            ax = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getPixelCoord().x + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            ay = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getPixelCoord().y + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            //(int)(getSize() / 2)
            bx = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].j].getPixelCoord().x + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            by = CheckPoint[question7trianglevariantOfFirstLine[VARIANT].j].getPixelCoord().y + (CheckPoint[question7trianglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            firstpointInput_i = question7trianglevariantOfFirstLine[VARIANT].i;
            firstpointInput_j = question7trianglevariantOfFirstLine[VARIANT].j;



            break;

        case rectangle:
            VARIANT = rand() % 7;
            ax = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            ay = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
           
            bx = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            by = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            firstpointInput_i = question7rectanglevariantOfFirstLine[VARIANT].i;
            firstpointInput_j = question7rectanglevariantOfFirstLine[VARIANT].j;


                      break;

        case square:
            VARIANT = rand() % 7;
            ax = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            ay = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);

            bx = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().x + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            by = CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].j].getPixelCoord().y + (CheckPoint[question7rectanglevariantOfFirstLine[VARIANT].i].getSize() / 2);
            firstpointInput_i = question7rectanglevariantOfFirstLine[VARIANT].i;
            firstpointInput_j = question7rectanglevariantOfFirstLine[VARIANT].j;
            break;

        
    }
    addLine(ax, ay, bx, by);
    addChekpointInput(firstpointInput_i, firstpointInput_j);
    
};

void squareBoard::addLine(float ax, float ay, float bx, float by) {
    line.push_back(MyVertexArray());
    int size = line.size()-1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax, ay);
    line[size][0].color = sf::Color::Red;
    line[size][1].position = sf::Vector2f(bx, by);
    line[size][1].color = sf::Color::Red;
    

    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax + 0.5, ay + 0.5);
    line[size][0].color = sf::Color::Red;
    line[size][1].position = sf::Vector2f(bx + 0.5, by + 0.5);
    line[size][1].color = sf::Color::Red;
    
    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax - 0.5, ay - 0.5);
    line[size][0].color = sf::Color::Red;
    line[size][1].position = sf::Vector2f(bx - 0.5, by - 0.5);
    line[size][1].color = sf::Color::Red;
    
    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax + 1, ay + 1);
    line[size][0].color = sf::Color::Red;
    line[size][1].position = sf::Vector2f(bx + 1, by + 1);
    line[size][1].color = sf::Color::Red;
    
    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax - 1, ay - 1);
    line[size][0].color = sf::Color::Red;
    line[size][1].position = sf::Vector2f(bx - 1, by - 1);
    line[size][1].color = sf::Color::Red;

    ////std::cout << "sz of line="<<line.size() << std::endl;
}

void squareBoard::setMargintop(float mt) { 
    marginTop = mt;
}

float squareBoard::getMargintop() { return marginTop; }
float squareBoard::getMarginLeft(){ return marginLeft; }
float squareBoard::getsquareWidth() { return squareWidth; }
void squareBoard::setquestFigure(int qf) { questFigure = qf; }
coord point::getPixelCoord() {
    return coord(x, y);
};
coord point::getBoardCoord() {
    return coord(i, j);
};

bool squareBoard::clickPoint(bool trydrawLine){

   for (int i = 0; i < 6; ++i) {
        coord  position  = CheckPoint[i].getPixelCoord();
        int x0 = position.x;
        int y0 = position.y;
        int x1 = (float)x0 + CheckPoint[i].getSize();
        int y1 = (float)y0 + CheckPoint[i].getSize();



        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;
        
        if (M.x >= x0-25  && M.x<= x1+25  && M.y >= y0 - 25 && M.y <= y1 + 25) {
            
           
            ////std::cout << "clickPoint #" << CurrentClickpoint << std::endl;
            if (trydrawLine) {
                //std::cout << "line "<< i<<"->"<< getCurrentClickpoint() <<  std::endl;
                dellLastline();
                addLine((getCheckPoint())[getCurrentClickpoint()].getPixelCoord().x + CheckPoint[i].getSize() / 2,
                    (getCheckPoint())[getCurrentClickpoint()].getPixelCoord().y + +CheckPoint[i].getSize() / 2,
                    x0 + CheckPoint[i].getSize() / 2, y0 + CheckPoint[i].getSize() / 2
                );
                line[line.size()-1].setHold();
                if (i != CurrentClickpoint) {
                    addChekpointInput(i, CurrentClickpoint);
                    CurrentClickpoint = -1;
                }
                
            }
            else CurrentClickpoint = i;


            return true;

        } 

    }
    return false;

}

void squareBoard::draw() {


  /*  sf::Vector2f y0 = UserInputLine[0].getPoint(0);
    sf::Vector2f y1 = UserInputLine[0].getPoint(1);
    sf::Vector2f y2 = UserInputLine[0].getPoint(2);*/
    
    
  
    for (int i = 0; i < NN; i++) {
        if (!alreadyDraw) HorizLine[i].move(marginLeft,marginTop+ i * squareWidth);
        WindowLink.getWindow()->draw(HorizLine[i]);
        
    }
    for (int i = 0; i < MM; i++) {
        if (!alreadyDraw) VertLine[i].move(marginLeft+i* squareWidth, marginTop );
        WindowLink.getWindow()->draw(VertLine[i]);

    }
    for (int i = 0; i < CheckPoint.size(); i++)
        WindowLink.getWindow()->draw(CheckPoint[i]);
  
    for (int i = 0; i < line.size(); i++)
    {
        ////std::cout << "drawline " << line[i].getVertexCount() << std::endl;
        WindowLink.getWindow()->draw(line[i]);
        
    }
    



    alreadyDraw = true;
}

float point::getSize() { return size; }
void point::setSb(squareBoard* sBB) { Sb = sBB; }
void point::setPosition(float ii, float jj) { 
    int tmp = Sb->getsquareWidth();
    float squarefromVertical = static_cast<int>(Sb->getwidthsqareBord() / Sb->getsquareWidth());
    int point0 = (squarefromVertical - 28) / 2;
    i = ii;
    j = jj;
    x = Sb->getMarginLeft() + (point0+14*jj) * Sb->getsquareWidth() - (int)(getSize() / 2);
    y = Sb->getMargintop() + (6+14*ii) * Sb->getsquareWidth() - (int)(getSize() / 2);
    sf::RectangleShape::setPosition(x, y);
}

bool QuestType7::IsclearButtonClick() {
    const sf::Vector2i& M = sf::Mouse::getPosition(*getWindow());
    const sf::Vector2f& position = EraseButtonSprite.getPosition();
    const sf::IntRect& rect = EraseButtonSprite.getTextureRect();
    ////std::cout << scale << rect.width << std::endl;
    int x0 = position.x;
    int y0 = position.y;
    int x1 = x0 + rect.width ;
    int y1 = y0 + rect.height;


    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
        ////std::cout << "rect height = " << rect.height << " " << M.x << "*" << x0 << " " << M.x << "*" << x1 << " " << M.y << "*" << y0 << " " << M.y << "*" << y1 << std::endl;
        return true;
    }
    return false;

}

void squareBoard::eraseLines() {
    ChekpointInput.clear();
    line.clear();

    float ax, bx;
    float ay, by;

    ax = CheckPoint[firstpointInput_i].getPixelCoord().x + (CheckPoint[firstpointInput_i].getSize() / 2);
    ay = CheckPoint[firstpointInput_i].getPixelCoord().y + (CheckPoint[firstpointInput_i].getSize() / 2);

    bx = CheckPoint[firstpointInput_j].getPixelCoord().x + (CheckPoint[firstpointInput_i].getSize() / 2);
    by = CheckPoint[firstpointInput_j].getPixelCoord().y + (CheckPoint[firstpointInput_i].getSize() / 2);

    addLine(ax, ay, bx, by);
    addChekpointInput(firstpointInput_i, firstpointInput_j);
}

bool squareBoard::issegmentexsistinFigure(int segment) {
    unsigned long long tmp = result;
    while (tmp > 0) {
        if ((tmp % 100) == segment) return true;
        //std::cout << tmp << std::end;
        tmp = tmp / 100;
    }

    return false;
}

bool squareBoard::isfigureInputright(const unsigned long long* figureAnswer) {
    if (!issegmentexsistinFigure(firstpointInput_i*10+ firstpointInput_j)) return false;
    int size = sizeof(question7AnswersTriangle) / sizeof(*question7AnswersTriangle);
    for (int i = 0; i < size; i++)
        if (figureAnswer[i] == result) return true;

    return false;
}


QuestType7::QuestType7(int w, int h) :
    Window(w, h, ((rand() % 3)), 6),
    sB(w,h,*this) {
bool first = true;
    int margintopSlideButton = 0;    
    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);
    
    EraseButtonTexture.loadFromFile("resources/images/clear.png");
    EraseButtonSprite.setTexture(EraseButtonTexture);
    EraseButtonSprite.setPosition(sf::Vector2f(w-128, h - 128));

    sB.setquestFigure(question7Text[getQuestNumber()].key);
    QuestComment.settext(L"");
    
    

    sf::Event event;
    bool trydrawLine = false;
    while (window->isOpen()) {

        window->clear();


       
        window->draw(List);


        window->draw(textFrame.gettext());
        window->draw(CheckButtonSprite);
        window->draw(EraseButtonSprite);
        window->draw(QuestComment.gettext());
        sB.draw();
       
        

     


        window->display();

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor)) {
                    sB.sortChekpointInput();
                    sB.printChekpointInput();
                    switch (sB.getquestFigure())
                    {
                    case triangle:
                        if (sB.isfigureInputright(question7AnswersTriangle)) QuestComment.settext(CommentsDic[1]);
                        else QuestComment.settext(CommentsDic[2]);
                        break;


                    case rectangle:
                        if (sB.isfigureInputright(question7AnswersRectangle)) QuestComment.settext(CommentsDic[1]);
                        else QuestComment.settext(CommentsDic[2]);
                        break;


                    case square:
                        if (sB.isfigureInputright(question7AnswersSquare)) QuestComment.settext(CommentsDic[1]);
                        else QuestComment.settext(CommentsDic[2]);
                        break;
                    };
                    QuestComment.setmargin_top(h - QuestComment.getHeight()-50);


                }
                if (IsclearButtonClick()) {

                    sB.eraseLines();

                };
                sB.clickPoint(trydrawLine); trydrawLine = false;
                CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); 
                readyforCheck = true;
                CheckButtonSprite.setTexture(CheckButtonTexture);
                


            }
            int CurrentClickpointID = sB.getCurrentClickpoint();
            if (CurrentClickpointID >= 0) {
                coord XY;
                XY = sB.getCheckPoint()[CurrentClickpointID].getPixelCoord();
                const sf::Vector2i& M = sf::Mouse::getPosition(*window);               
                sf::VertexArray VA = sB.getLastline();
                ////std::cout << M.x << "x" << M.y << std::endl;
                sB.dellLastline();
                int szPoint = sB.getCheckPoint()[0].getSize() / 2;
                sB.addLine(XY.x+ szPoint, XY.y+ szPoint, M.x+ szPoint, M.y+ szPoint);
                trydrawLine = true;
                
            }
        }
    }

    //srand(time(0));
}


QuestType8::QuestType8(int w, int h)
    :Window(w, h, ((rand() % 4)), 7),
    setofpic0(*this),
    setofpic1(*this),
    setofpic2(*this),
    setofpic3(*this),

    plus(*this),
    minus(*this),
    thingsCount(0)
{
    



    bool first = true;
    int margintopSlideButton = 0;

    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);

   
    setofpic0.setButtonCount(1);
    setofpic1.setButtonCount(1);
    setofpic2.setButtonCount(1);
    setofpic3.setButtonCount(1);
    plus.setButtonCount(1);
    minus.setButtonCount(1);


    

    setofpic0.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "1");
    setofpic1.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "2");
    setofpic2.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "3");
    setofpic3.setpictureFilename("resources/images/" + filenamesforPicaQuest8[getQuestNumber()] + "0");

    plus.setpictureFilename("resources/images/" +  filenamesforPicaQuestPlus8[getQuestNumber()] );
    minus.setpictureFilename("resources/images/" + filenamesforPicaQuestMinus8[getQuestNumber()]);

    setofpic0.setMargin_left(0);
    setofpic0.CalcucateCoordinate(1);
    setofpic1.setMargin_left(setofpic0.getWidth());
    setofpic1.CalcucateCoordinate(1);
    setofpic2.setMargin_left(2*(setofpic1.getWidth() ));
    setofpic2.CalcucateCoordinate(1);
    setofpic3.setMargin_left(3 * (setofpic2.getWidth()  ));
    setofpic3.CalcucateCoordinate(1);

    plus.setMargin_left(0);
    plus.setisAdd();
    plus.CalcucateCoordinate(2);
    minus.setMargin_left(plus.getMarginLeft()+ plus.getWidth());
    
        minus.setMargin_top(500);
    minus.CalcucateCoordinate(2);
    
    sf::Event event;
    while (window->isOpen()) {
        window->clear();
        window->draw(List);

        if (first) {
            
            first = false;

            
            QuestComment.CalcucateCoordinate(h / 3,w/2);
            QuestComment.settext(L"");
            first = false;
            QuestComment.setmargin_top(h - minus.getHeight());
        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        window->draw(*setofpic0.getButtons()[0]);
        window->draw(*setofpic1.getButtons()[0]);
        window->draw(*setofpic2.getButtons()[0]);
        window->draw(*setofpic3.getButtons()[0]);
        window->draw(*plus.getButtons()[0]);
        window->draw(*minus.getButtons()[0]);
        window->draw(CheckButtonSprite);
        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor))
                    if (thingsCount==4) QuestComment.settext(CommentsDic[1]);
                    else QuestComment.settext(CommentsDic[2]);


                int thingsCounttmp = thingsCount;
                    thingsCount = minus.click(thingsCount, setofpic3) ; 
  
        
                    thingsCount = plus.click(thingsCount, setofpic3) ;
                    if (thingsCounttmp != thingsCount) {
                        CheckButtonTexture.loadFromFile("resources/images/arrow_up.png");
                        readyforCheck = true;
                    }
                
                    window->draw(*setofpic3.getButtons()[0]);


            }
        }
    }

    srand(time(0));
}

table::table( Window& wlink):WindowLink(wlink){
    for (int i = 0; i < 6; i++)
    {
        
        if (i < 5) {
            verticalline[i].resize(2);
            verticalline[i].setPrimitiveType(sf::LineStrip);
        }
        if (i < 4) {
            horizline[i].resize(2);
            horizline[i].setPrimitiveType(sf::LineStrip);
        }
    }
    float margintop = wlink.gettextFrame().getHeight() + wlink.gettextFrame().getmargin_top() + 15;

    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    text[0].setString(CommentsDic[6]);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Black);
    text[0].setPosition(sf::Vector2f(0, 0));
    text[0].setCharacterSize(WindowLink.gettextFrame().getSize()-15);  //WindowLink.getWindow()->draw(text[4]);

    float height0Row = text[0].getLocalBounds().height+10;
    float width0Row  = text[0].getLocalBounds().width + 30;
    float tableWidth = wlink.getWidth() * 2 / 3 - 10;
    float objectsrowWidth = (tableWidth + 10 - width0Row) / 3;
    mash_koeff =  (objectsrowWidth / 4) / 310;
    mash_width = objectsrowWidth / 4;
    mash_height = mash_width;




    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    text[0].setString(CommentsDic[3]);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Black);
    text[0].setPosition(sf::Vector2f(10, margintop-3));
    text[0].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);


    horizline[0][0].position= sf::Vector2f(10, margintop);
    horizline[0][1].position = sf::Vector2f(tableWidth, margintop);
    horizline[0][0].color = sf::Color::Black;
    horizline[0][1].color = sf::Color::Black;

    horizline[1][0].position = sf::Vector2f(10, margintop+ height0Row);
    horizline[1][1].position = sf::Vector2f(tableWidth, margintop + height0Row);
    horizline[1][0].color = sf::Color::Black;
    horizline[1][1].color = sf::Color::Black;
    
    text[4].setString(CommentsDic[6]);
    text[4].setFont(font);
    text[4].setFillColor(sf::Color::Black);
    text[4].setPosition(sf::Vector2f(10, margintop + height0Row));
    text[4].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);


    horizline[2][0].position = sf::Vector2f(10, margintop + height0Row+ 3 * mash_height);
    horizline[2][1].position = sf::Vector2f(tableWidth, margintop + height0Row + 3 * mash_height);
    horizline[2][0].color = sf::Color::Black;
    horizline[2][1].color = sf::Color::Black;


    horizline[3][0].position = sf::Vector2f(10, margintop + 6 * mash_height);
    horizline[3][1].position = sf::Vector2f(tableWidth, margintop + 6 * mash_height);
    horizline[3][0].color = sf::Color::Black;
    horizline[3][1].color = sf::Color::Black;



    verticalline[0][0].position = sf::Vector2f(10, margintop );
    verticalline[0][1].position = sf::Vector2f(10, margintop + 6 * mash_height);
    verticalline[0][0].color = sf::Color::Black;
    verticalline[0][1].color = sf::Color::Black;
    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    //text[4].setString(CommentsDic[3]);
    //text[4].setFont(font);
    //text[4].setFillColor(sf::Color::Black);
    //text[4].setPosition(sf::Vector2f(10, margintop));
    //text[4].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);


    verticalline[1][0].position = sf::Vector2f(width0Row, margintop);
    verticalline[1][1].position = sf::Vector2f(width0Row, margintop + 6*mash_height);
    verticalline[1][0].color = sf::Color::Black;
    verticalline[1][1].color = sf::Color::Black;
    text[1].setString(CommentsDic[4]);
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Black);
    text[1].setPosition(sf::Vector2f(width0Row, margintop - 3));
    text[1].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);
    mash_x = width0Row;
    mash_y = margintop + height0Row;


    verticalline[2][0].position = sf::Vector2f(width0Row + objectsrowWidth, margintop);
    verticalline[2][1].position = sf::Vector2f(width0Row + objectsrowWidth, margintop + 6 * mash_height);
    verticalline[2][0].color = sf::Color::Black;
    verticalline[2][1].color = sf::Color::Black;

    text[2].setString(CommentsDic[5]);
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::Black);
    text[2].setPosition(sf::Vector2f(width0Row + objectsrowWidth, margintop - 3));
    text[2].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);

    //text[5].setString(CommentsDic[4]);
    //text[5].setFont(font);
    //text[5].setFillColor(sf::Color::Black);
    //text[5].setPosition(sf::Vector2f(width0Row, margintop));
    //text[5].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);
    verticalline[3][0].position = sf::Vector2f(width0Row + 2* objectsrowWidth, margintop - 3);
    verticalline[3][1].position = sf::Vector2f(width0Row + 2* objectsrowWidth, margintop + 6 * mash_height);
    verticalline[3][0].color = sf::Color::Black;
    verticalline[3][1].color = sf::Color::Black;

    text[3].setString(CommentsDic[5]);
    text[3].setFont(font);
    text[3].setFillColor(sf::Color::Black);
    text[3].setPosition(sf::Vector2f(width0Row + 2 * objectsrowWidth, margintop - 3));
    text[3].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);


    verticalline[4][0].position = sf::Vector2f(width0Row + 3 * objectsrowWidth-10, margintop);
    verticalline[4][1].position = sf::Vector2f(width0Row + 3 * objectsrowWidth-10, margintop + 6 * mash_height);
    verticalline[4][0].color = sf::Color::Black;
    verticalline[4][1].color = sf::Color::Black;

    text[5].setString(CommentsDic[7]);
    text[5].setFont(font);
    text[5].setFillColor(sf::Color::Black); 
    text[5].setPosition(sf::Vector2f(10, margintop + height0Row + 3 * mash_height));
    text[5].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);

    //objectsrowWidth / 4 



    //text[6].setString(CommentsDic[4]);
    //text[6].setFont(font);
    //text[6].setFillColor(sf::Color::Black);
    //text[6].setPosition(sf::Vector2f(width0Row, margintop));
    //text[6].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);
  





}

void table::draw() {

    for (int i = 0; i < 6; i++)
    {

        //if (i < 5) WindowLink.getWindow()->draw(verticalline[i]);
        if (i < 4) {
            WindowLink.getWindow()->draw(horizline[i]);
        }
        if (i < 5) {
            WindowLink.getWindow()->draw(verticalline[i]);
        }
        WindowLink.getWindow()->draw(text[i]);
    }
    
    
    
}

QuestType9::QuestType9( int w, int h, int qtyButtons) :Window(w, h, ((rand() % 4)), 8),Buttons(qtyButtons, *this),
tab(*this){

    bool first=true;

    CheckButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    CheckButtonSprite.setTexture(CheckButtonTexture);
    sf::Event event;

    for (int i = 0; i < 13; i++)
    {
        MashTexture[i].loadFromFile(res_path + "mushroom.png" );
        MashSprite[i].setTexture(MashTexture[i]);
        BerryTexture[i].loadFromFile(res_path + "berry.png");
        BerrySprite[i].setTexture(BerryTexture[i]);
    }

    while (window->isOpen()) {
        window->clear();
        window->draw(List);
        tab.draw();
        if (first) {

            first = false;

            Buttons.CalcucateCoordinate(); first = false;
            QuestComment.CalcucateCoordinate(h / 3, w / 2);
            QuestComment.setmargin_top(h - Buttons.getHeight());
            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
            first = false;
            for (int i = 0; i < 4; i++) {
                MashSprite[i].setScale(tab.getmash_koeff(), tab.getmash_koeff());                
                MashSprite[i].setPosition(sf::Vector2f(tab.getmash_x()+i*
                    tab.getmash_width()
                    , tab.getmash_y()   ));

                BerrySprite[i].setScale(tab.getmash_koeff()+ 0.08, tab.getmash_koeff() + 0.08);
                BerrySprite[i].setPosition(sf::Vector2f(4*tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y()));

            }



            for (int i = 0; i < 4; i++) {
                MashSprite[i+4].setScale(tab.getmash_koeff(), tab.getmash_koeff());
                MashSprite[i+4].setPosition(sf::Vector2f(tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + tab.getmash_height()));

                BerrySprite[i+4].setScale(tab.getmash_koeff() + 0.08, tab.getmash_koeff() + 0.08);
                BerrySprite[i+4].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + tab.getmash_height()));

            }
            BerrySprite[8].setScale(tab.getmash_koeff() + 0.08, tab.getmash_koeff() + 0.08);
            BerrySprite[8].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x()  
                , tab.getmash_y() + tab.getmash_height()*2));


            for (int i = 0; i < 4; i++) {
                MashSprite[i + 8].setScale(tab.getmash_koeff(), tab.getmash_koeff());
                MashSprite[i + 8].setPosition(sf::Vector2f(tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + 3*tab.getmash_height()));


                BerrySprite[i + 9].setScale(tab.getmash_koeff() + 0.08, tab.getmash_koeff() + 0.08);
                BerrySprite[i + 9].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x() + i *
                    tab.getmash_width()
                    , tab.getmash_y() + 3 * tab.getmash_height()));

            }
/*            for (int i = 0; i < 4; i++) {
                BerrySprite[i + 13].setScale(tab.getmash_koeff() + 0.08, tab.getmash_koeff() + 0.08);
                BerrySprite[i + 13].setPosition(sf::Vector2f(4 * tab.getmash_width() + tab.getmash_x()
                    , tab.getmash_y() + 3 * tab.getmash_height()));
            }*/
            MashSprite[12].setScale(tab.getmash_koeff(), tab.getmash_koeff());
            MashSprite[12].setPosition(sf::Vector2f(tab.getmash_x() 
                , tab.getmash_y() + 4 * tab.getmash_height()));
            
        }
        window->draw(QuestComment.gettext());
        window->draw(textFrame.gettext());
        for (int bc = 0; bc < Buttons.getButtonCount(); bc++) {
            window->draw(*Buttons.getButtons()[bc]);
        }
        window->draw(CheckButtonSprite);
        for (int i = 0; i < 13; i++) {
            window->draw(MashSprite[i]);
            window->draw(BerrySprite[i]);
        }
        window->draw(BerrySprite[13]);
        window->draw(BerrySprite[14]);
        window->draw(BerrySprite[15]);
     

        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                //if (readyforCheck && checkandnextQuest(Settings::ButtonFactor))
                //    if (thingsCount == 4) QuestComment.settext(CommentsDic[1]);
                //    else QuestComment.settext(CommentsDic[2]);


                //int thingsCounttmp = thingsCount;
                //thingsCount = minus.click(thingsCount, setofpic3);


                //thingsCount = plus.click(thingsCount, setofpic3);
                //if (thingsCounttmp != thingsCount) {
                //    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png");
                //    readyforCheck = true;
                //}

                //window->draw(*setofpic3.getButtons()[0]);


            }
        }
    }

    srand(time(0));

}