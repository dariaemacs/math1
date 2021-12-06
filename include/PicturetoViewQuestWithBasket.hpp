#ifndef PicturetoViewQuestWithBasket_H
#define PicturetoViewQuestWithBasket_H

#include "PicturetoView.hpp"
class PicturetoViewQuestWithBasket : public  PicturetoView {
    sf::Texture basketTexture;
    sf::Sprite basketSprite;
public:
    PicturetoViewQuestWithBasket(window&);
    void CalcucateCoordinate();
    sf::Texture getBasketTexture() {
        return basketTexture;
    }
    sf::Sprite getBasketSprite() {
        return basketSprite;
    }


};

#endif 