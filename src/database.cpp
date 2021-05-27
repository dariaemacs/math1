#include "database.hpp"
#include "settings.hpp"
#include "color.hpp"
#include "window.hpp"

extern const figureQestions question1Figure[] =
  {
    figureQestions{L"������� ������� �� �������� �� ������ ? "       ,circle},
    figureQestions{L"������� ��������������� �� �������� �� ������ ? ",rectangle},
    figureQestions{L"������� ������������� �� �������� �� ������ ? ",triangle},    
  }	;
extern const figureQestions question2Figure[] =
{
figureQestions{ L"���� ����� �������� ������ N �������. �� �������� \n����� M ������� . ������� ������� ���� ��� ����� ?",seashell },
figureQestions{ L"� ������� ���� N ���� ��������. ����� ���� , ��� ����� ���� \n��������� ����, �������� M. ������� ���� ���� ����� ?",berry },
figureQestions{ L"���� ����� ����� N ������. ��� �������� ����� M ������. \n������� ������ �� ��� ����� ?",mashroom },
figureQestions{ L"���� � ���� ������� N �����. ���� ������ M �����. \n������� ����� ������� ����?",fish },
figureQestions{ L"������ ����� ���������� N �������. ��� ���������� \n M �������. ������� ������� �������� ����������? ",butterfly },
figureQestions{ L"���� ����� ������ ���������. �� ����� N ������, \n������ � ���� � ������� M ������. �������  ��� ������ ����� ����, \n����� ������� �� ���������?",bycicle }
};

extern const figureQestions* qestionarrayList[] = { question1Figure ,question2Figure };

extern const std::array<std::string, N2> filenamesforPicaQuest2 = { std::string("shell"),std::string("berry"),std::string("mushroom"),std::string("fish"),
std::string("butterfly"),std::string("coin")
};


const std::array <std::array<phrasetoReplace, X>, Y> phrasestoReplace= {
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






