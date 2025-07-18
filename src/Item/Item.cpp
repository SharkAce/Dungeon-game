#include "Item.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {
namespace Items {

Item::Item(
	Dungeon::Player *parent): 
		cooldown_sw(16.f, parent->parent_game, false), 
		attack_sw(11.f, parent->parent_game, false),
		Dungeon::Entity(parent->parent_game),
		sprite(parent->parent_game->sprite_sheet){

	this->window = parent->window;
	this->parent = parent;
	this->parent_game = parent->parent_game;
	this->scale = 3.f;
	this->damage = 34.f;
	this->make_sprite();
};

//this should be done by entity's makeEntitySprite method instead
void Item::make_sprite() {
	this->sprite.setTextureRect({{163, 32}, {10, 32}});
	this->sprite.setScale({this->scale, this->scale});
	this->sprite.setOrigin({8.f, 28.f});
};

};
};
