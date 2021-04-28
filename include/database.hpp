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

constexpr int N = 3; //Question count
const int ELAPSED_TIME = 20;
const float FPS = 30.0f;


extern const std::array<figureQestions, N> questionFigure;
extern const std::vector<FrameFigure> figures;
extern const std::vector<pica> tree;

#endif //DATABASE_H

