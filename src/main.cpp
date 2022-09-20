#include "Game/Game.hpp"
#include "Levels/Levels.hpp"

int main(int argc, char *argv[])
{
					   // Is fullscreen ?
	Dungeon::Game game(argc > 1 ? argv[1][0] == 'f' : false);

	//init level
	game.initLevel(Dungeon::testLevel(&game));

	// Main loop
	while(game.isOpen()){
		game.update();
		game.render();
	}

	return 0;
};
