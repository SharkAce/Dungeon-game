#include "../Game.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

void Game::initLevel(Level *level, sf::Vector2f playerPos){
	if (this->current_level != nullptr) delete this->current_level;
	this->current_level = level;
	this->player->setCollisionBounds(&(level->solid_tiles_rect));
	this->current_level->enemiesSetSolidTilesSprites();
	this->player->setEnemyList();
	this->player->setPosition(playerPos);
};

};
