#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include "../Entity/Entity.hpp"
#include <math.h>

namespace Dungeon {
class Player; // Forward declaration for this header file, 
			  // the cpp source uses the ../Player/Player.hpp header directly
class Game;
namespace Items {
class Item : public Entity {
private:
	Dungeon::Player *parent;
	Dungeon::Game *parent_game;
	sf::RenderWindow *window;
	sf::Texture *sheet;
	sf::Sprite sprite;
	float scale; 
public:
	Item(
		Dungeon::Player *parent
	);

	void make_sprite();

	void update() override;
	void render() override;
	void setItemPosition();
	void setItemAngle();

	bool is_attacking;
	bool can_attack;
	float angle;
	int charge;
	int attack_frame;
	int cooldown_frame;
	int frame_per_attack;
	float damage;
	void initAttack();
	void initAttackCooldown();
	void updateCooldown();
	void updateAttackFrame();
	void handleEnemyCollision();
};

};
};
#endif
