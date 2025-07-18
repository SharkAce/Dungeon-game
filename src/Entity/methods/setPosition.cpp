#include "../Entity.hpp"

namespace Dungeon {

void Entity::setPosition(float x, float y){
	this->sprite.setPosition({x,y});
};

void Entity::setPosition(sf::Vector2<float> pos){
	this->sprite.setPosition({pos.x, pos.y});
};
};
