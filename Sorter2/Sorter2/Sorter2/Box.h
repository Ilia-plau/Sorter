#pragma once

#include <iostream>
#include <raylib.h>
#include <string>
#include <deque>
#include <raymath.h>
#include "Textures.h"
#include "Loaders.h"

using namespace std;

class Box
{
public:
	int tmp;
	int count = 0;
	float box_x;
	float box_y;
	int box_width = 50;
	int box_height = 50;
	int speed = 50;
	int c = 1;
	Textures textures = Textures();

	void Draw2() {};
	void Update1() {};
	void Reset1() {};
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
	};
};
