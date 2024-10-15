#include "Game.h"

void Game::Draw() {
	Draw1();
	Draw3();
	Draw4();
	Draw2();
	Draw5();
}

void Game::Score() {
	if (box_x >= 100 && box_x <= 200 && box_y >= 450 && box_y <= 550 && GetRandomType() == "rbox") {
		score++;
		Reset1();
	}
	if (box_x >= 350 && box_x <= 450 && box_y >= 450 && box_y <= 550 && GetRandomType() == "bbox") {
		score++;
		Reset1();
	}
	if (box_x >= 600 && box_x <= 700 && box_y >= 450 && box_y <= 550 && GetRandomType() == "gbox") {
		score++;
		Reset1();
	}
}

void Game::Update() {
	if (running) {
		Update1();
		Update2();
	}
}

void Game::Reset() {
	Reset1();
	Reset2();
}