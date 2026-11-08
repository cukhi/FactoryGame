#pragma once
#include <vector>


#include "main.h"

enum Directions {
	east,
	norh,
	west,
	south
};

struct Belt_struct {
	Entity en;
	bool has_product;
	int facing;
	std::vector<int> neighbors;


};

class Belt {
	Belt_struct belt;

	int width;
	int height;
	int cell_size;

public:
	vector<int> belt_index;


	Belt(int width, int height, int cell_size);
	void generate_belt_line();

};
