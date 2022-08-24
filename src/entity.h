#ifndef ENTITY_H
#define ENTITY_H


#include <SFML/Graphics.hpp>

class Base_entity{
	private:

	public:
		Base_entity(sf::Texture texture, sf::RenderWindow* window);
		void render();
		void update();

		sf::Sprite sprite;
		sf::Texture texture;
		sf::RenderWindow* window;

		int max_hp;
		int current_hp;
		int damage;
		int sprite_coord_x;
		int sprite_coord_y;
		int px_height;
		int px_width;
		float speed;
		sf::Vector2f direction;
};

class Player: public Base_entity{
	public:
		Player(sf::Texture texture, sf::RenderWindow*);
};


#endif
