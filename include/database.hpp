#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <array>
#include "pica.hpp"
#include "figures.hpp"

struct figureQestions {
	
	std::wstring questionText;
	types key;
};

extern const std::wstring CommentsDic[];

constexpr int N = 9; //Question count
const int ELAPSED_TIME = 20;
const float FPS = 30.0f;


extern const std::array<figureQestions, N> questionFigure;
//extern const std::vector<FrameFigure> figures;
extern const std::vector<pica> tree;
extern const std::vector<std::string> iconsFilename;
extern const std::vector<FrameFigure*> figures;

#endif //DATABASE_H

