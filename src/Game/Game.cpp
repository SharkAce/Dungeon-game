#include "Game.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {

Game::Game(bool is_fullscreen) {
	this->sprite_sheet.loadFromFile("res/0x72_16x16DungeonTileset.v4.png");
	this->sprite_size = 16;
	
	initWindow(is_fullscreen);

	this->player = new Player(this);
	this->current_level = nullptr;

	//Font stuff
	this->default_font = new sf::Font;
	this->default_font->loadFromFile("res/ARCADECLASSIC.TTF");
	this->default_text = new sf::Text;
	this->default_text->setFont(*(this->default_font));
	this->default_text->setFillColor(sf::Color::White);
	
	//Clock stuff
	this->base_clock = new sf::Clock;
	this->current_frame = 1;

	this->pause = false;
	this->game_over = false;
	
	//Heart sprite
	this->heart_sprite.setTexture(this->sprite_sheet);
	this->heart_sprite.setTextureRect(sf::IntRect(0,16*15,16,16));
	this->heart_sprite.scale(2.5,2.5);

	//Generate seed for rand()
	std::srand(std::time(nullptr));
	
};

Game::~Game() {
	delete this->window;
	delete this->player;
	delete this->base_clock;
	delete this->default_font;
	delete this->current_level;
};

};
