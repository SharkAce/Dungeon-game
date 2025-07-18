#include "../Game.hpp"
#include <SFML/Graphics/Rect.hpp>


namespace Dungeon {

void Game::makeSfxSoundMap(){
	this->sfx_sound_map.insert({"Hit1", sfx_instance(2084,2300,17.f)});
	this->sfx_sound_map.insert({"Hit2", sfx_instance(2120,2500,40.f)});
	this->sfx_sound_map.insert({"PotionPickup", sfx_instance(0,300,30.f)});
	this->sfx_sound_map.insert({"FireBurst", sfx_instance(1085,1600,15.f)});
	this->sfx_sound_map.insert({"KeyPickup", sfx_instance(625,800,30.f)});
	this->sfx_sound_map.insert({"SwordSwing", sfx_instance(880,1000,18.f)});
}

void Game::startSfx(std::string sound_name){
	if (this->sfx_sound.getStatus() != sf::Sound::Status::Stopped) this->sfx_sound.stop();

	sfx_instance& sfx = this->sfx_sound_map.find(sound_name)->second;
	this->current_sfx = sound_name;
	this->sfx_sound.setPlayingOffset(sf::milliseconds(sfx.a));
	this->sfx_sound.setVolume(sfx.volume);
	this->sfx_sound.play();
}

void Game::updateSfx(){
	if (this->sfx_sound.getStatus() == sf::Sound::Status::Stopped) return;

	float current_time = this->sfx_sound.getPlayingOffset().asMilliseconds();
	sfx_instance& sfx = this->sfx_sound_map.find(this->current_sfx)->second;
	if (current_time > sfx.b){
		this->sfx_sound.stop();
	}	
}

}
