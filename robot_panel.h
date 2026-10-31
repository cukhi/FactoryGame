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
    Color color;
    Entity entity;

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
    void  init_entities();

public:
    std::array<Entity_ui,ENTITY_COUNT> entity_inventory;
    
    SideEntities();
    Entity_ui select_entity();
    void ui();
};
