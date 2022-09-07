#include "../Game.hpp"

namespace Dungeon {

void Game::restart(){
	delete this->current_level;
	delete this->player;

	this->player = new Player(this);
	this->initLevel(testLevel(this));
	this->player->setPosition(20*48,11*48);

	this->game_over = false;


};


};
