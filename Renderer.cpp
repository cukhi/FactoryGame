#include <iostream>
#include "raylib.h"
#include "Renderer.h"




void Renderer::draw_world(const FactoryWorld& world, const AssetRegistry& assets){
    FactoryWorld factory_world();

    
}

void Renderer::draw_panel(const SidePanel& panel,const LayoutConfig& layout, const AssetRegistry& assets){
    
    for(int i =0; i<assets.visuals.size(); i++){
        int curr_x = layout.panel_start_x + layout.panel_offset + i * layout.cell_size; 
        if(assets.visuals[i].is_sprite){
            Vector2 draw_pos = {(float)curr_x,0};
            DrawTextureRec(assets.master_texture,assets.visuals[i].render_data.sprite,draw_pos,WHITE);

        }else{
            DrawRectangle(curr_x,0,layout.cell_size,layout.cell_size,assets.visuals[i].render_data.color);

        }
        DrawRectangleLines(curr_x,0,layout.cell_size,layout.cell_size,LIGHTGRAY);
    }
}