
enum Entity{
    none,
    robot,
    belt,


};

struct Point{
    int x;
    int y;    
};

struct Grid_Point{
    Point point;
    Entity entity;
    bool has_product;



};