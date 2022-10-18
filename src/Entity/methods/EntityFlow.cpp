#include "../Entity.hpp"
#include "../../Game/Game.hpp"
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

	sf::Vector2<bool> wall_collisions = wallCollisionCheck();

	if (this->has_collisions){
		if (wall_collisions.x) this->direction.x = 0;
		if (wall_collisions.y) this->direction.y = 0;
	}


	this->sprite.move(this->direction);

	
	this->position = this->sprite.getPosition();
};

void Entity::render() {
	this->parent_game->window->draw(this->sprite);
};

};
