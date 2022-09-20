#include "../Game.hpp"

namespace Dungeon {

void Game::drawHearts(){
	this->heart_sprite.setPosition(5,0);
	for (int i=0; i<this->player->current_hp;i++){
		this->window->draw(this->heart_sprite);
		this->heart_sprite.move(45,0);
	}
};

void Game::drawFramerate() {
	this->writeToScreen(std::to_string((int)this->framerate),this->window->getSize().x - 24.f,0);
};

void Game::drawPause(){
	this->writeToScreen("Paused",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f);
};


void Game::drawGameOver(){
	this->writeToScreen("Game Over",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f);
	this->writeToScreen("Press  Enter  to  restart",this->window->getSize().x/2.0f,this->window->getSize().y/1.05);
};


};
