#include "Game.hpp"

namespace Dungeon {

Game::Game(bool is_fullscreen) {
	this->sprite_sheet.loadFromFile("res/0x72_16x16DungeonTileset.v4.png");
	
	initWindow(is_fullscreen);

	this->player = new Player(&(this->sprite_sheet), this->window);
	this->base_clock = new sf::Clock;
	this->default_font = new sf::Font;
	this->default_font->loadFromFile("res/ARCADECLASSIC.TTF");
	this->default_text = new sf::Text;
	this->default_text->setFont(*(this->default_font));
	this->default_text->setFillColor(sf::Color::White);
	this->current_frame = 1;
	
	//Temporary stuff
	this->current_level = new Level(&(this->sprite_sheet), this->window);	
	this->current_level->setTileIdMulti(17,13,27,0,23);
	this->current_level->setTileIdMulti(50,14,26,1,22);
	this->current_level->setTileId(7,0,0);
	this->current_level->setTileId(64,1,0);
	this->current_level->createBg();

	std::vector<sf::Sprite>* ptr_sts = &(this->current_level->solid_tiles_sprites);
	this->player->setSolidTilesSprites(ptr_sts);
	this->player->sprite.setPosition(20*48,11*48);
	//end
};

Game::~Game() {
	delete this->window;
};

};
