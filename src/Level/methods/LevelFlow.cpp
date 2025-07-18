#include "../Level.hpp"
#include "../../Game/Game.hpp"

#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {

void Level::renderBg() {
	for (int i = 0; i < (int)(bg_tiles.size()); i++){
		this->bg_tiles[i].render();
	}	

	for (int i = 0; i < (int)(fg_tiles.size()); i++){
		this->fg_tiles[i].render();
	}	
	
	if (gate_is_open) this->parent_game->window.draw(*this->door_sprite);
};

void Level::updateEnemyList(){
	for (int i=0; i<this->enemy_list.size(); i++){
		if (this->enemy_list[i]->is_dead){
			//dorp potion a third of the time
			if (std::rand()%4 == 0 && this->enemy_list[i]->drops_potions){
				this->consumable_list.push_back(Potion(this->parent_game, this->enemy_list[i]->position));
			}
			this->parent_game->dead_enemies[this->enemy_list[i]->id] = true;
			delete this->enemy_list[i];
			this->enemy_list.erase(this->enemy_list.begin()+i);
		}else{
			this->enemy_list[i]->Enemy::update();
			this->enemy_list[i]->Entity::update();
			this->enemy_list[i]->update();
		}
	}
};

void Level::updateConsumableList(){
	for (int i=0; i<this->consumable_list.size(); i++){
		Consumable& consumable = this->consumable_list[i];
		if (consumable.end_of_life){
			this->consumable_list.erase(this->consumable_list.begin()+i);
		}else{
			consumable.Entity::update();
		}
	}
}

void Level::renderEnemyList(){
	for (int i=0; i<this->enemy_list.size(); i++){
		this->enemy_list[i]->Entity::render();
		this->enemy_list[i]->render();
	}
};

void Level::renderConsumableList(){
	for (int i=0; i<this->consumable_list.size(); i++){
		this->consumable_list[i].Entity::render();
	}
};

void Level::renderKeyCount(){
	if (!this->gate_level || this->parent_game->player->key_count == -1) return;

	sf::Text& text = this->parent_game->default_text;
	text.setFont(this->parent_game->secondary_font);
	
	this->parent_game->writeToScreen(
			std::to_string(this->parent_game->player->key_count) + "|" + std::to_string(this->key_req),
			this->parent_game->window.getSize().x/2.0f,
			this->parent_game->window.getSize().y/6.0f,
			text
	);
};

void Level::updateDoor(){
	if (!this->gate_level || this->gate_is_open) return;

	if ((this->parent_game->player->key_count == this->key_req &&
			this->parent_game->player->sprite.getGlobalBounds().findIntersection(this->gate_area)) || 
			this->parent_game->player->key_count == -1
			){
		this->gate_is_open = true;
		this->parent_game->player->key_count = -1;
		//create Open Door Sprite
		sf::Sprite* sprite = new sf::Sprite(this->parent_game->sprite_sheet);
		sprite->setTextureRect({{160,112},{32,32}});
		sprite->setScale({3.f,3.f});
		sprite->setPosition({(float)this->door_position.x*48, (float)this->door_position.y*48});
		this->door_sprite = sprite;

		//add FinishRect
		this->finish_rect_list.push_back(*this->gate_finish_rect);

	}
}

void Level::updateFinishRects(){
	for (int i=0; i<this->finish_rect_list.size(); i++){
		FinishRect& finish_rect = this->finish_rect_list[i];
		if (finish_rect.check_player_collision(this->parent_game->player->sprite.getGlobalBounds())){
			this->parent_game->initLevel(
				finish_rect.level_callback(this->parent_game),
				this->parent_game->getMirroredVector2(this->parent_game->player->position, finish_rect.axis, true)
			);
			break;
		}
	}
};

void Level::renderLevel(){
	this->renderBg();
	this->renderConsumableList();
	this->renderEnemyList();
	this->renderKeyCount();
};

};
