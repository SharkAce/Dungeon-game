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
	this->frame_per_attack = 11;
	this->attack_frame = 0;
	this->is_attacking = false;
	this->make_sprite();
};

//this should be done by entity's makeEntitySprite method instead
void Item::make_sprite() {
	this->sprite.setTexture(*(this->sheet));
	this->sprite.setTextureRect(sf::IntRect(163, 32, 10, 32));
	this->sprite.setScale(this->scale, this->scale);
	this->sprite.setOrigin(8.f, 28.f);
};

};
};
