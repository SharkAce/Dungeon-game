#include "../Game.hpp"

namespace Dungeon {

void Game::drawFramerate() {
	sf::Text text = *(this->default_text);
	std::string str = std::to_string((int)this->framerate);
	text.setString(str);
	sf::Rect size = text.getGlobalBounds();
	text.setPosition(
		this->window->getSize().x - (size.top*4.f),
		size.left
	);
	this->window->draw(text);
};

};
