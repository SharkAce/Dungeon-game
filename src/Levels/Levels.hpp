#ifndef LEVELS_H
#define LEVELS_H

#include "../Level/Level.hpp"
#include "../Enemy/Enemies/Enemies.hpp"

namespace Dungeon {

class Game;

struct World1 {
	static Level *level1B(Game *game_ptr);
	static Level *level1C(Game *game_ptr);
	static Level *level1D(Game *game_ptr);
	static Level *level2A(Game *game_ptr);
	static Level *level2B(Game *game_ptr);
	static Level *level2C(Game *game_ptr);
	static Level *level2D(Game *game_ptr);
	static Level *level3A(Game *game_ptr);
	static Level *level3B(Game *game_ptr);
	static Level *level3C(Game *game_ptr);
	static Level *level3D(Game *game_ptr);
	static Level *level4B(Game *game_ptr);
	static Level *level4C(Game *game_ptr);
	static Level *level5C(Game *game_ptr);
};

};

#endif
