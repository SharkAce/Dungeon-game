#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Enemy/Enemy.hpp"

namespace Dungeon {

class Game;

class Level {
	public:
		Level(Game *parent_game);
		std::vector<std::vector<int>> bg_tiles_ids;
		std::vector<sf::Sprite> bg_tiles_sprites;
		std::vector<sf::Sprite> solid_tiles_sprites;
		sf::Texture *texture;
		sf::RenderWindow *window;
		Game *parent_game;

		void setTileSprite(int x, int y);

		void setTileId(
			int tile_id,
			int x,
			int y
		);

		void setTileIdMulti(
			int tile_id,
			int x1,
			int x2,
			int y1,
			int y2
		);

		void renderBg();
		void createBg();

		int tiles_x;
		int tiles_y;
		int tile_px;

		
		std::vector<Enemy*> enemy_list;
		void updateEnemyList();
		void renderEnemyList();

		void enemiesSetSolidTilesSprites();

		//std::vector<Game_obj> Game_obj_list;

};

};

#endif
