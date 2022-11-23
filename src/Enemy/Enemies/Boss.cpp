#include "Enemies.hpp"
#include "../../Game/Game.hpp"

namespace Dungeon {

BossZombie::BossZombie(Game* parent_game, sf::Vector2<float> start_position, int id): Dungeon::Enemy(parent_game, start_position, id) {
	this->scale = 3.0;
	this->max_hp = 60;
	this->current_hp = 60;
	this->damage = 20;
	this->sprite_coord_x = 102;
	this->sprite_coord_y = 182;
	this->px_height = 26;
	this->px_width = 20;
	this->speed = 2.5f;
	this->kb_force = 14.f;
	this->has_projectiles = false;

	this->makeEntitySprite();

};

void BossZombie::update(){
	
};

void BossZombie::renderHealthBar(){
	sf::RectangleShape outline(sf::Vector2<float>(this->parent_game->window->getSize().x*0.8f,15.f));
	outline.setFillColor(sf::Color::Black);

	sf::RectangleShape hp(sf::Vector2<float>(((this->parent_game->window->getSize().x*80)/this->max_hp)*this->current_hp,13.f));
	hp.setFillColor(sf::Color::Red);

	this->parent_game->window->draw(outline);
	this->parent_game->window->draw(hp);

};
};

