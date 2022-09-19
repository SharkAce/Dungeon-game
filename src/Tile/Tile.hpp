#ifndef TILE_H
#define TILE_H

#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

namespace Dungeon {

class Game;

class Tile{
	private:
		Game *parent_game;
	public:
		Tile(Game *parent_game, int tile_id, int rotation, float scale, sf::Vector2i position);

		void render();
		
		sf::Sprite sprite;
};

};

#endif
