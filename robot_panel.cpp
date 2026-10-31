#include <iostream>
#include <vector>
#include <cmath>
#include <array>


//header files
#include "raylib.h"
#include "main.h"
#include "robot_panel.h"

using namespace std;





void SideEntities::init_entities(){

    Entity_ui r;
    r.color = RED;
    r.entity = robot;
    r.pos.x = 0;
    r.pos.y = 0;

    Entity_ui r1;
    r1.color = GREEN;
    r1.entity = robot1;
    r1.pos.x = 1;
    r1.pos.y = 0;

    Entity_ui b;
    b.color = BLACK;
    b.entity = belt;
    b.pos.x = 2;
    b.pos.y = 0;

    Entity_ui en_none;
    en_none.color = GRAY;
    en_none.entity = none;
    en_none.pos.x = 3;
    en_none.pos.y = 0;

     entity_inventory[0] = r;
     entity_inventory[1] = r1;
     entity_inventory[2] = b;
     entity_inventory[3] = en_none;
}
    SideEntities::SideEntities(){
        init_entities();

       
        
    }

    
    Entity_ui SideEntities::select_entity(){
        Point pos = get_mouse_position();
    
    int panel_start_x = 1050;
    int local_x = pos.x - panel_start_x;
    
    int cell_x = local_x / CELL_SIZE;
    int cell_y = pos.y / CELL_SIZE;
    
    int cells_per_row = GRID_WIDTH / CELL_SIZE;
    int total_cols = GRID_HEIGHT / CELL_SIZE;
    
    if (local_x < 0 || cell_x >= entity_inventory.size() || cell_y < 0 || cell_y >= total_cols) {
        cout << "Error: position out of bounds" << endl;
        return entity_inventory[3]; // Return 'none'
    }

    int index = (cell_y * cells_per_row) + cell_x; 
    
    cout << "Selected entity index: " << index << endl;
    return entity_inventory[index];
        }
         
        
        
        
        
       
    
    void SideEntities::ui(){
        
        int offset = 20;
        int x = 1050;
        int y = 0;
        for(const auto& entity : entity_inventory){
            int curr_x = x + offset + (entity.pos.x * CELL_SIZE);
            DrawRectangle(curr_x, y,CELL_SIZE,CELL_SIZE,entity.color);
            DrawRectangleLines(curr_x,y,CELL_SIZE,CELL_SIZE,LIGHTGRAY);
        }
    }
    

