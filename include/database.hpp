#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <array>
#include "pica.hpp"

struct figureQestions {
	
	std::wstring questionText;
	types key;
};

constexpr int N = 2;
const int ELAPSED_TIME = 20;
const float FPS = 30.0f;


extern const std::array<figureQestions, N> questionFigure;
extern const std::vector<pica> flower;
extern const std::vector<pica> tree;

#endif //DATABASE_H

