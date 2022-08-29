#include "./Levels.hpp"

namespace Dungeon {

Level* testLevel(sf::Texture* sprite_sheet, sf::RenderWindow* window){

	Dungeon::Level* test_level = new Dungeon::Level(sprite_sheet,window);	
	test_level->setTileIdMulti(17,13,27,0,23);
	test_level->setTileIdMulti(50,14,26,1,22);
	test_level->setTileIdMulti(97,17,23,4,19);
	test_level->setTileId(7,0,0);
	test_level->setTileId(64,1,0);
	test_level->createBg();
	test_level->enemy_list.push_back(new Dungeon::Zombie(sprite_sheet,window));
	test_level->enemy_list.push_back(new Dungeon::Zombie(sprite_sheet,window));
	test_level->enemy_list[0]->setPosition(22*48,3*48);
	test_level->enemy_list[1]->setPosition(18*48,3*48);

	return test_level;

};

};
