#pragma once
#include <vector>
#include <unordered_map>
#include "game_structs.h"
#include "main.h"
#include "robot_panel.h"






class Belt {
	Belt_struct belt_struct;
	std::vector<Belt_struct> belts;
	int width;
	int height;
	int cell_size;

public:
	


	Belt();
	void generate_belt_line(std::vector<Grid_Point>& gp, int cells_per_row);
	neighbors_map check_neighbors(std::vector<Grid_Point>& gp, int center, int cells_per_row);
	void set_directions(Belt_struct &bs);
};
