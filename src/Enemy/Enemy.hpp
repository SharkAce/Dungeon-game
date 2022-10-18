#ifndef ENEMY_H
#define ENEMY_H

#include "../Entity/Entity.hpp"
#include "../Projectile/Projectile.hpp"

namespace Dungeon {

class Enemy: public Entity { 
	public:
		Enemy(Game *parent_game, sf::Vector2<float> start_position, int id);


		int max_hp;
		int current_hp;
		int damage;
		float kb_force;
		int id;

		bool is_hit;
		bool is_dead;
		bool has_projectiles;
		bool drops_potions;
		std::vector<Projectile*> projectiles	;
		void hit(int angle, float force, float damage);
		virtual void update() override;
		virtual void render() override;

};

};

#endif
