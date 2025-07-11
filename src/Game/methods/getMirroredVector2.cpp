#include "../Game.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

sf::Vector2f Game::getMirroredVector2(sf::Vector2f vec, sf::Vector2<bool> axis, bool center_offset){

	if (axis.x){
		vec.x = this->window_bound.size.x - vec.x;

		if (vec.x < (this->window_bound.size.x/2)) vec.x +=  center_offset ? 10 : 0;
		else vec.x -= center_offset ? 10 : 0;
	}
	
	if (axis.y){
		vec.y = this->window_bound.size.y - vec.y;

		if (vec.y < (this->window_bound.size.y/2)) vec.y += center_offset ? 51 : 0;

	}

	return vec;
};


};
