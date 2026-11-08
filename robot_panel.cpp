#include <iostream>
#include <vector>
#include <cmath>
#include <array>


//header files
#include "raylib.h"
#include "main.h"
#include "sprites.h"
#include "robot_panel.h"
using namespace std;







void SideEntities::init_entities(vector<Rectangle> s){
    std::vector<Rectangle> sprites = s;
    if (sprites.empty()) {
        cout << "Error at init_entities: the sprites vector is empty" << endl;
    }

    Entity_ui r;
    r.render_data.sprite = sprites[1];
    r.is_sprite = true;
    r.entity = robot;
    r.pos.x = 1;
    r.pos.y = 0;

    Entity_ui r1;
    r1.render_data.sprite = sprites[2];
    r1.is_sprite = true;
    r1.entity = robot1;
    r1.pos.x = 2;
    r1.pos.y = 0;

    Entity_ui b;
    b.render_data.sprite = sprites[0];
    b.is_sprite = true;
    b.entity = belt;
    b.pos.x = 0;
    b.pos.y = 0;

    Entity_ui en_none;
    en_none.render_data.color = WHITE;
    en_none.is_sprite = false;
    en_none.entity = none;
    en_none.pos.x = 3;
    en_none.pos.y = 0;

    entity_inventory[belt] = b;
    entity_inventory[robot] = r;
    entity_inventory[robot1] = r1;
    entity_inventory[none] = en_none;
}
    SideEntities::SideEntities(vector<Rectangle> s){
        init_entities(s);

       
        
    }

    
    Entity SideEntities::select_entity(){
        Point pos = get_mouse_position();
    
    int panel_start_x = 1050;
    int local_x = pos.x - panel_start_x;
    
    int cell_x = local_x / CELL_SIZE;
    int cell_y = pos.y / CELL_SIZE;
    
    int cells_per_row = GRID_WIDTH / CELL_SIZE;
    int total_cols = GRID_HEIGHT / CELL_SIZE;
    
    if (local_x < 0 || cell_x >= entity_inventory.size() || cell_y < 0 || cell_y >= total_cols) {
        cout << "Error: position out of bounds" << endl;
        return entity_inventory[3].entity; // Return 'none'
    }

    int index = (cell_y * cells_per_row) + cell_x; 
    
    cout << "Selected entity index: " << index << endl;
    return entity_inventory[index].entity;
    }
         
    void SideEntities::ui(Texture2D master_texture){
        
        int offset = 20;
        int x = 1050;
        int y = 0;
        for(const auto& entity : entity_inventory){
            int curr_x = x + offset + (entity.pos.x * CELL_SIZE);
            if (entity.is_sprite) {
                Vector2 draw_pos = { float(curr_x),(float)y };
                DrawTextureRec(master_texture, entity.render_data.sprite, draw_pos, WHITE);
            }
            else {
               DrawRectangle(curr_x, y, CELL_SIZE, CELL_SIZE, entity.render_data.color);
            }
         
            DrawRectangleLines(curr_x,y,CELL_SIZE,CELL_SIZE,LIGHTGRAY);
        }
    }
    
    

