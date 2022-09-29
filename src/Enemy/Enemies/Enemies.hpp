#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Enemy.hpp"
#include "../../Projectile/Projectile.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Dungeon {

class Zombie: public Enemy {
	public:
		Zombie(Game* parent_game, sf::Vector2<float> start_position);

		void update() override;

};

class Sorcerer: public Enemy {
	public:
		Sorcerer(Game* parent_game, sf::Vector2<float> start_position);

		void update() override;
		

		int projectile_max_count;
		int projectile_cooldown;
		int projectile_cooldown_current;
		bool is_projectile_cooldown;


};

};


#endif
