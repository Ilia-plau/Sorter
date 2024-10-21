#include "Game.h"


void Game::Draw() {
	background.Draw1();
	conveyor.Draw3();
	plate.Draw4();
	box.Draw2();
	loaders.Draw5();
}
void Game::Score() {
	if (box.box_x >= 100 && box.box_x <= 200 && box.box_y >= 450 && box.box_y <= 550 && box.GetRandomType() == "rbox") {
		score++;
		box.Reset1();
	}
	if (box.box_x >= 350 && box.box_x <= 450 && box.box_y >= 450 && box.box_y <= 550 && box.GetRandomType() == "bbox") {
		score++;
		box.Reset1();
	}
	if (box.box_x >= 600 && box.box_x <= 700 && box.box_y >= 450 && box.box_y <= 550 && box.GetRandomType() == "gbox") {
		score++;
		box.Reset1();
	}
}

void Game::Update() {
	if (running) {
		box.Update1(loaders.loaders_y,loaders.loaders_x,loaders.loaders_height,loaders.loaders_width);
		loaders.Update2();
	}
}

void Game::Reset() {
	box.Reset1();
	loaders.Reset2();
}

void Game::Stop() {
	if (IsKeyDown(KEY_TAB) && loaders.EventTriggered1(0.15)) {
		running = false;
	}
}