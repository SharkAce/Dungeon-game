#include "Consumables.hpp"
#include "../Consumable.hpp"
#include "../../Game/Game.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

Key::Key(Game *parent_game, sf::Vector2<float> start_position, int id): 
	Consumable(
			parent_game, 
			sf::Rect<int> (32,257,16,15), 
			start_position, 
			"key"
			){
	std::map<int,bool>& taken_keys = this->parent_game->taken_keys;
	this->id = id;

	if (taken_keys.find(id) == taken_keys.end()){
		taken_keys.insert({id,false});
	} else {
		if (taken_keys[id]) end_of_life = true;
	}
		return;
	};
};

