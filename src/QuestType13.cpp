#include "QuestType13.hpp"
#include "database.hpp"
QuestType13::QuestType13(float w, float h) :
    window(w, h, 0, 12),
    checkbutton(*this)


{


    std::shared_ptr<FrameFigure> pica[] =
    { std::make_shared<ThreePicture0>(win) ,
        std::make_shared<ThreePicture1>(win),
        std::make_shared<ThreePicture2>(win),
        std::make_shared<ThreePicture3>(win)
    };
    bool first = true;
    FrameFigure::resetnumber_of_figure();
    srand(static_cast<unsigned int>(time(NULL)));
    int SIZE = sizeof(pica) / sizeof(*pica);
    srand(static_cast<unsigned int>(time(NULL)));
    questionVariantID1 = rand() % SIZE;
    SIZE = sizeof(question13Variant) / sizeof(*question13Variant);
    srand(static_cast<unsigned int>(time(NULL)));
    questionVariantID2 = rand() % SIZE;
    SIZE = sizeof(question13VariantofRandom) / sizeof(*question13VariantofRandom);
    srand(static_cast<unsigned int>(time(NULL)));
    questionVariantID3 = rand() % SIZE;

    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    sf::Event event;
    checkbutton.SetqudroSize(35);

    QuestComment.settext(CommentsDic[0]);


    while (win->isOpen()) {
        win->clear();

        win->draw(List);
        win->draw(ArrowButtonSprite);
        if (first) {

            first = false;




            QuestComment.CalcucateCoordinate(static_cast<float>(h / 3), static_cast<float>(w / 2));
            checkbutton.Set_margitop((h - (checkbutton.getQudroSize() + 20) * 3) - checkbutton.getSprite()[0].getPosition().y);

            QuestComment.setmargin_top(checkbutton.getSprite()[0].getPosition().y - checkbutton.getQudroSize() - 25);
            checkbutton.SetSpacing(11);

            checkbutton.resetclickID();
            ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png");
            readyforCheck = true;
            ArrowButtonSprite.setTexture(ArrowButtonTexture);
        }


        for (int i = 0; i < 3; i++) {
            win->draw(checkbutton.getSprite()[i]);
            std::wstring tmpStr = question13Variant[questionVariantID2][question13VariantofRandom[questionVariantID3][i]];
            checkbutton.setStrValue(i, tmpStr,28);
            tmpStr = checkbutton.getText()[i].getString();
            win->draw(checkbutton.getText()[i]);
        }



        win->draw(QuestComment.gettext());
        pica[questionVariantID1]->draw();
        win->draw(textFrame.gettext());



        if (badAnswer) {

        }
        DrawGameTime();
        win->display();
        while (win->pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                win->close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Settings::ButtonFactor))
                {

                    countofBALL = 0;


                    //char tmp = 1 << 0;
                    std::vector <int> result;
                    if (((checkbutton.getClickID() & (1 << 0)) >> 0) > 0) result.push_back(question13VariantofRandom[questionVariantID3][0]); //  ;
                    if (((checkbutton.getClickID() & (1 << 1)) >> 1) > 0) result.push_back(question13VariantofRandom[questionVariantID3][1]); //  ;
                    if (((checkbutton.getClickID() & (1 << 2)) >> 2) > 0) result.push_back(question13VariantofRandom[questionVariantID3][2]); //  ;
                    sort(result.begin(), result.end(), std::greater<int>());
                    unsigned char result_int = 0;
                    int dec = 1;
                    for (int i = 0; i < result.size(); i++)
                    {
                        result_int = result_int | (1 << result[i]);


                    }
                    std::cout << std::endl;

                    if (question13Answers[questionVariantID1][questionVariantID2] == result_int) { QuestComment.settext(CommentsDic[1]); }
                    else {

                        QuestComment.settext(CommentsDic[2]);

                    };

                    for (int i = 0; i < 3; i++)
                    {
                        int ismustClick = (question13Answers[questionVariantID1][questionVariantID2] & (1 << question13VariantofRandom[questionVariantID3][i]));

                        if (ismustClick > 0 && checkbutton.getSprite()[i].getActive())
                        {
                            checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_right.png");
                        }

                        else {
                            if (ismustClick == 0 && checkbutton.getSprite()[i].getActive()) {
                                checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_wrong.png");
                            }
                            else {
                                if (ismustClick > 0 && !checkbutton.getSprite()[i].getActive())
                                    checkbutton.getquadroTexture()[i].loadFromFile(Settings::RESOURCE_PATH + Settings::IMAGES_PATH + "select_right.png");

                            }
                        }
                    }




                    wasAnswer = true;

                }

                if (checkbutton.click(0)) {


                }

            }

         
        }
        if (wasAnswer && afterAsk()) return;
    }



}