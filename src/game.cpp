#include "game.h"

void Game::initVariables(){
	this->window = nullptr;
}

void Game::initWindow(){
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->window = new sf::RenderWindow(this->videoMode, "test", sf::Style::Fullscreen);
}

Game::Game(int delay){
	this->delay = delay;
	initVariables();
	initWindow();
}

Game::~Game(){
	delete this->window;
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
				//handle key press
				break;
		}
	}
}

void Game::update(){
	this->pollEvents();
}

void Game::render(){
	window->clear();

	//draw stuff

	window->display();
	usleep(this->delay);
}
