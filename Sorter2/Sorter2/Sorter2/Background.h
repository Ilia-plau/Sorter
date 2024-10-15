#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <raylib.h>
#include "Textures.h"

using namespace std;

class Background : public Textures
{
public:
	void Draw1() {

		DrawTexture(background, 0, 50, WHITE);
	};
};

#endif