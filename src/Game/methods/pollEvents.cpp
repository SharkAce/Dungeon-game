#include "../Game.hpp"

namespace Dungeon {

void Game::pollEvents() {
	while (this->window->pollEvent(this->events)){
		switch (this->events.type){
			case sf::Event::Closed :
				this->window->close();
				break;
			case sf::Event::KeyPressed :
				break;
			default:
				break;

		}
	}
};

};
