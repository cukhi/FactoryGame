#include <iostream>
#include "raylib.h"
#include <vector>
#include <cmath>


//header files
#include "main.h"
#include "robot_panel.h"
#include "grid.h"
using namespace std;


Grid::Grid(){
    init_grid_points();
}
void Grid::print_grid_points(){
    for(const auto& gp: grid_points){
        cout << gp.point.x << " " << gp.point.y << " " 
        << gp.entity << " " << gp.has_product << endl;
    }
}
void Grid::init_grid_points()
    {

        int cell_count = 0;
        int full_rows = GRID_WIDTH / CELL_SIZE;  
        int full_cols = GRID_HEIGHT / CELL_SIZE;
        grid_points.reserve(full_cols * full_rows);
        for (int col = 0; col < full_cols; col++)
        {
            for (int row = 0; row < full_rows; row++)
            {
                Grid_Point gp; 
                gp.point.x = row;
                gp.point.y = col;
                gp.entity = none;
                gp.has_product = false;
                gp.color = WHITE;
                grid_points.push_back(gp);
                
            }
        }
        
    }
    
    void Grid::select_cell(Entity_ui selected_entity){
        
        Point pos = get_mouse_position();
        int cell_x = pos.x / CELL_SIZE;
        int cell_y = pos.y / CELL_SIZE;
        
        int cells_per_row = GRID_WIDTH / CELL_SIZE;
        int total_cols = GRID_HEIGHT/CELL_SIZE;
        
        

        
        if(cell_x >= 0 && cell_x < cells_per_row && cell_y >= 0 && cell_y < total_cols){
            int index = (cell_y * cells_per_row) + cell_x;
           // cout << "index of the cell "<<  index << endl;
            
          
            Color selected_color = selected_entity.color;
            grid_points[index].color = selected_color;
        }   
     
       
        


    }
   
    void Grid::build_grid()
    {
        for(const auto& gp : grid_points){
            
            DrawRectangle(gp.point.x * CELL_SIZE, gp.point.y * CELL_SIZE, CELL_SIZE,CELL_SIZE,gp.color);
            DrawRectangleLines(gp.point.x * CELL_SIZE, gp.point.y * CELL_SIZE, CELL_SIZE,CELL_SIZE,LIGHTGRAY);
        }
        
    

       
        
    }
