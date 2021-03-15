#ifndef GAME_H
#define GAME_H

#include <vector>
#include <random>
#include <cstdint>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>

//#include <yaml-cpp/yaml.h>

struct settings_t {
  float area_width;
  float area_height;
  unsigned int fps;

  std::string font_path;
  std::string image_path;
};

struct random{
  static unsigned int get(unsigned int upper_bound){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> distrib(0, upper_bound - 1);
    return distrib(gen);
  }
};

enum class StateType{
  Menu = 0,
  Game,
  Paused,
  GameOver,
  //...
  Count
};

class Game{
  
private:
  // void handle_input();
  void render();
  void update();
  // void pause();
  // void start();

  //  void save_result();

  void process_events();
  
  void set_icon();

public:
  Game();//const YAML::Node& config);
  void run();


private:
  std::unique_ptr<sf::RenderWindow> window;  
  sf::CircleShape player;
  std::unique_ptr<settings_t> settings;
  sf::Font font;
};

#endif // GAME_H
