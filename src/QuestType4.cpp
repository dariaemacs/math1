#include "QuestType4.hpp"
#include "database.hpp"
#include "Mysf_text.hpp"

int QuestType4::getquestionVariantID1() { return 0; }
int QuestType4::getquestionVariantID2() { return 0; }
int QuestType4::getquestionVariantID3() { return 0; }
int QuestType4::getquestionVariantID4() { return 0; }
int QuestType4::getquestionVariantID5() { return 0; }

QuestType4::QuestType4(float w, float h, int qtyButtons) :
    window(w, h, 0, 3),
    Buttons(qtyButtons, *this) {

    bool first = true;
    bool firstPrintTrain = true;
    int margintopSlideButton = 0;
    int numberInTrainCharactersize = 0;
    FrameFigure::resetnumber_of_figure();
    ArrowButtonTexture.loadFromFile("resources/images/arrow_disable.png");
    ArrowButtonSprite.setTexture(ArrowButtonTexture);
    float squareWidth = 0;
    int opennumbaerCount = 0;
    TrainForQuest  TrainForQuest(win);
    //TrainForQuest  TrainRight(window);
    //sf::CircleShape shape(1);

    //shape.setFillColor(sf::Color::Red);

    questionVariantID1 = rand() % numSeries.size();
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




    for (unsigned int i = 0; i < numSeries[0].size(); i++) {
        numberInTrain.push_back(new Mysf_text(50));
        numberInTrain[i]->setString(std::to_string(numSeries[questionVariantID1][i]));


        numberInTrain[i]->setFont(font);

        numberInTrain[i]->setFillColor(sf::Color::Black);



    }

    sf::Event event;
    while (win->isOpen()) {
        win->clear();
        win->draw(List);
        if (first) {
            margintopSlideButton = 20;
            Buttons.setMargin_top(static_cast<float>(margintopSlideButton) + 10);

            Buttons.CalcucateCoordinate(); first = false;

            QuestComment.setmargin_top(h - Buttons.getHeight());


            QuestComment.CalcucateCoordinate(Buttons.getMarginLeft() - 10, Buttons.getMarginTop());


        }
        win->draw(QuestComment.gettext());
        win->draw(textFrame.gettext());
        win->draw(ArrowButtonSprite);






        for (int bc = 0; bc < Buttons.getButtonCount(); bc++) {

            win->draw(*Buttons.getButtons()[bc]);
        }

        TrainForQuest.draw();
        float YnumberInTrain = static_cast<float>(TrainForQuest.getmargin_top());

        YnumberInTrain = TrainForQuest.getmargin_top() +
            TrainForQuest.getymin() * TrainForQuest.getkoef();




        for (unsigned int i = 0; i < numSeries[0].size(); i++) {

            squareWidth = static_cast<float>((TrainForQuest.getxmax() - TrainForQuest.getxmin())) * static_cast<float>(TrainForQuest.getkoef())
                / static_cast<float>(TrainForQuest.getrectengleQTY());
            numberInTrain[i]->setPosition(
                TrainForQuest.getxmin() * TrainForQuest.getkoef() + TrainForQuest.getmargin_left() +


                squareWidth *
                i, YnumberInTrain);
            //*numberInTrain[i]->
            //if (i==1) shape.setPosition(TrainForQuest.getxmin() + TrainForQuest.getmargin_left() +
            //    squareWidth *
            //    i , YnumberInTrain);
            if ((!(i == closeNumber[0] ||
                i == closeNumber[1] || i == closeNumber[2]
                )) || i == usercloseNumberEnter[0].index || i == usercloseNumberEnter[1].index || i == usercloseNumberEnter[2].index) {
                if (firstPrintTrain) {
                    numberInTrain[i]->CalcucateCoordinate(squareWidth - 10, squareWidth - 10);
                    numberInTrainCharactersize = numberInTrain[i]->getSize();

                }
                firstPrintTrain = false;
                numberInTrain[i]->setCharacterSize(numberInTrainCharactersize);
                win->draw(*numberInTrain[i]);
            };



            TrainForQuest.SetSquareColor(closeNumber[currentusercloseNumberIndex], true);


        }
        float scaletrainpicture = squareWidth / 185 + 0.1f;
        trainpictureSprite.setScale(scaletrainpicture, scaletrainpicture);
        trainpictureSprite.setPosition(
            TrainForQuest.getxmin() * TrainForQuest.getkoef() + TrainForQuest.getmargin_left() +


            squareWidth *
            6 + 3, static_cast<float>(YnumberInTrain) - 185 * scaletrainpicture + squareWidth + 3);

        win->draw(trainpictureSprite);




        if (badAnswer) {
            sf::Sprite sprite(questanswer.getminiwindow().getTexture());
            //sprite.setPosition(TrainForQuest.getxmin()* TrainForQuest.getkoef() + TrainForQuest.getmargin_left(), Buttons.getMarginTop() - questanswer.getHeight());
            sprite.setPosition(TrainForQuest.getxmin() * TrainForQuest.getkoef() + TrainForQuest.getmargin_left(), YnumberInTrain
                + squareWidth * TrainForQuest.getkoef() + 10
            );

            win->draw(sprite);

        }
        win->display();
        while (win->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                win->close();

            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasAnswer) {

                if (readyforCheck && checkandnextQuest(Buttons.getScale())) {

                    if ((numSeries[questionVariantID1][closeNumber[0]] == usercloseNumberEnter[0].closeNumber) &&
                        (numSeries[questionVariantID1][closeNumber[1]] == usercloseNumberEnter[1].closeNumber) &&
                        (numSeries[questionVariantID1][closeNumber[2]] == usercloseNumberEnter[2].closeNumber))
                        QuestComment.settext(CommentsDic[1]);
                    else {
                        QuestComment.settext(CommentsDic[2]);
                        badAnswer = true;

                        questanswer.setParams(squareWidth * 6, squareWidth, 6, squareWidth / 500.0f);
                        for (unsigned int i = 0; i < numSeries[0].size(); i++)
                            questanswer[i].loadFromFile(res_path + "digit" + std::to_string(numSeries[questionVariantID1][i]) + ".jpg");

                        questanswer.draw();
                    }
                    wasAnswer = true;
                    QuestComment.CalcucateCoordinate(Buttons.getMarginLeft(), Buttons.getMarginTop());
                }

                if (Buttons.click()) {
                    TrainForQuest.SetSquareColor(closeNumber[currentusercloseNumberIndex], false);

                    usercloseNumberEnter[currentusercloseNumberIndex].closeNumber = Buttons.GetButtonsClickID() + 1;
                    usercloseNumberEnter[currentusercloseNumberIndex].index = closeNumber[currentusercloseNumberIndex];
                    //closeNumber[currentusercloseNumberIndex] = -90;
                    //window->draw(*numberInTrain[i]);
                    ////std::cout << "TUTA: " <<usercloseNumberEnter[currentusercloseNumberIndex].closeNumber << " " << usercloseNumberEnter[currentusercloseNumberIndex].index<<std::endl;
                    numberInTrain[closeNumber[currentusercloseNumberIndex]]->setString(std::to_string(Buttons.GetButtonsClickID() + 1));
                    //numberInTrain[closeNumber[currentusercloseNumberIndex]]->CalcucateCoordinate(squareWidth - 10, squareWidth - 10);
                    //numberInTrainCharactersize = numberInTrain[closeNumber[currentusercloseNumberIndex]]->getSize();
                    numberInTrain[closeNumber[currentusercloseNumberIndex]]->setCharacterSize(numberInTrainCharactersize);
                    currentusercloseNumberIndex++;
                    if (currentusercloseNumberIndex > 2) currentusercloseNumberIndex = 0;
                    ArrowButtonSprite.setTexture(ArrowButtonTexture);
                    opennumbaerCount++;
                    if (opennumbaerCount == 3) {
                        readyforCheck = true;
                        ArrowButtonTexture.loadFromFile("resources/images/arrow_up.png");
                    }

                }
            }



        }





        if (wasAnswer && afterAsk()) return;
    }
}