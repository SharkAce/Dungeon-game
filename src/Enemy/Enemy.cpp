#include "./Enemy.hpp"
#include "../Game/Game.hpp"

#include <iostream>

namespace Dungeon {

Enemy::Enemy(Game *parent_game): Dungeon::Entity(parent_game) {
	this->is_hit = false;
	this->is_dead = false;
};

void Enemy::hit(int angle, float force, float damage){
	if (this->kb_last_frame == 0) this->current_hp -= damage;
	this->startKnockback(angle, force);
	this->is_hit = true;
	this->sprite.setColor(sf::Color::Red);
};

void Enemy::update(){
	if (this->current_hp <= 0) this->is_dead = true;
};

};
