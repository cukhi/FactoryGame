#include <iostream>
#include <vector>
#include <cmath>


//header files
#include "raylib.h"
#include "main.h"
#include "robot_panel.h"
#include "grid.h"
using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

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
    SideEntities side_entities;
    grid.print_grid_points();

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        grid.build_grid();
        side_entities.ui();
        EndDrawing();
        
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            //functions for left click handling based on pos
               grid.select_cell();
        }
    }

    CloseWindow();
}