#pragma once

#include "raylib.h"

enum Entity {
    belt,
    robot,
    robot1,
    none,
    ENTITY_COUNT



};
struct Grid_Point {
    Entity entity;
    bool has_product;




};

struct Entity_ui {
    Point pos;
    Entity entity;
    bool is_sprite;
    union {
        Color color;
        Rectangle sprite; //Rectangle is the texture from the map

    }render_data;

};