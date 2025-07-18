#include "Game/Game.hpp"
#include "Levels/Levels.hpp"
#include <SFML/System/Vector2.hpp>

int main(int argc, char *argv[])
{
	// Is fullscreen ?
	Dungeon::Game game(argc > 1 ? argv[1][0] != 'w' : true);

	// Load first level
	game.initLevel(Dungeon::World1::level3A(&game),sf::Vector2f(20*48,20*48));

	// Main loop
	while(game.isOpen()){
		/* ./Game/methods/GameFlow.cpp */
		game.update();
		game.render();
	}

	return 0;
};
