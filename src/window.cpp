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

    int button_margin_left = 0;
    tmp.loadFromFile(pictureFilename+".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y && PICTURESIZE.x / PICTURESIZE.y >= 2)  PICTURESIZE.x /=  2;
    int ButtonSlideHeght = WindowLink.getHeight() / 3;
    
    float PICTURESIZE_W = PICTURESIZE.x;
    float PICTURESIZE_H = PICTURESIZE.y;
    //std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            //std::cout << "k=" << scale << std::endl;
            //std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
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
        //std::cout<<"here"<<std::endl;
        //2 rows
        
        float PICTURESIZE_W = PICTURESIZE.x;
        float PICTURESIZE_H = PICTURESIZE.y;
        //std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
         scale = PICTURESIZE_W  / (PICTURESIZE_W - 5);
        cout << "scale = "<<scale << endl;
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            //std::cout << "k=" << scale << std::endl;
            //std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
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
        //std::cout << "pica: scale=" << scale << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<" " <<(x1 - x0) << "x"<<(y1 - y0) << std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            //std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
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
    //std::cout << "scale" <<scale << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
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

    //std::cout << "text size=" << width << "x" << height << " size=" << size <<std::endl;
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
    //std::cout << Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf" << std::endl;
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
    //std::cout << questionNumber << " "<< beginQuestion2Index << std::endl;
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
    //std::cout << "numberQuest="<<numberQuest << std::endl;
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
    //std::cout<<"Check point" << std::endl;
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
  //std::cout << scale << rect.width << std::endl;
  int x0 = position.x;
  int y0 = position.y;
  int x1 = x0 + rect.width ;
  int y1 = y0 + rect.height ;
 
  
  if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {

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
                        //std::cout << Buttons.GetButtonsClickID() << std::endl;
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
                    //std::cout << Buttons.GetButtonsClickID()+1 = N- << std::endl;
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
                    //std::cout << "Button.click" << std::endl;
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
                if (Picture.click()) {
                    //std::cout << "Picture.click" << std::endl;
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
    //std::cout << fig1 << "," << fig2 << std::endl;

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
    //std::cout << "picture" << std::endl;
    sf::Vector2u PICTURESIZE = tmp.getSize();
    
    //std::cout << PICTURESIZE.x << std::endl;
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

    //std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
 
    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            //std::cout << "k=" << scale << std::endl;
            //std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
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
        //    //std::cout << "k=" << scale << std::endl;
        //    //std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        //} while (((BASKETPICTURESIZE_W *  +  5)) > WindowLink.getWidth() || BASKETPICTURESIZE_H + 5 > ButtonSlideHeght);
        //

        //basketSprite.setTexture(basketTexture);
        //basketSprite.setScale(BASKETSCALE, BASKETSCALE);
        //basketSprite.move(button_margin_left , ButtonSlideHeght);
    }
    else
    {
        //std::cout << PICTURESIZE.x << std::endl;
        //2 rows

        float PICTURESIZE_W = PICTURESIZE.x;
        float PICTURESIZE_H = PICTURESIZE.y;
        //std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            //std::cout << "k=" << scale << std::endl;
            //std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
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
    //std::cout << qtyButtons << std::endl;
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
                    //std::cout << Buttons.GetButtonsClickID()+1 = N- << std::endl;
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
                    //std::cout << "Button.click" << std::endl;
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
                if (PictureAndBasket.click()) {
                    //std::cout << "Picture.click" << std::endl;
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

       // std::cout << "closeNumber1 " << closeNumber1 << " " << closeNumber2 << " " << closeNumber3 << std::endl;
        
     
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
                    //std::cout << "TUTA: " <<usercloseNumberEnter[currentusercloseNumberIndex].closeNumber << " " << usercloseNumberEnter[currentusercloseNumberIndex].index<<std::endl;
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
                    //std::cout << "Button.click" << std::endl;
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

    int button_margin_left = 0;
    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y && PICTURESIZE.x / PICTURESIZE.y >= 2) { PICTURESIZE.x /= 3; coinWidth = PICTURESIZE.x; coinHeight = PICTURESIZE.y; }
    int ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = PICTURESIZE.x;
    float PICTURESIZE_H = PICTURESIZE.y;
    //std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            //std::cout << "k=" << scale << std::endl;
            //std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round(ButtonCount) + round((ButtonCount)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

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
    }
    else
    {
        //std::cout<<"here"<<std::endl;
        //2 rows

        float PICTURESIZE_W = PICTURESIZE.x;
        float PICTURESIZE_H = PICTURESIZE.y;
        //std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
        do {
            scale = scale - 0.01;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            //std::cout << "k=" << scale << std::endl;
            //std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) > WindowLink.getWidth() || 2 * PICTURESIZE_H + 5 > ButtonSlideHeght);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, ButtonSlideHeght);


            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;


            if (i + 1 == (int)(ButtonCount / 2)) {
                button_margin_left = 0; ButtonSlideHeght = ButtonSlideHeght + PICTURESIZE.y * scale + 5;
            }
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);

        }
    }

    //setScale(scale);

}
bool PicturetAndFilmtoView::click() {
    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        int x0 = position.x;
        int y0 = position.y;
        int x1 = (float)x0 + (float)rect.width * scale;
        int y1 = (float)y0 + (float)rect.height * scale;



        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;
        //std::cout << "scale" <<scale << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            //std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture CheckButtonTexture;
            sf::Sprite CheckButtonSprite(CheckButtonTexture);

            if (ButtonPressID < 0) {
                //fileName = "resources/images/digit" + std::to_string(ButtonPressID + 1) + ".jpg";
                delay(1000);
                MyTexture[0]->loadFromFile(pictureFilename+".png", sf::IntRect(coinWidth, 0, coinWidth * 2, coinHeight));
                delay(1000);
                MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(coinWidth * 2, 0, coinWidth * 3, coinHeight));
                ButtonPressID = -1;
                
            }
            //fileName = "resources/images/digit" + std::to_string(i + 1) + "_select.jpg";
            ButtonPressID = i;

            //MyTexture[i]->loadFromFile(fileName);

            //w->draw(*Buttons[i]);
            //w->display();
            return true;

        } //else std::cout << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 << std::endl;
        //Buttons = Buttons.get()+1;

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
    if (coinRandomIndex == 0) {
        coin1.setpictureFilename("resources/images/moneta10");
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
    }

    coin1.setMargin_left(10);
    coin1.setMargin_top(textFrame.getHeight() * 2);

    coin1.CalcucateCoordinate();

    coin1.setButtonCount(1);

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


        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {


                }
                if (Buttons.click()) {
                    //std::cout << "Button.click" << std::endl;
                    CheckButtonTexture.loadFromFile("resources/images/arrow_up.png"); readyforCheck = true;
                    CheckButtonSprite.setTexture(CheckButtonTexture);
                }
                if (coin1.click()) {
                    //std::cout << "Picture.click" << std::endl;
                }


            }
        }
    }

    srand(time(0));
}



