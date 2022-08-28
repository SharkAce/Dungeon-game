#include <iostream>
#include "Game/Game.hpp"

int main(int argc, char *argv[])
{
					   // Is fullscreen ?
	Dungeon::Game game(argc > 1 ? argv[1][0] == 'f' : false);

	// Start Game
	while(game.isOpen()){
		game.update();
		game.render();
	}

	return 0;
};
