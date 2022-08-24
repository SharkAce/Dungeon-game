#include "game.h"

int main(){
	Game game(1000);
	
	while(game.isOpen()){
		game.update();
		game.render();
	}
	return 0;
}
