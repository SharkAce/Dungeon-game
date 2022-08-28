#include "../Entity.hpp"

namespace Dungeon {

void Entity::setSolidTilesSprites(
		std::vector<sf::Sprite>* sts
) {
	this->solid_tiles_sprites = sts;
};

};
