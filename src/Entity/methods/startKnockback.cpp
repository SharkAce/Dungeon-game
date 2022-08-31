#include "../Entity.hpp"

namespace Dungeon {

void Entity::startKnockback(int angle, int force){
	  this->kb_current_frame = 0; 
    this->kb_last_frame = force;
    this->kb_angle = angle;
};

};
