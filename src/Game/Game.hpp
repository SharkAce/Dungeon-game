#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include <cstdlib>
#include <time.h>

#include "../Player/Player.hpp"
#include "../Level/Level.hpp"
#include "../Levels//Levels.hpp"

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
		void drawHearts();
		void drawGameOver();
		void drawHelpMenu();

		void deleteDeadEnemies(std::vector<Enemy*> *enemy_list);

	public:
		void initLevel(Dungeon::Level *level, sf::Vector2f playerPos);
		Game(bool is_fullscreen);
		virtual ~Game();
		
		Dungeon::Level *current_level;
		Dungeon::Player *player;
		std::map<int,bool> dead_enemies;
		long int current_frame;
		int framerate;
		bool pause;
		bool game_over;
		bool help_menu;

		sf::RenderWindow *window;
		sf::Texture sprite_sheet;
		sf::Clock *base_clock;
		sf::Font *default_font;
		sf::Text *default_text;	
		sf::Vector2i mouse_pos;
		sf::Sprite heart_sprite;
		sf::FloatRect window_bound;

		int sprite_size;

		bool isOpen();
		void pollEvents();
		void render();
		void update();
		void restart();

		static float degToRad(float degree);
		static float radToDeg(float radian);

		void writeToScreen(std::string text_to_print, float posX, float posY);
		sf::Vector2f getMirroredVector2(sf::Vector2f vec, sf::Vector2<bool> axis,float center_offset);
};

};
#endif
