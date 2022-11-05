#include "./Enemy.hpp"
#include "../Game/Game.hpp"

#include <SFML/System/Vector2.hpp>
#include <iostream>

namespace Dungeon {

Enemy::Enemy(Game *parent_game, sf::Vector2<float> start_position, int id): Dungeon::Entity(parent_game) {
	this->setPosition(start_position);
	this->is_hit = false;
	this->is_dead = false;
	this->drops_potions = true;
	this->is_invincible = false;
	this->id = id;

	std::map<int,bool> *dead_enemies = &(this->parent_game->dead_enemies);

	if (dead_enemies->find(id) == dead_enemies->end()){
		dead_enemies->insert({id,false});
	}
};

void Enemy::hit(int angle, float force, float damage){
	if (this->is_invincible) return;
	if (this->kb_last_frame == 0) this->current_hp -= damage;
	this->startKnockback(angle, force);
	this->is_hit = true;
	this->sprite.setColor(sf::Color::Red);
};

void Enemy::update(){
	if (this->current_hp <= 0) this->is_dead = true;

	if (this->has_projectiles){
		for (int i=0; i<this->projectiles.size(); i++){
			if (this->projectiles[i]->end_of_life) {
				delete projectiles[i];
				projectiles.erase(projectiles.begin()+i);
			} else {
				projectiles[i]->update();
			}
		}
	}
};

void Enemy::render(){
	if (!(this->has_projectiles)) return;

	for (int i=0; i<this->projectiles.size(); i++){
		this->projectiles[i]->render();
	}
};

};
