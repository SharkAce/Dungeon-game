#include "./Levels.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace Dungeon {


Level *testLevel2(Game *game_ptr){

	Dungeon::Level* test_level = new Dungeon::Level(game_ptr);	
	test_level->parsePtsfFile("res/level3.ptlt");
	test_level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(20*48,10*48),201));
	test_level->finish_rect_list.push_back(FinishRect('b',&testLevel));

	return test_level;

};

Level *testLevel(Game *game_ptr){

	Dungeon::Level* test_level = new Dungeon::Level(game_ptr);	
	test_level->parsePtsfFile("res/testLevel.ptlt");
	test_level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(20*48,5*48),101));
	test_level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(18*48,3*48),102));
	test_level->finish_rect_list.push_back(FinishRect('t',&testLevel2));

	return test_level;

};

};
