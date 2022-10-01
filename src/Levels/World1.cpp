#include "./Levels.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace Dungeon {


Level* World1::level1(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level1.ptlt");
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(17*48,6*48),101));
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(23*48,6*48),102));
level->finish_rect_list.push_back(FinishRect('t',&World1::level2));

return level;
};	

Level* World1::level2(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level2.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,6*48),201));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(30*48,6*48),202));
level->finish_rect_list.push_back(FinishRect('b',&World1::level1));
level->finish_rect_list.push_back(FinishRect('l',&World1::level3));

return level;
};	
	

Level* World1::level3(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level3.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,9*48),301));
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(20*48,6*48),302));
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(20*48,12*48),303));
level->finish_rect_list.push_back(FinishRect('r',&World1::level2));

return level;
};	
}
