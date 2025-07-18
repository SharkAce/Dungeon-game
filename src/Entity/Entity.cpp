#include "Entity.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {

Entity::Entity(Game *parent_game): 
		kb_stopwatch(0, parent_game, false),
		parent_game(parent_game),
		sprite(parent_game->sprite_sheet) {
	this->parent_game = parent_game;
	this->direction.x = 0.f;
	this->direction.y = 0.f;
	this->window = &(this->parent_game->window);
	this->setCollisionBounds(&(parent_game->current_level->solid_tiles_rect));
	this->has_collisions = true;
};

};
