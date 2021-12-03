#include "PicturetoView.hpp"
class PicturetoViewQuestWithBasket : public  PicturetoView {
    sf::Texture basketTexture;
    sf::Sprite basketSprite;
public:
    PicturetoViewQuestWithBasket(Window&);
    void CalcucateCoordinate();
    sf::Texture getBasketTexture() {
        return basketTexture;
    }
    sf::Sprite getBasketSprite() {
        return basketSprite;
    }


};