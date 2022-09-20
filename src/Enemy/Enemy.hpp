#ifndef ENEMY_H
#define ENEMY_H

#include "../Entity/Entity.hpp"

namespace Dungeon {

class Enemy: public Entity { 
	public:
		Enemy(Game *parent_game);


		int max_hp;
		int current_hp;
		int damage;
		float kb_force;

		bool is_hit;
		bool is_dead;
		void hit(int angle, float force, float damage);
		void update() override;

};

};

#endif
