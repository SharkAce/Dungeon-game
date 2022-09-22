#include "Enemies.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <iostream>
#include "../../Game/Game.hpp"

namespace Dungeon {

Sorcerer::Sorcerer(Game* parent_game): Dungeon::Enemy(parent_game) {

	this->scale = 3.0;
	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 81;
	this->sprite_coord_y = 144;
	this->px_height = 16;
	this->px_width = 15;
	this->speed = 8.f;
	this->kb_force = 15.f;
	this->projectile_cooldown = 60;
	this->projectile_cooldown_current = 0;
	this->projectile_max_count = 10;
	this->is_projectile_cooldown = false;
	this->has_projectiles = true;

	this->makeEntitySprite();

};

void Sorcerer::update(){
	if (this->is_projectile_cooldown){
		this->projectile_cooldown_current ++;
		if (this->projectile_cooldown_current >= this->projectile_cooldown){
			this->is_projectile_cooldown = false;
			this->projectile_cooldown_current = 0;
		}
	}


	if (!(this->is_projectile_cooldown) && this->projectiles.size() <= this->projectile_max_count){
		sf::Rect<int>	sprite_rect;
		sprite_rect.top = 52;
		sprite_rect.left = 20;
		sprite_rect.width = 8;
		sprite_rect.height = 9;

		float enemy_player_angle = Game::radToDeg(atan2(
					this->parent_game->player->position.y - this->position.y, 
					(this->parent_game->player->position.x - this->position.x) *-1
		))-90;
		
		projectiles.push_back(new Projectile(
				this->parent_game,
				this->collision_bounds,
				sprite_rect,
				this->position,
				enemy_player_angle,
				12
		));

		this->is_projectile_cooldown = true;
		this->projectile_cooldown_current = 0;

	}

	return;
}

};
