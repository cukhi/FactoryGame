#include <iostream>
#include "raylib.h"
#include <SidePanel.h>


Entity SidePanel::select_entity(Point mouse_pos, const LayoutConfig& layout){
    int local_x = mouse_pos.x - layout.panel_start_x;

    int cell_x = local_x / layout.cell_size;
    int cell_y = mouse_pos.y / layout.cell_size;

    int total_cols = layout.grid_height / layout.cell_size;

    if(local_x < 0 || cell_x >= pallete.size() || cell_y < 0 || cell_y >= total_cols){
        std::cout << "Side Panel Error: position out of bounds "<<std::endl;
        return pallete[3];
    }
    int index = (cell_y * layout.cells_per_row) + cell_x;
    std::cout << "Side Panel: Selected entity index" << index;
    selected_entity = pallete[index];
    return selected_entity;
}


