#ifndef LEVELS_H
#define LEVELS_H

#include "../Level/Level.hpp"
#include "../Enemy/Enemies/Enemies.hpp"

namespace Dungeon {

	class Game;

	Level *testLevel(Game *game_ptr);
	Level *testLevel2(Game *game_ptr);
	Level *level1(Game *game_ptr);
	Level *level2(Game *game_ptr);
	Level *level3(Game *game_ptr);
	Level *level4(Game *game_ptr);

};

#endif
