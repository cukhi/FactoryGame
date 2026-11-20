#pragma once
#include <vector>
#include <unordered_map>

#include "main.h"
#include "robot_panel.h"

enum Directions {
	e,
	n,
	w,
	s,
	
	
};

struct Belt_struct {
	int index;
	bool has_product;
	
	Directions direction;
	std::unordered_map<int,std::vector<bool>> neighbors;


};

class Belt {
	Belt_struct belt_struct;
	std::vector<Belt_struct> belts;
	int width;
	int height;
	int cell_size;

public:
	


	Belt();
	void generate_belt_line(std::vector<Grid_Point>& gp, int cells_per_row);
	std::unordered_map<int, std::vector<bool>> check_neighbors(std::vector<Grid_Point>& gp, int center, int cells_per_row);
	
};
