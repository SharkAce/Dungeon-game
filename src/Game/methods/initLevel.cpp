#include "../Game.hpp"

namespace Dungeon {

void Game::initLevel(Level* level) {
	this->current_level = level;
	this->current_level->createBg();
	std::vector<sf::Sprite>* ptr_sts = &(this->current_level->solid_tiles_sprites);
	this->player->setSolidTilesSprites(ptr_sts);
};

};
