#include "../Game.hpp"
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Dungeon {

void Game::initLevel(Level *level, sf::Vector2f playerPos){
	if (this->current_level != nullptr) delete this->current_level;
	this->current_level = level;
	this->deleteDeadEnemies(&level->enemy_list);
	this->player->setCollisionBounds(&(level->solid_tiles_rect));
	this->current_level->enemiesSetSolidTilesSprites();
	this->player->setEnemyList();
	this->player->setPosition(playerPos);
};

void Game::deleteDeadEnemies(std::vector<Enemy*> *enemy_list){

	for (int i=0; i<enemy_list->size(); i++){
		if (this->dead_enemies[enemy_list->at(i)->id]){
			enemy_list->at(i)->is_dead = true;
		}
	}	
};

};
