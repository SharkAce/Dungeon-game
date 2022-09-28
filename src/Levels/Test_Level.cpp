#include "./Levels.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {


Level *testLevel2(Game *game_ptr){

	Dungeon::Level* test_level = new Dungeon::Level(game_ptr);	
	test_level->parsePtsfFile("res/level3.ptlt");
	test_level->enemy_list.push_back(new Dungeon::Sorcerer(game_ptr));
	test_level->enemy_list[0]->setPosition(20*48,10*48);
	game_ptr->player->setPosition(20*48,23*48);

	return test_level;

};

Level *testLevel(Game *game_ptr){

	Dungeon::Level* test_level = new Dungeon::Level(game_ptr);	
	test_level->parsePtsfFile("res/testLevel.ptlt");
	test_level->enemy_list.push_back(new Dungeon::Zombie(game_ptr));
	test_level->enemy_list.push_back(new Dungeon::Sorcerer(game_ptr));
	test_level->enemy_list[0]->setPosition(20*48,3*48);
	test_level->enemy_list[1]->setPosition(18*48,3*48);
	game_ptr->player->setPosition(20*48,11*48);
	test_level->finish_rect_list.push_back(FinishRect(sf::FloatRect(0,0,48*40,60),&testLevel2));

	return test_level;

};

};
