#include "../Item.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

namespace Items {


void Item::initAttack(){
	this->attack_sw.is_stop = false;
	this->cooldown_sw.is_stop = false;
	this->charge = 0;
	this->cooldown_sw.is_stop = false;
	this->parent_game->startSfx("SwordSwing");
};

};
};
