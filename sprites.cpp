#include <iostream>
#include <vector>

#include "raylib.h"


#include "sprites.h"
using namespace std;





	

	SpriteMapHandler::SpriteMapHandler() {

		
	}

	void SpriteMapHandler::cut_master_to_sprites(int count) {
		int sprite_size = master_texture.width / count;

		for (int i = 0; i < count; i++) {
			Rectangle frame;
			frame.x = i * sprite_size;
			frame.y = 0.0f;
			frame.width = sprite_size;
			frame.height = sprite_size;
			sprite_frames.push_back(frame);
		}

	}
	void SpriteMapHandler::DrawFrame(int frame_index, int x, int y) {
		if (frame_index >= 0 && frame_index < sprite_frames.size()) {
			Vector2 pos = { x,y };
			DrawTextureRec(master_texture, sprite_frames[frame_index], pos, WHITE);
		}
	}
	void SpriteMapHandler::Load(const char * frame_path, int frame_count) {
		Image image = LoadImage(frame_path);
		Texture2D sprite_map = LoadTextureFromImage(image);
		master_texture = sprite_map;
		cut_master_to_sprites(frame_count);
	}




