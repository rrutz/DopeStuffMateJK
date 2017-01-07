#pragma once
class Bullet {

public:
	Bullet(int x, int y, int vx, int vy);
	int x;
	int y;
	bool exists = true;
	int vx;
	int vy;

	void Move();
};