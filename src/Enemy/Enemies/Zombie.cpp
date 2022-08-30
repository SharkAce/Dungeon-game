#include "Enemies.hpp"

namespace Dungeon {

Zombie::Zombie(Game* parent_game): Dungeon::Enemy(parent_game) {

	this->scale = 3.0;
	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 16;
	this->sprite_coord_y = 160;
	this->px_height = 16;
	this->px_width = 16;
	this->speed = 8.f;

	this->makeEntitySprite();

};

void Zombie::update(){
	return;
};

};
