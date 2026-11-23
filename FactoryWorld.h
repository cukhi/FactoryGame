#pragma once 
#include "raylib.h"
#include <vector>
#include "game_structs.h"





class FactoryWorld{
private:
    LayoutConfig layout;
    std::vector<Grid_Point> grid_points;
    std::vector<Belt_struct> belts;
    std::vector<Robot_struct> robots;

public:
    FactoryWorld(int grid_size,int cell_size,int panel_start_x,int panel_offset);
    void place_entity(Point mouse_pos,Entity type);
    void remove_entity(Point mouse_pos);
    void rotate_entity(Point mouse_pos);

};

