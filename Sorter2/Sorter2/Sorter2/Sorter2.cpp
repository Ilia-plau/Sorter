// Sorter2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "Game.h"


#define RAYGUI_IMPLEMENTATION

using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

/*class Textures {
public:
	Texture2D boxr, boxb, boxg, plater, plateb, plateg, background, conveyor, loader;
	Textures() {
		loader = LoadTexture(".\\loader.png");
		boxr = LoadTexture(".\\rbox.png");
		boxb = LoadTexture(".\\bbox.png");
		boxg = LoadTexture(".\\gbox.png");
		plater = LoadTexture(".\\rrplate.png");
		plateb = LoadTexture(".\\bbplate.png");
		plateg = LoadTexture(".\\ggplate.png");
		background = LoadTexture(".\\background.png");
		conveyor = LoadTexture(".\\conveyor.png");
	}

};*/

/*class Loaders : public Textures {
public:
	float loaders_x;
	float loaders_y;
	int loaders_width = 50;
	int loaders_height = 50;
	int speed = 50;

	void Draw() {
		DrawTexture(loader, loaders_x, loaders_y, WHITE);
	}

	void Update(float box_x, float box_y, float box_width, float box_height) {
		if (IsKeyDown(KEY_W) && EventTriggered(0.15) && loaders_y - 50 >= 25) {
			loaders_y -= speed;
		}
		if (IsKeyDown(KEY_S) && EventTriggered(0.15) && loaders_y + 100 <= 700) {
			loaders_y += speed;

		}
		if (IsKeyDown(KEY_A) && EventTriggered(0.15) && loaders_x >= 25) {
			loaders_x -= speed;
		}
		if (IsKeyDown(KEY_D) && EventTriggered(0.15) && loaders_x + 100 <= 850) {
			loaders_x += speed;
		}
		if (loaders_y == 150 && loaders_x < 200) {
			loaders_x += 0.5;
		}
	}
	void Reset() {
		loaders_x = GetScreenWidth() / 2 - 25;
		loaders_y = (GetScreenHeight() - 50) / 2 - 25;
		speed = 50;

	}
};*/

/*class Box : public Textures {
public:
	int tmp;
	int count = 0;
	float box_x;
	float box_y;
	float box_width;
	float box_height;
	float speed = 50;
	int c = 1;

	void Draw() {
		if (GetRandomType() == "rbox") {
			DrawTexture(boxr, box_x, box_y, WHITE);
		}
		if (GetRandomType() == "bbox") {
			DrawTexture(boxb, box_x, box_y, WHITE);
		}
		if (GetRandomType() == "gbox") {
			DrawTexture(boxg, box_x, box_y, WHITE);
		}

	}
	void Update(float ball_x, float ball_y, float ball_height, float ball_width) {
		if ((2 * ball_y + ball_height) / 2 - 50 == (2 * box_y + box_height) / 2 && (2 * ball_x + ball_width) / 2 == (2 * box_x + box_width) / 2) {
			if (IsKeyDown(KEY_W) && EventTriggered(0.15) && box_y - 100 >= 25) {
				box_y -= speed;
			}
		}
		if ((2 * ball_y + ball_height) / 2 + 50 == (2 * box_y + box_height) / 2 && (2 * ball_x + ball_width) / 2 == (2 * box_x + box_width) / 2) {
			if (IsKeyDown(KEY_S) && EventTriggered(0.15) && box_y + 150 <= 700) {
				box_y += speed;
			}
		}
		if ((2 * ball_y + ball_height) / 2 == (2 * box_y + box_height) / 2 && (2 * ball_x + ball_width) / 2 - 50 == (2 * box_x + box_width) / 2) {
			if (IsKeyDown(KEY_A) && EventTriggered(0.15) && box_x - 50 >= 25) {
				box_x -= speed;
			}
		}
		if ((2 * ball_y + ball_height) / 2 == (2 * box_y + box_height) / 2 && (2 * ball_x + ball_width) / 2 + 50 == (2 * box_x + box_width) / 2) {
			if (IsKeyDown(KEY_D) && EventTriggered(0.15) && box_x + 150 <= 850) {
				box_x += speed;
			}
		}
		if (box_x < 200 && box_y == 150) {
			box_x += 0.5;
		}

	}
	void Reset() {
		box_x = 50;
		box_y = 150;
		box_width = 50;
		box_height = 50;
		speed = 50;
		count = 0;
	}
	string GetRandomType() {
		if (count == 0) {
			tmp = GetRandomValue(1, 3);
			count += 1;
		}
		if (tmp == 1) {
			return "rbox";
		}
		if (tmp == 2) {
			return "bbox";
		}
		if (tmp == 3) {
			return "gbox";
		}
	}
};*/

/*class Background : public Textures {
public:
	void Draw() {
		DrawTexture(background, 0, 50, WHITE);
	}
};*/

/*class Plate : public Textures {
public:
	void Draw() {
		DrawTexture(plater, 100, 450, WHITE);
		DrawTexture(plateb, 350, 450, WHITE);
		DrawTexture(plateg, 600, 450, WHITE);
	}
};*/

/*class Conveyor : public Textures {
public:
	void Draw() {
		DrawTexture(conveyor, 0, 150, WHITE);
	}
};*/

/*class Game : public Box, public Loaders {
public:
	bool running = true;
	Textures textures = Textures();
	Loaders loaders = Loaders();
	Box box = Box();
	Plate plate = Plate();
	Conveyor conveyor = Conveyor();
	Background background = Background();
	int score = 0;

	void Draw() {
		background.Draw();
		conveyor.Draw();
		plate.Draw();
		box.Draw();
		loaders.Draw();
	}

	void Score() {
		if (box.box_x >= 100 && box.box_x <= 200 && box.box_y >= 450 && box.box_y <= 550 && box.GetRandomType() == "rbox") {
			score++;
			box.Reset();
		}
		if (box.box_x >= 350 && box.box_x <= 450 && box.box_y >= 450 && box.box_y <= 550 && box.GetRandomType() == "bbox") {
			score++;
			box.Reset();
		}
		if (box.box_x >= 600 && box.box_x <= 700 && box.box_y >= 450 && box.box_y <= 550 && box.GetRandomType() == "gbox") {
			score++;
			box.Reset();
		}
	}

	void Update() {
		if (running) {
			box.Update(loaders.loaders_x, loaders.loaders_y, loaders.loaders_height, loaders.loaders_width);
			loaders.Update(box.box_x, box.box_y, box.box_width, box.box_height);
		}
	}

	void Reset() {
		box.Reset();
		loaders.Reset();
	}
};*/
int main()
{
	Color Dark_Green = Color{ 20, 160, 133, 255 };
	const float screenWidth = 850;
	const float screenHeight = 700;
	InitWindow(screenWidth, screenHeight, "My first program!");
	Game game = Game();

	SetTargetFPS(60);
	game.Reset();
	while (WindowShouldClose() == false)
	{

		game.Update();
		game.Score();
		game.Draw();

		DrawText(TextFormat("%i", game.score), 162.5, 12.5, 30, BLACK);
		DrawText(TextFormat("%s", "score:"), 55, 12.5, 30, BLACK);
		ClearBackground(GREEN);
		EndDrawing();

	}
	CloseWindow();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
