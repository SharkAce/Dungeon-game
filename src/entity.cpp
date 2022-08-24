#include "entity.h"

Base_entity::Base_entity(sf::Texture texture, sf::RenderWindow* window){
	this->texture = texture;
	this->window = window;
	this->direction.x = 0.f;
	this->direction.y = 0.f;
}

void Base_entity::render(){
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(
		sprite_coord_x,
		sprite_coord_y,
		px_width,
		px_height
	));
	this->window->draw(this->sprite);
}

void Base_entity::update(){
	this->sprite.move(this->direction);
}

Player::Player(sf::Texture texture, sf::RenderWindow* window): 
		Base_entity(texture, window){
	
	this->sprite.setScale(4.0, 4.0);

	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 224;
	this->sprite_coord_y = 224;
	this->px_height = 32;
	this->px_width = 16;
	this->speed = 10.f;
}
