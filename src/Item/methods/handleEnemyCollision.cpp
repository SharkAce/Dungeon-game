#include "../Item.hpp"
#include "../../Enemy/Enemy.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

namespace Items {

void Item::handleEnemyCollision(){
	if (!(this->is_attacking)) return;

	for (int i=0; i<this->parent_game->current_level->enemy_list.size(); i++){
		Enemy *enemy = this->parent_game->current_level->enemy_list[i];
		sf::Vector2f enemy_pos = enemy->sprite.getPosition();
		if (!(enemy->is_hit)){
			if (enemy->sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds())){
				
				int attack_degree = std::atan2(this->parent->position.y - enemy_pos.y, this->parent->position.x - enemy_pos.x)*180/M_PI;
				enemy->hit(attack_degree-180,12);
			}
		}
	}	
};

};

};
