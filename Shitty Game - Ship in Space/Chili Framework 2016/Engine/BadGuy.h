#pragma once

#include "Graphics.h"

class BadGuy
{
public:
	void Init(int x_in, int y_in, int vx_in, int vy_in );
	void Update();
	void Hit(int shipx, int shipy);
	int x; 
	int y;
	int vx; 
	int vy;
	bool killed = false;
	void draw(Graphics& gfx );
	bool isKilled();
};