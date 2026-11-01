#include <iostream>
#include "raylib.h"
#include "main.h"
#include <vector>
using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

class Grid
{
private:
    vector<Grid_Point> grid_points;
    const int GRID_WIDTH = 1002;
    const int GRID_HEIGHT = 702;
    const int CELL_SIZE = 100;

   

   

   

public:
    Grid() {
        init_grid_points();
    }
    void print_grid_points() const{
       for(const auto& gp : grid_points) {
           cout << gp.entity << " "
               << gp.has_product << " x: "
               << gp.point.x << " y: "
               << gp.point.y << endl;
        }
       
}
    void init_grid_points()
    {

        int cell_count = 0;
        int full_cols = GRID_WIDTH / CELL_SIZE;  
        int full_rows = GRID_HEIGHT / CELL_SIZE;

        for (int col = 0; col < full_cols; col++)
        {
            
            for (int row = 0; row < full_rows; row++)
            {
              
                Grid_Point gp; 
                gp.point.x = col;
                gp.point.y = row;
                gp.entity = none;
                gp.has_product = false;
                gp.color = WHITE;
                grid_points.push_back(gp);
                
            }
        }
      
        
        
    }
    Point get_mouse_position()
    {
        Point mouse_pos;
        mouse_pos.x = GetMouseX();
        mouse_pos.y = GetMouseY();

        return mouse_pos;
    }
    void get_cell_by_position() {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

            Point pos = get_mouse_position();
            int x_cell = floor(pos.x / CELL_SIZE);
            int y_cell = floor(pos.y / CELL_SIZE);
            cout << x_cell << " " << y_cell << endl;
            for (auto& gp : grid_points) {
                if (gp.point.x == x_cell && gp.point.y == y_cell) {
                    
                    gp.color = RED;
                }
            }
        }
        
    }
    
    //UI methods

    void build_grid()
    {
        for (const auto& gp : grid_points) {
           
            DrawRectangle(gp.point.x * CELL_SIZE, gp.point.y * CELL_SIZE, CELL_SIZE, CELL_SIZE,gp.color);
            DrawRectangleLines(gp.point.x * CELL_SIZE, gp.point.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, LIGHTGRAY);
           
        }
        




    
    }
    void color_cells() {

    }
    
};



int main()
{
    // Program Properties
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FactoryGame");
    SetTargetFPS(60);

    // Objects definitions
    Grid grid;
   

   

  

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        grid.build_grid();
        grid.get_cell_by_position();
        EndDrawing();
        
        
        
    
    }

    CloseWindow();
}