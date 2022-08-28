#include "Item.hpp"
#include "../Player/Player.hpp"

namespace Dungeon {
namespace Items {

Item::Item(
	sf::Texture *sprite_sheet,
	sf::RenderWindow *window,
	Dungeon::Player *parent
) {
	this->window = window;
	this->sheet = sprite_sheet;
	this->parent = parent;
	this->scale = 3.f;
	this->make_sprite();
};

void Item::make_sprite() {
	this->sprite.setTexture(*(this->sheet));
	this->sprite.setTextureRect(sf::IntRect(160, 32, 16, 32));
	this->sprite.setScale(this->scale, this->scale);
	this->sprite.setOrigin(8.f, 32.f);
};

void Item::render() {
	this->window->draw(this->sprite);
};

void Item::update() {

	sf::Vector2f playerPos = this->parent->position;
	playerPos.y -= 10;
	this->sprite.setPosition(playerPos);

	sf::Vector2i mousePos = sf::Mouse::getPosition(*(this->parent->window));
	float player_mouse_angle = 
	std::atan2(playerPos.y - mousePos.y, playerPos.x - mousePos.x)*180/M_PI-90;
  
	float x_offset = 30 * std::sin(player_mouse_angle/180*M_PI);
	float y_offset = 30 * std::cos(player_mouse_angle/180*M_PI)*-1;

	this->sprite.move(x_offset,y_offset);
	this->sprite.setRotation(player_mouse_angle);
};

};
};
