#include "Player.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {

Player::Player(Game *parent_game): Dungeon::Entity(parent_game) {

	this->scale = 3.0;
	this->max_hp = 100;
	this->current_hp = 100;
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
	this->sprite.setOrigin(float(this->px_width)/2,float(this->px_height)/1.5);
};


void Player::update() {
	this->handleEnemyCollision();
	this->setPlayerMouseAngle();
	this->weapon->update();
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
	this->player_mouse_angle = Game::RadToDeg(player_mouse_angle);
}; 
	
void Player::handleEnemyCollision(){
	for (int i=0; i<this->enemy_list->size(); i++){
		if (this->enemy_list->at(i)->sprite.getGlobalBounds()
		.intersects(this->sprite.getGlobalBounds())
		){
			sf::Vector2f enemy_pos = this->enemy_list->at(i)->sprite.getPosition();
			float angle = std::atan2(this->position.y - enemy_pos.y, this->position.x - enemy_pos.x);
			angle = angle*180/M_PI;
			this->startKnockback(angle,this->enemy_list->at(i)->kb_force);
			this->sprite.setColor(sf::Color::Red);
		}
	}
};

};
