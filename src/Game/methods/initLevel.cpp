#include "../Game.hpp"

namespace Dungeon {

void Game::initLevel(Level *level) {
	this->current_level = level;
	this->player->setSolidTilesSprites(&(level->solid_tiles_sprites));
	this->current_level->enemiesSetSolidTilesSprites();
	this->player->setEnemyList();
};

};
