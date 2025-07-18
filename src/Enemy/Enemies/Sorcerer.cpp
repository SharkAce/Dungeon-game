#include "Enemies.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "../../Game/Game.hpp"

namespace Dungeon {

Sorcerer::Sorcerer(Game* parent_game, sf::Vector2<float> start_position, int id): 
	Dungeon::Enemy(parent_game, start_position, id),
	projectile_sw(60.f, parent_game, true){

	this->scale = 3.0;
	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 81;
	this->sprite_coord_y = 144;
	this->px_height = 16;
	this->px_width = 15;
	this->speed = 480.f;
	this->kb_force = 15.f;
	this->has_projectiles = true;

	this->makeEntitySprite();

};

void Sorcerer::update(){
	if (this->is_hit) this->projectile_sw.current_time = 0.f;
	if (!this->projectile_sw.update()){
		sf::Rect<int>	sprite_rect;
		sprite_rect.position.x = 34;
		sprite_rect.position.y = 245;
		sprite_rect.size.x = 12;
		sprite_rect.size.y = 10;

		float enemy_player_angle = Game::radToDeg(atan2(
					this->parent_game->player->position.y - this->position.y, 
					(this->parent_game->player->position.x - this->position.x) *-1
		))-90;
		
		this->projectiles.push_back(new Projectile(
				this->parent_game,
				this->collision_bounds,
				sprite_rect,
				0,
				this->position,
				enemy_player_angle,
				12
		));
	}

	return;
}

};
