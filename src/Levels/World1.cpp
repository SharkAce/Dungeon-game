#include "./Levels.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace Dungeon {


Level *level1(Game *game_ptr){

Dungeon::Level* test_level = new Dungeon::Level(game_ptr);	
test_level->parsePtsfFile("res/level1.ptlt");
test_level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(17*48,6*48),101));
test_level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(23*48,6*48),102));
test_level->finish_rect_list.push_back(FinishRect('t',&level2));

return test_level;
};	

Level *level2(Game *game_ptr){

Dungeon::Level* test_level = new Dungeon::Level(game_ptr);	
test_level->parsePtsfFile("res/level2.ptlt");
test_level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,6*48),201));
test_level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(30*48,6*48),202));
test_level->finish_rect_list.push_back(FinishRect('b',&level1));
test_level->finish_rect_list.push_back(FinishRect('l',&level3));

return test_level;
};	
	

Level *level3(Game *game_ptr){

Dungeon::Level* test_level = new Dungeon::Level(game_ptr);	
test_level->parsePtsfFile("res/level3.ptlt");
test_level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,9*48),301));
test_level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(20*48,6*48),302));
test_level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(20*48,12*48),303));
	test_level->finish_rect_list.push_back(FinishRect('r',&level2));

return test_level;
};	
}
