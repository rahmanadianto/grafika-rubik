#include "square.h"
#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h>

square::square()
{
}

square::~square()
{
}

void square::setPoint(float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3,
	float x4, float y4, float z4)
{
	point[0] = x1; point[1] = y1; point[2] = z1;
	point[3] = x2; point[4] = y2; point[5] = z2;
	point[6] = x3; point[7] = y3; point[8] = z3;
	point[9] = x4; point[10] = y4; point[11] = z4;
}

void square::setColor(char c)
{
	float r, g, b;
	switch (c) {
		case 'h': r = 0.0f; g = 0.0f; b = 0.0f; break;
		case 'r': r = 1.0f; g = 0.0f; b = 0.0f; break;
		case 'g': r = 0.0f; g = 1.0f; b = 0.0f; break;
		case 'b': r = 0.0f; g = 0.0f; b = 1.0f; break;
	}
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void square::draw()
{
	glBegin(GL_QUADS);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(point[0], point[1], point[2]);
	glVertex3f(point[3], point[4], point[5]);
	glVertex3f(point[6], point[7], point[8]);
	glVertex3f(point[9], point[10], point[11]);
	glEnd();
}
