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
};

void Level::updateEnemyList(){
	for (int i=0; i<this->enemy_list.size(); i++){
		if (this->enemy_list[i]->is_dead){
			//dorp potion a third of the time
			if (std::rand()%3 == 0 && this->enemy_list[i]->drops_potions){
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

};
