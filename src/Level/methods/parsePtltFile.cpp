#include "../Level.hpp"
#include "../../Game/Game.hpp"
#include <vector>

namespace Dungeon {

void Level::parsePtltFile(std::string file_path){
	std::fstream file;
	std::string current_line;
	std::string segment;
	std::vector<int> line_data;
	std::vector<std::vector<int>*> data_array;

	//line 1
	std::vector<int> level_info;
	data_array.push_back(&level_info);
	
	//line 2
	std::vector<int> bg_tile_ids;
	data_array.push_back(&bg_tile_ids);
	
	//line 3
	std::vector<int> bg_tile_rot;
	data_array.push_back(&bg_tile_rot);
	
	//line 4
	std::vector<int> fg_tile_ids;
	data_array.push_back(&fg_tile_ids);
	
	//line 5
	std::vector<int> fg_tile_rot;
	data_array.push_back(&fg_tile_rot);
	
	//line 6
	std::vector<int> solid_tiles;
	data_array.push_back(&solid_tiles);


	int line_num = 0;
	float game_sprite_size = this->parent_game->sprite_size*this->sprite_scale;

	file.open(file_path,std::ios::in);
	
	while(std::getline(file,current_line)){
		std::stringstream line_stream(current_line);
		while(std::getline(line_stream, segment, ',')){
			line_data.push_back(std::stoi(segment));
		}

		*(data_array[line_num]) = line_data;

		line_data.clear();
		line_num ++;
	}
	
	this->tiles_x = level_info[0];
	this->tiles_y = level_info[1];

	for (int i=0; i<(this->tiles_x*this->tiles_y); i++){

		if (bg_tile_ids[i] != -1){
			this->bg_tiles.push_back(Tile(
				this->parent_game,
				bg_tile_ids[i],
				bg_tile_rot[i],
				this->sprite_scale,
				sf::Vector2i(i%this->tiles_x,i/this->tiles_x)
			));
		};

		if (fg_tile_ids[i] != -1){
			this->fg_tiles.push_back(Tile(
				this->parent_game,
				fg_tile_ids[i],
				fg_tile_rot[i],
				this->sprite_scale,
				sf::Vector2i(i%this->tiles_x,i/this->tiles_x)
			));	
		}
			
			if (solid_tiles[i] == 1) {
				this->solid_tiles_rect.push_back(sf::FloatRect(
					(i%this->tiles_x)*game_sprite_size,
					(i/this->tiles_x)*game_sprite_size,
					game_sprite_size,
					game_sprite_size
				));
			}
		}


	file.close();
};

};
