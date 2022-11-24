#include "Stopwatch.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {

Stopwatch::Stopwatch(float stop_time, Game* game_ptr, bool is_loop){
	this->stop_time = stop_time;
	this->current_time = 0;
	this->parent_game = game_ptr;
	this->is_stop = !is_loop;
	this->is_loop = is_loop;
};

bool Stopwatch::update(){
	if (this->is_stop){
		return false;
	}
	
	if (this->current_time + this->parent_game->time_unit >= this->stop_time){
		if (!this->is_loop)
			this->is_stop = true;
		this->current_time = 0;
		return false;
	} else {
		this->current_time += this->parent_game->time_unit;
		return true;
	}

};

};

