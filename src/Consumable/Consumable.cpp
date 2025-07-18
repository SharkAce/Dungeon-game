#include "./Consumable.hpp"
#include <cmath>
#include <string>
#include "../Game/Game.hpp"

namespace Dungeon{


Consumable::Consumable(
	Game *parent_game,
	sf::Rect<int> sprite_rect,
	sf::Vector2<float> start_position,
	std::string name
): Dungeon::Entity(parent_game) {

	this->name = name;
	this->sprite_coord_x = sprite_rect.position.x;
	this->sprite_coord_y = sprite_rect.position.y;
	this->px_width = sprite_rect.size.x;
	this->px_height = sprite_rect.size.y;
	this->speed = speed;
	this->angle = Game::radToDeg(std::atan2(
			start_position.y-parent_game->player->position.y,
			start_position.x-parent_game->player->position.x
		));
	this->end_of_life = false;
	this->makeEntitySprite();
	this->sprite.setScale({2.5,2.5});
	this->setPosition(start_position.x, start_position.y);
	this->startKnockback(angle,9);
};

};
