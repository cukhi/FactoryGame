#include <iostream>
#include <vector>
#include <cmath>


//header files
#include "raylib.h"
#include "main.h"
#include "robot_panel.h"
#include "grid.h"
#include "sprites.h"
#include "belt.h"
using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
const int SPRITE_MAP_SIZE = 3;

Point get_mouse_position()
{
    Point mouse_pos;
    mouse_pos.x = GetMouseX();
    mouse_pos.y = GetMouseY();

    return mouse_pos;
}


int main()
{
    // Program Properties
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FactoryGame");
    SetTargetFPS(60);
    
   
    

    // Objects definitions
    Grid grid;
    SpriteMapHandler sprites;
    sprites.Load("sprites/Frame1.png",SPRITE_MAP_SIZE);
    SideEntities side_entities(sprites.sprite_frames);
   

    Entity current_entity = side_entities.entity_inventory[3].entity;
   
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
      
        grid.build_grid(side_entities.entity_inventory,sprites.master_texture);
        
        side_entities.ui(sprites.master_texture);
        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            //functions for left click handling based on pos
            int mouse_x = GetMouseX();
            

            if (mouse_x >= 1050) {
                current_entity = side_entities.select_entity();
            }

            else {
               
                grid.select_cell(current_entity);
            }





        }
    }

    CloseWindow();
}