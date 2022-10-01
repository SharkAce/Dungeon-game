#ifndef LEVELS_H
#define LEVELS_H

#include "../Level/Level.hpp"
#include "../Enemy/Enemies/Enemies.hpp"

namespace Dungeon {

class Game;

struct World1 {
	static Level *level1(Game *game_ptr);
	static Level *level2(Game *game_ptr);
	static Level *level3(Game *game_ptr);
	static Level *level4(Game *game_ptr);
};

};

#endif
