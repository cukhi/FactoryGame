#pragma once 



enum Entity{
    none,
    robot,
    robot1,
    belt,
    ENTITY_COUNT



};

struct Point{
    int x;
    int y;    
};


Point get_mouse_position();