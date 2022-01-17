#ifndef SimpleText_H
#define SimpleText_H

#include "window.hpp"

class SimpleText : public sf::Text {
	std::wstring str;
	sf::Font font;

	float margin_left;
	float margin_top;
	public:
	SimpleText(std::wstring s);
	SimpleText();
	void ñalcucateCoordinate();
	void ñalcucateCoordinate(float , float);
	void setmargin_top(float);
	void setmargin_left(float);
	float getmargin_top();
	float getmargin_left();
	float getwidth();
	float getheight();
	void setSize(float);
	float getSize();
};
#endif