#include "../Game.hpp"

namespace Dungeon {

void Game::drawHearts(){
	this->heart_sprite.setPosition(0,0);
	for (int i=0; i<this->player->current_hp;i++){
		this->window->draw(this->heart_sprite);
		this->heart_sprite.move(45,0);
	}
};

};
