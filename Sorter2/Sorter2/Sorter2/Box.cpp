#include "Box.h"

Textures textures2 = Textures();
Box box2 = Box();
Loaders loaders2 = Loaders();
double lastUpdateTime2 = 0;

bool EventTriggered2(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime2 >= interval)
	{
		lastUpdateTime2 = currentTime;
		return true;
	}
	return false;
}

void Draw2(){
	if (box2.GetRandomType() == "rbox") {
		DrawTexture(textures2.boxr, box2.box_x, box2.box_y, WHITE);
	}
	if (box2.GetRandomType() == "bbox") {
		DrawTexture(textures2.boxb, box2.box_x, box2.box_y, WHITE);
	}
	if (box2.GetRandomType() == "gbox") {
		DrawTexture(textures2.boxg, box2.box_x, box2.box_y, WHITE);
	}
}

void Update1() {
	if ((2 * loaders2.loaders_y + loaders2.loaders_height) / 2 - 50 == (2 * box2.box_y + box2.box_height) / 2 && (2 * loaders2.loaders_x + loaders2.loaders_width) / 2 == (2 * box2.box_x + box2.box_width) / 2) {
		if (IsKeyDown(KEY_W) && EventTriggered2(0.15) && box2.box_y - 100 >= 25) {
			box2.box_y -= box2.speed;
		}
	}
	if ((2 * loaders2.loaders_y + loaders2.loaders_height) / 2 + 50 == (2 * box2.box_y + box2.box_height) / 2 && (2 * loaders2.loaders_x + loaders2.loaders_width) / 2 == (2 * box2.box_x + box2.box_width) / 2) {
		if (IsKeyDown(KEY_S) && EventTriggered2(0.15) && box2.box_y + 150 <= 700) {
			box2.box_y += box2.speed;
		}
	}
	if ((2 * loaders2.loaders_y + loaders2.loaders_height) / 2 == (2 * box2.box_y + box2.box_height) / 2 && (2 * loaders2.loaders_x + loaders2.loaders_width) / 2 - 50 == (2 * box2.box_x + box2.box_width) / 2) {
		if (IsKeyDown(KEY_A) && EventTriggered2(0.15) && box2.box_x - 50 >= 25) {
			box2.box_x -= box2.speed;
		}
	}
	if ((2 * loaders2.loaders_y + loaders2.loaders_height) / 2 == (2 * box2.box_y + box2.box_height) / 2 && (2 * loaders2.loaders_x + loaders2.loaders_width) / 2 + 50 == (2 * box2.box_x + box2.box_width) / 2) {
		if (IsKeyDown(KEY_D) && EventTriggered2(0.15) && box2.box_x + 150 <= 850) {
			box2.box_x += box2.speed;
		}
	}
	if (box2.box_x < 200 && box2.box_y == 150) {
		box2.box_x += 0.5;
	}

}

void Reset1() {
	box2.box_x = 50;
	box2.box_y = 150;
	box2.box_width = 50;
	box2.box_height = 50;
	box2.speed = 50;
	box2.count = 0;
}
