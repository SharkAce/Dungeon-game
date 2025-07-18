#include "Projectile.hpp"
#include "../Game/Game.hpp"

namespace Dungeon {

Projectile::Projectile(
	Game *parent_game,
	std::vector<sf::FloatRect> *collision_bounds,
	sf::Rect<int> sprite_rect,
	float sprite_angle,
	sf::Vector2<float> start_position,
	float angle,
	float speed
): Dungeon::Entity(parent_game) {

	this->scale = 3.0;
	this->sprite_coord_x = sprite_rect.position.x;
	this->sprite_coord_y = sprite_rect.position.y;
	this->px_width = sprite_rect.size.x;
	this->px_height = sprite_rect.size.y;
	this->speed = speed;
	this->angle = angle;
	this->end_of_life = false;
	this->makeEntitySprite();
	this->sprite.setRotation(sf::degrees(360-(angle-90)+sprite_angle));
	this->setCollisionBounds(collision_bounds);
	this->setPosition(start_position.x, start_position.y);
};

void Projectile::update(){
	this->direction.x = speed * (sin(Game::degToRad(angle)));	
	this->direction.y = speed * (cos(Game::degToRad(angle)));

	
	sf::Vector2<bool> collisions = wallCollisionCheck();
	bool window_collisions = (bool)this->sprite.getGlobalBounds().findIntersection(this->parent_game->window_bound);

	if (collisions.x || collisions.y || !window_collisions){
		this->end_of_life = true;
	} else {

	
		this->sprite.move(this->direction*this->parent_game->time_unit);
		this->position = this->sprite.getPosition();
	}

}
	
};
