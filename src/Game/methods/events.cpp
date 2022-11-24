#include "../Game.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

namespace Dungeon {

void Game::pollEvents() {
	while (this->window->pollEvent(this->events)){
		switch (this->events.type){
			case sf::Event::Closed :
				this->window->close();
				break;
			case sf::Event::MouseButtonPressed :
				if (this->events.mouseButton.button == sf::Mouse::Left)
					if (this->player->weapon->cooldown_sw.is_stop){
						this->player->weapon->initAttack();
					}
			case sf::Event::KeyPressed :
				if (this->help_menu == true) help_menu = false;
				if (this->events.key.code == sf::Keyboard::Escape){
					this->pause = !(this->pause);
				}
				else if (this->events.key.code == sf::Keyboard::Enter){
					if (this->game_over) this->restart();
				}
				else if (this->events.key.code == sf::Keyboard::R){
					if (this->win_state) this->restart();
				}
				break;
			default:
				break;

		}
	}
};


void Game::handleKeyPress() {
	float speed = this->player->speed;
	
	this->player->direction.x = 0.f;
	this->player->direction.y = 0.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		this->player->direction.y += speed*-1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		this->player->direction.x += speed*-1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		this->player->direction.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		this->player->direction.x += speed;
	}
	//slow when in diagnal
	if (
		this->player->direction.x != 0.f &&
		this->player->direction.y != 0.f 
	) {
		this->player->direction.x/=1.5;
		this->player->direction.y/=1.5;
	}
};

void Game::activateWinState() {
	this->win_state = true;
	this->game_time = this->game_clock->getElapsedTime().asSeconds();

	return;
};

};
