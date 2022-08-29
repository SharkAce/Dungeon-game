#include "Player.hpp"

namespace Dungeon {

Player::Player(
	sf::Texture *texture,
	sf::RenderWindow *window
): Dungeon::Entity(texture, window) {

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
		this->texture,
		this->window,
		this
	);

	this->makeEntitySprite();
	
	this->sprite.setOrigin(this->px_width/2,this->px_height/1.5);
};


void Player::update() {
	this->weapon->update();
};
	
void Player::render() {
	this->weapon->render();
	this->window->draw(this->sprite);
};

};
