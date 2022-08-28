#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>

#include "../Player/Player.hpp"
#include "../Level/Level.hpp"

namespace Dungeon {

class Game {
	private:
		sf::RenderWindow *window;
		sf::VideoMode videoMode;
		sf::Event events;

		void initVariables();
		void initWindow(bool is_fullscreen);
		void initLevel(Dungeon::Level *level);

		Dungeon::Player *player;

		void handleKeyPress();
		void drawFramerate();

	public:
		Game(bool is_fullscreen);
		virtual ~Game();
		
		Dungeon::Level* current_level;
		long int current_frame;
		int framerate;

		sf::Texture sprite_sheet;
		sf::Clock* base_clock;
		sf::Font* default_font;
		sf::Text* default_text;	

		bool isOpen();
		void pollEvents();
		void render();
		void update();
};

};
#endif
