#include "../Game.hpp"

namespace Dungeon {

void Game::writeToScreen(std::string text_to_print, float posX, float posY, sf::Text text){

	text.setString(text_to_print);
	text.setOrigin(text.getLocalBounds().width/2.0f,text.getLocalBounds().height/2.0f);
	text.setPosition(posX,posY);
	this->window->draw(text);

};

};
