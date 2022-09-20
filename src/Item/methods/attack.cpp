#include "../Item.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

namespace Items {

void Item::updateAttackFrame(){
	if (!(this->is_attacking)) return;

	if (this->attack_frame >= this->frame_per_attack) {
		this->is_attacking = false;
	} else this->attack_frame++;

}

void Item::initAttack(){
	this->is_attacking = true;
	this->attack_frame = 0;
	this->charge = 0;
	this->initAttackCooldown();
};

void Item::initAttackCooldown(){
	this->can_attack = false;
	this->cooldown_frame = 0;
}

void Item::updateCooldown(){
	if (this->can_attack == true) return;
	
	this->cooldown_frame ++;

	if (this->cooldown_frame >= this->frame_per_attack+5) {
		this->can_attack = true;
		for (int i=0; i<this->parent_game->current_level->enemy_list.size(); i++){
			this->parent_game->current_level->enemy_list[i]->is_hit = false;
		}
	}
};


};
};
