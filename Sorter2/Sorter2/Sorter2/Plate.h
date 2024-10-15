#ifndef PLATE_H
#define PLATE_H

#include <iostream>
#include <raylib.h>
#include "Textures.h"

using namespace std;

class Plate : public Textures
{
public:
	void Draw4();
};

#endif	// !PLATE_H