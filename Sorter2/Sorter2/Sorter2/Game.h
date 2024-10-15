#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <raylib.h>
#include <string>
#include <deque>
#include <raymath.h>
#include "Textures.h"
#include "Loaders.h"
#include "Box.h"
#include "Background.h"
#include "Conveyor.h"
#include "Plate.h"

using namespace std;

class Game : public Box, public Loaders,public Plate,public Background,public Conveyor
{
public:
	bool running = true;
	int score = 0;

	void Draw();
	void Score();
	void Update();
	void Reset();
};

#endif

