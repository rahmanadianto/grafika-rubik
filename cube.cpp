#include "cube.h"

void cube::setPoint(float x, float y, float z)
{
	// Front
	squares[0].setPoint(x, y, z,
						x + size, y, z,
						x + size, y + size, z,
						x, y + size, z);
	// Back
	squares[1].setPoint(x, y, z + size,
						x + size, y, z + size,
						x + size, y + size, z + size,
						x, y + size, z + size);
	// Left
	squares[2].setPoint(x, y, z,
						x, y, z + size,
						x, y + size, z + size,
						x, y + size, z);
	// Right
	squares[3].setPoint(x + size, y, z,
						x + size, y, z + size,
						x + size, y + size, z + size,
						x + size, y + size, z);
	// Top
	squares[4].setPoint(x, y + size, z,
						x + size, y + size, z,
						x + size, y + size, z + size,
						x, y + size, z + size);
	// Bottom
	squares[5].setPoint(x, y, z,
						x + size, y, z,
						x + size, y, z + size,
						x, y, z + size);
}
cube::cube()
{
}
cube::~cube()
{
}

void cube::setColor(char c0, char c1, char c2, char c3, char c4, char c5)
{
	squares[0].setColor(c0);
	squares[1].setColor(c1);
	squares[2].setColor(c2);
	squares[3].setColor(c3);
	squares[4].setColor(c4);
	squares[5].setColor(c5);
}

void cube::draw() {
	for (int i = 0; i < 6; i++)
		squares[i].draw();
}
