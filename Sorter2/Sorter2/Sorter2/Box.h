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
	int box_width = 50;
	int box_height = 50;
	int speed = 50;
	int c = 1;
	Loaders loaders = Loaders();

	void Draw2();
	void Update1();
	void Reset1();
	string GetRandomType();
};

#endif