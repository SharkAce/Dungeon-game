#include "../Item.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

namespace Items {

void Item::render() {
	this->window->draw(this->sprite);
};

void Item::update() {

	this->updateCooldown();
	this->updateAttackFrame();
	this->handleEnemyCollision();
	this->setItemAngle();
	this->setItemPosition();

};

};
};
