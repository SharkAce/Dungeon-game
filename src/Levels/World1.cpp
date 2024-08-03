#include "./Levels.hpp"
#include "../Game/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

namespace Dungeon {


Level* World1::level1B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level1B.ptlt");
level->enemy_list.push_back(new BigFire(game_ptr,sf::Vector2<float>(20*48,6*48),121));
level->finish_rect_list.push_back(FinishRect('r',&World1::level2B));
level->finish_rect_list.push_back(FinishRect('t',&World1::level1C));

return level;
};

Level* World1::level1C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level1C.ptlt");
level->enemy_list.push_back(new BigFire(game_ptr,sf::Vector2<float>(26*48,8*48),131));
level->enemy_list.push_back(new Skeleton(game_ptr,sf::Vector2<float>(20*48,6*48),132));
level->finish_rect_list.push_back(FinishRect('b',&World1::level1B));
level->finish_rect_list.push_back(FinishRect('r',&World1::level2C));

return level;
};

Level* World1::level1D(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level1D.ptlt");
level->consumable_list.push_back(Key(game_ptr, sf::Vector2<float>(20*48,9*48),1));
level->finish_rect_list.push_back(FinishRect('r',&World1::level2D));

return level;
};

Level* World1::level2A(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level2A.ptlt");
level->consumable_list.push_back(Key(game_ptr, sf::Vector2<float>(20*48,12*48),2));
level->finish_rect_list.push_back(FinishRect('t',&World1::level2B));

return level;
};

Level* World1::level2B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/World1/level2B.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,9*48),221));
level->enemy_list.push_back(new Armored_Zombie(game_ptr,sf::Vector2<float>(20*48,6*48),222));
level->enemy_list.push_back(new Armored_Zombie(game_ptr,sf::Vector2<float>(20*48,12*48),223));
level->finish_rect_list.push_back(FinishRect('r',&World1::level3B));
level->finish_rect_list.push_back(FinishRect('b',&World1::level2A));
level->finish_rect_list.push_back(FinishRect('l',&World1::level1B));
level->finish_rect_list.push_back(FinishRect('t',&World1::level2C));

return level;
};	

Level* World1::level2C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level2C.ptlt");
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(20*48,10.5*48),231));
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(20*48,12.5*48),232));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(23*48,11.5*48),233));
level->finish_rect_list.push_back(FinishRect('b',&World1::level2B));
level->finish_rect_list.push_back(FinishRect('l',&World1::level1C));
level->finish_rect_list.push_back(FinishRect('t',&World1::level2D));

return level;
};

Level* World1::level2D(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level2D.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,6*48),241));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(30*48,6*48),242));
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(20*48,6*48),243));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(35*48,18*48),246));
level->finish_rect_list.push_back(FinishRect('b',&World1::level2C));
level->finish_rect_list.push_back(FinishRect('l',&World1::level1D));
level->finish_rect_list.push_back(FinishRect('r',&World1::level3D));

return level;
};

Level* World1::level3A(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/World1/level3A.ptlt");
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(17*48,6*48),311));
level->enemy_list.push_back(new Zombie(game_ptr,sf::Vector2<float>(23*48,6*48),312));
level->finish_rect_list.push_back(FinishRect('t',&World1::level3B));

return level;
};

Level* World1::level3B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/World1/level3B.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(10*48,6*48),321));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(30*48,6*48),322));
level->finish_rect_list.push_back(FinishRect('b',&World1::level3A));
level->finish_rect_list.push_back(FinishRect('r',&World1::level4B));
level->finish_rect_list.push_back(FinishRect('l',&World1::level2B));

if (game_ptr->background_music->getStatus() != sf::Music::Status::Playing)
	game_ptr->background_music->play();
return level;
};

Level* World1::level3C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level3C.ptlt");
level->enemy_list.push_back(new Skeleton(game_ptr,sf::Vector2<float>(18*48,11*48),331));
level->enemy_list.push_back(new BigFire(game_ptr,sf::Vector2<float>(20*48,11*48),332));
level->enemy_list.push_back(new BigFire(game_ptr,sf::Vector2<float>(18*48,9*48),333));
level->finish_rect_list.push_back(FinishRect('r',&World1::level4C));
level->finish_rect_list.push_back(FinishRect('t',&World1::level3D));

return level;
};

Level* World1::level3D(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level3D.ptlt");
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(20*48,3*48),341));
level->enemy_list.push_back(new Skeleton(game_ptr,sf::Vector2<float>(18*48,4*48),342));
level->enemy_list.push_back(new Skeleton(game_ptr,sf::Vector2<float>(22*48,4*48),343));
level->enemy_list.push_back(new Armored_Zombie(game_ptr,sf::Vector2<float>(16*48,9*48),344));
level->enemy_list.push_back(new Armored_Zombie(game_ptr,sf::Vector2<float>(20*48,13*48),345));
level->finish_rect_list.push_back(FinishRect('t',&World1::level3E));
level->finish_rect_list.push_back(FinishRect('l',&World1::level2D));
level->finish_rect_list.push_back(FinishRect('b',&World1::level3C));

return level;
};

Level* World1::level3E(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->gate_level = true;
level->parsePtltFile("res/World1/level3E.ptlt");
level->finish_rect_list.push_back(FinishRect('b',&World1::level3D));

level->gate_area = sf::Rect<float>(0,0,23*48,6*48);
level->gate_finish_rect = new FinishRect(sf::FloatRect(0,0,48*40,2.5*48),sf::Vector2<bool>(false,true),&World1::level3F);
level->door_position = sf::Vector2<int>(19,0);

return level;
};

Level* World1::level3F(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level3F.ptlt");
level->enemy_list.push_back(new BossZombie(game_ptr,sf::Vector2<float>(960,160),1101));

return level;
};

Level* World1::level4B(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/World1/level4B.ptlt");
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(30*48,5*48),421));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(10*48,20*48),422));
level->enemy_list.push_back(new Sorcerer(game_ptr,sf::Vector2<float>(20*48,10*48),423));
level->finish_rect_list.push_back(FinishRect('l',&World1::level3B));
level->finish_rect_list.push_back(FinishRect('t',&World1::level4C));

return level;
}

Level* World1::level4C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);	
level->parsePtltFile("res/World1/level4C.ptlt");
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(10*48,6*48),431));
level->enemy_list.push_back(new BigSlime(game_ptr,sf::Vector2<float>(30*48,6*48),432));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(5*48,18*48),433));
level->enemy_list.push_back(new Ghost(game_ptr,sf::Vector2<float>(35*48,18*48),434));
level->finish_rect_list.push_back(FinishRect('b',&World1::level4B));
level->finish_rect_list.push_back(FinishRect('r',&World1::level5C));
level->finish_rect_list.push_back(FinishRect('l',&World1::level3C));

return level;
};

Level* World1::level5C(Game *game_ptr){

Dungeon::Level* level = new Dungeon::Level(game_ptr);
level->parsePtltFile("res/World1/level5C.ptlt");
level->consumable_list.push_back(Key(game_ptr, sf::Vector2<float>(20*48,9*48),3));
level->finish_rect_list.push_back(FinishRect('l',&World1::level4C));

return level;
};

};
