#include "table3_5.hpp"
#include "window.hpp"
#include "database.hpp"



table3_5::table3_5(window& w) :WindowLink(w) {

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

float table3_5::getheight0Row() {
    return height0Row;
};
float table3_5::getmash_koeff() {
    return mash_koeff;
};
float table3_5::getmargintop() {
    return margintop;
};
float table3_5::getmash_width() {
    return mash_width;
};
float table3_5::getmash_height() {
    return mash_height;
};
float table3_5::gettablemax_y() {
    return tablemax_y;
};
float table3_5::getmash_x() { return  mash_x; }
float table3_5::getmash_y() { return  mash_y; }


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
