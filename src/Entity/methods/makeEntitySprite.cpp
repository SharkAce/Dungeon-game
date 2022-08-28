#include "../Entity.hpp"

namespace Dungeon {

void Entity::makeEntitySprite() {
	this->sprite.setScale(3.0, 3.0);
	this->sprite.setTexture(*texture);
	this->sprite.setTextureRect(sf::IntRect(
		sprite_coord_x,
		sprite_coord_y,
		px_width,
		px_height
	));
	this->sprite.setOrigin(this->px_width/2,this->px_height/2);
};

};
