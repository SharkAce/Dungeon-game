#include "Game.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {

Game::Game(bool is_fullscreen):
	sprite_sheet("res/0x72_16x16DungeonTileset.v4.png"),
	default_font("res/ARCADECLASSIC.TTF"),
	secondary_font("res/PressStart2P-vaV7.ttf"),
	default_text(secondary_font),
	sfx_sound_buffer("res/sfx.wav"),
	sfx_sound(sfx_sound_buffer),
	background_music("res/033253562-dungeon.wav"),
	key_sprite(sprite_sheet),
	heart_sprite(sprite_sheet),
	heart_sprite_empty(sprite_sheet){
	
	initWindow(is_fullscreen);

	this->player = new Player(this);
	this->current_level = nullptr;

	//Font stuff
	this->default_text.setFillColor(sf::Color::White);
	this->default_text.setCharacterSize(20);
	this->default_text.setLetterSpacing(0.8);
	this->default_text.setLineSpacing(1.4);

	//Audio stuff
	this->sfx_sound.setVolume(10.f);
	this->makeSfxSoundMap();

	this->background_music.setLoopPoints({sf::Time::Zero, background_music.getDuration()});
	this->background_music.setLooping(true);

	
	//Clock stuff
	this->game_clock.restart();
	this->current_frame = 1;
	this->time_unit = 1;

	this->pause = false;
	this->game_over = false;
	this->help_menu = true;
	this->win_state = false;
	
	//Hud sprites
	this->heart_sprite.setTextureRect({{0,16*15},{16,16}});
	this->heart_sprite.scale({2.5,2.5});

	this->heart_sprite_empty.setTextureRect({{16,16*15},{16,16}});
	this->heart_sprite_empty.scale({2.5,2.5});

	this->key_sprite.setTextureRect({{32,257},{16,14}});
	this->key_sprite.scale({2.5,2.5});

	//Generate seed for rand()
	std::srand(std::time(nullptr));
};

Game::~Game() {
	delete this->player;
};

};
