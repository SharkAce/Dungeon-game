#include "../Game.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace Dungeon {

void Game::makeSfxSoundDelta(){
	this->sfx_sound_delta.insert({"Hit1", sf::Vector2<int>(0,200)});
}

void Game::startSfx(std::string sound_name){
	this->current_sfx = sound_name;
	if (this->sfx_sound->getStatus() != sf::Sound::Status::Stopped) this->sfx_sound->stop();
	this->sfx_sound->setPlayingOffset(sf::milliseconds(this->sfx_sound_delta.find(sound_name)->second.x));
	this->sfx_sound->play();
}

void Game::updateSfx(){
	float current_time = this->sfx_sound->getPlayingOffset().asMilliseconds();
	if (this->sfx_sound->getStatus() == sf::Sound::Status::Stopped) return;

	if (this->sfx_sound_delta.find(this->current_sfx)->second.y < current_time){
		this->sfx_sound->stop();
	}	
}

}
