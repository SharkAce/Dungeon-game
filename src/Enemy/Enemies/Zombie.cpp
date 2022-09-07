#include "Enemies.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

Zombie::Zombie(Game* parent_game): Dungeon::Enemy(parent_game) {

	this->scale = 3.0;
	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 18;
	this->sprite_coord_y = 160;
	this->px_height = 16;
	this->px_width = 12;
	this->speed = 8.f;
	this->kb_force = 14.f;

	this->makeEntitySprite();

};

void Zombie::update(){
	sf::Vector2f position = this->sprite.getPosition();
	sf::Vector2f playerPos = this->parent_game->player->position;
	float angle = std::atan2(playerPos.y-position.y,playerPos.x-position.x);
	this->direction.x = 3*cos(angle);
	this->direction.y = 3*sin(angle);
	return;
};

};
