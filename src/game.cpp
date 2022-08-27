#include "game.h"

void Game::initVariables(){
	this->window = nullptr;
}

void Game::initWindow(){
	this->window = new sf::RenderWindow(sf::VideoMode(1920,1080,32), "test", sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
}

Game::Game(){
	this->sprite_sheet.loadFromFile("res/0x72_16x16DungeonTileset.v4.png");
	initVariables();
	initWindow();
	this->player = new Player(&(this->sprite_sheet), this->window);
	
	//Temporary stuff
	this->current_level = new Level(&(this->sprite_sheet), this->window);	
	this->current_level->set_tile_id_multi(17,13,27,0,23);
	this->current_level->set_tile_id_multi(50,14,26,1,22);
	this->current_level->set_tile_id(7,0,0);
	this->current_level->set_tile_id(64,1,0);
	this->current_level->create_bg();

	std::vector<sf::Sprite>* ptr_sts = &(this->current_level->solid_tiles_sprites);
	this->player->set_solid_tiles_sprites(ptr_sts);
	this->player->sprite.setPosition(20*48,11*48);
	//end
}

Game::~Game(){
	delete this->window;
}

void Game::initLevel(Level* level){
	this->current_level = level;
	this->current_level->create_bg();
	std::vector<sf::Sprite>* ptr_sts = &(this->current_level->solid_tiles_sprites);
	this->player->set_solid_tiles_sprites(ptr_sts);
}

bool Game::isOpen(){
	return this->window->isOpen();
}

void Game::pollEvents(){
	while (this->window->pollEvent(this->events)){
		switch (this->events.type){
			case sf::Event::Closed :
				this->window->close();
				break;
			case sf::Event::KeyPressed :
				break;
		}
	}
}

void Game::handleKeyPress(){
	float speed = this->player->speed;
	
	sf::Keyboard::Key W = sf::Keyboard::W;
	sf::Keyboard::Key A = sf::Keyboard::A;
	sf::Keyboard::Key S = sf::Keyboard::S;
	sf::Keyboard::Key D = sf::Keyboard::D;

	this->player->direction.x = 0.f;
	this->player->direction.y = 0.f;

	if (sf::Keyboard::isKeyPressed(W)){
		this->player->direction.y += speed*-1.f;
	}
	if (sf::Keyboard::isKeyPressed(A)){
		this->player->direction.x += speed*-1.f;
	}
	if (sf::Keyboard::isKeyPressed(S)){
		this->player->direction.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(D)){
		this->player->direction.x += speed;
	}
	//slow when in diagnal
	if (this->player->direction.x != 0.f &&
			this->player->direction.y != 0.f ){
		this->player->direction.x/=1.5;
		this->player->direction.y/=1.5;
	}
}

void Game::update(){
	this->pollEvents();
	this->handleKeyPress();
	this->player->base_update();
	this->player->update();
}

void Game::render(){
	this->window->clear(sf::Color(96,8,64));
	this->current_level->render_bg();
	this->player->render();
	this->player->render_sowrd();
	this->window->display();
}
