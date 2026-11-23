#pragma once
#include <unordered_map>
#include "raylib.h"

struct LayoutConfig{
    int grid_width;
    int grid_height;
    int cell_size;
    int cells_per_row = grid_width / cell_size; //assuming cells are squares 
    int panel_start_x;
    int panel_offset;
};
struct Point{
    int x;
    int y;    
};



using neighbors_map = std::unordered_map<int,std::vector<bool>>;
struct Belt_struct {
	int index;
	bool has_product;
	
	Directions direction;
	neighbors_map neighbors;


};

enum Directions {
	e,
	n,
	w,
	s,
	ne,
	nw,
	se,
	sw
	
	
};

struct Robot_struct{
    bool is_working;
    int id;
    float speed;
    float cost;
    Point pos;
    Directions direction;

};
enum Entity {
    belt,
    robot,
    robot1,
    none,
    ENTITY_COUNT



};
struct Grid_Point {
    Entity entity;
    bool has_product;




};

struct Entity_ui {
    Point pos;
    Entity entity;
    bool is_sprite;
    union {
        Color color;
        Rectangle sprite; //Rectangle is the texture from the map

    }render_data;

};