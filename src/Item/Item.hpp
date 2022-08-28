#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>

namespace Dungeon {
class Player; // Forward declaration for this header file, 
			  // the cpp source uses the ../Player/Player.hpp header directly
namespace Items {

class Item {
private:
	Dungeon::Player *parent;
	sf::RenderWindow *window;
	sf::Texture *sheet;
	sf::Sprite sprite;
	float scale; 
public:
	Item(
		sf::Texture *sprite_sheet,
		sf::RenderWindow *window,
		Dungeon::Player *parent
	);

	void make_sprite();

	void update();
	void render();
};

};
};
#endif
