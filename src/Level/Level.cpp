#include "Level.hpp"

namespace Dungeon {

Level::Level(sf::Texture* texture, sf::RenderWindow* window) {
	this->texture = texture;
	this->window = window;
	this->tiles_x = 40;
	this->tiles_y = 23;
	this->tile_px = 16;
	this->bg_tiles_ids.resize(
		this->tiles_x, 
		std::vector<int>(this->tiles_y,-1)
	);
};

void Level::setTileId(int tile_id, int x, int y) {
	this->bg_tiles_ids[x][y] = tile_id;
};

void Level::setTileIdMulti(
	int tile_id,
	int x1,
	int x2,
	int y1,
	int y2
) {
	for (int i = x1; i < x2; i++){
		for (int j = y1; j < y2; j++){
			this->setTileId(tile_id, i, j);
		}
	}
};

void Level::setTileSprite(int x, int y) {
	int tile_id = this->bg_tiles_ids[x][y];
	if (tile_id == -1) return;
	sf::Sprite sprite;
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(
		(tile_id % 16) * this->tile_px,
		(tile_id / 16) * this->tile_px,
		this->tile_px,
		this->tile_px
	));
	sprite.setScale(3.0,3.0);
	sprite.setPosition(x*48,y*48);
	this->bg_tiles_sprites.push_back(sprite);
		
	if (tile_id == 17) {
		this->solid_tiles_sprites.push_back(sprite);
	}
};

// (60/34 tiles)
void Level::createBg() {
	for (int i=0; i<this->tiles_x; i++){
		for (int j=0; j<this->tiles_y; j++){
			this->setTileSprite(i,j);
		}
	}
};

void Level::renderBg() {
	for (int i = 0; i < (int)(bg_tiles_sprites.size()); i++){
		this->window->draw(bg_tiles_sprites[i]);
	}	
};

};
