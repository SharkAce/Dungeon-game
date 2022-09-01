#include "Enemies.hpp"

namespace Dungeon {

Sorcerer::Sorcerer(Game* parent_game): Dungeon::Enemy(parent_game) {

	this->scale = 3.0;
	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 16;
	this->sprite_coord_y = 176;
	this->px_height = 16;
	this->px_width = 16;
	this->speed = 8.f;
	this->kb_force = 15.f;

	this->makeEntitySprite();

};

void Sorcerer::update(){
	return;
}

};
