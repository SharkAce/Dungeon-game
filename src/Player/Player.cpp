#include "Player.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {

Player::Player(Game *parent_game): Dungeon::Entity(parent_game) {

	this->scale = 3.0;
	this->max_hp = 3;
	this->current_hp = 3;
	this->key_count = 0;
	this->damage = 20;
	this->sprite_coord_x = 224;
	this->sprite_coord_y = 236;
	this->px_height = 20;
	this->px_width = 16;
	this->speed = 7.f;

	this->weapon = new Dungeon::Items::Item(
		this
	);

	this->makeEntitySprite();
	this->sprite.setOrigin({float(this->px_width/2),float(this->px_height/1.5)});
};


void Player::update() {

	if (this->direction.x < 0){
		this->sprite.setScale({this->scale*-1,this->scale});
	} else if (this->direction.x > 0){
		this->sprite.setScale({this->scale,this->scale});
	};
	this->handleEnemyCollision();
	this->handleConsumableCollision();
	this->setPlayerMouseAngle();
	this->weapon->update();
	if (this->current_hp <= 0) this->parent_game->game_over = true;
};
	
void Player::render() {
	this->weapon->render();
	this->window->draw(this->sprite);
};

void Player::setEnemyList(){
	this->enemy_list = &(this->parent_game->current_level->enemy_list);
};

void Player::setPlayerMouseAngle(){
	float player_mouse_angle = std::atan2(
			this->position.y - this->parent_game->mouse_pos.y,
			this->position.x - this->parent_game->mouse_pos.x
	);
	this->player_mouse_angle = Game::radToDeg(player_mouse_angle);
}; 

void Player::hit(int angle, float force){
			if (this->kb_stopwatch.is_stop) this->current_hp -= 1;
			this->startKnockback(angle,force);
			this->sprite.setColor(sf::Color::Red);
			this->parent_game->startSfx("Hit2");
}

void Player::handleConsumableCollision(){
	for (int i=0; i<this->parent_game->current_level->consumable_list.size(); i++){
		Consumable& consumable = this->parent_game->current_level->consumable_list[i];

		if (consumable.sprite.getGlobalBounds().findIntersection(this->sprite.getGlobalBounds())) { 
			if (consumable.name == "potion" && this-> current_hp < this->max_hp){
				this->current_hp ++;
				consumable.end_of_life = true;
				this->parent_game->startSfx("PotionPickup");
			} else if (consumable.name == "key"){
				this->key_count ++;
				consumable.end_of_life = true;
				this->parent_game->taken_keys[consumable.id] = true;
				this->parent_game->startSfx("KeyPickup");
			}
		}
	}
};
	
void Player::handleEnemyCollision(){
	for (int i=0; i<this->enemy_list->size(); i++){
		Enemy& enemy = *enemy_list->at(i);
		if (enemy.sprite.getGlobalBounds()
		.findIntersection(this->sprite.getGlobalBounds())
		){

			sf::Vector2f enemy_pos = enemy.sprite.getPosition();
			float angle = Game::radToDeg(std::atan2(this->position.y - enemy_pos.y, this->position.x - enemy_pos.x));
			this->hit(angle,enemy.kb_force);

		}

		if (enemy.has_projectiles){
			for (int j=0; j<enemy.projectiles.size(); j++){
				Projectile& projectile = *enemy.projectiles.at(j);
				if (projectile.sprite.getGlobalBounds()
				.findIntersection(this->sprite.getGlobalBounds())
				){

					sf::Vector2f ptile_pos = projectile.sprite.getPosition();
					float ptile_angle = Game::radToDeg(std::atan2(this->position.y - ptile_pos.y, this->position.x - ptile_pos.x));
					projectile.end_of_life = true;
					this->hit(ptile_angle,enemy.kb_force);
				}
			}
		}
	}
};

};
