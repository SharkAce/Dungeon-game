#include "./Enemy.hpp"
#include "../Game/Game.hpp"

#include <iostream>

namespace Dungeon {

Enemy::Enemy(Game *parent_game): Dungeon::Entity(parent_game) {
	this->is_hit = false;
	this->is_dead = false;
};

void Enemy::hit(int angle, float force, float damage){
	this->startKnockback(angle, force);
	this->is_hit = true;
	this->sprite.setColor(sf::Color::Red);
	this->current_hp -= damage;
};

void Enemy::update(){
	if (this->current_hp <= 0) this->is_dead = true;
};

};
