#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

struct Settings {
    static constexpr int COUNT = 1;
    static constexpr  float ButtonFactor = 0.15f;
    static constexpr  int ButtonMarginTop = 1200;
    static constexpr int WIDTH = 1280;
    static constexpr int HEIGHT = 752;
    static constexpr float FPS = 60.0f;

    static constexpr int   PADDING = 10;
    static constexpr int   QUESTFONTSIZE = 70;
    static constexpr int   TEXTFRAMHEIGHT = 150;
    static constexpr int   IMGPADDINGLEFT = 350;
    static constexpr int   BUTTONPADDINGTOP = 1200;
    static constexpr float THICKNESS = 8.0f;
 
    static const std::string RESOURCE_PATH;
    static const std::string IMAGES_PATH;
    static const std::string FONTS_PATH;
   
};


#endif //SETTINGS_H

