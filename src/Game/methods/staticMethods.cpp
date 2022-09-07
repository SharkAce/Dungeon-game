#include "../Game.hpp"

namespace Dungeon {

float Game::degToRad(float degree){
	return degree / 180 * M_PI; 
};

float Game::RadToDeg(float radian){
	return radian * 180 / M_PI;
};


};
