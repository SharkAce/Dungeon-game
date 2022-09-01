#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity/Entity.hpp"
#include "../Item/Item.hpp"
#include <vector>
#include <math.h>

namespace Dungeon {

class Enemy;

class Player: public Entity {
	private:
		std::vector<Enemy*> *enemy_list;
	public:
		Player(Game *parent_game);

		Dungeon::Items::Item *weapon;
		void sword_attack();
		void handleEnemyCollision();
		void setEnemyList();

		void update() override;
		void render() override;

		int max_hp;
		int current_hp;
		int damage;	
		
};

};

#endif
