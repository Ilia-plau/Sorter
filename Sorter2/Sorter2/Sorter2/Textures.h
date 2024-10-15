#pragma once

#include <iostream>
#include <raylib.h>

using namespace std;

class Textures
{
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
};

