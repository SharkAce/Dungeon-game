#include "../Item.hpp"
#include "../../Enemy/Enemy.hpp"
#include "../../Game/Game.hpp"
#include "../../Projectile/Projectile.hpp"
#include <vector>

namespace Dungeon {

namespace Items {

void Item::handleEnemyCollision(){
	if (!(this->is_attacking)) return;

	for (int i=0; i<this->parent_game->current_level->enemy_list.size(); i++){
		Enemy& enemy = *this->parent_game->current_level->enemy_list[i];
		sf::Vector2f enemy_pos = enemy.sprite.getPosition();
		if (!(enemy.is_hit)){
			if (enemy.sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds())){
				
				int attack_degree = std::atan2(this->parent->position.y - enemy_pos.y, this->parent->position.x - enemy_pos.x)*180/M_PI;
				enemy.hit(attack_degree-180,12,this->damage);
			}
		}
		if (enemy.has_projectiles){
			for (int j=0; j<this->parent_game->current_level->enemy_list.at(i)->projectiles.size(); j++){
				Projectile& ptile = *enemy.projectiles[j];

				if (ptile.sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds())){
					ptile.end_of_life = true;
				}
			}
		}
	}	
};

};

};
