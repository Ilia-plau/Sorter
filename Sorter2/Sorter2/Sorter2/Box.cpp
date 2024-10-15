#include "Box.h"


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

void Box::Draw2(){
	if (GetRandomType() == "rbox") {
		DrawTexture(boxr, box_x, box_y, WHITE);
	}
	if (GetRandomType() == "bbox") {
		DrawTexture(boxb, box_x, box_y, WHITE);
	}
	if (GetRandomType() == "gbox") {
		DrawTexture(boxg,box_x,box_y, WHITE);
	}
}

void Box::Update1() {
	if ((2 * loaders_y + loaders_height) / 2 - 50 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_W) && EventTriggered2(0.15) && box_y - 100 >= 25) {
			box_y -= speed;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 + 50 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_S) && EventTriggered2(0.15) && box_y + 150 <= 700) {
			box_y += speed;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 - 50 == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_A) && EventTriggered2(0.15) && box_x - 50 >= 25) {
			box_x -= speed;
		}
	}
	if ((2 * loaders_y + loaders_height) / 2 == (2 * box_y + box_height) / 2 && (2 * loaders_x + loaders_width) / 2 + 50 == (2 * box_x + box_width) / 2) {
		if (IsKeyDown(KEY_D) && EventTriggered2(0.15) && box_x + 150 <= 850) {
			box_x += speed;
		}
	}
	if (box_x < 200 && box_y == 150) {
		box_x += 0.5;
	}

}

void Box::Reset1() {
	box_x = 50;
	box_y = 150;
	box_width = 50;
	box_height = 50;
	speed = 50;
	count = 0;
}
