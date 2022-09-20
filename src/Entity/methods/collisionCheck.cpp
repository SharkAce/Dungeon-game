#include "../Entity.hpp"

namespace Dungeon {

bool Entity::wallCollisionCheck() {
	sf::Rect<float> sprite_ghost	= this->sprite.getGlobalBounds();
	sprite_ghost.top += this->direction.y;
	sprite_ghost.left += this->direction.x;

	for	(int i = 0; i < (int)(this->collision_bounds->size()); i++){
		if(sprite_ghost.intersects(this->collision_bounds->at(i))) {
			return true;
		}
	}
	return false;
};

};
