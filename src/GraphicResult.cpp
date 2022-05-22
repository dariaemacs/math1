#include "GraphicResult.hpp"
#include "database.hpp"



const int Quest_N = 16;
const int commentWidth = 180;

std::vector <dataPoint> DATA;

std::vector <dataPoint> testDATA =
{
  {1,6,1981,15},
  {1,6,1981,11},
  {1,6,1981,9},
  {1,6,1981,16},

  {12,6,1981,15},
  {12,6,1981,11},
  {14,6,1981,9},
  {25,6,1981,16},

  { 1,7,1981,15},
  {5,7,1981,11},
  {14,7,1981,9},
  {3,4,2022,16},
  {3,4,2022,16},
  {3,4,2022,16},
  {3,4,2022,1},
  {3,4,2022,2},
  {3,4,2022,1},
  {3,4,2022,1},
  {3,4,2022,5},
  {3,4,2022,6},
  {3,4,2022,6},
  {3,4,2022,12},
  {3,4,2022,8},
  {3,4,2022,6},
  {3,4,2022,10},
  {3,4,2022,1},

  { 1,7,1981,12},
  {5,7,1981,8},
  {14,7,1981,1},
  {3,4,2022,1},
  {3,4,2022,1},
  {3,4,2022,10},
  {3,4,2022,7},
  {3,4,2022,12},
  {3,4,2022,11},
  {3,4,2022,14},
  {3,4,2022,13},
  {3,4,2022,12},
  {3,4,2022,5},
  {3,4,2022,2},
  {3,4,2022,7},
  {3,4,2022,8},
  {3,4,2022,1},
  {3,4,2022,2}

};

int priceofDiv(std::vector<dataPoint>& da, int l) { //cena deleniay po x
	return l / (da.size()+1);
}

GraphicResult::GraphicResult():
	window(gameClass::getWidth(), gameClass::getHeight(), (rand() % 3), 0),
	BackButton(*this),
	filesSaveData("data.dat")
{
	//filesSaveData.savetoFile(testDATA);
	



	filesSaveData.readVector(DATA);
	sf::VertexArray lines(sf::LinesStrip, DATA.size());
	int priceH = priceofDiv(DATA, gameClass::getWidth());

	int priceV = gameClass::getHeight() / (Quest_N);
	std::vector <sf::CircleShape> pointS;

	/*for (int i = 0; i < DATA.size(); i++) {
		filesSaveData.savetoFile(DATA[i].nomer, DATA[i].day, DATA[i].month, DATA[i].year, DATA[i].qtyBall);
	}*/

	rectangleComment.setSize(sf::Vector2f(commentWidth, 20));
	//rectangleComment.setOutlineColor(sf::Color::White);
	rectangleComment.setOutlineThickness(5);
	rectangleComment.setPosition(10, 20);
		
	

	font.loadFromFile(Settings::RESOURCE_PATH + Settings::FONTS_PATH + "standart_tt.ttf");
	
	comment.setFont(font);
	comment.setCharacterSize(15);
	comment.setFillColor(sf::Color::Black);


	for (int i = 1; i < (Quest_N + 1); i++) {
		horizLabels.push_back(sf::RectangleShape());
		horizLabels[i-1].setSize(sf::Vector2f(10, 3));
		horizLabels[i-1].setPosition(5, (i - 1) * priceV);

		vertDigit.push_back(sf::Text());
		vertDigit[i-1].setFont(font);
		vertDigit[i-1].setString(std::to_string((Quest_N + 1) -i));
		vertDigit[i-1].setCharacterSize(15);
		vertDigit[i-1].setPosition(15, (i-1) * priceV-8);
	}

	for (int i = 0; i < DATA.size(); i++) {
		verticalLabels.push_back(sf::RectangleShape());
		verticalLabels[i].setSize(sf::Vector2f(3, 10));
		verticalLabels[i].setPosition(sf::Vector2f((i+1) * priceH, gameClass::getHeight()-20));
		horzDigit.push_back(sf::Text());
		horzDigit[i].setFont(font);
		horzDigit[i].setString(std::to_string(i+1));
		horzDigit[i].setCharacterSize(15);
		horzDigit[i].setPosition(sf::Vector2f((i+1) * priceH, gameClass::getHeight() - 40));
		pointS.push_back(sf::CircleShape());
		pointS[i].setPosition(sf::Vector2f((i+1) * priceH, gameClass::getHeight()-priceV*DATA[i].qtyBall));
		pointS[i].setFillColor(sf::Color::Red);
		pointS[i].setRadius(5);
		lines[i].position = sf::Vector2f((i + 1) * priceH+5, gameClass::getHeight() - priceV * DATA[i].qtyBall+5);
	}

	x.setSize(sf::Vector2f(gameClass::getWidth()-10, 3));
	x.setFillColor(sf::Color::Green);
	x.setPosition(10, gameClass::getHeight() - 10);

	y.setSize(sf::Vector2f(3, gameClass::getHeight()-10));
	y.setFillColor(sf::Color::Green);
	y.setPosition(10, 0);
	while (win->isOpen()) {
		sf::Event event;
		while (win->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win->close();
		}

		win->clear();
		for (int i = 0; i < DATA.size(); i++) {
			win->draw(verticalLabels[i]);
			//verticalLabels
			win->draw(horzDigit[i]);
			win->draw(pointS[i]);
		}
		for (int i = 0; i < (Quest_N); i++) {
			win->draw(vertDigit[i]);
			win->draw(horizLabels[i]);
		}


		for (int i = 0; i < DATA.size(); i++) {
			const sf::Vector2i& M = sf::Mouse::getPosition(*win);
			int xComment = 0;
			int yComment = 0;
			if (pointS[i].getPosition().x + 10 >= M.x && pointS[i].getPosition().x - 10 <= M.x
				&&
				pointS[i].getPosition().y + 10 >= M.y && pointS[i].getPosition().y - 10 <= M.y
				) {
				
				comment.setString( 
					(DATA[i].day<10? std::to_wstring(0): L"") +
					std::to_wstring(DATA[i].day) + L":" + 
					(DATA[i].month < 10 ? std::to_wstring(0) : L"") +
					std::to_wstring(DATA[i].month) + L":" + std::to_wstring(DATA[i].year)+L" "+ CommentsDic[33]+ L": " +
					std::to_wstring(DATA[i].qtyBall)
								 );
				if (M.x + commentWidth >= gameClass::getWidth()) 
					xComment = M.x - commentWidth;						
				else 
					xComment = M.x + 20;

				if (M.y + 20 >= gameClass::getHeight())
					yComment = M.y - 40;
				else
					yComment = M.y + 20;

				rectangleComment.setPosition(xComment, yComment);
				comment.setPosition(xComment, yComment);
				//std::cout << M.x << std::endl;
				
				win->draw(rectangleComment);
				win->draw(comment);
			}
		}


		win->draw(x);
		win->draw(y);
		win->draw(lines);
		//win->draw(line, 2, sf::Lines);
		win->display();
		
	}
}

int GraphicResult::getquestionVariantID1() { return 0; }
int GraphicResult::getquestionVariantID2() { return 0; }
int GraphicResult::getquestionVariantID3() { return 0; }
int GraphicResult::getquestionVariantID4() { return 0; }
int GraphicResult::getquestionVariantID5() { return 0; }