#include "Game/Game.hpp"
#include "Levels/Levels.hpp"

int main(int argc, char *argv[])
{
					   // Is fullscreen ?
	Dungeon::Game game(argc > 1 ? argv[1][0] == 'f' : false);

	//init level

	game.initLevel(Dungeon::testLevel(&(game.sprite_sheet), game.window));
	game.player->setPosition(20*48,11*48);

	// Start Game
	while(game.isOpen()){
		game.update();
		game.render();
	}

	return 0;
};
