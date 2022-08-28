#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace Dungeon {

class Level {
	public:
		Level(sf::Texture* texture, sf::RenderWindow* window);
		// (60/34 tiles)
		std::vector<std::vector<int>> bg_tiles_ids;
		std::vector<sf::Sprite> bg_tiles_sprites;
		std::vector<sf::Sprite> solid_tiles_sprites;
		sf::Texture* texture;
		sf::RenderWindow* window;

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

		
		//std::vector<Entity> enemy_list;
		//std::vector<Game_obj> Game_obj_list;

};

};

#endif