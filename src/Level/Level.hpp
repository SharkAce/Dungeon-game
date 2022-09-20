#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "../Enemy/Enemy.hpp"
#include "../Tile/Tile.hpp"

namespace Dungeon {

class Game;

class Level {
	public:
		Level(Game *parent_game);
		virtual ~Level();
		std::vector<std::vector<int>> bg_tiles_ids;
		std::vector<Tile> bg_tiles;
		std::vector<Tile> fg_tiles;
		std::vector<sf::FloatRect> solid_tiles_rect;
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
		float sprite_scale;

		
		std::vector<Enemy*> enemy_list;
		void updateEnemyList();
		void renderEnemyList();
		void parsePtsfFile(std::string file_path);
		void enemiesSetSolidTilesSprites();

		//std::vector<Game_obj> Game_obj_list;

};

};

#endif
