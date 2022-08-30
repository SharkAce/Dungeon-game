#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity/Entity.hpp"
#include "../Item/Item.hpp"

namespace Dungeon {

class Player: public Entity {
	private:
		Dungeon::Items::Item *weapon;
	public:
		Player(Game* parent_game);

		void sword_attack();

		void update() override;
		void render() override;

		int max_hp;
		int current_hp;
		int damage;
		
};

};

#endif
