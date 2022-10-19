#ifndef CONSUMABLES_H
#define CONSUMABLES_H

#include "Consumable.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

class Game;

class Potion : public Consumable {
	public:
		Potion(Game *parent_game, sf::Vector2<float> start_position);

};

};

#endif
