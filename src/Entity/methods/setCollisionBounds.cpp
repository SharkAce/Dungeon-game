#include "../Entity.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {

void Entity::setCollisionBounds(
		std::vector<sf::FloatRect>* sts
) {
	this->collision_bounds = sts;
};

};
