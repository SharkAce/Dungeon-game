#include "../Game.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <optional>

namespace Dungeon {

void Game::pollEvents() {
	while (const std::optional event = this->window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			this->window.close();
		} else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
			if (mousePressed->button == sf::Mouse::Button::Left)
				if (this->player->weapon->cooldown_sw.is_stop){
					this->player->weapon->initAttack();
				}
		} else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			if (this->help_menu == true) help_menu = false;
			if (keyPressed->code == sf::Keyboard::Key::Escape){
				this->pause = !(this->pause);
			}
			else if (keyPressed->code == sf::Keyboard::Key::Enter){
				if (this->game_over) this->restart();
			}
			else if (keyPressed->code == sf::Keyboard::Key::R){
				if (this->win_state) this->restart();
			}
		}
	}
}

void Game::handleKeyState() {
	float speed = this->player->speed;
	
	this->player->direction.x = 0.f;
	this->player->direction.y = 0.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
		this->player->direction.y += speed*-1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
		this->player->direction.x += speed*-1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
		this->player->direction.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
		this->player->direction.x += speed;
	}
	//slow when in diagonal
	if (
		this->player->direction.x != 0.f &&
		this->player->direction.y != 0.f 
	) {
		this->player->direction.x/=1.5;
		this->player->direction.y/=1.5;
	}
};

void Game::activateWinState() {
	this->win_state = true;
	this->game_time = this->game_clock.getElapsedTime().asSeconds();

	return;
};

};
