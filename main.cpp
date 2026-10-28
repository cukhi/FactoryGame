#include <iostream>
#include "raylib.h"
#include "main.h"
#include <vector>
using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

class Grid
{

    Point mouse_pos;

   
protected:
    vector<Grid_Point> grid_points;

    const int GRID_WIDTH = 1002;
    const int GRID_HEIGHT = 702;
    const int CELL_SIZE = 100;
    

public:
vector<Grid_Point> init_grid_points()
    {

        int cell_count = 0;
        int full_cols = GRID_WIDTH / CELL_SIZE;  
        int full_rows = GRID_HEIGHT / CELL_SIZE;

        for (int col = 0; col < full_cols; col++)
        {
            for (int row = 0; row < full_rows; row++)
            {
                Grid_Point gp; 
                gp.point.x = row;
                gp.point.y = col;
                gp.entity = none;
                gp.has_product = false;
                
            }
        }
        
    }
    Point get_mouse_position()
    {
        mouse_pos.x = GetMouseX();
        mouse_pos.y = GetMouseY();

        cout << "Position is: " << mouse_pos.x << " " << mouse_pos.y << endl;
        return mouse_pos;
    }
};

class UI : public Grid
{

  

public:
    void build_grid()
    {
        
        for (int x = 0; x < GRID_WIDTH; x += CELL_SIZE)
        {
            DrawLine(x, 0, x, GRID_HEIGHT, LIGHTGRAY);
        }

       
        for (int y = 0; y < GRID_HEIGHT; y += CELL_SIZE)
        {
            DrawLine(0, y, GRID_WIDTH, y, LIGHTGRAY);
        }

       
        
    }
};

int main()
{
    // Program Properties
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FactoryGame");
    SetTargetFPS(60);

    // Objects definitions
    Grid grid;
    UI grid_ui;

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        grid_ui.build_grid();
        EndDrawing();
        grid.init_grid_points();
        
    
    }

    CloseWindow();
}