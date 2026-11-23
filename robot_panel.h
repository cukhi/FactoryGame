#pragma once
#include <array>
#include "game_structs.h"
#include "raylib.h"





class SideEntities{
private:
    const int GRID_WIDTH = 300;
    const int GRID_HEIGHT = 100;
    const int CELL_SIZE = 100;
    bool selected = false;
   
    void  init_entities(std::vector<Rectangle> s);
    
    

public:
    std::array<Entity_ui,ENTITY_COUNT> entity_inventory;
    
    SideEntities(std::vector<Rectangle> s);
  
    Entity select_entity();
    void ui(Texture2D master_texture);
};
