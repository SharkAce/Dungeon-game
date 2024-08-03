#include "Enemies.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

BossZombie::BossZombie(Game* parent_game, sf::Vector2<float> start_position, int id): 
	Dungeon::Enemy(parent_game, start_position, id),
	projectile_sw(30.f, parent_game, true),
	dash_charge_sw(80.f, parent_game, false){

	this->scale = 3.0;
	this->max_hp = 600;
	this->current_hp = 600;
	this->sprite_coord_x = 102;
	this->sprite_coord_y = 182;
	this->px_height = 26;
	this->px_width = 20;
	this->speed = 5.f;
	this->dash_speed = 14.f;
	this->kb_force = 14.f;
	this->has_projectiles = true;
	this->has_healthbar = true;

	this->destination_pt = sf::FloatRect(700,640,5,5);
	this-> is_in_dash = false;
	this->movement_count = 0;
	this->max_movement_count = 6;

	this->dash_count = 0;
	this->max_dash_count = 3;

	this->makeEntitySprite();
};

void BossZombie::update(){
	sf::Vector2<float> position = this->sprite.getPosition();
	if (this->current_hp <= 0) this->parent_game->activateWinState();

	if (!this->is_in_dash){

		if (!this->projectile_sw.update()){
			sf::Rect<int>	sprite_rect;
			sprite_rect.top = 98;
			sprite_rect.left = 152;
			sprite_rect.width = 6;
			sprite_rect.height = 13;

			float enemy_player_angle = Game::radToDeg(atan2(
						this->parent_game->player->position.y - this->position.y, 
						(this->parent_game->player->position.x - this->position.x) *-1
			))-90;
			
			this->projectiles.push_back(new Projectile(
					this->parent_game,
					this->collision_bounds,
					sprite_rect,
					90,	
					this->position,
					enemy_player_angle,
					10	
			));
			this->projectiles[projectiles.size()-1]->sprite.scale(1.3,1.3);

		}
	
		if (this->sprite.getGlobalBounds().intersects(this->destination_pt)){

			sf::Vector2<int> new_destination = sf::Vector2<int>(std::rand()%480 + 480,std::rand()%288 + 240);
			
			int current_quad = 0;
			if (position.x > 960) current_quad +=1;
			if (position.y > 588) current_quad +=2;
			
			int destination_quad = std::rand() % 3;
			if (destination_quad >= current_quad) destination_quad +=1;

			if (destination_quad == 1) new_destination.x += 480;
			else if (destination_quad == 2) new_destination.y += 240;
			else if (destination_quad == 3) {new_destination.x += 480; new_destination.y += 240;}

			this->destination_pt.left = new_destination.x;
			this->destination_pt.top = new_destination.y;
			
			this->movement_count ++;
			if (this->movement_count >= this->max_movement_count){
				this->is_in_dash = true;
				this->dash_charge_sw.is_stop = false;
				this->movement_count = 0;
			}

			
		} else {
			float angle = std::atan2(this->destination_pt.top-position.y,this->destination_pt.left-position.x);
			this->direction.x = this->speed*cos(angle);
			this->direction.y = this->speed*sin(angle);
		}
	}

	// is_in_dash:
	else {
		if (!this->dash_charge_sw.is_stop){
			if (this->dash_charge_sw.update()){
				this->direction.x += ((float)((int)(this->dash_charge_sw.current_time/3.f) % 2)-0.5)*4.f;
			} else {
				this->dash_angle = Game::radToDeg(atan2(
					this->parent_game->player->position.y - this->position.y, 
					(this->parent_game->player->position.x - this->position.x) *-1
				))-90;
			}
		} else {

			this->direction.x = this->dash_speed * (sin(Game::degToRad(this->dash_angle)));	
			this->direction.y = this->dash_speed * (cos(Game::degToRad(this->dash_angle)));
			sf::Vector2<bool> collisions = this->wallCollisionCheck();

			if (collisions.x || collisions.y){
				this->dash_count++;
				if (this->dash_count > this->max_dash_count){
					this->is_in_dash = false;
					this->dash_count = 0;
				} else {
					this->dash_charge_sw.is_stop = false;
				}
			}
		}
		



	}
	
};

};

