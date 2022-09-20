#include "../Game.hpp"

namespace Dungeon {

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

};
