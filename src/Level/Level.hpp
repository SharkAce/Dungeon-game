#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>
#include "../Enemy/Enemy.hpp"
#include "../Tile/Tile.hpp"

namespace Dungeon {

class Game;
class FinishRect;

class Level {
	public:
		Level(Game *parent_game);
		virtual ~Level();
		std::vector<Tile> bg_tiles;
		std::vector<Tile> fg_tiles;
		std::vector<sf::FloatRect> solid_tiles_rect;
		sf::Texture *texture;
		sf::RenderWindow *window;
		Game *parent_game;

		void parsePtsfFile(std::string file_path);
		void renderBg();

		int tiles_x;
		int tiles_y;
		int tile_px;
		float sprite_scale;

		
		std::vector<Enemy*> enemy_list;
		std::vector<FinishRect> finish_rect_list;
		void updateEnemyList();
		void renderEnemyList();
		void enemiesSetSolidTilesSprites();
		void updateFinishRects();

		//std::vector<Game_obj> Game_obj_list;

};

class FinishRect {
	public:
		FinishRect(sf::FloatRect rect, std::function<Level *(Game*)> level_callback);
		sf::FloatRect rect;
		std::function<Level *(Game*)> level_callback;
		bool check_player_collision(sf::FloatRect player_pos);

};

};

#endif
