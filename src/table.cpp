#include "table.hpp"
#include "window.hpp"
#include "database.hpp"


float table::getmash_koeff() {
    return mash_koeff;
};

float table::getmash_width() {
    return mash_width;
};
float table::getmash_height() {
    return mash_height;
};
float table::gettablemax_y() {
    return tablemax_y;
};
float table::getmash_x() { return  mash_x; }
float table::getmash_y() { return  mash_y; }

table::table(window& wlink) :WindowLink(wlink) {
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
}

void table::draw() {

    for (int i = 0; i < 6; i++)
    {
        if (i < 4) {
            WindowLink.getWindow()->draw(horizline[i]);
        }
        if (i < 5) {
            WindowLink.getWindow()->draw(verticalline[i]);
        }
        WindowLink.getWindow()->draw(text[i]);
    }
}
