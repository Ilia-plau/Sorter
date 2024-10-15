#include "Game.h"

//Textures textures0 = Textures();
Loaders loaders0 = Loaders();
Box box1 = Box();
Plate plate0 = Plate();
Conveyor conveyor0 = Conveyor();
Background background1 = Background();
Game game1 = Game();


void Draw() {
	background1.Draw1();
	conveyor0.Draw3();
	plate0.Draw4();
	box1.Draw2();
	loaders0.Draw5();
}

void Score() {
	if (box1.box_x >= 100 && box1.box_x <= 200 && box1.box_y >= 450 && box1.box_y <= 550 && box1.GetRandomType() == "rbox") {
		game1.score++;
		box1.Reset1();
	}
	if (box1.box_x >= 350 && box1.box_x <= 450 && box1.box_y >= 450 && box1.box_y <= 550 && box1.GetRandomType() == "bbox") {
		game1.score++;
		box1.Reset1();
	}
	if (box1.box_x >= 600 && box1.box_x <= 700 && box1.box_y >= 450 && box1.box_y <= 550 && box1.GetRandomType() == "gbox") {
		game1.score++;
		box1.Reset1();
	}
}

void Update() {
	if (game1.running) {
		box1.Update1();
		loaders0.Update2();
	}
}

void Reset() {
	box1.Reset1();
	loaders0.Reset2();
}