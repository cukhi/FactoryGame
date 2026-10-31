#pragma once




struct Grid_Point{
    Point point;
    Entity entity;
    bool has_product;
    Color color;



};

class Grid{
    private:
        std::vector<Grid_Point> grid_points;
        const int GRID_WIDTH = 1002;
        const int GRID_HEIGHT = 702;  
        const int CELL_SIZE = 100;
    public:
        Grid();
        void print_grid_points();
        void init_grid_points();
        void select_cell(Entity_ui selected_entity);
        void select_cell();
        void build_grid();

};