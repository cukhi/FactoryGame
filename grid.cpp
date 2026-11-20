#include <iostream>
#include "raylib.h"
#include <vector>
#include <cmath>


//header files
#include "main.h"
#include "game_structs.h"
#include "belt.h"
#include "grid.h"
using namespace std;

Belt belts;

Grid::Grid(){
    init_grid_points();
   
    belts.generate_belt_line(grid_points, cells_per_row);

}

void Grid::init_grid_points()
    {

       
         
        int full_cols = GRID_HEIGHT / CELL_SIZE;
        int total_cells = cells_per_row * full_cols;
        grid_points.reserve(cells_per_row * full_cols);
        for (int i = 0; i < total_cells; i++) {
            Grid_Point gp;
            gp.entity = none;
            gp.has_product = false;
            grid_points.push_back(gp);
        }
        
    }
    
    void Grid::select_cell(Entity selected_entity){
        
        Point pos = get_mouse_position();
        int cell_x = pos.x / CELL_SIZE;
        int cell_y = pos.y / CELL_SIZE;
        
        int cells_per_row = GRID_WIDTH / CELL_SIZE;
        int total_cols = GRID_HEIGHT/CELL_SIZE;
        
        

        
        if(cell_x >= 0 && cell_x < cells_per_row && cell_y >= 0 && cell_y < total_cols){
            int index = (cell_y * cells_per_row) + cell_x;
            if (grid_points[index].entity == belt) {
                grid_points[index].entity = belt;
            }
            else {
                grid_points[index].entity = selected_entity;
                cout << index;
            }
           
          
            
        }   
     
       
        


    }
   
    void Grid::build_grid(const std::array<Entity_ui, ENTITY_COUNT>& dic, Texture2D master_sheet) {
        int cells_per_row = GRID_WIDTH / CELL_SIZE;
       
        for (int i = 0; i < grid_points.size(); i++) {
            int grid_x = i % cells_per_row;
            int grid_y = i / cells_per_row;

            int pixel_x = grid_x * CELL_SIZE;
            int pixel_y = grid_y * CELL_SIZE;


            Entity curr_entity = grid_points[i].entity;

            Entity_ui visual = dic[curr_entity];
            
           
            
            

            if (visual.is_sprite) {
                Vector2 draw_pos = { (float)pixel_x, (float)pixel_y };
                
                DrawTextureRec(master_sheet, visual.render_data.sprite, draw_pos, WHITE);
            }
            else {
                
                DrawRectangle(pixel_x, pixel_y, CELL_SIZE, CELL_SIZE, visual.render_data.color);
            }
            
            DrawText(TextFormat("%i %i", grid_x,grid_y), pixel_x + 3, pixel_y + 3, 8, BLACK);
            DrawRectangleLines(pixel_x, pixel_y, CELL_SIZE, CELL_SIZE, LIGHTGRAY);
        
        }
    }
    
        
        
    

       
        
    
