#include "entity.h"

Base_entity::Base_entity(sf::Texture* texture, sf::RenderWindow* window){
	this->texture = texture;
	this->window = window;
	this->direction.x = 0.f;
	this->direction.y = 0.f;
}

void Base_entity::render(){
	this->window->draw(this->sprite);
}

void Base_entity::base_update(){
	if (!(collision_check())) this->sprite.move(this->direction);
	this->position = this->sprite.getPosition();
}
void Base_entity::make_entity_sprite(){
	this->sprite.setScale(3.0, 3.0);
	this->sprite.setTexture(*texture);
	this->sprite.setTextureRect(sf::IntRect(
		sprite_coord_x,
		sprite_coord_y,
		px_width,
		px_height
	));
	this->sprite.setOrigin(this->px_width/2,this->px_height/2);
}

void Base_entity::set_solid_tiles_sprites(std::vector<sf::Sprite>* sts){
	this->solid_tiles_sprites = sts;
}

bool Base_entity::collision_check(){
	sf::Rect sprite_ghost	= this->sprite.getGlobalBounds();
	sprite_ghost.top += this->direction.y;
	sprite_ghost.left += this->direction.x;

	for	(int i=0; i<this->solid_tiles_sprites->size();i++){
		sf::Sprite tile_sprite = this->solid_tiles_sprites->at(i);
		if(sprite_ghost.intersects(
				tile_sprite.getGlobalBounds())
			) {
			return true;
		}
	}
	return false;
}

Player::Player(sf::Texture* texture, sf::RenderWindow* window): 
		Base_entity(texture, window){
	

	this->scale = 3.0;
	this->max_hp = 100;
	this->current_hp = 100;
	this->damage = 20;
	this->sprite_coord_x = 224;
	this->sprite_coord_y = 224;
	this->px_height = 32;
	this->px_width = 16;
	this->speed = 8.f;
	this->sword_sprite_id = 63;
	this->make_entity_sprite();
	this->make_sword_sprite();

	this->sprite.setOrigin(this->px_width/2,this->px_height/1.5);
}

void Player::update(){
	this->update_sword();
}

void Player::make_sword_sprite(){
	this->sword.setTexture(*texture);
	this->sword.setTextureRect(sf::IntRect(160,32,16,32));
	this->sword.setScale(this->scale,this->scale);
	this->sword.setOrigin(8.f,32.f);
	
}

void Player::render_sowrd(){
	this->window->draw(this->sword);
}

void Player::update_sword(){
	
	sf::Vector2f playerPos = this->position;
	this->sword.setPosition(playerPos);

	sf::Vector2i mousePos = sf::Mouse::getPosition(*(this->window));
	float player_mouse_angle = 
		std::atan2(playerPos.y - mousePos.y,playerPos.x - mousePos.x)*180/M_PI-90;
  
	float x_offset = 30 * std::sin(player_mouse_angle/180*M_PI);
	float y_offset = 30 * std::cos(player_mouse_angle/180*M_PI)*-1;

	this->sword.move(x_offset,y_offset);
	this->sword.setRotation(player_mouse_angle);
}
