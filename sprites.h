#pragma once

#include <vector>

#include "raylib.h"
class SpriteMapHandler {
private:
	
	

	
	void cut_master_to_sprites(int count);

public:
	Texture2D master_texture;
	std::vector<Rectangle> sprite_frames;
	SpriteMapHandler();
	void Load(const char * frame_path, int frame_count);
	void DrawFrame(int frame_index, int x, int y);

};


