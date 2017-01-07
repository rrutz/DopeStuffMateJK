#include "Bullet.h"
#include "Graphics.h"


Bullet::Bullet(int x, int y, int vx, int vy)
{
	x = x;
	y = y;
	vx = vx;
	vy = vy;
}
void Bullet::Move()
{
	x += vx;
	y += vy;

	if (x < 0 || x + 9 >= Graphics::ScreenWidth || y< 0|| y + 9 >= Graphics::ScreenHeight)
	{
		exists = false;
	}
}
