#include "../Game.hpp"

namespace Dungeon {

void Game::restart(){
	delete this->player;
	this->player = new Player(this);


	this->initLevel(testLevel(this));

	this->game_over = false;


};


};
