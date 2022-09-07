#include "./Enemy.hpp"
#include "../Game/Game.hpp"

#include <iostream>

namespace Dungeon {

Enemy::Enemy(Game *parent_game): Dungeon::Entity(parent_game) {
	this->is_hit = false;
};

void Enemy::hit(int angle, float force){
	this->startKnockback(angle, force);
	this->is_hit = true;
	this->sprite.setColor(sf::Color::Red);
};

};
