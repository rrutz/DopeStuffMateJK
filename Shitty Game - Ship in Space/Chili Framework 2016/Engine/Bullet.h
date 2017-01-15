#pragma once

#include "Graphics.h"

class Bullet {

public:
	Bullet(int x, int y, int vx, int vy);
	int x;
	int y;
	bool exists = true;
	int vx;
	int vy;
	int bulletSize = 4;

	void Move();
	void draw(Graphics& gfx);
};