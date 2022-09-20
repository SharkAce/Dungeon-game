#include "../Entity.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

void Entity::update() {
	if (this->kb_last_frame!=0) {
		this->kb_current_frame ++;
		
		if (this->kb_last_frame == this->kb_current_frame){
			this->direction.x = 0;
			this->direction.y = 0;
			this->sprite.setColor(sf::Color::White);
		}
	}

	if (this->kb_current_frame < this->kb_last_frame){
		this->applyKnockback();
	} else this->kb_last_frame = 0;

	sf::Vector2<bool> collisions = wallCollisionCheck();

	if (collisions.x) this->direction.x = 0;
	if (collisions.y) this->direction.y = 0;


	this->sprite.move(this->direction);

	
	this->position = this->sprite.getPosition();
};

void Entity::render() {
	this->window->draw(this->sprite);
};

};
