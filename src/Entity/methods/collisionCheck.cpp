#include "../Entity.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

	sf::Vector2<bool> Entity::wallCollisionCheck() {
	sf::Rect<float> sprite_ghost_x	= this->sprite.getGlobalBounds();
	sf::Rect<float> sprite_ghost_y	= this->sprite.getGlobalBounds();

	sf::Vector2<bool> collisions(false,false);

	sprite_ghost_x.left += this->direction.x;
	sprite_ghost_y.top += this->direction.y;

	for	(int i = 0; i < (int)(this->collision_bounds->size()); i++){
		if(sprite_ghost_x.intersects(this->collision_bounds->at(i))) {
			collisions.x = true;
		}
		if(sprite_ghost_y.intersects(this->collision_bounds->at(i))) {
			collisions.y = true;
		}
	}
	return collisions;
};

};
