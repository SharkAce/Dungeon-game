#include "../Game.hpp"

namespace Dungeon {

void Game::restart(){
	delete this->player;
	this->player = new Player(this);
	this->dead_enemies.clear();
	this->taken_keys.clear();
	this->game_clock->restart();


	this->initLevel(World1::level3A(this),sf::Vector2f(20*48,20*48));

	this->game_over = false;
	this->win_state = false;


};


};
