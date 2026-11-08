#pragma once
#include <array>

struct Robot_struct{
    bool is_working;
    int id;
    float speed;
    float cost;
    Point pos;

};
struct Entity_ui{
    Point pos;
    Entity entity;
    bool is_sprite;
    union {
        Color color;
        Rectangle sprite; //Rectangle is the texture from the map
        
    }render_data;

};
struct Belt{
    bool has_item;
    Point pos;
};


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
