#include "../Level.hpp"

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
			this->enemy_list.erase(this->enemy_list.begin()+i);
		}else{
			this->enemy_list[i]->update();
			this->enemy_list[i]->Enemy::update();
			this->enemy_list[i]->Entity::update();
		}
	}
};

void Level::renderEnemyList(){
	for (int i=0; i<this->enemy_list.size(); i++){
		this->enemy_list[i]->render();
	}
};

};
