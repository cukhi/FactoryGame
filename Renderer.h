#pragma once
#include "raylib.h"
#include "FactoryWorld.h"
#include "SidePanel.h"
#include "AssetRegistry.h"
#include "game_structs.h"

class Renderer{

    public:
        void draw_world(const FactoryWorld& world, const AssetRegistry& assets);
        void draw_panel(const SidePanel& panel,const LayoutConfig& layout, const AssetRegistry& assets);
};