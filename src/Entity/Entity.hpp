#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
//#include "../Game/Game.hpp"

namespace Dungeon {

class Game;

class Entity {
	private:
		Game* parent_game;

	public:
		Entity(Game* parent_game);
		void makeEntitySprite();

		virtual void update();
		virtual void render();

		sf::Sprite sprite;
		sf::Texture *texture;
		sf::RenderWindow *window;

		bool collisionCheck();
		void setSolidTilesSprites(std::vector<sf::Sprite> *sts);
		std::vector<sf::Sprite> *solid_tiles_sprites; // This should be a class, called Wall or Tile or something

		void setPosition(float x, float y);

		int sprite_coord_x;
		int sprite_coord_y;
		int px_height;
		int px_width;
		float scale;
		float speed;
		sf::Vector2f direction;
		sf::Vector2f position;
};

};

#endif
