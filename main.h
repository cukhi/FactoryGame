#pragma once 



enum Entity{
    belt,
    robot,
    robot1,
    none,
    ENTITY_COUNT



};

struct Point{
    int x;
    int y;    
};


Point get_mouse_position();