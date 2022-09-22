#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../Entity/Entity.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <vector>

namespace Dungeon {

class Game;

class Projectile : public Entity {
	public:
		Projectile(
			Game *parent_game, 
			std::vector<sf::FloatRect> *collision_bounds,
			sf::Rect<int> sprite_rect,
			sf::Vector2<float> start_position,
			float angle, 
			float speed
		);

		bool end_of_life;

		float angle;

		void update() override;

};



};


#endif
