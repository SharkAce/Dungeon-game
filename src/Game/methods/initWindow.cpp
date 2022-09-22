#include "../Game.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {

void Game::initWindow(bool is_fullscreen) {

	short int wnx = is_fullscreen ? 1920 : 1280;
	short int wny = is_fullscreen ? 1080 : 720;

	this->window = new sf::RenderWindow(
		sf::VideoMode(wnx, wny, 32),
		"SFML Game", // My desktop is configured for windows with "SFML" in their titles popup as floating windows
		is_fullscreen ? sf::Style::Fullscreen : sf::Style::None
	);

	this->window->setFramerateLimit(60);

	this->window_bound = sf::FloatRect(0.f,0.f,this->window->getSize().x,this->window->getSize().y);
};

};
