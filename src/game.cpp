#include "game.hpp"
#include "color.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

Game::Game(const YAML::Node& config)
  : window(std::make_unique<sf::RenderWindow> (sf::VideoMode(1024, 752), "Математика 1 класс")),
    player(150)
{
    settings = std::make_unique<settings_t> (settings_t{
      .area_width = config["game"]["width"].as<float>(),
      .area_height = config["game"]["height"].as<float>(),
      .fps = config["game"]["fps"].as<unsigned int>(),
      .font_path = config["font"].as<std::string>(),
      .image_path = config["image"].as<std::string>()
    });

    //  window = std::make_unique<sf::RenderWindow> (VideoMode(settings->area_width, settings->area_height), "Математика 1 класс");
  
    player.setFillColor(color::fuchsia);
    player.setPosition(10, 20);
    
    window->setFramerateLimit(settings->fps);
    std::cout << "width: " << settings->area_width << " height: " << settings->area_height << std::endl;
}

void Game::run() {
    bool is_redraw_needed = true;
    sf::Clock clock;
    while (window->isOpen()) {
      if (clock.getElapsedTime().asSeconds() >= 1.0f / settings->fps) {
            is_redraw_needed = true;
            update();
            clock.restart();
        }
        process_events();
        if (is_redraw_needed) {
            is_redraw_needed = false;
            render();
        }
    }
}

void Game::process_events() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if ((event.type == sf::Event::Closed)
            or ((event.type == sf::Event::KeyPressed)
                and (event.key.code == sf::Keyboard::Escape))) {
            window->close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            // else if(event.key.code == sf::Keyboard::Up)
            // 	player.isMoving = true;
            // else if (event.key.code == sf::Keyboard::Left)
            // 	player.rotation = -1;
            // else if (event.key.code == sf::Keyboard::Right)
            // 	player.rotation = 1;
        }
        else if (event.type == sf::Event::KeyReleased) {
            // if(event.key.code == sf::Keyboard::Up)
            // 	player.isMoving = false;
            // else if (event.key.code == sf::Keyboard::Left)
            // 	player.rotation = 0;
            // else if (event.key.code == sf::Keyboard::Right)
            // 	player.rotation = 0;
        }
    }
}

void Game::update() {
    player.move(1.0f, 0);
}

void Game::render() {
    window->clear(sf::Color(0, 0, 0));
    window->draw(player);
    window->display();
}
