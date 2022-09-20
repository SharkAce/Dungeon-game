#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <math.h>

namespace Dungeon {

class Game;

class Entity {
	private:

	public:
		Entity(Game *parent_game);
		void makeEntitySprite();

		virtual void update();
		virtual void render();

		sf::Sprite sprite;
		sf::Texture *texture;
		sf::RenderWindow *window;
		Game* parent_game;

		bool wallCollisionCheck();
		void setCollisionBounds(std::vector<sf::FloatRect> *sts);
		std::vector<sf::FloatRect> *collision_bounds; // This should be a class, called Wall or Tile or something

		void setPosition(float x, float y);
		void applyKnockback();
		void startKnockback(int angle, float force);


		int sprite_coord_x;
		int sprite_coord_y;
		int px_height;
		int px_width;
		float scale;
		float speed;
		int kb_current_frame;
		int kb_last_frame;
		float kb_angle;
		sf::Vector2f direction;
		sf::Vector2f position;
};

};

#endif
