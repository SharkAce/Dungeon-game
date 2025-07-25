#include "Consumables.hpp"
#include "../Consumable.hpp"
#include "../../Game/Game.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

Potion::Potion(Game *parent_game, sf::Vector2<float> start_position): 
	Consumable(
			parent_game, 
			{{194,176},{12,16}}, 
			start_position, 
			"potion"
			){
		return;
	};
};
