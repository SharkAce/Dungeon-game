#include "Entity.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {

Entity::Entity(Game *parent_game){
	this->parent_game = parent_game;
	this->direction.x = 0.f;
	this->direction.y = 0.f;
	this->texture = &(this->parent_game->sprite_sheet);
	this->window = this->parent_game->window;
	this->kb_last_frame = 0;
	this->kb_current_frame = 0;
	this->setCollisionBounds(&(parent_game->current_level->solid_tiles_rect));
	this->has_collisions = true;
};

};
