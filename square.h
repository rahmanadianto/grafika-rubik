#pragma once
class square
{
public:
	square();
	~square();
	void setPoint(float x1, float y1, float z1,
		float x2, float y2, float z2, 
		float x3, float y3, float z3, 
		float x4, float y4, float z4);
	void setColor(char c);
	void draw();
private:
	float point[12];
	float color[3];
};

