#include "../Entity.hpp"

namespace Dungeon {

void Entity::update() {
	if (this->kb_last_frame!=0) this->kb_current_frame ++;
	if (this->kb_current_frame < this->kb_last_frame){
		this->applyKnockback();
	} else this->kb_last_frame = 0;

	if (!(wallCollisionCheck())) {
		this->sprite.move(this->direction);
	}
	this->position = this->sprite.getPosition();
};

void Entity::render() {
	this->window->draw(this->sprite);
};

};
