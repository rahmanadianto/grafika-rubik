#pragma once
#include "square.h"

class cube
{
public:
	cube();
	~cube();
	void setPoint(float x, float y, float z);	//point in front, left, bottom
	void setColor(char c0, char c1, char c2, char c3, char c4, char c5);
	void draw();
private:
	const float size = 5.0f;
	square squares[6];
};

