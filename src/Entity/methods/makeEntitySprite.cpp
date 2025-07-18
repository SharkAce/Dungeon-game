#include "../Entity.hpp"

namespace Dungeon {

void Entity::makeEntitySprite() {
	this->sprite.setScale({3.f, 3.f});
	this->sprite.setTextureRect({
		{sprite_coord_x, sprite_coord_y},
		{px_width, px_height}
	});
	this->sprite.setOrigin({this->px_width/2.f,this->px_height/2.f});
};

};
