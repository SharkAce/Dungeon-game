#include "../Entity.hpp"

namespace Dungeon {

bool Entity::collisionCheck() {
	sf::Rect sprite_ghost	= this->sprite.getGlobalBounds();
	sprite_ghost.top += this->direction.y;
	sprite_ghost.left += this->direction.x;

	for	(int i = 0; i < (int)(this->solid_tiles_sprites->size()); i++){
		sf::Sprite tile_sprite = this->solid_tiles_sprites->at(i);
		if(sprite_ghost.intersects(
				tile_sprite.getGlobalBounds())
			) {
			return true;
		}
	}
	return false;
};

};
