class table {

    float mash_koeff;
    float mash_width;
    float mash_height;
    float mash_x;
    float mash_y;
    float tablemax_y;

protected:

    std::array < sf::VertexArray, 5> verticalline;
    std::array < sf::VertexArray, 5> horizline;
    std::array < sf::Text, 6> text;
    sf::Font font;
    Window& WindowLink;
public:
    table(Window&);
    void draw();
    float table::getmash_koeff();
    float table::getmash_width();
    float table::getmash_height();
    float table::gettablemax_y();
    float table::getmash_x();
    float table::getmash_y();

};

