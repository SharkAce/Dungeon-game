#include "../Item.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

namespace Items {

void Item::render() {
	this->window->draw(this->sprite);
};

void Item::update() {

	this->cooldown_sw.update();
	this->attack_sw.update();
	this->handleEnemyCollision();
	this->setItemAngle();
	this->setItemPosition();

};

};
};
