#include "Tile.hpp"
#include "../Game/Game.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

Tile::Tile(Game *parent_game, int tile_id, int rotation, float scale, sf::Vector2i position){
	this->parent_game = parent_game;

	this->sprite = sf::Sprite();
	this->sprite.setTexture(parent_game->sprite_sheet);

	float sprite_size = (float) parent_game->sprite_size;
	int sprites_per_line = 
		this->parent_game->sprite_sheet.getSize().x / sprite_size;

	this->sprite.setTextureRect(sf::IntRect(
		(tile_id % sprites_per_line) * this->parent_game->sprite_size,
		(tile_id / sprites_per_line) * this->parent_game->sprite_size,
		this->parent_game->sprite_size,
		this->parent_game->sprite_size
	));

	//change rotation
	this->sprite.setOrigin(sprite_size/2,sprite_size/2);
	this->sprite.rotate(rotation*90.f);


	sprite.setScale(scale,scale);


	//setPosition
	//this->sprite.setOrigin(0,0);
	this->sprite.setPosition(
		position.x * (sprite_size*scale) + ((sprite_size*scale)/2), 
		position.y * (sprite_size*scale) + ((sprite_size*scale)/2)
	);
};

void Tile::render(){
	this->parent_game->window->draw(this->sprite);
};

};
