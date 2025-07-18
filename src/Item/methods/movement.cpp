#include "../Item.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

namespace Items {

void Item::setItemPosition(){
	sf::Vector2f playerPos = this->parent->position;
	playerPos.y -= 10;
	this->sprite.setPosition(playerPos);

	float player_mouse_angle = this->parent->player_mouse_angle - 95.f;

	if (!this->attack_sw.is_stop) player_mouse_angle += (this->attack_sw.current_time*8);

	float x_offset = 55 * std::sin(Game::degToRad(player_mouse_angle));
	float y_offset = 55 * std::cos(Game::degToRad(player_mouse_angle))*-1;

	this->sprite.move({x_offset,y_offset});
};

void Item::setItemAngle(){
	this->angle = this->parent->player_mouse_angle - 120 - 90;

	if (!this->attack_sw.is_stop){
		this->sprite.setRotation(sf::degrees(this->angle+(this->attack_sw.current_time*15)));	
	} else {
		this->sprite.setRotation(sf::degrees(this->angle));
	}
};

};
};
