#include "../Entity.hpp"

namespace Dungeon {

void Entity::update() {
	if (!(collisionCheck())) this->sprite.move(this->direction);
	this->position = this->sprite.getPosition();
};

void Entity::render() {
	this->window->draw(this->sprite);
};

};
