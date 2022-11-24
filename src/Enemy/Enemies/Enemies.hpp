#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Enemy.hpp"
#include "../../Projectile/Projectile.hpp"
#include "../../Stopwatch/Stopwatch.hpp"
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
		
		Stopwatch projectile_sw;


};

class Skeleton: public Enemy {
	public:
		Skeleton(Game* parent_game, sf::Vector2<float> start_position, int id);
		
		void update() override;

		Stopwatch projectile_sw;

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

		Stopwatch child_sw;

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

		Stopwatch child_sw;
};

class SmallFire: public Enemy {
	public:
		SmallFire(Game* parent_game, sf::Vector2<float> start_position, int id);

		int lifetime_current_frame;
		int lifetime_max_frame;

		void update() override;
};

class BossZombie: public Enemy {
	public:
		BossZombie(Game* parent_game, sf::Vector2<float> start_position, int id);

		sf::FloatRect destination_pt;

		bool is_in_dash;

		int movement_count;
		int max_movement_count;

		Stopwatch projectile_sw;
		Stopwatch dash_charge_sw;

		int dash_count;
		int max_dash_count;
		float dash_angle;
		float dash_speed;


		void update() override;
};

};


#endif
