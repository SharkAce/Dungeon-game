#ifndef STOPWATCH_H
#define STOPWATCH_H

namespace Dungeon {

class Game;

struct Stopwatch{
	Stopwatch();
	Stopwatch(float stop_time, Dungeon::Game* game_ptr, bool is_loop);
	float stop_time;
	float current_time;
	bool is_stop;
	bool is_loop;
	Game* parent_game;

	bool update();

};

};

#endif
