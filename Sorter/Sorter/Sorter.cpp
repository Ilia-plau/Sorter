// Sorter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

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

class Ball {
public:

	Texture2D texture;
	float ball_x;
	float ball_y;
	int ball_radius;
	int speed = 50;

	Ball() {
		texture = LoadTexture(".\\box.png");
	}

	void Draw() {
		DrawCircle(ball_x, ball_y, ball_radius, WHITE);
		//DrawTexture(texture,ball_x, ball_y,WHITE);
	}

	void Update(float box_x,float box_y,float box_width,float box_height) {
		if (IsKeyDown(KEY_W) && ball_y - 50 == (2 * box_y + box_height) / 2 && ball_x == (2 * box_x + box_width)/2) {
			ball_y -= 10;
		}
		if (IsKeyDown(KEY_S) && ball_y - 40 == (2 * box_y + box_height) / 2 && ball_x == (2 * box_x + box_width) / 2) {
			ball_y += 10;
		}
		if (IsKeyDown(KEY_W) && EventTriggered(0.15) && ball_y - 100 >= 25 ) {
			ball_y -= speed;
			
		}
		if (IsKeyDown(KEY_S) && EventTriggered(0.15) && ball_y + 50 <= 700 ) {
			ball_y += speed;

		}
		if (IsKeyDown(KEY_A) && EventTriggered(0.15) && ball_x-50>=25 ) {
			ball_x -= speed;
		}
		if (IsKeyDown(KEY_D) && EventTriggered(0.15) && ball_x+50<=850) {
			ball_x += speed;
		}
		//cout << ball_x << "  " << ball_y << "    " << speed;
		/*		if (ball_x - ball_radius <= 0 || ball_x + ball_radius >= GetScreenWidth()) {
					ball_x = 0;
				}
				if (ball_y - ball_radius <= 0 || ball_y + ball_radius >= GetScreenHeight()) {
					ball_y = 0;
				}*/
	}
	void Reset() {
		ball_x = GetScreenWidth() / 2;
		ball_y = (GetScreenHeight()-50) / 2;
		speed = 50;
	}
};
class Box {
public:
	Texture2D texture;
	int tmp;
	float box_x;
	float box_y;
	float box_width;
	float box_height;
	float speed = 50;

	Box() {
		texture = LoadTexture(".\\box.png");
	}
	
	void Draw() {
		DrawTexture(texture,box_x, box_y, WHITE);
	}
	void Update(float ball_x, float ball_y, float ball_radius) {
	/*	if (ball_x - ball_radius <= box_x + box_width &&
			((ball_y - ball_radius <= box_y + box_height && ball_y + ball_radius >= box_y )
				|| (ball_y + ball_radius >= box_y && ball_y - ball_radius <= box_y + box_height )
				) && ball_x + ball_radius >= box_x+box_width) {
			box_x -= speed;
		}
		else if (ball_x + ball_radius >= box_x &&
			((ball_y - ball_radius <= box_y + box_height && ball_y + ball_radius >= box_y )
				|| (ball_y + ball_radius >= box_y && ball_y - ball_radius <= box_y + box_height )
				) && ball_x - ball_radius <= box_x) {
			box_x += speed;
		}*/
		/*if (ball_x - ball_radius <= box_x + box_width &&
			((ball_y + ball_radius >= box_y + box_height && ball_y - ball_radius <= box_y)
				 || (ball_y + ball_radius >= box_y) && ball_y - ball_radius <= box_y + box_height
				)&& ball_x + ball_radius >= box_x + box_width && IsKeyDown(KEY_A)) {
			box_x -= speed;
		}
		else if (ball_x + ball_radius >= box_x &&
			((ball_y + ball_radius <= box_y + box_height && ball_y - ball_radius >= box_y)
				|| (ball_y - ball_radius <= box_y + box_height) && ball_y + ball_radius >= box_y
				) && ball_x - ball_radius <= box_x && ball_x && IsKeyDown(KEY_D)) {
			box_x += speed;
		}
		
		if (ball_y - ball_radius <= box_y + box_height &&
			((ball_x - ball_radius <= box_x + box_width && ball_x + ball_radius >= box_x)
				|| (ball_x + ball_radius >= box_x && ball_x - ball_radius <= box_x + box_width)
				) && ball_y + ball_radius >= box_y+box_height && IsKeyDown(KEY_W)) {
			box_y -= speed;
		}
		else if (ball_y + ball_radius >= box_y &&
			((ball_x + ball_radius >= box_x  && ball_x - ball_radius <= box_x + box_width )
				|| (ball_x - ball_radius <= box_x + box_height && ball_x + ball_radius >= box_x )
				) && ball_y - ball_radius <= box_y && IsKeyDown(KEY_S)) {
			box_y += speed;
		}*/
		if (ball_y ==(2*box_y + box_height) / 2 && ball_x == (2*box_x + box_width) / 2) {
			if (IsKeyDown(KEY_W) && EventTriggered(0.15) && ball_y - 100 >= 25) {
				box_y -= speed;

			}
			if (IsKeyDown(KEY_S) && EventTriggered(0.15) && ball_y + 50 <= 700) {
				box_y += speed;
			}
			if (IsKeyDown(KEY_A) && EventTriggered(0.15) && ball_x - 50 >= 25) {
				box_x -= speed;
			}
			if (IsKeyDown(KEY_D) && EventTriggered(0.15) && ball_x + 50 <= 850) {
				box_x += speed;
			}
		}

																					  /*else if (ball_x+ball_radius  >= box_x && ball_y+ball_radius  <= box_y+box_height && ball_y-ball_radius  >= box_y) {
																						  box_x += speed;
																					  }
																					  else if (ball_y-ball_radius <= box_y + box_height && ball_x+ball_radius  <= box_x + box_width && ball_x-ball_radius >=box_x) {
																						  box_y -= speed;
																					  }
																					  else if (ball_y+ball_radius >= box_y && ball_x+ball_radius <= box_x + box_width && ball_x-ball_radius  >= box_x) {
																						  box_y += speed;
																					  }*/

	}
	void Reset() {
		box_x = GetScreenWidth() / 4-12;
		box_y = (GetScreenHeight()-50) / 4-12;
		box_width = 50;
		box_height = 50;
		speed = 50;
	}
};

int main()
{

	Color Dark_Green = Color{ 20, 160, 133, 255 };
	const float screenWidth = 850;
	const float screenHeight = 700;
	InitWindow(screenWidth, screenHeight, "My first program!");
	int score = 0;
	Ball ball = Ball();
	Box box = Box();

	ball.ball_radius = 15;

	
	SetTargetFPS(60);
	box.Reset();
	ball.Reset();
	while (WindowShouldClose() == false)
	{

		
		box.Update(ball.ball_x, ball.ball_y, ball.ball_radius);
		ball.Update(box.box_x,box.box_y,box.box_width,box.box_height);
		// Drawing
		if (box.box_x >= 50 && box.box_x <= 200 && box.box_y >= 450 && box.box_y <= 600) {
			score += 1;
			box.Reset();
		}
		
		
		DrawText(TextFormat("%i",score),162.5 ,12.5, 30, BLACK);
		DrawText(TextFormat("%s", "score:"), 55 , 12.5, 30,BLACK);
		DrawRectangle(100, 450, 150, 150, WHITE);
		DrawRectangle(350, 450, 150,150, YELLOW);
		DrawRectangle(600, 450, 150, 150, BROWN);

		box.Draw();
		ball.Draw();
		ClearBackground(GREEN);
		EndDrawing();
		for (int i = 0;i <= 800;++i) {
			if (i % 50 == 0) {
				DrawLine(i, 50, i, screenHeight, WHITE);
			}
		};
		for (int i = 50;i <= 650;++i) {
			if (i % 50 == 0) {
				DrawLine(0, i, screenWidth, i, WHITE);
			}
		};
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
