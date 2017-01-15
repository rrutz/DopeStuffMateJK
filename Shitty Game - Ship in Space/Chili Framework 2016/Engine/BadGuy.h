#pragma once

#include "Graphics.h"

class BadGuy
{
public:
	BadGuy(int x_in, int y_in, float vx_in, float vy_in );
	void Update();
	bool Hit(int shipx, int shipy);
	int x; 
	int y;
	float vx;
	float vy;
	bool killed = false;
	void draw(Graphics& gfx );
	bool isKilled();

	int cubeSize = 20;
};