#include "../Game.hpp"

namespace Dungeon {

float Game::degToRad(float degree){
	return degree / 180 * M_PI; 
};

float Game::radToDeg(float radian){
	return radian * 180 / M_PI;
};


};
