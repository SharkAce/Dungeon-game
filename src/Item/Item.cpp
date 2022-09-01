#include "Item.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {
namespace Items {

Item::Item(
	Dungeon::Player *parent
) : Dungeon::Entity(parent->parent_game){
	this->window = parent->window;
	this->sheet = parent->texture;
	this->parent = parent;
	this->parent_game = parent->parent_game;
	this->scale = 3.f;
	this->is_attacking = false;
	this->make_sprite();
};

void Item::make_sprite() {
	this->sprite.setTexture(*(this->sheet));
	this->sprite.setTextureRect(sf::IntRect(160, 32, 16, 32));
	this->sprite.setScale(this->scale, this->scale);
	this->sprite.setOrigin(8.f, 28.f);
};

void Item::render() {
	this->window->draw(this->sprite);
};

void Item::update() {

	this->updateCooldown();
	this->position = this->sprite.getPosition();

	sf::Vector2f playerPos = this->parent->position;
	playerPos.y -= 10;
	this->sprite.setPosition(playerPos);

	sf::Vector2i mousePos = sf::Mouse::getPosition(*(this->parent->window));
	float player_mouse_angle = 
	std::atan2(playerPos.y - mousePos.y, playerPos.x - mousePos.x)*180/M_PI-90;

	if (this->is_attacking)
		player_mouse_angle += attack_frame*8;
  
	float x_offset = 40 * std::sin(player_mouse_angle/180*M_PI);
	float y_offset = 40 * std::cos(player_mouse_angle/180*M_PI)*-1;

	this->sprite.move(x_offset,y_offset);
	

	if (!(this->is_attacking)){
		this->angle = player_mouse_angle-120;
		this->sprite.setRotation(this->angle);
	}
	else {
		this->sprite.setRotation(this->angle+(this->attack_frame*15));	
		this->handleEnemyCollision();

		// Number of frame per attack
		if (this->attack_frame >= 11) {
			this->is_attacking = false;
		}
		this->attack_frame++;
	}
};

void Item::initAttack(){
	this->is_attacking = true;
	this->attack_frame = 0;
	this->charge = 0;
	this->initAttackCooldown();
};

void Item::initAttackCooldown(){
	this->can_attack = false;
	this->cooldown_frame = 0;
}

void Item::updateCooldown(){
	if (this->can_attack == true) return;
	
	this->cooldown_frame ++;

	if (this->cooldown_frame >= 40) {
		this->can_attack = true;
		for (int i=0; i<this->parent_game->current_level->enemy_list.size(); i++){
			this->parent_game->current_level->enemy_list[i]->is_hit = false;
		}
	}
};

void Item::handleEnemyCollision(){
	for (int i=0; i<this->parent_game->current_level->enemy_list.size(); i++){
		Enemy *enemy = this->parent_game->current_level->enemy_list[i];
		sf::Vector2f enemy_pos = enemy->sprite.getPosition();
		if (!(enemy->is_hit)){
			if (enemy->sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds())){
				
				int attack_degree = std::atan2(this->position.y - enemy_pos.y, this->position.x - enemy_pos.x)*180/M_PI;
				enemy->hit(attack_degree-180,12);
			}
		}
	}	
};


};
};
