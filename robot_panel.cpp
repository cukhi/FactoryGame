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

     entity_inventory[0] = r;
     entity_inventory[1] = r1;
     entity_inventory[2] = b;
}
    SideEntities::SideEntities(){
        init_entities();

       
        
    }

    
    void SideEntities::select_entity(){
        Point pos = get_mouse_position();


    }
    void SideEntities::ui(){
        const int GRID_WIDTH = 300;
        const int GRID_HEIGHT = 100;
        const int CELL_SIZE = 100;
        int offset = 20;
        int x = 1050;
        int y = 0;
        for(const auto& entity : entity_inventory){
            int curr_x = x + offset + (entity.pos.x * CELL_SIZE);
            DrawRectangle(curr_x, y,CELL_SIZE,CELL_SIZE,entity.color);
            DrawRectangleLines(curr_x,y,CELL_SIZE,CELL_SIZE,LIGHTGRAY);
        }
    }

