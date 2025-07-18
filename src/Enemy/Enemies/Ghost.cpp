#include "Enemies.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

Ghost::Ghost(Game* parent_game, sf::Vector2<float> start_position, int id): Dungeon::Enemy(parent_game, start_position, id) {

	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 50;
	this->sprite_coord_y = 208;
	this->px_height = 16;
	this->px_width = 14;
	this->speed = 8.f;
	this->kb_force = 14.f;
	this->has_projectiles = false;
	this->has_collisions = false;

	this->makeEntitySprite();

	this->sprite.setScale({4.0,4.0});
};

void Ghost::update(){
	sf::Vector2f position = this->sprite.getPosition();
	sf::Vector2f playerPos = this->parent_game->player->position;
	float angle = std::atan2(playerPos.y-position.y,playerPos.x-position.x);
	this->direction.x = 3*cos(angle);
	this->direction.y = 3*sin(angle);
	return;
};

};
