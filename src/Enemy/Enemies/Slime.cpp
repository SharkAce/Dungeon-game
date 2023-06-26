#include "Enemies.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

BigSlime::BigSlime(Game* parent_game, sf::Vector2<float> start_position, int id): 
	Dungeon::Enemy(parent_game, start_position, id),
	child_sw(80,parent_game,true){

	this->scale = 3.0;
	this->max_hp = 60;
	this->current_hp = 60;
	this->damage = 20;
	this->sprite_coord_x = 80;
	this->sprite_coord_y = 192;
	this->px_height = 16;
	this->px_width = 16;
	this->speed = 8.f;
	this->kb_force = 14.f;
	this->has_projectiles = false;

	this->child_sw.current_time = 60.f;

	this->makeEntitySprite();

};

void BigSlime::update(){
	if (this->is_hit) this->child_sw.current_time = 0.f;
	if (!this->child_sw.update()){
		this->parent_game->current_level->enemy_list.push_back(new SmallSlime(this->parent_game, this->position, -1));
	}
	return;
};

SmallSlime::SmallSlime(Game* parent_game, sf::Vector2<float> start_position, int id): Dungeon::Enemy(parent_game, start_position, id) {

	this->scale = 3.0;
	this->max_hp = 30;
	this->current_hp = 30;
	this->damage = 20;
	this->sprite_coord_x = 81;
	this->sprite_coord_y = 214;
	this->px_height = 12;
	this->px_width = 14;
	this->speed = 8.f;
	this->kb_force = 14.f;
	this->has_projectiles = false;
	this->drops_potions = false;

	this->makeEntitySprite();

};

void SmallSlime::update(){
	sf::Vector2f position = this->sprite.getPosition();
	sf::Vector2f playerPos = this->parent_game->player->position;
	float angle = std::atan2(playerPos.y-position.y,playerPos.x-position.x);
	this->direction.x = 3*cos(angle);
	this->direction.y = 3*sin(angle);
	return;
};

};
