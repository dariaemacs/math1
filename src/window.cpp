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
#include <math.h>

#include "QuestType2.hpp"

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

void mySpriteCheckButton::setTop(float t) { top = t; }
void mySpriteCheckButton::setLeft(float l) { left = l; }


int CheckButton::GenerateRandomSetNumber() {
    int SIZE = sizeof(question10VariantForRandom1) / sizeof(*question10VariantForRandom1);
    return rand() % SIZE;
}
float CheckButton::getHeightText() {
    return str[0].getLocalBounds().height;
}
float CheckButton::getWidthText(int index) {
    return str[index].getLocalBounds().width;
}

bool CheckButton::click() {
    for (int i = 0; i < 4; ++i) {
        const sf::Vector2f& position = quadroSprite[i].getPosition();
        const sf::IntRect& rect = quadroSprite[i].getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * coeff;
        float y1 = (float)y0 + (float)rect.height * coeff;
        const sf::Vector2i& M = sf::Mouse::getPosition(*wLnk.getWindow());
        if (M.x >= x0 && M.x <= x1 + getWidthText(i) + textmarginleft && M.y >= y0 && M.y <= y1) {
            std::cout << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 << std::endl;
            if (clickID >= 0) {
                quadroSprite[clickID].setActive();
                quadroTexture[clickID].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + quadroSprite[i].getFN());
            }
            clickID = i;
            quadroSprite[i].setActive();
            quadroTexture[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + quadroSprite[i].getFN());
            if (!quadroSprite[i].getActive()) clickID = -1;

            return true;
        }
    }

    return false;
}
unsigned char CheckButton11::getanswerNUMBER() {
    return answerNUMBER;
};
bool CheckButton11::isAnswerRight(int i, int question11Variant3ID, int question11Variant1ID) {

    if (question11Variant1ID == 0)  //увеличение
    {
        if (question11ALLVariants[question11Variant3ID][i] == 0 || question11ALLVariants[question11Variant3ID][i] == 3) return true;
    }
    else {
        if (question11ALLVariants[question11Variant3ID][i] == 1 || question11ALLVariants[question11Variant3ID][i] == 2) return true;
    }

    return false;
}

bool CheckButton11::click(int question11Variant3ID) {
    for (int i = 0; i < 4; ++i) {
        const sf::Vector2f& position = getSprite()[i].getPosition();
        const sf::IntRect& rect = getSprite()[i].getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * coeff;
        float y1 = (float)y0 + (float)rect.height * coeff;
        const sf::Vector2i& M = sf::Mouse::getPosition(*wLnk.getWindow());
        if (M.x >= x0 && M.x <= x1 + getWidthText(i) + textmarginleft && M.y >= y0 && M.y <= y1) {
            getSprite()[i].setActive();
            getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + getSprite()[i].getFN());
            unsigned char tmp = question11ALLVariants[question11Variant3ID][i];
            answerNUMBER = ((1 << tmp)) ^ answerNUMBER;
            clickID = ((1 << i)) ^ clickID;
           std::cout << "clickID=" << clickID << std::endl;
            return true;
        }
    };

    return false;
};
void CheckButton11::resetclickID() { clickID = 0; };
std::wstring get_wstr(int questvariantIndex, int ordNumber) {
    //    setlocale(LC_ALL, "Russian");
    std::stringstream ss;
    ss << (ordNumber+1) << ". ";
    std::string str = ss.str();

    std::wstring ws(str.begin(), str.end());
    ws += qestionarrayList[ordNumber][questvariantIndex].questionText.c_str();

    return ws;
}
float TextFrameBase::getHeight() {
    std::cout << "h=" << text.getLocalBounds().height << std::endl;
    return text.getLocalBounds().height;
}


void PicturetoView::CalcucateCoordinate() {
    using namespace std;
    sf::Texture tmp;

    float button_margin_left = margin_left;
    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y&& PICTURESIZE.x / PICTURESIZE.y >= 2)  PICTURESIZE.x /= 2;
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    unsigned int PICTURESIZE_W = PICTURESIZE.x;
    width = static_cast<float>(PICTURESIZE.x);
    unsigned int PICTURESIZE_H = PICTURESIZE.y;
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = static_cast<float>(PICTURESIZE_W) / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = static_cast<unsigned int>(PICTURESIZE.x * scale);
            PICTURESIZE_H = static_cast<unsigned int>(PICTURESIZE.y * scale);
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
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
        ////std::cout<<"here"<<std::endl;
        //2 rows

        int PICTURESIZE_W = PICTURESIZE.x;
        int PICTURESIZE_H = PICTURESIZE.y;
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = static_cast<float>(PICTURESIZE_W) / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = static_cast<unsigned int>(PICTURESIZE.x * scale);
            PICTURESIZE_H = static_cast<unsigned int>(PICTURESIZE.y * scale);
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

bool PicturetoView::click() {





    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * scale;
        float y1 = (float)y0 + (float)rect.height * scale;


        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());

        x1 = x1;
        ////std::cout << "pica: scale=" << scale << "i=" << i << " M.x=" << M.x << " M.y=" << M.y << " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<" " <<(x1 - x0) << "x"<<(y1 - y0) << std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture ArrowButtonTexture;
            sf::Sprite ArrowButtonSprite(ArrowButtonTexture);

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
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * scale;
        float y1 = (float)y0 + (float)rect.height * scale;



        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;
        ////std::cout << "scale" <<scale << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture ArrowButtonTexture;
            sf::Sprite ArrowButtonSprite(ArrowButtonTexture);

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
Buttons::Buttons(int qtyButton, Window& w) :WindowLink(w), ButtonCount(qtyButton) {

}
Buttons::Buttons(Window& w) : WindowLink(w) {}

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

void TextFrameBase::CalcucateCoordinate(const float w, const float h) {
    size = 50;
    text.setCharacterSize(static_cast<unsigned int>(size));
    float width = text.getLocalBounds().width; float height = text.getLocalBounds().height;
    while (width > w || height > h){
        if (size > 0) { size--;  text.setCharacterSize(static_cast<unsigned int>(size)); }
        else return;
        width =  text.getLocalBounds().width;
        height = text.getLocalBounds().height;
    }
  
    margin_top = text.getLocalBounds().top;
}

PicturetoView::PicturetoView(QuestType2& qtl, std::string fn) : Buttons(0, qtl), pictureFilename(fn) {};
//PicturetoView(QuestType2&, std::string)
void Buttons::CalcucateCoordinate(float hieght) {
    float ButtonSize = (WindowLink.getWidth() * 2 / 3 - 50) / 10;
    float step = 5;
    float margin_left_button;
    float margin_top_button;
    if (ButtonCount >= 10)
    {
        while (ButtonSize + 10 > hieght / 2) ButtonSize--;
        margin_left_button = WindowLink.getWidth() - (ButtonSize * 10 + 50);
        margin_top_button = WindowLink.getHeight() - ButtonSize * 2 - 5;
    }
    else {
        while (ButtonSize + 10 > hieght) ButtonSize--;
        margin_left_button = WindowLink.getWidth() - (ButtonSize * ButtonCount + 50);
        margin_top_button = WindowLink.getHeight() - hieght;
    };
    margin_left = margin_left_button;
    margin_top = margin_top_button;
    for (int i = 0; i < ButtonCount; i++) {
        std::string pictureFilename = "resources/images/digit" + std::to_string(i + 1) + ".jpg";
        std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
        txt->loadFromFile(pictureFilename);
        static sf::Vector2u PICTURESIZE = txt->getSize();
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(*txt.get());
        if (i == 0) scale = (float)ButtonSize / PICTURESIZE.y;
        sprite->setScale(scale, scale);

        sprite->move(margin_left_button, margin_top_button);
        if ((i + 1) % 10 == 0 && i + 1 > 0) {
            margin_left_button = margin_left;
            margin_top_button += (ButtonSize + 5);
        }
        else
            margin_left_button += (5 + ButtonSize);
        MyTexture.emplace_back(std::move(txt));
        ButtonsList.emplace_back(std::move(sprite));
    }
    height = ButtonSize;
    width = ButtonSize;
}
void Buttons::CalcucateCoordinate() {
    using namespace std;
   float ButtonSlideHeght = WindowLink.getHeight() / 3;
    float step = 0;
    float  ButtonSize = (WindowLink.getWidth() / 11) * 2 / 3;
    height = ButtonSize;
    while (ButtonSize + 10 > ButtonSlideHeght / 2) ButtonSize--;
    step = ButtonSize / 5;
    if (ButtonCount > 11) margin_top = WindowLink.getHeight() - (ButtonSize + step) * 2; else margin_top = WindowLink.getHeight() - (ButtonSize + step);
    margin_left = WindowLink.getWidth() - 11 * (ButtonSize + step);
    float margin_left_button = margin_left;
    float margin_top_button = margin_top;
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
        if (i % 10 == 0 && i > 0) {
            //cout << "here***rr" << ButtonCount << std::endl;
            margin_top_button = margin_top_button + ButtonSize + 10; margin_left_button = WindowLink.getWidth() - 11 * (ButtonSize + step);
        }
        else margin_left_button = margin_left_button + ButtonSize + step;
        MyTexture.emplace_back(std::move(txt));
        ButtonsList.emplace_back(std::move(sprite));
    };
    height = ButtonSize;
    width = ButtonSize;

}


TextFrameBase::TextFrameBase(float s, Window& winLink, char) :size(s), WindowLink(winLink) { //delegate
    ////std::cout << Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf" << std::endl;
    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");

    text = sf::Text("", font, static_cast<unsigned int>(s));
    text.setFillColor(sf::Color::Black);
    text.setPosition(Settings::PADDING, Settings::PADDING);
}

TextFrameBase::TextFrameBase(float s, std::wstring str, float w1, float h1, Window& winLink) :TextFrameBase(s, winLink, 'c') {
    w = w1;
    h = h1;
    text.setString(str);
}

void TextFrameBase::setmargin_top(float m) {
    sf::Vector2f pos = text.getPosition();
    text.setPosition(pos.x, m);
    margin_top = m;
}

TextFrameBase::TextFrameBase(float s, int quest, int w, int h, Window& winLink)
    :TextFrameBase(s, winLink, 'c') {
    questionNumber = quest;
    text.setString(get_wstr(quest, winLink.getordQuestNumber()));


    CalcucateCoordinate(static_cast<float>(w) * 18 / 19, static_cast<float>(h));



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
    for (int x = 0; x < X - 1; x++) {
        replaceFrom = phrasestoReplace[questionNumber][x].find;
        replaceTo = phrasestoReplace[questionNumber][x].replace;
        posn = question.find(replaceFrom);
        if (posn < question.length()) { question.replace(posn, replaceFrom.length(), replaceTo); }

    }

    text.setString(question);

}

Window::Window(float w, float h, int numberQuest, int ord)

    : badAnswer(false),
    ordQuestNumber(ord),
    questNumber(numberQuest),
    readyforCheck(false),
    first(true),
    textFrame(Settings::QUESTFONTSIZE, numberQuest, static_cast<unsigned int>(w), static_cast<unsigned int>(h), *this),
    QuestComment(Settings::QUESTFONTSIZE, CommentsDic[0], w, h, *this),
    countofBALL(0)
{

    width = w;
    height = h;
    std::string CheckButtonPictureFileName = "resources/images/arrow_disable.png";
    ArrowButtonTexture.loadFromFile(CheckButtonPictureFileName);
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    ArrowButtonSprite.scale(Settings::ButtonFactor, Settings::ButtonFactor);
    const sf::IntRect& CheckButtonRect = ArrowButtonSprite.getTextureRect();
    float CheckButtonWidth = CheckButtonRect.width * Settings::ButtonFactor;
    ArrowButtonSprite.move(width - CheckButtonWidth, 0);
    //
    List.setSize(sf::Vector2f(width, height));
    List.setPosition(0, 0);
    List.setFillColor(sf::Color::White);
    sf::Clock clock;

    //sf::ContextSettings settings(0,0,8);


    //if (!first) {
    std::string comment = std::string("Game ") + std::to_string(static_cast<unsigned int>(w)) + "x" + std::to_string(static_cast<unsigned int>(h));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(static_cast<unsigned int>(w), static_cast<unsigned int>(h)), comment, sf::Style::Default, settings);//,  sf::Style::Fullscreen);
    window->setFramerateLimit(static_cast<unsigned int>(Settings::FPS));
    ////std::cout<<"Check point" << std::endl;
    //window->~RenderWindow();



}




bool Window::checkandnextQuest(float scale) {

    const sf::Vector2i& M = sf::Mouse::getPosition(*window);
    const sf::Vector2f& position = ArrowButtonSprite.getPosition();
    const sf::IntRect& rect = ArrowButtonSprite.getTextureRect();
    ////std::cout << scale << rect.width << std::endl;
    float x0 = position.x;
    float y0 = position.y;
    float x1 = x0 + rect.width * Settings::ButtonFactor;
    float y1 = y0 + rect.height * Settings::ButtonFactor;


    if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
        ////std::cout << "rect height = "<< rect.height <<" "<< M.x <<"*"<< x0 << " " << M.x <<"*"<< x1 <<" " << M.y <<"*"<< y0 <<" " << M.y <<"*"<< y1<< std::endl;
        return true;
    }
    return false;
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
    float PICTURESIZEy = static_cast<float>(PICTURESIZE.y);
    if (PICTURESIZE.x > PICTURESIZE.y && ((float)PICTURESIZE.x / (float)PICTURESIZE.y) >= 1.5) {
        PICTURESIZE.x /= 2;
    }

    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
    float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
    float BASKETPICTURESIZE_W = 0;
    float BASKETPICTURESIZE_H = 0;
    float BASKETSCALE = 1;

    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = PICTURESIZE.x * scale;
            PICTURESIZE_H = PICTURESIZE.y * scale;
            ////std::cout << "k=" << scale << std::endl;
            ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
        } while (((PICTURESIZE_W * round(ButtonCount + 2) + round((ButtonCount + 2)) * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);

        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(static_cast<float>(button_margin_left), static_cast<float>(ButtonSlideHeght));
            button_margin_left = static_cast<int>(button_margin_left + 5 + PICTURESIZE.x * scale);
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

        float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
        float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

        do {
            scale = scale - 0.01f;
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
            sprite->move(static_cast<float>(button_margin_left), static_cast<float>(ButtonSlideHeght));


            button_margin_left = static_cast<int>(button_margin_left + 5 + PICTURESIZE.x * scale);

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
        BASKETSCALE = BASKETSCALE - 0.01f;
        BASKETPICTURESIZE_W = BASKETPICTURESIZE.x * BASKETSCALE;
        BASKETPICTURESIZE_H = BASKETPICTURESIZE.y * BASKETSCALE;
    } while (((BASKETPICTURESIZE_W * +5)) > WindowLink.getWidth() || BASKETPICTURESIZE_H + 5 > ButtonSlideHeght);


    basketSprite.setTexture(basketTexture);
    basketSprite.setScale(BASKETSCALE, BASKETSCALE);
    basketSprite.move(static_cast<float>(button_margin_left), static_cast<float>((BASKETPICTURESIZE_H / BASKETPICTURESIZE_W >= 1.5 ?
        (WindowLink.getHeight() - BASKETPICTURESIZE_H) / 2 : WindowLink.getHeight() / 3)));
}









void PicturetAndFilmtoView::CalcucateCoordinate() {
    using namespace std;
    sf::Texture tmp;


    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y&& PICTURESIZE.x / PICTURESIZE.y >= 2) { PICTURESIZE.x /= 3; coinWidth = static_cast<float>(PICTURESIZE.x); coinHeight = static_cast<float>(PICTURESIZE.y); }
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
    float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01f;
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

        float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
        float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
        ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
        scale = PICTURESIZE_W / (PICTURESIZE_W - 5);
        cout << "scale = " << scale << endl;
        do {
            scale = scale - 0.01f;
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
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    float PICTURESIZE_W = static_cast<float>(PICTURESIZE.x);
    float PICTURESIZE_H = static_cast<float>(PICTURESIZE.y);
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = PICTURESIZE_W / (PICTURESIZE_W - 5);


    do {
        scale = scale - 0.01f;
        PICTURESIZE_W = PICTURESIZE.x * scale;
        PICTURESIZE_H = PICTURESIZE.y * scale;
        ////std::cout << "k=" << scale << std::endl;
        ////std::cout << "L="<< ((PICTURESIZE_W * round((float)ButtonCount / 2) + round(((float)ButtonCount) / 2) * 5)) << " QTY="<< round((float)ButtonCount / 2) << std::endl;
    } while (((PICTURESIZE_W * 6 + 6 * 5)) > WindowLink.getWidth() || PICTURESIZE_H + 5 > ButtonSlideHeght);


    std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
    txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
    ////std::cout << "first loadFromFile" << std::endl;
    std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*txt.get());
    sprite->setScale(scale, scale);
    if (where == 1) sprite->move(margin_left, ButtonSlideHeght); else
        if (where == 2) {
            if (isAdd) margin_left = (WindowLink.getWidth() - PICTURESIZE_W * 2) / 2;
            sprite->move(margin_left, WindowLink.getHeight() - PICTURESIZE_H);
        }
    MyTexture.emplace_back(std::move(txt));
    ButtonsList.emplace_back(std::move(sprite));
    isblackSide.push_back(true);
    width = PICTURESIZE_W;
    height = PICTURESIZE_H;
}

bool PicturetAndFilmtoView::click() {
    const int speedRotation = 100;
    for (int i = 0; i < ButtonCount; ++i) {
        const sf::Vector2f& position = ButtonsList[i]->getPosition();
        const sf::IntRect& rect = ButtonsList[i]->getTextureRect();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * scale;
        float y1 = (float)y0 + (float)rect.height * scale;

        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;
        ////std::cout << "scale" <<scale << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            ////std::cout << "i=" << i<<" M.x="<< M.x << " M.y=" << M.y<< " x0=" << x0 << " y0=" << y0 << " x1=" << x1 << " y1=" << y1 <<std::endl;
            sf::Texture ArrowButtonTexture;
            sf::Sprite ArrowButtonSprite(ArrowButtonTexture);


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

                        MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(static_cast<int>(coinWidth), 0, static_cast<int>(coinWidth * 2), static_cast<int>(coinHeight)));
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
                            MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(static_cast<int>(coinWidth * 2), 0, static_cast<int>(coinWidth * 3), static_cast<int>(coinHeight)));
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
                        MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(static_cast<int>(coinWidth), 0, static_cast<int>(coinWidth * 2), static_cast<int>(coinHeight)));
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
                            MyTexture[0]->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, static_cast<int>(coinWidth), static_cast<int>(coinHeight)));
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


point::point(float sz) :x(0), y(0), i(0), j(0), Sb(0), size(sz), sf::RectangleShape() {
    sf::RectangleShape::setPosition(0, 0);
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
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + (float)rect.width * scale;
        float y1 = (float)y0 + (float)rect.height * scale;

        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;

        if (M.x >= x0 && M.x <= x1 && M.y >= y0 && M.y <= y1) {
            std::string fileName = "";
            sf::Texture ArrowButtonTexture;
            sf::Sprite ArrowButtonSprite(ArrowButtonTexture);
            //std::cout << "**" << std::to_string(qty) << std::endl;
            if (isAdd && qty<5) qty++; 
            if (qty > 0 && !isAdd) qty--;
            if (qty >= 0) {
                fileName = "resources/images/" + filenamesforPicaQuest8[WindowLink.getQuestNumber()] + std::to_string(qty);
                //WindowLink.setofpic3.loadFromFile(fileName + ".png"); //ButtonPressID = -1;
                // std::cout << std::to_string(qty) << std::endl;
                (lastpic.getButtonTexture()[0])->loadFromFile(fileName + ".png"); //ButtonPressID = -1;;

            }


        }
    }
    return qty;
}

squareBoard::squareBoard(float ww, float hh, Window& wl) : w(ww), h(hh), questFigure(wl.getQuestNumber()), squareWidth(0), alreadyDraw(false),
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
    for (int i = 0; i < NN + 1; i++)
    {
        HorizLine.push_back(sf::RectangleShape());
        HorizLine[i].setSize(sf::Vector2f(ww - 2 * marginLeft, 1));
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
  

    for (unsigned int i = 0; i < CheckPoint.size(); i++)
        CheckPoint[i].setFillColor(sf::Color::Blue);

    CheckPoint[0].setPosition(0, 0);
    CheckPoint[1].setPosition(0, 1);
    CheckPoint[2].setPosition(0, 2);

    CheckPoint[3].setPosition(1, 0);
    CheckPoint[4].setPosition(1, 1);
    CheckPoint[5].setPosition(1, 2);
    ////std::cout << question7Text[questFigure].key << std::endl;
    float ax, bx;
    float ay, by;
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
    addLine(ax, ay, bx, by, sf::Color::Green);
    addChekpointInput(firstpointInput_i, firstpointInput_j);

};
//void squareBoard::(float ax, float ay, float bx, float by) {
void squareBoard::viewVariant(const long long figuraCoord) {


    int i = 0;
    long long currentLine = 0;
    int length = log10(figuraCoord) + 1;
    long long Tentodegree;
    float ax, bx;
    float ay, by;
    for (int i = 0; (Tentodegree = pow(10, static_cast<int>(log10(figuraCoord) + 1) - 2 * (i + 1))) >= 1; i++) {
        currentLine = figuraCoord / Tentodegree;
        currentLine = currentLine - (static_cast<long long>(currentLine / 100)) * 100;
        ax = CheckPoint[currentLine / 10].getPixelCoord().x + (CheckPoint[currentLine / 10].getSize() / 2);
        ay = CheckPoint[currentLine / 10].getPixelCoord().y + (CheckPoint[currentLine / 10].getSize() / 2);
        bx = CheckPoint[(currentLine % 10) ].getPixelCoord().x + (CheckPoint[(currentLine % 10) ].getSize() / 2);
        by = CheckPoint[(currentLine % 10) ].getPixelCoord().y + (CheckPoint[(currentLine % 10) ].getSize() / 2);
        addLine(ax, ay, bx, by,sf::Color::Red);
    }
}
void squareBoard::addLine(float ax, float ay, float bx, float by, sf::Color Color) {
    line.push_back(MyVertexArray());
    size_t size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax, ay);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx, by);
    line[size][1].color = Color;


    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax + 0.5f, ay + 0.5f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx + 0.5f, by + 0.5f);
    line[size][1].color = Color;

    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax - 0.5f, ay - 0.5f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx - 0.5f, by - 0.5f);
    line[size][1].color = Color;

    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax + 1.0f, ay + 1.0f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx + 1.0f, by + 1.0f);
    line[size][1].color = Color;

    line.push_back(MyVertexArray());
    size = line.size() - 1;
    line[size].setPrimitiveType(sf::LineStrip);
    line[size].resize(2);
    line[size][0].position = sf::Vector2f(ax - 1.0f, ay - 1.0f);
    line[size][0].color = Color;
    line[size][1].position = sf::Vector2f(bx - 1.0f, by - 1.0f);
    line[size][1].color = Color;


}

void squareBoard::setMargintop(float mt) {
    marginTop = mt;
}

float squareBoard::getMargintop() { return marginTop; }
float squareBoard::getMarginLeft() { return marginLeft; }
float squareBoard::getsquareWidth() { return squareWidth; }
void squareBoard::setquestFigure(int qf) { questFigure = qf; }
coord point::getPixelCoord() {
    return coord(x, y);
};
coord point::getBoardCoord() {
    return coord(i, j);
};

bool squareBoard::clickPoint(bool trydrawLine) {

    for (int i = 0; i < 6; ++i) {
        coord  position = CheckPoint[i].getPixelCoord();
        float x0 = position.x;
        float y0 = position.y;
        float x1 = (float)x0 + CheckPoint[i].getSize();
        float y1 = (float)y0 + CheckPoint[i].getSize();



        const sf::Vector2i& M = sf::Mouse::getPosition(*WindowLink.getWindow());
        x1 = x1;

        if (M.x >= x0 - 25 && M.x <= x1 + 25 && M.y >= y0 - 25 && M.y <= y1 + 25) {


            ////std::cout << "clickPoint #" << CurrentClickpoint << std::endl;
            if (trydrawLine) {
                //std::cout << "line "<< i<<"->"<< getCurrentClickpoint() <<  std::endl;
                dellLastline();
                addLine((getCheckPoint())[getCurrentClickpoint()].getPixelCoord().x + CheckPoint[i].getSize() / 2,
                    (getCheckPoint())[getCurrentClickpoint()].getPixelCoord().y + +CheckPoint[i].getSize() / 2,
                    x0 + CheckPoint[i].getSize() / 2, y0 + CheckPoint[i].getSize() / 2,sf::Color::Green
                );
                line[line.size() - 1].setHold();
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
        if (!alreadyDraw) HorizLine[i].move(marginLeft, marginTop + i * squareWidth);
        WindowLink.getWindow()->draw(HorizLine[i]);

    }
    for (int i = 0; i < MM; i++) {
        if (!alreadyDraw) VertLine[i].move(marginLeft + i * squareWidth, marginTop);
        WindowLink.getWindow()->draw(VertLine[i]);

    }
    for (unsigned int i = 0; i < CheckPoint.size(); i++)
        WindowLink.getWindow()->draw(CheckPoint[i]);

    for (unsigned int i = 0; i < line.size(); i++)
    {
        ////std::cout << "drawline " << line[i].getVertexCount() << std::endl;
        WindowLink.getWindow()->draw(line[i]);

    }




    alreadyDraw = true;
}

float point::getSize() { return size; }
void point::setSb(squareBoard* sBB) { Sb = sBB; }
void point::setPosition(float ii, float jj) {
    float tmp = Sb->getsquareWidth();
    float squarefromVertical = Sb->getwidthsqareBord() / Sb->getsquareWidth();
    float point0 = (squarefromVertical - 28) / 2;
    i = ii;
    j = jj;
    x = Sb->getMarginLeft() + (point0 + 14 * jj) * Sb->getsquareWidth() - static_cast<unsigned int>(getSize() / 2);
    y = Sb->getMargintop() + (6 + 14 * ii) * Sb->getsquareWidth() - static_cast<unsigned int>(getSize() / 2);
    sf::RectangleShape::setPosition(x, y);
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

    addLine(ax, ay, bx, by,sf::Color::Green);
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
    if (!issegmentexsistinFigure(firstpointInput_i * 10 + firstpointInput_j)) return false;
    int size = sizeof(question7AnswersTriangle) / sizeof(*question7AnswersTriangle);
    for (int i = 0; i < size; i++)
        if (figureAnswer[i] == result) return true;

    return false;
}








table::table(Window& wlink) :WindowLink(wlink) {
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
    text[0].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);  //WindowLink.getWindow()->draw(text[4]);

    float height0Row = text[0].getLocalBounds().height + 10;
    float width0Row = text[0].getLocalBounds().width + 30;
    float tableWidth = wlink.getWidth() * 2 / 3 - 10;
    float objectsrowWidth = (tableWidth + 10 - width0Row) / 3;
    mash_koeff = (objectsrowWidth / 4) / 310;
    mash_width = objectsrowWidth / 4;
    mash_height = mash_width;




    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    text[0].setString(CommentsDic[3]);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Black);
    text[0].setPosition(sf::Vector2f(10, margintop - 3));
    text[0].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);


    horizline[0][0].position = sf::Vector2f(10, margintop);
    horizline[0][1].position = sf::Vector2f(tableWidth, margintop);
    horizline[0][0].color = sf::Color::Black;
    horizline[0][1].color = sf::Color::Black;

    horizline[1][0].position = sf::Vector2f(10, margintop + height0Row);
    horizline[1][1].position = sf::Vector2f(tableWidth, margintop + height0Row);
    horizline[1][0].color = sf::Color::Black;
    horizline[1][1].color = sf::Color::Black;

    text[4].setString(CommentsDic[6]);
    text[4].setFont(font);
    text[4].setFillColor(sf::Color::Black);
    text[4].setPosition(sf::Vector2f(10, margintop + height0Row));
    text[4].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);


    horizline[2][0].position = sf::Vector2f(10, margintop + height0Row + 3 * mash_height);
    horizline[2][1].position = sf::Vector2f(tableWidth, margintop + height0Row + 3 * mash_height);
    horizline[2][0].color = sf::Color::Black;
    horizline[2][1].color = sf::Color::Black;


    horizline[3][0].position = sf::Vector2f(10, margintop + 6 * mash_height);
    horizline[3][1].position = sf::Vector2f(tableWidth, margintop + 6 * mash_height);
    horizline[3][0].color = sf::Color::Black;
    horizline[3][1].color = sf::Color::Black;



    verticalline[0][0].position = sf::Vector2f(10, margintop);
    verticalline[0][1].position = sf::Vector2f(10, margintop + 6 * mash_height);
    verticalline[0][0].color = sf::Color::Black;
    verticalline[0][1].color = sf::Color::Black;
    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");

    verticalline[1][0].position = sf::Vector2f(width0Row, margintop);
    verticalline[1][1].position = sf::Vector2f(width0Row, margintop + 6 * mash_height);
    verticalline[1][0].color = sf::Color::Black;
    verticalline[1][1].color = sf::Color::Black;
    text[1].setString(CommentsDic[4]);
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Black);
    text[1].setPosition(sf::Vector2f(width0Row, margintop - 3));
    text[1].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
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
    text[2].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);

    //text[5].setString(CommentsDic[4]);
    //text[5].setFont(font);
    //text[5].setFillColor(sf::Color::Black);
    //text[5].setPosition(sf::Vector2f(width0Row, margintop));
    //text[5].setCharacterSize(WindowLink.gettextFrame().getSize() - 15);
    verticalline[3][0].position = sf::Vector2f(width0Row + 2 * objectsrowWidth, margintop - 3);
    verticalline[3][1].position = sf::Vector2f(width0Row + 2 * objectsrowWidth, margintop + 6 * mash_height);
    verticalline[3][0].color = sf::Color::Black;
    verticalline[3][1].color = sf::Color::Black;
    tablemax_y = margintop + 6 * mash_height;

    text[3].setString(CommentsDic[5]);
    text[3].setFont(font);
    text[3].setFillColor(sf::Color::Black);
    text[3].setPosition(sf::Vector2f(width0Row + 2 * objectsrowWidth, margintop - 3));
    text[3].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);


    verticalline[4][0].position = sf::Vector2f(width0Row + 3 * objectsrowWidth - 10, margintop);
    verticalline[4][1].position = sf::Vector2f(width0Row + 3 * objectsrowWidth - 10, margintop + 6 * mash_height);
    verticalline[4][0].color = sf::Color::Black;
    verticalline[4][1].color = sf::Color::Black;

    text[5].setString(CommentsDic[7]);
    text[5].setFont(font);
    text[5].setFillColor(sf::Color::Black);
    text[5].setPosition(sf::Vector2f(10, margintop + height0Row + 3 * mash_height));
    text[5].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);

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
table3_5::table3_5(Window& w) :WindowLink(w) {

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

    margintop = w.getHeight() / 3;

    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    if (maximal(question14TextColumn[w.getquestionVariantID1()][0].length(), 17) == 17)
        text[0].setString(CommentsDic[11]); else  text[0].setString(question14TextColumn[w.getquestionVariantID1()][0]);
    text[0].setFont(font);
    /*text[0].setFillColor(sf::Color::Black);
    text[0].setPosition(sf::Vector2f(0, 0));*/



    height0Row = text[0].getLocalBounds().height + 10;
    float width0Row = (w.getWidth() / 5);
    float tableWidth = w.getWidth() * 2 / 3 - 10;
    float objectsrowWidth = (tableWidth + 10 - width0Row) / 3;
    mash_koeff = (objectsrowWidth / 4) / 310;
    mash_width = objectsrowWidth / 4;
    mash_height = mash_width;

    calcFontSize(static_cast<int>(width0Row) - 10, static_cast<int>(height0Row) - 8);

    float k = 5;
    //getquestion14VariantID1();

    text[0].setString(question14TextColumn[w.getquestionVariantID1()][0]);
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Black);
    text[0].setPosition(sf::Vector2f(10 + k, margintop - 3));
    //text[0].setPosition(sf::Vector2f(200,200));
    text[0].setCharacterSize(static_cast<int>(fontSize));
    horizline[0][0].position = sf::Vector2f(10, margintop);
    horizline[0][1].position = sf::Vector2f(width0Row * 3, margintop);
    horizline[0][0].color = sf::Color::Black;
    horizline[0][1].color = sf::Color::Black;

    horizline[1][0].position = sf::Vector2f(10, margintop + height0Row);
    horizline[1][1].position = sf::Vector2f(width0Row * 3, margintop + height0Row);
    horizline[1][0].color = sf::Color::Black;
    horizline[1][1].color = sf::Color::Black;



    horizline[2][0].position = sf::Vector2f(10, margintop + height0Row * 2);
    horizline[2][1].position = sf::Vector2f(width0Row * 3, margintop + height0Row * 2);
    horizline[2][0].color = sf::Color::Black;
    horizline[2][1].color = sf::Color::Black;


    horizline[3][0].position = sf::Vector2f(10, margintop + height0Row * 3);
    horizline[3][1].position = sf::Vector2f(width0Row * 3, margintop + height0Row * 3);
    horizline[3][0].color = sf::Color::Black;
    horizline[3][1].color = sf::Color::Black;



    verticalline[0][0].position = sf::Vector2f(10, margintop);
    verticalline[0][1].position = sf::Vector2f(10, margintop + height0Row * 4);
    verticalline[0][0].color = sf::Color::Black;
    verticalline[0][1].color = sf::Color::Black;
    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");

    verticalline[1][0].position = sf::Vector2f(width0Row, margintop);
    verticalline[1][1].position = sf::Vector2f(width0Row, margintop + height0Row * 4);
    verticalline[1][0].color = sf::Color::Black;
    verticalline[1][1].color = sf::Color::Black;
    text[1].setString(CommentsDic[11]);
    text[1].setFont(font);
    text[1].setCharacterSize(static_cast<int>(fontSize));
    text[1].setFillColor(sf::Color::Black);
    text[1].setPosition(sf::Vector2f(width0Row + k, margintop - 3));
    text[1].setCharacterSize(static_cast<int>(fontSize));
    mash_x = width0Row;
    mash_y = margintop + height0Row;


    verticalline[2][0].position = sf::Vector2f(width0Row * 2, margintop);
    verticalline[2][1].position = sf::Vector2f(width0Row * 2, margintop + height0Row * 4);
    verticalline[2][0].color = sf::Color::Black;
    verticalline[2][1].color = sf::Color::Black;

    text[2].setString(CommentsDic[12]);
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::Black);
    text[2].setPosition(sf::Vector2f(width0Row * 2 + k, margintop - 3));
    text[2].setCharacterSize(static_cast<int>(fontSize));


    verticalline[3][0].position = sf::Vector2f(width0Row * 3, margintop - 3);
    verticalline[3][1].position = sf::Vector2f(width0Row * 3, margintop + height0Row * 4);
    verticalline[3][0].color = sf::Color::Black;
    verticalline[3][1].color = sf::Color::Black;
    tablemax_y = margintop + 6 * mash_height;



    text[3].setString(question14TextVariant[w.getquestionVariantID1()][0]);
    text[3].setFont(font);
    text[3].setFillColor(sf::Color::Black);
    text[3].setPosition(sf::Vector2f(10 + k, margintop + height0Row));
    text[3].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    text[3].setCharacterSize(static_cast<int>(fontSize));

    text[4].setString(question14TextVariant[w.getquestionVariantID1()][1]);
    text[4].setFont(font);
    text[4].setFillColor(sf::Color::Black);
    text[4].setPosition(sf::Vector2f(10 + k, margintop + 2 * height0Row));
    text[4].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    text[4].setCharacterSize(static_cast<int>(fontSize));


    text[5].setString(question14TextVariant[w.getquestionVariantID1()][2]);
    text[5].setFont(font);
    text[5].setFillColor(sf::Color::Black);
    text[5].setPosition(sf::Vector2f(10 + k, margintop - 3 + height0Row * 3));
    text[5].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    text[5].setCharacterSize(static_cast<int>(fontSize));
    horizline[4].resize(2);
    horizline[4].setPrimitiveType(sf::LineStrip);
    horizline[4][0].position = sf::Vector2f(10, margintop + height0Row * 4);
    horizline[4][1].position = sf::Vector2f(width0Row * 3, margintop + height0Row * 4);
    horizline[4][0].color = sf::Color::Black;
    horizline[4][1].color = sf::Color::Black;

    Celltext[0].setString(question14DigitsInTable[w.getquestionVariantID1()][0][0]);
    Celltext[0].setFont(font);
    Celltext[0].setFillColor(sf::Color::Black);
    Celltext[0].setPosition(sf::Vector2f(width0Row + width0Row / 2, margintop - 3 + height0Row));
    Celltext[0].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    Celltext[0].setCharacterSize(static_cast<int>(fontSize));

    Celltext[1].setString(question14DigitsInTable[w.getquestionVariantID1()][0][1]);
    Celltext[1].setFont(font);
    Celltext[1].setFillColor(sf::Color::Black);
    Celltext[1].setPosition(sf::Vector2f(width0Row + width0Row / 2, margintop - 3 + 2 * height0Row));
    Celltext[1].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    Celltext[1].setCharacterSize(static_cast<int>(fontSize));

    Celltext[2].setString(question14DigitsInTable[w.getquestionVariantID1()][0][2]);
    Celltext[2].setFont(font);
    Celltext[2].setFillColor(sf::Color::Black);
    Celltext[2].setPosition(sf::Vector2f(width0Row + width0Row / 2, margintop - 3 + 3 * height0Row));
    Celltext[2].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    Celltext[2].setCharacterSize(static_cast<int>(fontSize));

    Celltext[3].setString(question14DigitsInTable[w.getquestionVariantID1()][1][0]);
    Celltext[3].setFont(font);
    Celltext[3].setFillColor(sf::Color::Black);
    Celltext[3].setPosition(sf::Vector2f(width0Row * 2 + width0Row / 2, margintop - 3 + height0Row));
    Celltext[3].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    Celltext[3].setCharacterSize(static_cast<int>(fontSize));

    Celltext[4].setString(question14DigitsInTable[w.getquestionVariantID1()][1][1]);
    Celltext[4].setFont(font);
    Celltext[4].setFillColor(sf::Color::Black);
    Celltext[4].setPosition(sf::Vector2f(width0Row * 2 + width0Row / 2, margintop - 3 + 2 * height0Row));
    Celltext[4].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    Celltext[4].setCharacterSize(static_cast<int>(fontSize));

    Celltext[5].setString(question14DigitsInTable[w.getquestionVariantID1()][1][2]);
    Celltext[5].setFont(font);
    Celltext[5].setFillColor(sf::Color::Black);
    Celltext[5].setPosition(sf::Vector2f(width0Row * 2 + width0Row / 2, margintop - 3 + 3 * height0Row));
    Celltext[5].setCharacterSize(static_cast<int>(WindowLink.gettextFrame().getSize()) - 15);
    Celltext[5].setCharacterSize(static_cast<int>(fontSize));


}
void table3_5::draw() {

    for (int i = 0; i < 5; i++)
    {


        WindowLink.getWindow()->draw(verticalline[i]);
        WindowLink.getWindow()->draw(horizline[i]);
        WindowLink.getWindow()->draw(text[i]);
        WindowLink.getWindow()->draw(Celltext[i]);



    };
    WindowLink.getWindow()->draw(text[5]);
    WindowLink.getWindow()->draw(Celltext[5]);

    //WindowLink.getWindow()->draw(horizline[5]);
    //WindowLink.getWindow()->draw(verticalline[5]);


}


sf::Font& CheckButton::getFont() { return font; }

std::array<sf::Texture, 4>& CheckButton::getquadroTexture() { return quadroTexture; }
float CheckButton::getQudroSize() {
    return qudroSize;
}
float CheckButton::getTextmarginleft() { return static_cast<float>(textmarginleft); }
void CheckButton::setStrValue(int index, std::wstring str1, int SIZE = 28) {
    getFont().loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
    getText()[index] = sf::Text(str1, getFont(), 28);
    float x = getSprite()[index].getPosition().x; // +qudroSize;
    float y = getSprite()[index].getPosition().y + (getQudroSize() - getHeightText()) / 2;
    getText()[index].setPosition(x + getQudroSize() + getTextmarginleft(), y-5);
    getText()[index].setFillColor(sf::Color::Black);
    getText()[index].setOutlineColor(sf::Color::Red);

};
void CheckButton::SetqudroSize(float q) {
    qudroSize = q;
    coeff = qudroSize / 500;
    for (int i = 0; i < 4; i++)
        getSprite()[i].setScale(coeff, coeff);
};
void CheckButton::setTextValue(int index) {

    font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");

    sf::RectangleShape rectangle;
    //std::cout << wLnk.gettextFrame().getSize() << std::endl;
    int question10Variant1IDRandom1 = rand() % (sizeof(question10VariantForRandom1) / sizeof(question10VariantForRandom1[0]));

    for (int i = 0; i < 4; i++) {

        str[i] = sf::Text(

            question10Variant2[index][question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][0]]
            +
            question10Variant2[index][question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][1]]
            +
            question10Variant2[index][question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][2]]

            , font, 35);

        if (question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][0] == 0 &&
            question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][1] == 1 &&
            question10VariantForRandom2[question10VariantForRandom1[question10Variant1IDRandom1][i]][2] == 2) rightQuestNum = i;


        float x = quadroSprite[i].getPosition().x; // +qudroSize;
        float tmiii = quadroSprite[i].getLocalBounds().width;
        str[i].setLineSpacing(0.001f);
        float huuu = str[i].getLineSpacing();

        float y = quadroSprite[i].getPosition().y + (qudroSize - getHeightText()) / 2;
        str[i].setPosition(x + qudroSize + textmarginleft, y - 10);
        str[i].setFillColor(sf::Color::Black);
        str[i].setOutlineColor(sf::Color::Red);

    }




}
void  CheckButton::Set_margitop(float mt) {
    margin_top = mt;
    for (int i = 0; i < getSprite().size(); i++)
        getSprite()[i].setPosition(getSprite()[i].getPosition().x, i * getQudroSize() + margin_top);
}
CheckButton::CheckButton(Window& wl) :wLnk(wl), textmarginleft(10), clickID(-1), margin_top(0) {
    coeff = (452.0f / ((wl.getHeight() - wl.gettextFrame().getHeight()))) / 5;
    coeff = 25.0f / wl.getHeight();
    float tmp = wl.gettextFrame().getHeight();
    tmp = wl.getHeight();
    qudroSize = coeff * 452.0f;
    float margin = qudroSize / 6;
    for (int i = 0; i < quadroTexture.size(); i++) {
        quadroTexture[i].loadFromFile(res_path + "empty.jpg");
        quadroSprite[i].setTexture(quadroTexture[i]);
        quadroSprite[i].setScale(coeff, coeff);
        //quadroSprite[i].setPosition(10, ( wl.gettextFrame().getHeight())+30 + (qudroSize+ margin) *i );


    }


}
std::array<mySpriteCheckButton, 4>& CheckButton::getSprite() {
    return quadroSprite;
}
std::array<sf::Text, 4>& CheckButton::getText() {
    std::wstring tmp = str[3].getString();
    return str;
};

std::string mySpriteCheckButton::getFN() { return fn; };
bool mySpriteCheckButton::getActive() { return active; }

void CheckButton11::SetSpacing(float space) {
    for (int i = 1; i < 4; i++)
    {
        float left = getSprite()[i].getPosition().x;;
        float wi = getSprite()[i].getLocalBounds().width;
        float top = getSprite()[i - 1].getPosition().y + qudroSize + space;

        getSprite()[i].setPosition(left, top - space);
    }
}
void PicturetoView11::CalcucateCoordinate(float w) {

    using namespace std;
    sf::Texture tmp;

    float button_margin_left = margin_left;
    tmp.loadFromFile(pictureFilename + ".png");
    sf::Vector2u PICTURESIZE = tmp.getSize();
    if (PICTURESIZE.x > PICTURESIZE.y&& PICTURESIZE.x / PICTURESIZE.y >= 2)  PICTURESIZE.x /= 2;
    float ButtonSlideHeght = WindowLink.getHeight() / 3;

    int PICTURESIZE_W = PICTURESIZE.x;
    width = static_cast<float>(PICTURESIZE.x);
    int PICTURESIZE_H = PICTURESIZE.y;
    ////std::cout << PICTURESIZE_W << "x" << PICTURESIZE_H << std::endl;
    scale = static_cast<float>(PICTURESIZE_W / (PICTURESIZE_W - 5));

    if (ButtonCount < 7)  // 1 row of pictures
    {
        do {
            scale = scale - 0.01f;
            PICTURESIZE_W = static_cast<int>(PICTURESIZE.x * scale);
            PICTURESIZE_H = static_cast<int>(PICTURESIZE.y * scale);
        } while ((PICTURESIZE_W * round(ButtonCount)) > WindowLink.getWidth() / 2);


        for (int i = 0; i < ButtonCount; i++) {
            std::shared_ptr<sf::Texture> txt = std::make_shared<sf::Texture>();
            txt->loadFromFile(pictureFilename + ".png", sf::IntRect(0, 0, PICTURESIZE.x, PICTURESIZE.y));
            std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*txt.get());
            sprite->setScale(scale, scale);
            sprite->move(button_margin_left, margin_top);
            button_margin_left = button_margin_left + 5 + PICTURESIZE.x * scale;
            MyTexture.emplace_back(std::move(txt));
            ButtonsList.emplace_back(std::move(sprite));
            isblackSide.push_back(true);
        }
    }

    height = static_cast<float>(PICTURESIZE_H);


}



float CheckButton::getcoeff() {
    return coeff;
}


void table3_5::calcFontSize(const int w, const int h) {


    fontSize = 50;
    text[0].setCharacterSize(static_cast<int>(fontSize));
    float width = text[0].getLocalBounds().width; float height = text[0].getLocalBounds().height;
    while (width > w || height > h)
    {
        fontSize--;
        if (fontSize > 0) text[0].setCharacterSize(static_cast<int>(fontSize)); else return;
        width = text[0].getLocalBounds().width;
        height = text[0].getLocalBounds().height;
    }
    fontSize--;
    //margin_top = text[0].getLocalBounds().top;
}





