#include "../Game.hpp"

namespace Dungeon {

void Game::drawGameOver(){
	sf::Text text = *(this->default_text);
	std::string str = "Game Over";
	text.setString(str);
	text.setOrigin(text.getLocalBounds().width/2.0f,text.getLocalBounds().height/2.0f);
	text.setPosition(this->window->getSize().x/2.0f,this->window->getSize().y/3.0f);
	this->window->draw(text);
};

};
