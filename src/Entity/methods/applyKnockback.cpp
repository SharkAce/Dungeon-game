#include "../Entity.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

void Entity::applyKnockback(){
	float force = this->kb_stopwatch.stop_time - this->kb_stopwatch.current_time;

	float x_offset = force * (std::cos(Game::degToRad(this->kb_angle)));
	float y_offset = force * (std::sin(Game::degToRad(this->kb_angle)));
	this->direction.x = x_offset;
	this->direction.y = y_offset;
};

};
