#include "BadGuy.h"
#include "Graphics.h"

// random starting points and speeds

void BadGuy::Init(int x_in, int y_in, int vx_in, int vy_in)
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
	else if (x + 9 >= Graphics::ScreenWidth)
	{
		vx = -vx;
		x = Graphics::ScreenWidth - 9;
	}

	if (y  < 0)
	{
		vy = -vy;
		y = 0;
	}
	else if (y + 9 >= Graphics::ScreenHeight)
	{
		vy = -vy;
		y = Graphics::ScreenHeight - 9;
	}
}
	
void BadGuy::Hit(int shipx, int shipy)
{
	if ( (shipx <= x +8 && shipx >= x) && 
		(shipy >= y && shipy <= y+8 ))
	{
		killed = true;
	}

}

void BadGuy::draw(Graphics& gfx)
{
	gfx.PaintDanger(x, y, 0, 100, 0);
}

bool BadGuy::isKilled()
{
	return killed;
}
