#include "./Levels.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace Dungeon {


Level* World1::level1C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level1C.ptlt");
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(17*48,6*48),101));
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(23*48,6*48),102));
level->finish_rect_list.push_back(FinishRect('t',&World1::level2C));

return level;
};	

Level* World1::level2C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level2C.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,6*48),201));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(30*48,6*48),202));
level->finish_rect_list.push_back(FinishRect('b',&World1::level1C));
level->finish_rect_list.push_back(FinishRect('r',&World1::level2D));
level->finish_rect_list.push_back(FinishRect('l',&World1::level2B));

return level;
};	
	

Level* World1::level2B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level2B.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,9*48),301));
level->enemy_list.push_back(new Armored_Zombie(game_ptr,sf::Vector2<float>(20*48,6*48),302));
level->enemy_list.push_back(new Armored_Zombie(game_ptr,sf::Vector2<float>(20*48,12*48),303));
level->finish_rect_list.push_back(FinishRect('r',&World1::level2C));
level->finish_rect_list.push_back(FinishRect('b',&World1::level1B));
level->finish_rect_list.push_back(FinishRect('l',&World1::level2A));
level->finish_rect_list.push_back(FinishRect('t',&World1::level3B));

return level;
};	

Level* World1::level2D(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level2D.ptlt");
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(30*48,5*48),401));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(10*48,20*48),402));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(20*48,10*48),403));
level->finish_rect_list.push_back(FinishRect('l',&World1::level2C));
level->finish_rect_list.push_back(FinishRect('t',&World1::level3D));

return level;
};

Level* World1::level3D(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/level3D.ptlt");
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(10*48,6*48),501));
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(30*48,6*48),502));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(5*48,18*48),503));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(35*48,18*48),504));
level->finish_rect_list.push_back(FinishRect('b',&World1::level2D));
level->finish_rect_list.push_back(FinishRect('r',&World1::level3E));
level->finish_rect_list.push_back(FinishRect('l',&World1::level3C));

return level;
};

Level* World1::level1B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level1B.ptlt");
level->finish_rect_list.push_back(FinishRect('t',&World1::level2B));

return level;
};

Level* World1::level3E(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level3E.ptlt");
level->finish_rect_list.push_back(FinishRect('l',&World1::level3D));

return level;
};

Level* World1::level4B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level4B.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,6*48),111));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(30*48,6*48),112));
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(20*48,6*48),113));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(35*48,18*48),116));
level->finish_rect_list.push_back(FinishRect('b',&World1::level3B));
level->finish_rect_list.push_back(FinishRect('l',&World1::level4A));
level->finish_rect_list.push_back(FinishRect('r',&World1::level4C));

return level;
};

Level* World1::level3A(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level3A.ptlt");
level->enemy_list.push_back(new BigFire(game_ptr,sf::Vector2<float>(26*48,8*48),901));
level->enemy_list.push_back(new Skeleton(game_ptr,sf::Vector2<float>(20*48,6*48),902));
level->finish_rect_list.push_back(FinishRect('b',&World1::level2A));
level->finish_rect_list.push_back(FinishRect('r',&World1::level3B));

return level;
};
Level* World1::level2A(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level2A.ptlt");
level->enemy_list.push_back(new BigFire(game_ptr,sf::Vector2<float>(20*48,6*48),801));
level->finish_rect_list.push_back(FinishRect('r',&World1::level2B));
level->finish_rect_list.push_back(FinishRect('t',&World1::level3A));

return level;
};
Level* World1::level3B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level3B.ptlt");
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(20*48,10.5*48),701));
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(20*48,12.5*48),702));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(23*48,11.5*48),703));
level->finish_rect_list.push_back(FinishRect('b',&World1::level2B));
level->finish_rect_list.push_back(FinishRect('l',&World1::level3A));
level->finish_rect_list.push_back(FinishRect('t',&World1::level4B));

return level;
};

Level* World1::level4A(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level4A.ptlt");
level->finish_rect_list.push_back(FinishRect('r',&World1::level4B));

return level;
};

Level* World1::level3C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level3C.ptlt");
level->finish_rect_list.push_back(FinishRect('r',&World1::level3D));
level->finish_rect_list.push_back(FinishRect('t',&World1::level4C));

return level;
};

Level* World1::level4C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/level4C.ptlt");
//level->finish_rect_list.push_back(FinishRect('t',&World1::level5C));
level->finish_rect_list.push_back(FinishRect('l',&World1::level4B));
level->finish_rect_list.push_back(FinishRect('b',&World1::level3C));

return level;
};
};
