#include <iostream>
#include "FactoryWorld.h"


FactoryWorld::FactoryWorld(int grid_size,int cell_size,int panel_start_x,int panel_offset){
    this->layout.grid_width = grid_size;
    this->layout.grid_height = grid_size;
    this->layout.cell_size = cell_size;
    this->layout.panel_offset = panel_offset;
    this->layout.panel_start_x = panel_start_x;
}

void FactoryWorld::place_entity(Point mouse_pos,Entity type){
    
}
