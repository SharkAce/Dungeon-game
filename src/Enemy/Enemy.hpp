#ifndef ENEMY_H
#define ENEMY_H

#include "../Entity/Entity.hpp"
#include "../Projectile/Projectile.hpp"

namespace Dungeon {

class Enemy: public Entity { 
	public:
		Enemy(Game *parent_game, sf::Vector2<float> start_position);


		int max_hp;
		int current_hp;
		int damage;
		float kb_force;

		bool is_hit;
		bool is_dead;
		bool has_projectiles;
		std::vector<Projectile*> projectiles	;
		void hit(int angle, float force, float damage);
		void update() override;
		void render() override;

};

};

#endif
