#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "level.h"

class Game {
	private:
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event events;

		void initVariables();
		void initWindow();
		void initLevel(Level* level);

		Player* player;

		void handleKeyPress();

	public:
		Game();
		virtual ~Game();
		
		Level* current_level;
		int framerate;
		sf::Texture sprite_sheet;

		bool isOpen();
		void pollEvents();
		void render();
		void update();
};

#endif
