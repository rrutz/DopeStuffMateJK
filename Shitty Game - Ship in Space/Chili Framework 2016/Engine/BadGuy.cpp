#include "BadGuy.h"
#include "Graphics.h"

// random starting points and speeds

BadGuy::BadGuy(int x_in, int y_in, float vx_in, float vy_in)
{
	x = x_in;
	y = y_in;
	vx = vx_in;
	vy = vy_in;
}

void BadGuy::Update()
{
	x += vx;
	y += vy;

	if (x < 0)
	{
		vx = -vx;
		x = 0;
	}
	else if (x + cubeSize+1 >= Graphics::ScreenWidth)
	{
		vx = -vx;
		x = Graphics::ScreenWidth - cubeSize-1;
	}

	if (y  < 0)
	{
		vy = -vy;
		y = 0;
	}
	else if (y + cubeSize+1  >= Graphics::ScreenHeight)
	{
		vy = -vy;
		y = Graphics::ScreenHeight - cubeSize-1;
	}
}
	
bool BadGuy::Hit(int shipx, int shipy)
{
	if ( (shipx <= x + cubeSize && shipx >= x) &&
		(shipy >= y && shipy <= y+ cubeSize))
	{
		killed = true;
	}
	return killed;

}

void BadGuy::draw(Graphics& gfx)
{
	gfx.PaintDanger(x, y, 0, 100, 0, cubeSize);
}

bool BadGuy::isKilled()
{
	return killed;
}
