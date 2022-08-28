#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

namespace Dungeon {

class Entity {
	public:
		Entity(sf::Texture *texture, sf::RenderWindow *window);
		void makeEntitySprite();

		virtual void update();
		virtual void render();

		sf::Sprite sprite;
		sf::Texture *texture;
		sf::RenderWindow *window;

		bool collisionCheck();
		void setSolidTilesSprites(std::vector<sf::Sprite> *sts);
		std::vector<sf::Sprite> *solid_tiles_sprites; // This should be a class, called Wall or Tile or something

		int max_hp;
		int current_hp;
		int damage;
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
