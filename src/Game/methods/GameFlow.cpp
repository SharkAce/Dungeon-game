#include "../Game.hpp"

namespace Dungeon {

bool Game::isOpen() {
	return this->window->isOpen();
};

void Game::update() {

	// Clock things
	if (this->current_frame % 20 == 0){
		float time = this->base_clock->getElapsedTime().asSeconds();
		this->framerate = 1.f / time;
		this->time_unit = time * 60;

	}
	
	this->base_clock->restart();
	this->current_frame ++;

	// Events
	this->pollEvents();

	// Update sfx
	this->updateSfx();

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

	//Gate update
	this->current_level->updateDoor();

};

void Game::render() {
	// Clear window
	this->window->clear(sf::Color(96,8,64));
	
	// Render 
	this->current_level->renderLevel();
	this->player->render();

	// Display framerate in top left corner
	this->drawFramerate();

	// Displat win screen
	if (this->win_state) this->drawWinScreen();

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
