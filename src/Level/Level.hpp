#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>
#include <cstdlib>
#include "../Enemy/Enemy.hpp"
#include "../Tile/Tile.hpp"
#include "../Consumable/Consumables.hpp"

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

		void parsePtltFile(std::string file_path);
		void renderBg();

		int tiles_x;
		int tiles_y;
		int tile_px;
		float sprite_scale;

		
		std::vector<Enemy*> enemy_list;
		std::vector<Consumable> consumable_list;
		std::vector<FinishRect> finish_rect_list;
		void updateEnemyList();
		void renderEnemyList();


		void updateConsumableList();
		void renderConsumableList();

		void enemiesSetSolidTilesSprites();
		void updateFinishRects();

		//std::vector<Game_obj> Game_obj_list;

};

struct FinishRect {
		FinishRect(char rect_type, std::function<Level *(Game*)> level_callback);
		FinishRect(sf::FloatRect rect, sf::Vector2<bool> axis, std::function<Level *(Game*)> level_callback);
		sf::FloatRect rect;
		sf::Vector2<bool> axis;
		std::function<Level *(Game*)> level_callback;
		bool check_player_collision(sf::FloatRect player_pos);

};

};

#endif
