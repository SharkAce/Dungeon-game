#include "../Entity.hpp"

namespace Dungeon {

void Entity::startKnockback(int angle, float force){
		
		this->kb_stopwatch.is_stop = false;
		this->kb_stopwatch.stop_time = force;
    this->kb_angle = angle;
};

};
