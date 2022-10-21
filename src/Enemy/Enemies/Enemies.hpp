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
		Zombie(Game* parent_game, sf::Vector2<float> start_position, int id);

		void update() override;

};

class Armored_Zombie: public Enemy {
	public:
		Armored_Zombie(Game* parent_game, sf::Vector2<float> start_position, int id);

		void update() override;

};

class Sorcerer: public Enemy {
	public:
		Sorcerer(Game* parent_game, sf::Vector2<float> start_position, int id);

		void update() override;
		

		int projectile_max_count;
		int projectile_cooldown;
		int projectile_cooldown_current;
		bool is_projectile_cooldown;


};

class Ghost: public Enemy {
	public:
		Ghost(Game* parent_game, sf::Vector2<float> start_position, int id);

		void update() override;
};


class BigSlime: public Enemy {
	public:
		BigSlime(Game* parent_game, sf::Vector2<float> start_position, int id);

		void update() override;

		int child_max_count;
		int child_cooldown;
		int child_cooldown_current;
		bool is_child_cooldown;
};

class SmallSlime: public Enemy {
	public:
		SmallSlime(Game* parent_game, sf::Vector2<float> start_position, int id);

		void update() override;
};

class BigFire: public Enemy {
	public:
		BigFire(Game* parent_game, sf::Vector2<float> start_position, int id);

		void update() override;

		int child_max_count;
		int child_cooldown;
		int child_cooldown_current;
		bool is_child_cooldown;
};

class SmallFire: public Enemy {
	public:
		SmallFire(Game* parent_game, sf::Vector2<float> start_position, int id);

		int lifetime_current_frame;
		int lifetime_max_frame;

		void update() override;
};
};


#endif
