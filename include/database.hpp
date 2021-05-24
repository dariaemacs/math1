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

constexpr int N = 9; 
constexpr int X = 5; 
constexpr int Y = 6;

constexpr int beginQuestion2Index = 3;

const int ELAPSED_TIME = 20;
const float FPS = 30.0f;




extern const std::array<figureQestions, N> questionFigure;
//extern const std::vector<FrameFigure> figures;
extern const std::vector<pica> tree;
extern const std::vector<std::string> iconsFilename;
extern const std::vector<FrameFigure*> figures;

struct phrasetoReplace {
	std::wstring find;
	std::wstring replace;
};

//prasetoReplace OOO[] = { { L"SDF",L"cvcv" },{ L"SDF",L"cvcv" } };
//const std::array <std::array<int, X>, Y> INT0 = { { L"SDF",L"cvcv" },{ L"SDF",L"cvcv" } };

extern const std::array <std::array<phrasetoReplace, X>,Y> phrasestoReplace;
extern const std::vector<std::string> filenamesforPicaQuest2 ;

#endif //DATABASE_H

