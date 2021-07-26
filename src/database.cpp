#include "database.hpp"
#include "settings.hpp"
#include "color.hpp"
#include "window.hpp"

extern std::vector< std::vector<int>> numSeries = { {20,19,18,17,16,15},{1,2,3,4,5,6},{17,14,11,8,5,2} };
//extern const int numSeries[][6] = { {31,29,27,25,23,21},{1,2,3,4,5,6},{17,21,25,29,33,37} };

extern const figureQestions question1Text[] =
{
  figureQestions{L"Сколько кружков на рисунках вы видете ? "       ,circle},
  figureQestions{L"Сколько прямоугольников на рисунках вы видите ? ",rectangle},
  figureQestions{L"Сколько треугольников на рисунках вы видите ? ",triangle},
};



extern const figureQestions question2Text[] =
{
figureQestions{ L"Лена хочет подарить родным N ракушек. Ей осталось \nнайти M ракушек . Сколько ракушек Лена уже нашла ?",seashell },
figureQestions{ L"В корзине было N ягод клубники. После того , как Игорь съел \nнесколько ягод, осталось M. Сколько ягод съел Игорь ?",berry },
figureQestions{ L"Ване нужно найти N грибов. Ему осталось найти M грибов. \nСколько грибов он уже нашел ?",mashroom },
figureQestions{ L"Паша и Люба поймали N рыбок. Паша поймал M рыбок. \nСколько рыбок поймала Люба?",fish },
figureQestions{ L"Наташе нужно раскрасить N бабочек. Она раскрасила \n M бабочек. Сколько бабочек осталось раскрасить? ",butterfly },
figureQestions{ L"Саша хочет купить велосипед. Он стоит N рублей, \nсейчас у Саши в копилке M рублей. Сколько  еще рублей нужно Саше, \nчтобы хватило на велосипед?",bycicle }
};



extern const figureQestions question3Text[] =
{



figureQestions{ L"В первый день в курятнике вылупились N цыплят. А во второй день \nвылупились еще M, их посадили в корзинку. Сколько всего цыплят вылупилось за два дня?",chicken     },
figureQestions{L"У Кати было N карандашей. Мама купила ей еще M (в коробке). Сколько\n карандашей стало у Кати?",                                                         pencil      },
figureQestions{L"Сначала строители построили N дома, а потом еще M (за деревьями).\n Сколько всего домов построили строители?",                                           house       },
figureQestions{L"На берегу пруда сидели N лягушек. Затем к ним прискакали \nеще M лягушек (за камышами). Сколько теперь всего лягушек сидит на берегу?" ,                  frog        },
figureQestions{L"Утром после дождя ребята собрали N грибов, а днем \nеще M грибов (в корзинке). Сколько всего грибов собрали ребята?",                                    mashroom        },
figureQestions{L"Для урока Коля собрал N дубовых листьев и еще M \nкленовых (в корзинке). Сколько всего листьев собрал Коля?",                                            oaklist     }

};

extern const figureQestions question4Text[] = { figureQestions{ L"На математическом поезде числа записаны по \n определенному правилу. Определите правило и \nнажмите на пропущенные числа, чтобы они появились в окошках?",train     } };

extern const figureQestions question5Text[] =
{
figureQestions{L"У Алисы 20 карандашей, а у Тони на 10 карандашей меньше. Сколько карандашей у Тони?"       ,calc},
figureQestions{L"У Димы есть 16 машинок, а у Захара на 5 машинок меньше. Сколько машинок у Захара?"       ,calc},
figureQestions{L"Кошка Мурка весит 6 килограммов,  а пес Шарик на 12 килограммов тяжелее. Сколько весит Шарик?"       ,calc},
figureQestions{L"Арсению 11 лет, а его сестра Катя на 8 лет старше. Сколько лет Кате?"       ,calc},
figureQestions{L"У Полины ленточка длиной 10 см, а у Сони на 10 см длиннее. Какая длина Сониной ленточки?"       ,calc},
figureQestions{L"Марку 14 лет, а его брат Андрей на 11 лет младше. Сколько лет Андрею?"       ,calc}
};
extern const int question5Answers[] = {10,11,18,19,20,3};



extern const std::array<std::string, N2> filenamesforPicaQuest2 = { std::string("shell"),std::string("berry"),std::string("mushroom"),std::string("fish"),
std::string("butterfly"),std::string("coin")
};
extern const figureQestions question6Text[] = {
figureQestions{L"Максим решил купить в магазине наклейки за 6 рублей. У него есть такие монеты.\n Продавцу Максим дал одну монету и получил сдачу. Какую сдачу \nполучил мальчик"       ,calc},
figureQestions{L"Деньги за покупку шоколада принимает автомат. У Насти есть такие монеты. Девочка хочет \nкупить шоколад за 8 рублей. Она опустила в автомат одну \nмонету и получила сдачу. Какую сдачу получила Настя?"       ,calc},
figureQestions{L"Лиза решила купить в магазине шарик за 7 рублей. У нее есть такие монеты. \nПродавцу Лиза дала одну монету и получила сдачу. \nКакую сдачу получила девочка?"       ,calc},
figureQestions{L"Деньги за покупку игрушки принимает автомат. У Ани есть такие монеты. \nДевочка хочет купить игрушку за 9 рублей. Она опустила в автомат одну \nмонету и получила сдачу. Какую сдачу получила Аня? "       ,calc},
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
    figureQestions{L"Дорисуй мышкой данную фигуру так, чтобы получился треугольник",triangle},
    figureQestions{L"Дорисуй мышкой данную фигуру так, чтобы получился прямоугольник",rectangle},
    figureQestions{L"Дорисуй мышкой данную фигуру так, чтобы получился квадрат",square},
};

extern const figureQestions question8Text[] = {

figureQestions{L"Катя рисует аквариум с рыбками по правилу.\n Определи это правило и нарисуй нужное количество рыбок в пустом аквариуме.",calc},
figureQestions{L"Серёжа рисует дом с окошками по правилу. Определи это правило\n и нарисуй нужное количество окошек в последнем доме.",calc},
figureQestions{L"Игнат рисует листочки по правилу. Определи это правило\n и нарисуй нужное количество листочков на пустой веточке.",calc},
figureQestions{L"Ангелина рисует бабочек по правилу. Определи это правило\n и нарисуй нужное количество бабочек на пустом цветке.",calc}

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
{L" 1 ракушек", L" 1 ракушку"},   { L" 2 ракушек", L" 2 ракушки" }, { L" 3 ракушек", L" 3 ракушки" }, { L" 4 ракушек", L" 4 ракушки" }, { L" 21 ракушек", L" 21 ракушку" }
      }
    },
    {
      {
{L" 1 ягод", L" 1 ягода"},   { L" 2 ягод", L" 2 ягоды" }, { L" 3 ягод", L" 3 ягоды" }, { L" 4 ягод", L" 4 ягоды" }, { L" 21 ягод", L" 21 ягода" }
      }
    },

    {
      {
{L" 1 грибов", L" 1 гриб"},   { L" 2 грибов", L" 2 гриба" }, { L" 3 грибов", L" 3 гриба" }, { L" 4 грибов", L" 4 гриба" }, { L" 21 грибов", L" 21 гриб" }
      }
    }

    ,


    {
      {
{L" 1 рыбок", L" 1 рыбку"},   { L" 2 рыбок", L" 2 рыбки" }, { L" 3 рыбок", L" 3 рыбки" }, { L" 4 рыбок", L" 4 рыбки" }, { L" 21 рыбок", L" 21 рыбку" }
      }
    }
,

        {
      {
{L" 1 бабочек", L" 1 бабочку"},   { L" 2 бабочек", L" 2 бабочки" }, { L" 3 бабочек", L" 3 бабочки" }, { L" 4 бабочек", L" 4 бабочки" }, { L" 21 бабочек", L" 21 бабочку" }
      }
    }

    ,

            {
      {
{L" 1 рублей", L" 1 рубль"},   { L" 2 рублей", L" 2 рубля" }, { L" 3 рублей", L" 3 рубля" }, { L" 4 рублей", L" 4 рубля" }, { L" 21 рублей", L" 21 рубль" }
      }
    }


  }
};



const std::wstring CommentsDic[] =
{
    {L"Выбери ответ" },
    {L"Верно. Молодец, +1 балл" },
    {L"Неверно. Ошибка :(" }
};






