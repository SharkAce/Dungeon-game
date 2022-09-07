#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>

#include "../Player/Player.hpp"
#include "../Level/Level.hpp"

namespace Dungeon {

class Game {
	private:
		sf::VideoMode videoMode;
		sf::Event events;

		void initVariables();
		void initWindow(bool is_fullscreen);


		void handleKeyPress();
		void drawFramerate();
		void drawPause();

	public:
		void initLevel(Dungeon::Level *level);
		Game(bool is_fullscreen);
		virtual ~Game();
		
		Dungeon::Level *current_level;
		Dungeon::Player *player;
		long int current_frame;
		int framerate;
		bool pause;

		sf::RenderWindow *window;
		sf::Texture sprite_sheet;
		sf::Clock *base_clock;
		sf::Font *default_font;
		sf::Text *default_text;	
		sf::Vector2i mouse_pos;

		bool isOpen();
		void pollEvents();
		void render();
		void update();

		static float degToRad(float degree);
		static float RadToDeg(float radian);
};

};
#endif
