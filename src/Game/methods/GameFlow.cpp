#include "../Game.hpp"

namespace Dungeon {

bool Game::isOpen() {
	return this->window->isOpen();
};

void Game::update() {
	// Events
	this->pollEvents();
	this->handleKeyPress();

	// Player update
	//           Same thing as previous `base_update`
	this->player->Entity::update(); // This is collision check and storing the sprites position, this could be a player method
	this->player->update();

	//Enemy update
	this->current_level->updateEnemyList();

	// Clock things
	if (this->current_frame % 20 == 0)
		this->framerate = 1.f / this->base_clock->getElapsedTime().asSeconds();
	
	this->base_clock->restart();
	this->current_frame ++;
};

void Game::render() {
	// Clear window
	this->window->clear(sf::Color(96,8,64));
	
	// Render 
	this->current_level->renderBg();
	this->current_level->renderEnemyList();
	this->player->render();

	// Display framerate in top left corner
	this->drawFramerate();

	// 
	this->window->display();
};

};
