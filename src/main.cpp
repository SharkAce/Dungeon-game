#include <SFML/Graphics.hpp>
#include <unistd.h>

int main(){
	sf::RenderWindow window(sf::VideoMode(600,600), "Place holder text", sf::Style::Fullscreen);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		shape.move(5,5);
		window.draw(shape);
		window.display();
		usleep(5000);
	}
	return 0;

}
