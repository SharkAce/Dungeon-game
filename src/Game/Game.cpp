#include "Game.hpp"

namespace Dungeon {

Game::Game(bool is_fullscreen) {
	this->sprite_sheet.loadFromFile("res/0x72_16x16DungeonTileset.v4.png");
	
	initWindow(is_fullscreen);

	this->player = new Player(this);
	this->base_clock = new sf::Clock;
	this->default_font = new sf::Font;
	this->default_font->loadFromFile("res/ARCADECLASSIC.TTF");
	this->default_text = new sf::Text;
	this->default_text->setFont(*(this->default_font));
	this->default_text->setFillColor(sf::Color::White);
	this->current_frame = 1;
	
};

Game::~Game() {
	delete this->window;
	delete this->player;
	delete this->base_clock;
	delete this->default_font;
	delete this->current_level;
};

};
