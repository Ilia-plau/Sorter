#include "Loaders.h"

double lastUpdateTime1 = 0;

bool EventTriggered1(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime1 >= interval)
	{
		lastUpdateTime1 = currentTime;
		return true;
	}
	return false;
}

void Loaders::Draw5(){
	DrawTexture(loader, loaders_x, loaders_y, WHITE);
}

void Loaders::Update2() {
	if (IsKeyDown(KEY_W) && EventTriggered1(0.15) && loaders_y - 50 >= 25) {
		loaders_y -= speed;
	}
	if (IsKeyDown(KEY_S) && EventTriggered1(0.15) && loaders_y + 100 <= 700) {
		loaders_y += speed;
	}
	if (IsKeyDown(KEY_A) && EventTriggered1(0.15) && loaders_x >= 25) {
		loaders_x -= speed;
	}
	if (IsKeyDown(KEY_D) && EventTriggered1(0.15) && loaders_x + 100 <= 850) {
		loaders_x += speed;
	}
	if (loaders_y == 150 && loaders_x < 200) {
		loaders_x += 0.5;
	}
}

void Loaders::Reset2() {
	loaders_x = GetScreenWidth() / 2 - 25;
	loaders_y = (GetScreenHeight() - 50) / 2 - 25;
	speed = 50;
}