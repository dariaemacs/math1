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
extern std::vector< std::vector<int>> numSeries;


constexpr int N1 = 3; 
constexpr int N2 = 6;
constexpr int N3 = 6;
constexpr int X = 5; 
constexpr int Y = 6;

constexpr int beginQuestion2Index = 3;

const int ELAPSED_TIME = 20;
const float FPS = 30.0f;




extern const figureQestions question1Text[];
extern const figureQestions question2Text[];
extern const figureQestions question3Text[];

extern const figureQestions question4Text[];
extern const figureQestions question5Text[];
extern const figureQestions question6Text[];
extern const figureQestions question7Text[];
extern const figureQestions* qestionarrayList[];


extern const int question5Answers[];
extern const int question6Answers[];

struct variantOfLine { int i, j; };
extern const variantOfLine question7squarevariantOfFirstLine[];
extern const variantOfLine question7trianglevariantOfFirstLine[];
extern const variantOfLine question7rectanglevariantOfFirstLine[];

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
extern const std::array<std::string,N2> filenamesforPicaQuest2 ;
extern const std::array<std::string, N2> filenamesforPicaQuest3;

#endif //DATABASE_H

