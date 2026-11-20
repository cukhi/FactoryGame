#pragma once


#include "raylib.h"
#include "robot_panel.h"



class Grid{
    private:
        
        
    public:

       
        std::vector<Grid_Point> grid_points;
        const int GRID_WIDTH = 1002;
        const int GRID_HEIGHT = 702;
        const int CELL_SIZE = 100;
        const  int cells_per_row = GRID_WIDTH / CELL_SIZE;
        
        Grid();
        
        void init_grid_points();
        void select_cell(Entity selected_entity);
        
        void build_grid(const std::array<Entity_ui, ENTITY_COUNT>& dic, Texture2D master_sheet);

};