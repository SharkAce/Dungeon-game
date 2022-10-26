#include "Enemies.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

BigFire::BigFire(Game* parent_game, sf::Vector2<float> start_position, int id): Dungeon::Enemy(parent_game, start_position, id) {

	this->scale = 3.0;
	this->max_hp = 60;
	this->current_hp = 60;
	this->damage = 20;
	this->sprite_coord_x = 32;
	this->sprite_coord_y = 192;
	this->px_height = 16;
	this->px_width = 16;
	this->speed = 2.5f;
	this->kb_force = 14.f;
	this->has_projectiles = false;

	this->child_cooldown = 20;
	this->child_cooldown_current = 0;
	this-> is_child_cooldown = false;

	this->makeEntitySprite();

};

void BigFire::update(){
	if (this->is_child_cooldown) {
		this->child_cooldown_current ++;
		if (this->child_cooldown_current >= this->child_cooldown){
			this->is_child_cooldown = false;
			child_cooldown_current = 0;
		}
	} else {
		this->parent_game->current_level->enemy_list.push_back(new SmallFire(this->parent_game, this->position, -1));
		this->is_child_cooldown = true;
	}

	sf::Vector2f position = this->sprite.getPosition();
	sf::Vector2f playerPos = this->parent_game->player->position;
	float angle = std::atan2(playerPos.y-position.y,playerPos.x-position.x);
	this->direction.x = speed*cos(angle);
	this->direction.y = speed*sin(angle);
	return;
};

SmallFire::SmallFire(Game* parent_game, sf::Vector2<float> start_position, int id): Dungeon::Enemy(parent_game, start_position, id) {

	this->scale = 3.0;
	this->max_hp = 30;
	this->current_hp = 30;
	this->damage = 20;
	this->sprite_coord_x = 33;
	this->sprite_coord_y = 208;
	this->px_height = 16;
	this->px_width = 14;
	this->speed = 8.f;
	this->kb_force = 11.f;
	this->has_projectiles = false;
	this->drops_potions = false;
	this->is_invincible = true;

	this->lifetime_max_frame = 160;
	this->lifetime_current_frame = 0;

	this->makeEntitySprite();

};

void SmallFire::update(){
	this->lifetime_current_frame ++;
	if (this->lifetime_current_frame >= this->lifetime_max_frame) this->is_dead = true;
};

};

