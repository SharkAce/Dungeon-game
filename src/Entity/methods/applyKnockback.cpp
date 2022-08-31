#include "../Entity.hpp"

namespace Dungeon {

void Entity::applyKnockback(){
	float force = this->kb_last_frame - this->kb_current_frame;

	//force*=30;

	float x_offset = force * (std::cos(this->kb_angle/180*M_PI));
	float y_offset = force * (std::sin(this->kb_angle/180*M_PI));
	this->direction.x = x_offset;
	this->direction.y = y_offset;
};

};
