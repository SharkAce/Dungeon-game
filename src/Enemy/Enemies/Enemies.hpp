#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Enemy.hpp"

namespace Dungeon {

class Zombie: public Enemy {
	public:
		Zombie(sf::Texture*, sf::RenderWindow*);

		void update() override;

};

};


#endif
