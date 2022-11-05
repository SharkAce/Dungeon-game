#include "../Game.hpp"

namespace Dungeon {

bool Game::isOpen() {
	return this->window->isOpen();
};

void Game::update() {

	// Clock things
	if (this->current_frame % 20 == 0)
		this->framerate = 1.f / this->base_clock->getElapsedTime().asSeconds();
	
	this->base_clock->restart();
	this->current_frame ++;

	// Events
	this->pollEvents();

	//set mouse position
	mouse_pos = sf::Mouse::getPosition(*(this->window));

	if (this->pause || this->game_over || this->help_menu) {
		return;
	}

	this->handleKeyPress();

	// Player update
	//           Same thing as previous `base_update`
	this->player->Entity::update(); // This is collision check and storing the sprites position, this could be a player method
	this->player->update();

	//Check if player collides with a finish rect and changes current_level accordingly
	this->current_level->updateFinishRects();

	//Enemy update
	this->current_level->updateEnemyList();

	//Consumable update
	this->current_level->updateConsumableList();

};

void Game::render() {
	// Clear window
	this->window->clear(sf::Color(96,8,64));
	
	// Render 
	this->current_level->renderBg();
	this->current_level->renderConsumableList();
	this->current_level->renderEnemyList();
	this->player->render();

	// Display framerate in top left corner
	this->drawFramerate();

	// Display pause message
	if (this->pause && !game_over) this->drawPause();

	if (this->game_over) this->drawGameOver();

	if (this->help_menu) this->drawHelpMenu();

	// Display player hearts
	this->drawHearts();

	// Display player keys
	this->drawKeys();

	// 
	this->window->display();
};

};
