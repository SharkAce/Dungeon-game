#include "../Game.hpp"

namespace Dungeon {

void Game::restart(){
	delete this->player;
	this->player = new Player(this);
	this->dead_enemies.clear();


	this->initLevel(testLevel(this),sf::Vector2f(20*48,20*48));

	this->game_over = false;


};


};
