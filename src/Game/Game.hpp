#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <cstdlib>
#include <time.h>

#include "../Player/Player.hpp"
#include "../Level/Level.hpp"
#include "../Levels/Levels.hpp"

namespace Dungeon {

class Game {
	private:
		sf::VideoMode videoMode;

		void initVariables();
		void initWindow(bool is_fullscreen);


		void handleKeyState();
		void drawFramerate();
		void drawPause();
		void drawHearts();
		void drawKeys();
		void drawGameOver();
		void drawHelpMenu();
		void drawWinScreen();

		void deleteDeadEnemies(std::vector<Enemy*> *enemy_list);

	public:
		void initLevel(Dungeon::Level *level, sf::Vector2f playerPos);
		Game(bool is_fullscreen);
		virtual ~Game();
		
		Dungeon::Level *current_level;
		Dungeon::Player *player;
		std::map<int,bool> dead_enemies;
		std::map<int,bool> taken_keys;
		long int current_frame;
		int framerate;
		float time_unit;
		bool pause;
		bool game_over;
		bool help_menu;

		sf::RenderWindow window;
		sf::Texture sprite_sheet;
		sf::IntRect window_bound;
		
		sf::Clock base_clock;
		sf::Clock game_clock;
		float game_time;
		sf::Vector2i mouse_pos;
		
		sf::Font default_font;
		sf::Font secondary_font;
		sf::Text default_text;	
		
		sf::Sprite heart_sprite;
		sf::Sprite heart_sprite_empty;
		sf::Sprite key_sprite;

		sf::Music background_music;
		void updateBackgroundMusic();
		
		
		sf::SoundBuffer sfx_sound_buffer;
		sf::Sound sfx_sound;

		struct sfx_instance {
			sfx_instance(int a, int b, float volume){
				this->a = a;
				this->b = b;
				this->volume = volume;
			}
			int a;
			int b;
			float volume;
		};

		std::map<std::string, sfx_instance> sfx_sound_map;
		std::string current_sfx;
		std::string current_sfx_fg;
		void makeSfxSoundMap();

		void startSfx(std::string sound_name);
		void updateSfx();

		int sprite_size = 16;

		bool isOpen();
		void pollEvents();
		void render();
		void update();
		void restart();
		bool win_state;
		void activateWinState();

		static float degToRad(float degree);
		static float radToDeg(float radian);

		void writeToScreen(std::string text_to_print, float posX, float posY, sf::Text text);
		sf::Vector2f getMirroredVector2(sf::Vector2f vec, sf::Vector2<bool> axis,bool center_offset);

};

};
#endif
