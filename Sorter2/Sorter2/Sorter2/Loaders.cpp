#include "Loaders.h"

double lastUpdateTime1 = 0;

Textures textures1 = Textures();
//Box box2 = Box();
Loaders loaders1 = Loaders();
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

void Draw5(){
	DrawTexture(textures1.loader, loaders1.loaders_x, loaders1.loaders_y, WHITE);
}

void Update2() {
	if (IsKeyDown(KEY_W) && EventTriggered1(0.15) && loaders1.loaders_y - 50 >= 25) {
		loaders1.loaders_y -= loaders1.speed;
	}
	if (IsKeyDown(KEY_S) && EventTriggered1(0.15) && loaders1.loaders_y + 100 <= 700) {
		loaders1.loaders_y += loaders1.speed;
	}
	if (IsKeyDown(KEY_A) && EventTriggered1(0.15) && loaders1.loaders_x >= 25) {
		loaders1.loaders_x -= loaders1.speed;
	}
	if (IsKeyDown(KEY_D) && EventTriggered1(0.15) && loaders1.loaders_x + 100 <= 850) {
		loaders1.loaders_x += loaders1.speed;
	}
	if (loaders1.loaders_y == 150 && loaders1.loaders_x < 200) {
		loaders1.loaders_x += 0.5;
	}
}

void Reset2() {
	loaders1.loaders_x = GetScreenWidth() / 2 - 25;
	loaders1.loaders_y = (GetScreenHeight() - 50) / 2 - 25;
	loaders1.speed = 50;
}