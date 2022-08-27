#ifndef ENTITY_H
#define ENTITY_H


#include <SFML/Graphics.hpp>
#include <math.h>
#include <cmath>

class Base_entity{
	private:

	public:
		Base_entity(sf::Texture* texture, sf::RenderWindow* window);
		void make_entity_sprite();
		void render();
		void base_update();

		sf::Sprite sprite;
		sf::Texture* texture;
		sf::RenderWindow* window;

		bool collision_check();
		void set_solid_tiles_sprites(std::vector<sf::Sprite>* sts);
		std::vector<sf::Sprite>* solid_tiles_sprites;

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

class Player: public Base_entity{
	public:
		Player(sf::Texture*, sf::RenderWindow*);

		sf::Sprite sword;
		int sword_sprite_id;
		void update();
		void update_sword();
		void render_sowrd();
		void sword_attack();
		void make_sword_sprite();
};


#endif
