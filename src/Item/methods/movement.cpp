#include "../Item.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

namespace Items {

void Item::setItemPosition(){
	sf::Vector2f playerPos = this->parent->position;
	playerPos.y -= 10;
	this->sprite.setPosition(playerPos);

	float player_mouse_angle = this->parent->player_mouse_angle - 95.f;

	if (this->is_attacking) player_mouse_angle += (this->attack_frame*8);

	float x_offset = 55 * std::sin(Game::degToRad(player_mouse_angle));
	float y_offset = 55 * std::cos(Game::degToRad(player_mouse_angle))*-1;

	this->sprite.move(x_offset,y_offset);
};

void Item::setItemAngle(){
	this->angle = this->parent->player_mouse_angle - 120 - 90;

	if (this->is_attacking){
		this->sprite.setRotation(this->angle+(this->attack_frame*15));	
	} else {
		this->sprite.setRotation(this->angle);
	}
};

};
};
