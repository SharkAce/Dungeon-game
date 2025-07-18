#include "Enemies.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "../../Game/Game.hpp"

namespace Dungeon {

Skeleton::Skeleton(Game* parent_game, sf::Vector2<float> start_position, int id): 
	Dungeon::Enemy(parent_game, start_position, id), 
	projectile_sw(60.f,parent_game,true){

	this->scale = 3.0;
	this->max_hp = 60;
	this->current_hp = 60;
	this->damage = 20;
	this->sprite_coord_x = 18;
	this->sprite_coord_y = 144;
	this->px_height = 16;
	this->px_width = 15;
	this->speed = 8.f;
	this->kb_force = 15.f;
	this->has_projectiles = true;

	this->makeEntitySprite();

};

void Skeleton::update(){
	if (!this->projectile_sw.update()){
		sf::Rect<int>	sprite_rect;
		sprite_rect.position.x = 65;
		sprite_rect.position.y = 243;
		sprite_rect.size.x = 13;
		sprite_rect.size.y = 12;

		float enemy_player_angle = Game::radToDeg(atan2(
					this->parent_game->player->position.y - this->position.y, 
					(this->parent_game->player->position.x - this->position.x) *-1
		))-90;
		
		projectiles.push_back(new Projectile(
				this->parent_game,
				this->collision_bounds,
				sprite_rect,
				45,
				this->position,
				enemy_player_angle,
				10
		));

	}

	return;
}

};
