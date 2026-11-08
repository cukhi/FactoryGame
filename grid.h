#pragma once




struct Grid_Point{
    Entity entity;
    bool has_product;
   



};

class Grid{
    private:
        std::vector<Grid_Point> grid_points;
        
    public:
        const int GRID_WIDTH = 1002;
        const int GRID_HEIGHT = 702;
        const int CELL_SIZE = 100;
        Grid();
        
        void init_grid_points();
        void select_cell(Entity selected_entity);
        
        void Grid::build_grid(const std::array<Entity_ui, ENTITY_COUNT>& dic, Texture2D master_sheet);

};