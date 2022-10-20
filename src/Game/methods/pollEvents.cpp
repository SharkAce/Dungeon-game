#include "../Game.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

namespace Dungeon {

void Game::pollEvents() {
	while (this->window->pollEvent(this->events)){
		switch (this->events.type){
			case sf::Event::Closed :
				this->window->close();
				break;
			case sf::Event::MouseButtonPressed :
				if (this->events.mouseButton.button == sf::Mouse::Left)
					if (this->player->weapon->can_attack){
						this->player->weapon->initAttack();
					}
			case sf::Event::KeyPressed :
				if (this->help_menu == true) help_menu = false;
				if (this->events.key.code == sf::Keyboard::Escape){
					this->pause = !(this->pause);
				}
				else if (this->events.key.code == sf::Keyboard::Enter){
					if (this->game_over) this->restart();
				}
				break;
			default:
				break;

		}
	}
};

};
