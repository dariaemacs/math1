#ifndef QuestType9_H1
#define QuestType9t_H1
#include "window.hpp"
#include "table.hpp"
#include "SimpleButtons.hpp"
#include "questanswerClass.hpp"

class QuestType9 : public window {
    table tab;
    SimpleButtons Buttons;
    std::array<sf::Texture, 13> MashTexture;
    std::array<sf::Sprite, 13>  MashSprite;

    std::array<sf::Texture, 16> BerryTexture;
    std::array<sf::Sprite, 16>  BerrySprite;

    std::array<sf::Texture, 12> LeafTexture;
    std::array<sf::Sprite, 12>  LeafSprite;
    questanswerClass questanswer;
public:
    QuestType9(float, float, int);
    std::array<sf::Sprite, 13> getMashsprite() { return MashSprite; }
    std::array<sf::Sprite, 16> getMBerryprite() { return BerrySprite; }
    std::array<sf::Sprite, 12> getLeafsprite() { return LeafSprite; }
    int getquestionVariantID1();
    int getquestionVariantID2();
    int getquestionVariantID3();
    int getquestionVariantID4();
    int getquestionVariantID5();
};
#endif