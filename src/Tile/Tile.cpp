#include "Tile.hpp"
#include "../Game/Game.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

Tile::Tile(Game *parent_game, int tile_id, int rotation, float scale, sf::Vector2i position):
		sprite(parent_game->sprite_sheet) {

	this->parent_game = parent_game;

	float sprite_size = (float) parent_game->sprite_size;
	int sprites_per_line = 
		this->parent_game->sprite_sheet.getSize().x / sprite_size;

	this->sprite.setTextureRect({
		{(tile_id % sprites_per_line) * this->parent_game->sprite_size,
		(tile_id / sprites_per_line) * this->parent_game->sprite_size},
		{this->parent_game->sprite_size,
		this->parent_game->sprite_size}
	});

	//change rotation
	this->sprite.setOrigin({sprite_size/2,sprite_size/2});
	this->sprite.rotate(sf::degrees(rotation*90.f));


	sprite.setScale({scale,scale});

	this->sprite.setPosition({
		position.x * (sprite_size*scale) + ((sprite_size*scale)/2), 
		position.y * (sprite_size*scale) + ((sprite_size*scale)/2)
	});
};

void Tile::render(){
	this->parent_game->window.draw(this->sprite);
};

};
