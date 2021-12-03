#include "TextFrameBase.hpp"



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


void TextFrameBase::settext(std::wstring a) { text.setString(a); }

sf::Text TextFrameBase::gettext() {
    return text;
}

sf::Text TextFrameBase::gettext() {
    return text;
};

void TextFrameBase::settext(std::wstring a) { text.setString(a); }

void TextFrameBase::setmargin_top(float m) {
    sf::Vector2f pos = text.getPosition();
    text.setPosition(pos.x, m);
    margin_top = m;
}


float TextFrameBase::getmargin_top() {
    return margin_top;
}
void TextFrameBase::CalcucateCoordinate(const float w, const float h) {
    size = 50;
    text.setCharacterSize(static_cast<unsigned int>(size));
    float width = text.getLocalBounds().width; float height = text.getLocalBounds().height;
    while (width > w || height > h) {
        if (size > 0) { size--;  text.setCharacterSize(static_cast<unsigned int>(size)); }
        else return;
        width = text.getLocalBounds().width;
        height = text.getLocalBounds().height;
    }

    margin_top = text.getLocalBounds().top;
}

float TextFrameBase::getHeight() {
    return text.getLocalBounds().height;
}

void TextFrameBase :: setquestionNumber(int qn) { questionNumber = qn; }
float TextFrameBase :: getSize() {
    return size;
}