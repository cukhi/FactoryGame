#pragma once
#include "raylib.h"
#include "game_structs.h"
#include <array>
#include <vector>
struct EntityVisual{
    bool is_sprite;
    union {
        Color color;
        Rectangle sprite;
    }render_data;
};


class AssetRegistry{
   

public:
 Texture2D master_texture;
    std::array<EntityVisual,ENTITY_COUNT> visuals;

    AssetRegistry();
    std::vector<Rectangle> cut_master_to_sprites(int count);
    void load(const char* frame_path,int frame_count);


};