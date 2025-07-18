#include "../Entity.hpp"
#include "../../Game/Game.hpp"
#include <SFML/System/Vector2.hpp>

namespace Dungeon {

void Entity::update() {

	if (!this->kb_stopwatch.is_stop){
		if (this->kb_stopwatch.update()){
			this->applyKnockback();
		} else {
			this->direction.x = 0;
			this->direction.y = 0;
			this->sprite.setColor(sf::Color::White);
		}
	}

	sf::Vector2<bool> wall_collisions = wallCollisionCheck();

	if (this->has_collisions){
		if (wall_collisions.x) this->direction.x = 0;
		if (wall_collisions.y) this->direction.y = 0;
	}


	this->direction.x *= this->parent_game->time_unit;
	this->direction.y *= this->parent_game->time_unit;
	this->sprite.move(this->direction);

	
	this->position = this->sprite.getPosition();
};

void Entity::render() {
	this->parent_game->window.draw(this->sprite);
};

};
