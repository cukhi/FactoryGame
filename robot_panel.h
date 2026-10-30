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
    std::array<Entity_ui,ENTITY_COUNT -1> entity_inventory;
    void  init_entities();

public:
    SideEntities();
    void select_entity();
    void ui();
};
