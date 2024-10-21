#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <raylib.h>
#include <string>
#include <deque>
#include <raymath.h>
#include "Textures.h"
#include "Loaders.h"

using namespace std;

class Box:public Textures{
public:
	int tmp;
	int count = 0;
	float box_x;
	float box_y;
	float box_width;
	float box_height;
	float speed = 50;
	int c = 1;
	Loaders loaders = Loaders();

	void Draw2();
	void Update1(float loaders_y, float loaders_x, float loaders_height, float loaders_width);
	void Reset1();
	string GetRandomType();
};

#endif