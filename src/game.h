#include <string>
#include <SFML/Graphics.hpp>
#include "entity.h"

#ifndef GAME_H
#define GAME_H

class Game {
	private:
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event events;

		void initVariables();
		void initWindow();

		Player* player;

		void handleKeyPress();

	public:
		Game();
		virtual ~Game();
		
		int framerate;
		sf::Texture sprite_sheet;

		bool isOpen();
		void pollEvents();
		void render();
		void update();
};

#endif
