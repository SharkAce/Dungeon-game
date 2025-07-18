#include "../Game.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {

void Game::initWindow(bool is_fullscreen) {

	unsigned int wnx = is_fullscreen ? 1920 : 1280;
	unsigned int wny = is_fullscreen ? 1080 : 720;

	this->window = sf::RenderWindow(
		sf::VideoMode({wnx, wny}, 32),
		"SFML Game", // My desktop is configured for windows with "SFML" in their titles popup as floating windows
		is_fullscreen ? sf::State::Fullscreen : sf::State::Windowed
	);

	this->window.setFramerateLimit(144);

	this->window_bound = {{0,0},{(float)this->window.getSize().x,(float)this->window.getSize().y}};
};

};
