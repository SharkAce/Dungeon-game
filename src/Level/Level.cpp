#include "Level.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>


#include <iostream>
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
	for (int i=0; i<this->enemy_list.size(); i++) {
		if (this->enemy_list[i]->has_projectiles) {
			for (int j=0; j<this->enemy_list[i]->projectiles.size(); j++){
				delete this->enemy_list[i]->projectiles[j];
			}
		}
		delete this->enemy_list[i];
	}
};


void Level::enemiesSetSolidTilesSprites(){
	for (int i=0; i<this->enemy_list.size(); i++){
		this->enemy_list[i]->setCollisionBounds(&(this->solid_tiles_rect));
	}
};

FinishRect::FinishRect(char rect_type, std::function<Level *(Game*)> level_callback){
	//tile_px * scale * tiles_x/y
	float width  = 16*3*40;
	float height = 16*3*23;

	switch (rect_type) {
		case 't':{
							 this->rect = sf::FloatRect(0,0,width,1);
							 this->axis = sf::Vector2<bool>(false,true);
							 break;
						 }
		case 'b':{
							 this->rect = sf::FloatRect(0,height,width,1);
							 this->axis = sf::Vector2<bool>(false,true);
							 break;
						 }
		case 'l':{
							 this->rect = sf::FloatRect(0,0,1,height);
							 this->axis = sf::Vector2<bool>(true,false);
							 break;
						 }
		case 'r':{
							 this->rect = sf::FloatRect(width,0,1,height);
							 this->axis = sf::Vector2<bool>(true,false);
							 break;
						 }
	}
	
	this->level_callback = level_callback;
};
FinishRect::FinishRect(sf::FloatRect rect, sf::Vector2<bool> axis, std::function<Level *(Game*)> level_callback){
	this->rect = rect;
	this->axis = axis;
	this->level_callback = level_callback;
}

bool FinishRect::check_player_collision(sf::FloatRect player_pos){
	return player_pos.intersects(this->rect);
};

};
