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
	this->secondary_font = new sf::Font;
	this->secondary_font->loadFromFile("res/PressStart2P-vaV7.ttf");
	this->default_text = new sf::Text;
	this->default_text->setFont(*secondary_font);
	this->default_text->setFillColor(sf::Color::White);
	this->default_text->setCharacterSize(20);
	this->default_text->setLetterSpacing(0.8);
	this->default_text->setLineSpacing(1.4);

	//Audio stuff
	this->sfx_sound_buffer = new sf::SoundBuffer();
	this->sfx_sound_buffer->loadFromFile("res/sfx.wav");
	this->sfx_sound = new sf::Sound(*this->sfx_sound_buffer);
	this->sfx_sound->setVolume(10.f);
	this->makeSfxSoundMap();

	this->background_music = new sf::Music();
	this->background_music->openFromFile("res/033253562-dungeon.wav");
	this->background_music->setLoopPoints(sf::Music::TimeSpan(sf::Time::Zero,this->background_music->getDuration()));
	this->background_music->setLoop(true);

	
	//Clock stuff
	this->base_clock = new sf::Clock;
	this->game_clock = new sf::Clock;
	this->game_clock->restart();
	this->current_frame = 1;
	this->time_unit = 1;

	this->pause = false;
	this->game_over = false;
	this->help_menu = true;
	this->win_state = false;
	
	//Hud sprites
	this->heart_sprite.setTexture(this->sprite_sheet);
	this->heart_sprite.setTextureRect(sf::IntRect(0,16*15,16,16));
	this->heart_sprite.scale(2.5,2.5);

	this->heart_sprite_empty.setTexture(this->sprite_sheet);
	this->heart_sprite_empty.setTextureRect(sf::IntRect(16,16*15,16,16));
	this->heart_sprite_empty.scale(2.5,2.5);

	this->key_sprite.setTexture(this->sprite_sheet);
	this->key_sprite.setTextureRect(sf::IntRect(32,257,16,14));
	this->key_sprite.scale(2.5,2.5);

	//Generate seed for rand()
	std::srand(std::time(nullptr));
	
};

Game::~Game() {
	delete this->window;
	delete this->player;
	delete this->base_clock;
	delete this->default_font;
	delete this->current_level;
	delete this->sfx_sound;
	delete this->sfx_sound_buffer;
	delete this->background_music;
};

};
