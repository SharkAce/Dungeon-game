#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <math.h>
#include "../Stopwatch/Stopwatch.hpp"

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

		sf::Vector2<bool> wallCollisionCheck();
		void setCollisionBounds(std::vector<sf::FloatRect> *sts);
		std::vector<sf::FloatRect> *collision_bounds; // This should be a class, called Wall or Tile or something

		void setPosition(float x, float y);
		void setPosition(sf::Vector2<float> pos);
		void applyKnockback();
		void startKnockback(int angle, float force);


		bool has_collisions;
		int sprite_coord_x;
		int sprite_coord_y;
		int px_height;
		int px_width;
		float scale;
		float speed;
		Stopwatch kb_stopwatch;
		float kb_angle;
		sf::Vector2f direction;
		sf::Vector2f position;
};

};

#endif
