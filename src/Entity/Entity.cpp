#include "Entity.hpp"

namespace Dungeon {

Entity::Entity(sf::Texture* texture, sf::RenderWindow* window){
	this->texture = texture;
	this->window = window;
	this->direction.x = 0.f;
	this->direction.y = 0.f;
};

};
