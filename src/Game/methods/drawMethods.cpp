#include "../Game.hpp"

namespace Dungeon {

void Game::drawHearts(){
	this->heart_sprite_empty.setPosition(5,0);
	this->heart_sprite.setPosition(5,0);
	for (int i=0; i<this->player->max_hp;i++){
		this->window->draw(this->heart_sprite_empty);
		this->heart_sprite_empty.move(45,0);
	}
	for (int i=0; i<this->player->current_hp;i++){
		this->window->draw(this->heart_sprite);
		this->heart_sprite.move(45,0);
	}
};

void Game::drawKeys(){
	this->key_sprite.setPosition(5,45);
	for (int i=0; i<this->player->key_count;i++){
		this->window->draw(this->key_sprite);
		this->key_sprite.move(45,0);
	}
};


void Game::drawFramerate() {
	this->writeToScreen(std::to_string((int)this->framerate),this->window->getSize().x - 40.f,18.f, *this->default_text);
};

void Game::drawPause(){
	this->writeToScreen("Paused",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f, *this->default_text);
};


void Game::drawGameOver(){
	this->writeToScreen("Game Over",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f, *this->default_text);
	this->writeToScreen("Press Enter to restart",this->window->getSize().x/2.0f,this->window->getSize().y/1.05, *this->default_text);
};

void Game::drawHelpMenu(){
	this->writeToScreen("How to play:",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f+(40.f*-1.f), *this->default_text);
	this->writeToScreen("The sword follows the cursor",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f+(40.f*1.f), *this->default_text);
	this->writeToScreen("Left Click to attack",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f+(40.f*2.f), *this->default_text);
	this->writeToScreen("W,A,S,D for moving",this->window->getSize().x/2.0f,this->window->getSize().y/3.0f+(40.f*3.f), *this->default_text);
	this->writeToScreen("Press any key to start",this->window->getSize().x/2.0f,this->window->getSize().y/1.05, *this->default_text);
};

void Game::drawWinScreen(){
	this->writeToScreen("Thanks  for  playing\nPress 'r' to restart", this->window->getSize().x/2.0f,this->window->getSize().y/2.0f-90.f, *this->default_text);

	int minutes = ((int)this->game_time - ((int)this->game_time % 60)) / 60;
	int seconds = (int)this->game_time - (minutes * 60);
	int centisecond = (int)((this->game_time-(int)this->game_time)*100);

	std::ostringstream oss;
	oss << "Time : " << minutes << ':' << seconds << '.' << centisecond;
	this->writeToScreen(oss.str(), this->window->getSize().x/2.0f,this->window->getSize().y/2.0f, *this->default_text);


};


};
