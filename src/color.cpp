//#include "../include/color.hpp"
#include "color.hpp"
#include <iostream>

const sf::Color color::aliceblue							= sf::Color(0xf0f8ffff); // 240,248,255
const sf::Color color::antiquewhite							= sf::Color(0xfaebd7ff); // 250,235,215
const sf::Color color::aqua									= sf::Color(0x00ffffff); // ,255,255
const sf::Color color::aquamarine							= sf::Color(0x7fffd4ff); // 127,255,212
const sf::Color color::azure								= sf::Color(0xf0ffffff); // 240,255,255
const sf::Color color::beige								= sf::Color(0xf5f5dcff); // 245,245,220
const sf::Color color::bisque								= sf::Color(0xffe4c4ff); // 255,228,196
const sf::Color color::black								= sf::Color(0x000000ff); // ,0,0
const sf::Color color::blanchedalmond						= sf::Color(0xffebcdff); // 255,235,205
const sf::Color color::blue									= sf::Color(0x0000ffff); // ,0,255
const sf::Color color::blueviolet							= sf::Color(0x8a2be2ff); // 38,43,226
const sf::Color color::brown								= sf::Color(0xa52a2aff); // 65,42,42
const sf::Color color::burlywood							= sf::Color(0xdeb887ff); // 222,184,135
const sf::Color color::cadetblue							= sf::Color(0x5f9ea0ff); // 5,158,160
const sf::Color color::chartreuse							= sf::Color(0x7fff00ff); // 27,255,0
const sf::Color color::chocolate							= sf::Color(0xd2691eff); // 10,105,30
const sf::Color color::coral								= sf::Color(0xff7f50ff); // 55,127,80
const sf::Color color::cornflowerblue						= sf::Color(0x6495edff); // 100,149,237
const sf::Color color::cornsilk								= sf::Color(0xfff8dcff); // 255,248,220
const sf::Color color::crimson								= sf::Color(0xdc143cff); // 20,20,60
const sf::Color color::cyan									= sf::Color(0x00ffffff); // ,255,255
const sf::Color color::darkblue								= sf::Color(0x00008bff); // ,0,139
const sf::Color color::darkcyan								= sf::Color(0x008b8bff); // ,139,139
const sf::Color color::darkgoldenrod						= sf::Color(0xb8860bff); // 84,134,11
const sf::Color color::darkgray								= sf::Color(0xa9a9a9ff); // 169,169,169
const sf::Color color::darkgreen							= sf::Color(0x006400ff); // ,100,0
const sf::Color color::darkgrey								= sf::Color(0xa9a9a9ff); // 169,169,169
const sf::Color color::darkkhaki							= sf::Color(0xbdb76bff); // 189,183,107
const sf::Color color::darkmagenta							= sf::Color(0x8b008bff); // 39,0,139
const sf::Color color::darkolivegreen						= sf::Color(0x556b2fff); // 5,107,47
const sf::Color color::darkorange							= sf::Color(0xff8c00ff); // 55,140,0
const sf::Color color::darkorchid							= sf::Color(0x9932ccff); // 53,50,204
const sf::Color color::darkred								= sf::Color(0x8b0000ff); // 39,0,0
const sf::Color color::darksalmon							= sf::Color(0xe9967aff); // 233,150,122
const sf::Color color::darkseagreen							= sf::Color(0x8fbc8fff); // 143,188,143
const sf::Color color::darkslateblue						= sf::Color(0x483d8bff); // 2,61,139
const sf::Color color::darkslategray						= sf::Color(0x2f4f4fff); // 7,79,79
const sf::Color color::darkslategrey						= sf::Color(0x2f4f4fff); // 7,79,79
const sf::Color color::darkturquoise						= sf::Color(0x00ced1ff); // ,206,209
const sf::Color color::darkviolet							= sf::Color(0x9400d3ff); // 48,0,211
const sf::Color color::deeppink								= sf::Color(0xff1493ff); // 55,20,147
const sf::Color color::deepskyblue							= sf::Color(0x00bfffff); // ,191,255
const sf::Color color::dimgray								= sf::Color(0x696969ff); // 105,105,105
const sf::Color color::dimgrey								= sf::Color(0x696969ff); // 105,105,105
const sf::Color color::dodgerblue							= sf::Color(0x1e90ffff); // 0,144,255
const sf::Color color::firebrick							= sf::Color(0xb22222ff); // 78,34,34
const sf::Color color::floralwhite							= sf::Color(0xfffaf0ff); // 255,250,240
const sf::Color color::forestgreen							= sf::Color(0x228b22ff); // 4,139,34
const sf::Color color::fuchsia								= sf::Color(0xff00ffff); // 55,0,255
const sf::Color color::gainsboro							= sf::Color(0xdcdcdcff); // 220,220,220
const sf::Color color::ghostwhite							= sf::Color(0xf8f8ffff); // 248,248,255
const sf::Color color::gold									= sf::Color(0xffd700ff); // 55,215,0
const sf::Color color::goldenrod							= sf::Color(0xdaa520ff); // 18,165,32
const sf::Color color::gray									= sf::Color(0x808080ff); // 128,128,128
const sf::Color color::green								= sf::Color(0x008000ff); // ,128,0
const sf::Color color::greenyellow							= sf::Color(0xadff2fff); // 73,255,47
const sf::Color color::grey									= sf::Color(0x808080ff); // 128,128,128
const sf::Color color::honeydew								= sf::Color(0xf0fff0ff); // 240,255,240
const sf::Color color::hotpink								= sf::Color(0xff69b4ff); // 255,105,180
const sf::Color color::indianred							= sf::Color(0xcd5c5cff); // 05,92,92
const sf::Color color::indigo								= sf::Color(0x4b0082ff); // 5,0,130
const sf::Color color::ivory								= sf::Color(0xfffff0ff); // 255,255,240
const sf::Color color::khaki								= sf::Color(0xf0e68cff); // 240,230,140
const sf::Color color::lavender								= sf::Color(0xe6e6faff); // 230,230,250
const sf::Color color::lavenderblush						= sf::Color(0xfff0f5ff); // 255,240,245
const sf::Color color::lawngreen							= sf::Color(0x7cfc00ff); // 24,252,0
const sf::Color color::lemonchiffon							= sf::Color(0xfffacdff); // 255,250,205
const sf::Color color::lightblue							= sf::Color(0xadd8e6ff); // 173,216,230
const sf::Color color::lightcoral							= sf::Color(0xf08080ff); // 240,128,128
const sf::Color color::lightcyan							= sf::Color(0xe0ffffff); // 224,255,255
const sf::Color color::lightgoldenrodyellow					= sf::Color(0xfafad2ff); // 250,250,210
const sf::Color color::lightgray							= sf::Color(0xd3d3d3ff); // 211,211,211
const sf::Color color::lightgreen							= sf::Color(0x90ee90ff); // 144,238,144
const sf::Color color::lightgrey							= sf::Color(0xd3d3d3ff); // 211,211,211
const sf::Color color::lightpink							= sf::Color(0xffb6c1ff); // 255,182,193
const sf::Color color::lightsalmon							= sf::Color(0xffa07aff); // 255,160,122
const sf::Color color::lightseagreen						= sf::Color(0x20b2aaff); // 2,178,170
const sf::Color color::lightskyblue							= sf::Color(0x87cefaff); // 135,206,250
const sf::Color color::lightslategray						= sf::Color(0x778899ff); // 119,136,153
const sf::Color color::lightslategrey						= sf::Color(0x778899ff); // 119,136,153
const sf::Color color::lightsteelblue						= sf::Color(0xb0c4deff); // 176,196,222
const sf::Color color::lightyellow							= sf::Color(0xffffe0ff); // 255,255,224
const sf::Color color::lime									= sf::Color(0x00ff00ff); // ,255,0
const sf::Color color::limegreen							= sf::Color(0x32cd32ff); // 0,205,50
const sf::Color color::linen								= sf::Color(0xfaf0e6ff); // 250,240,230
const sf::Color color::magenta								= sf::Color(0xff00ffff); // 55,0,255
const sf::Color color::maroon								= sf::Color(0x800000ff); // 28,0,0
const sf::Color color::mediumaquamarine						= sf::Color(0x66cdaaff); // 102,205,170
const sf::Color color::mediumblue							= sf::Color(0x0000cdff); // ,0,205
const sf::Color color::mediumorchid							= sf::Color(0xba55d3ff); // 86,85,211
const sf::Color color::mediumpurple							= sf::Color(0x9370dbff); // 147,112,219
const sf::Color color::mediumseagreen						= sf::Color(0x3cb371ff); // 0,179,113
const sf::Color color::mediumslateblue						= sf::Color(0x7b68eeff); // 123,104,238
const sf::Color color::mediumspringgreen					= sf::Color(0x00fa9aff); // ,250,154
const sf::Color color::mediumturquoise						= sf::Color(0x48d1ccff); // 2,209,204
const sf::Color color::mediumvioletred						= sf::Color(0xc71585ff); // 99,21,133
const sf::Color color::midnightblue							= sf::Color(0x191970ff); // 5,25,112
const sf::Color color::mintcream							= sf::Color(0xf5fffaff); // 245,255,250
const sf::Color color::mistyrose							= sf::Color(0xffe4e1ff); // 255,228,225
const sf::Color color::moccasin								= sf::Color(0xffe4b5ff); // 255,228,181
const sf::Color color::navajowhite							= sf::Color(0xffdeadff); // 255,222,173
const sf::Color color::navy									= sf::Color(0x000080ff); // ,0,128
const sf::Color color::oldlace								= sf::Color(0xfdf5e6ff); // 253,245,230
const sf::Color color::olive								= sf::Color(0x808000ff); // 28,128,0
const sf::Color color::olivedrab							= sf::Color(0x6b8e23ff); // 07,142,35
const sf::Color color::orange								= sf::Color(0xffa500ff); // 55,165,0
const sf::Color color::orangered							= sf::Color(0xff4500ff); // 55,69,0
const sf::Color color::orchid								= sf::Color(0xda70d6ff); // 218,112,214
const sf::Color color::palegoldenrod						= sf::Color(0xeee8aaff); // 238,232,170
const sf::Color color::palegreen							= sf::Color(0x98fb98ff); // 152,251,152
const sf::Color color::paleturquoise						= sf::Color(0xafeeeeff); // 175,238,238
const sf::Color color::palevioletred						= sf::Color(0xdb7093ff); // 219,112,147
const sf::Color color::papayawhip							= sf::Color(0xffefd5ff); // 255,239,213
const sf::Color color::peachpuff							= sf::Color(0xffdab9ff); // 255,218,185
const sf::Color color::peru									= sf::Color(0xcd853fff); // 05,133,63
const sf::Color color::pink									= sf::Color(0xffc0cbff); // 255,192,203
const sf::Color color::plum									= sf::Color(0xdda0ddff); // 221,160,221
const sf::Color color::powderblue							= sf::Color(0xb0e0e6ff); // 176,224,230
const sf::Color color::purple								= sf::Color(0x800080ff); // 28,0,128
const sf::Color color::red									= sf::Color(0xff0000ff); // 55,0,0
const sf::Color color::rosybrown							= sf::Color(0xbc8f8fff); // 188,143,143
const sf::Color color::royalblue							= sf::Color(0x4169e1ff); // 5,105,225
const sf::Color color::saddlebrown							= sf::Color(0x8b4513ff); // 39,69,19
const sf::Color color::salmon								= sf::Color(0xfa8072ff); // 250,128,114
const sf::Color color::sandybrown							= sf::Color(0xf4a460ff); // 44,164,96
const sf::Color color::seagreen								= sf::Color(0x2e8b57ff); // 6,139,87
const sf::Color color::seashell								= sf::Color(0xfff5eeff); // 255,245,238
const sf::Color color::sienna								= sf::Color(0xa0522dff); // 60,82,45
const sf::Color color::silver								= sf::Color(0xc0c0c0ff); // 192,192,192
const sf::Color color::skyblue								= sf::Color(0x87ceebff); // 135,206,235
const sf::Color color::slateblue							= sf::Color(0x6a5acdff); // 06,90,205
const sf::Color color::slategray							= sf::Color(0x708090ff); // 112,128,144
const sf::Color color::slategrey							= sf::Color(0x708090ff); // 112,128,144
const sf::Color color::snow									= sf::Color(0xfffafaff); // 255,250,250
const sf::Color color::springgreen							= sf::Color(0x00ff7fff); // ,255,127
const sf::Color color::steelblue							= sf::Color(0x4682b4ff); // 0,130,180
const sf::Color color::tan									= sf::Color(0xd2b48cff); // 210,180,140
const sf::Color color::teal									= sf::Color(0x008080ff); // ,128,128
const sf::Color color::thistle								= sf::Color(0xd8bfd8ff); // 216,191,216
const sf::Color color::tomato								= sf::Color(0xff6347ff); // 55,99,71
const sf::Color color::turquoise							= sf::Color(0x40e0d0ff); // 4,224,208
const sf::Color color::violet								= sf::Color(0xee82eeff); // 238,130,238
const sf::Color color::wheat								= sf::Color(0xf5deb3ff); // 245,222,179
const sf::Color color::white								= sf::Color(0xffffffff); // 255,255,255
const sf::Color color::whitesmoke							= sf::Color(0xf5f5f5ff); // 245,245,245
const sf::Color color::yellow								= sf::Color(0xffff00ff); // 55,255,0
const sf::Color color::yellowgreen							= sf::Color(0x9acd32ff); // 54,205,50 




//const sf::Color* wheels[] = { &color::aliceblue, &color::skyblue, &color::salmon };


	
