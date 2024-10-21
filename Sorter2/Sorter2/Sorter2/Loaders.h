#ifndef LOADERS_H
#define LOADERS_H

#include <iostream>
#include <raylib.h>
#include <string>
#include <deque>
#include <raymath.h>
#include "Textures.h"
//#include "Box.h"

using namespace std;

class Loaders : public Textures{
public:

	float loaders_x;
	float loaders_y;
	int loaders_width = 50;
	int loaders_height = 50;
	int speed = 50;
	double lastUpdateTime1 = 0;
	//Box box = Box();

	bool EventTriggered1(double interval);
	void Draw5();
	void Update2();
	void Reset2();
};

#endif
