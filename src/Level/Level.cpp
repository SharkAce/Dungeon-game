#include "Level.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

namespace Dungeon {

Level::Level(Game *parent_game) {
	this->parent_game = parent_game;
	this->texture = &(parent_game->sprite_sheet);
	this->window = parent_game->window;
	this->tiles_x = 40;
	this->tiles_y = 23;
	this->tile_px = 16;
	this->sprite_scale = 3.f;
};

Level::~Level(){
	for (int i=0; i<this->enemy_list.size(); i++) delete this->enemy_list[i];
};


void Level::enemiesSetSolidTilesSprites(){
	for (int i=0; i<this->enemy_list.size(); i++){
		this->enemy_list[i]->setCollisionBounds(&(this->solid_tiles_rect));
	}
};

};
