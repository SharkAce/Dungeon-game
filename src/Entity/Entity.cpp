#include "Entity.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {

Entity::Entity(Game* parent_game){
	this->parent_game = parent_game;
	this->direction.x = 0.f;
	this->direction.y = 0.f;
	this->texture = &(this->parent_game->sprite_sheet);
	this->window = this->parent_game->window;
};

};
