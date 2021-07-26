#include "database.hpp"
#include "settings.hpp"
#include "color.hpp"
#include "window.hpp"

extern std::vector< std::vector<int>> numSeries = { {20,19,18,17,16,15},{1,2,3,4,5,6},{17,14,11,8,5,2} };
//extern const int numSeries[][6] = { {31,29,27,25,23,21},{1,2,3,4,5,6},{17,21,25,29,33,37} };

extern const figureQestions question1Text[] =
{
  figureQestions{L"������� ������� �� �������� �� ������ ? "       ,circle},
  figureQestions{L"������� ��������������� �� �������� �� ������ ? ",rectangle},
  figureQestions{L"������� ������������� �� �������� �� ������ ? ",triangle},
};



extern const figureQestions question2Text[] =
{
figureQestions{ L"���� ����� �������� ������ N �������. �� �������� \n����� M ������� . ������� ������� ���� ��� ����� ?",seashell },
figureQestions{ L"� ������� ���� N ���� ��������. ����� ���� , ��� ����� ���� \n��������� ����, �������� M. ������� ���� ���� ����� ?",berry },
figureQestions{ L"���� ����� ����� N ������. ��� �������� ����� M ������. \n������� ������ �� ��� ����� ?",mashroom },
figureQestions{ L"���� � ���� ������� N �����. ���� ������ M �����. \n������� ����� ������� ����?",fish },
figureQestions{ L"������ ����� ���������� N �������. ��� ���������� \n M �������. ������� ������� �������� ����������? ",butterfly },
figureQestions{ L"���� ����� ������ ���������. �� ����� N ������, \n������ � ���� � ������� M ������. �������  ��� ������ ����� ����, \n����� ������� �� ���������?",bycicle }
};



extern const figureQestions question3Text[] =
{



figureQestions{ L"� ������ ���� � ��������� ���������� N ������. � �� ������ ���� \n���������� ��� M, �� �������� � ��������. ������� ����� ������ ���������� �� ��� ���?",chicken     },
figureQestions{L"� ���� ���� N ����������. ���� ������ �� ��� M (� �������). �������\n ���������� ����� � ����?",                                                         pencil      },
figureQestions{L"������� ��������� ��������� N ����, � ����� ��� M (�� ���������).\n ������� ����� ����� ��������� ���������?",                                           house       },
figureQestions{L"�� ������ ����� ������ N �������. ����� � ��� ���������� \n��� M ������� (�� ��������). ������� ������ ����� ������� ����� �� ������?" ,                  frog        },
figureQestions{L"����� ����� ����� ������ ������� N ������, � ���� \n��� M ������ (� ��������). ������� ����� ������ ������� ������?",                                    mashroom        },
figureQestions{L"��� ����� ���� ������ N ������� ������� � ��� M \n�������� (� ��������). ������� ����� ������� ������ ����?",                                            oaklist     }

};

extern const figureQestions question4Text[] = { figureQestions{ L"�� �������������� ������ ����� �������� �� \n ������������� �������. ���������� ������� � \n������� �� ����������� �����, ����� ��� ��������� � �������?",train     } };

extern const figureQestions question5Text[] =
{
figureQestions{L"� ����� 20 ����������, � � ���� �� 10 ���������� ������. ������� ���������� � ����?"       ,calc},
figureQestions{L"� ���� ���� 16 �������, � � ������ �� 5 ������� ������. ������� ������� � ������?"       ,calc},
figureQestions{L"����� ����� ����� 6 �����������,  � ��� ����� �� 12 ����������� �������. ������� ����� �����?"       ,calc},
figureQestions{L"������� 11 ���, � ��� ������ ���� �� 8 ��� ������. ������� ��� ����?"       ,calc},
figureQestions{L"� ������ �������� ������ 10 ��, � � ���� �� 10 �� �������. ����� ����� ������� ��������?"       ,calc},
figureQestions{L"����� 14 ���, � ��� ���� ������ �� 11 ��� ������. ������� ��� ������?"       ,calc}
};
extern const int question5Answers[] = {10,11,18,19,20,3};



extern const std::array<std::string, N2> filenamesforPicaQuest2 = { std::string("shell"),std::string("berry"),std::string("mushroom"),std::string("fish"),
std::string("butterfly"),std::string("coin")
};
extern const figureQestions question6Text[] = {
figureQestions{L"������ ����� ������ � �������� �������� �� 6 ������. � ���� ���� ����� ������.\n �������� ������ ��� ���� ������ � ������� �����. ����� ����� \n������� �������"       ,calc},
figureQestions{L"������ �� ������� �������� ��������� �������. � ����� ���� ����� ������. ������� ����� \n������ ������� �� 8 ������. ��� �������� � ������� ���� \n������ � �������� �����. ����� ����� �������� �����?"       ,calc},
figureQestions{L"���� ������ ������ � �������� ����� �� 7 ������. � ��� ���� ����� ������. \n�������� ���� ���� ���� ������ � �������� �����. \n����� ����� �������� �������?"       ,calc},
figureQestions{L"������ �� ������� ������� ��������� �������. � ��� ���� ����� ������. \n������� ����� ������ ������� �� 9 ������. ��� �������� � ������� ���� \n������ � �������� �����. ����� ����� �������� ���? "       ,calc},
};
extern const int question6Answers[] = { 4,2,3,1};
extern const unsigned long long question7AnswersRectangle[3] = { 21415254, 10304143, 102130435254 };
extern const unsigned long long question7AnswersSquare[2] = { 21415254, 10304143};
extern const unsigned long long question7AnswersTriangle[21] = {
103031,
104041,
10213032,
10215052,
105051,
10214042,
10213032,
30435054,
304043,
32435254,
425254,
215152,
415154,
31435154,
213132,
214142,
103031,
10213032,
405054,
324243,
314143
};

extern const figureQestions question7Text[] = { 
    figureQestions{L"������� ������ ������ ������ ���, ����� ��������� �����������",triangle},
    figureQestions{L"������� ������ ������ ������ ���, ����� ��������� �������������",rectangle},
    figureQestions{L"������� ������ ������ ������ ���, ����� ��������� �������",square},
};

extern const figureQestions question8Text[] = {

figureQestions{L"���� ������ �������� � ������� �� �������.\n �������� ��� ������� � ������� ������ ���������� ����� � ������ ���������.",calc},
figureQestions{L"����� ������ ��� � �������� �� �������. �������� ��� �������\n � ������� ������ ���������� ������ � ��������� ����.",calc},
figureQestions{L"����� ������ �������� �� �������. �������� ��� �������\n � ������� ������ ���������� ��������� �� ������ �������.",calc},
figureQestions{L"�������� ������ ������� �� �������. �������� ��� �������\n � ������� ������ ���������� ������� �� ������ ������.",calc}

};

extern const variantOfLine question7squarevariantOfFirstLine[] = { 1,0, 2,1, 3,2 , 4,3 , 5,4 ,5,0 , 5,1  };
extern const variantOfLine question7trianglevariantOfFirstLine[] = { 1,0, 2,1, 3,2 , 4,3 , 5,4 ,5,0 , 5,1,
3,0,5,2,3,1,4,2,5,1,4,0

};
extern const variantOfLine question7rectanglevariantOfFirstLine[] = { 1,0, 2,1, 5,2 , 4,1 , 3,0 ,4,3 , 5,4 };

extern const figureQestions* qestionarrayList[] = { question1Text ,question2Text,question3Text,question4Text,question5Text,question6Text,question7Text,question8Text };
extern const std::array<std::string, N3> filenamesforPicaQuest3 = {
    std::string("chicken"),
    std::string("pencil"),
    std::string("house"),
    std::string("frog"),
    std::string("mushroom"),
    std::string("leaf")
};

extern const std::array<std::string, N8> filenamesforPicaQuest8 = {
    std::string("aqua_fish"),
    std::string("house"),
    std::string("leaf"),
    std::string("flower")
};

extern const std::array<std::string, N8> filenamesforPicaQuestMinus8 = {
    std::string("delete_fish"),
    std::string("delete_window"),
    std::string("delete_leaf"),
    std::string("delete_butterfly")
};
extern const std::array<std::string, N8> filenamesforPicaQuestPlus8 = {
    std::string("add_fish"),
    std::string("add_window"),
    std::string("add_leaf"),
    std::string("add_butterfly")
};

const std::array <std::array<phrasetoReplace, X>, Y> phrasestoReplace = {
  {
    {
      {
{L" 1 �������", L" 1 �������"},   { L" 2 �������", L" 2 �������" }, { L" 3 �������", L" 3 �������" }, { L" 4 �������", L" 4 �������" }, { L" 21 �������", L" 21 �������" }
      }
    },
    {
      {
{L" 1 ����", L" 1 �����"},   { L" 2 ����", L" 2 �����" }, { L" 3 ����", L" 3 �����" }, { L" 4 ����", L" 4 �����" }, { L" 21 ����", L" 21 �����" }
      }
    },

    {
      {
{L" 1 ������", L" 1 ����"},   { L" 2 ������", L" 2 �����" }, { L" 3 ������", L" 3 �����" }, { L" 4 ������", L" 4 �����" }, { L" 21 ������", L" 21 ����" }
      }
    }

    ,


    {
      {
{L" 1 �����", L" 1 �����"},   { L" 2 �����", L" 2 �����" }, { L" 3 �����", L" 3 �����" }, { L" 4 �����", L" 4 �����" }, { L" 21 �����", L" 21 �����" }
      }
    }
,

        {
      {
{L" 1 �������", L" 1 �������"},   { L" 2 �������", L" 2 �������" }, { L" 3 �������", L" 3 �������" }, { L" 4 �������", L" 4 �������" }, { L" 21 �������", L" 21 �������" }
      }
    }

    ,

            {
      {
{L" 1 ������", L" 1 �����"},   { L" 2 ������", L" 2 �����" }, { L" 3 ������", L" 3 �����" }, { L" 4 ������", L" 4 �����" }, { L" 21 ������", L" 21 �����" }
      }
    }


  }
};



const std::wstring CommentsDic[] =
{
    {L"������ �����" },
    {L"�����. �������, +1 ����" },
    {L"�������. ������ :(" }
};






