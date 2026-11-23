#pragma once 
#include "raylib.h"
#include <vector>
#include "game_structs.h"


class SidePanel{

    


public:
    Entity selected_entity;
    std::vector<Entity> pallete;
    Entity select_entity(Point mouse_pos, const LayoutConfig& layout);
};