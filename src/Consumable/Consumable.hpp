#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "../Entity/Entity.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <string>

namespace Dungeon {

class Game;

class Consumable : public Entity {
	public:
		Consumable(
			Game *parent_game, 
			sf::Rect<int> sprite_rect,
			sf::Vector2<float> start_position,
			std::string name
		);

		bool end_of_life;
		float angle;
		float force;
		int id;
		std::string name;

};



};


#endif
