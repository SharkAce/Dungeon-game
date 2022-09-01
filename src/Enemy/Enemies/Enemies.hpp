#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Enemy.hpp"

namespace Dungeon {

class Zombie: public Enemy {
	public:
		Zombie(Game* parent_game);

		void update() override;

};

class Sorcerer: public Enemy {
	public:
		Sorcerer(Game* parent_game);

		void update() override;

};

};


#endif
