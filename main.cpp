#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <gl/GLU.h>
#include <gl/freeglut.h>
#include <gl/glut.h>
#include "cube.h"

float angle = 0.0f;
cube rubic[27];

void setRubic() {
	// Declare all front cube
	rubic[0].setPoint(-10.0f, -10.0f, -10.0f);
	rubic[0].setColor('r', 'h', 'b', 'h', 'h', 'p');
	rubic[1].setPoint(-3.0f, -10.0f, -10.0f);
	rubic[1].setColor('r', 'h', 'h', 'h', 'h', 'p');
	rubic[2].setPoint(4.0f, -10.0f, -10.0f);
	rubic[2].setColor('r', 'h', 'h', 'g', 'h', 'p');
	rubic[3].setPoint(-10.0f, -3.0f, -10.0f);
	rubic[3].setColor('r', 'h', 'b', 'h', 'h', 'h');
	rubic[4].setPoint(-3.0f, -3.0f, -10.0f);
	rubic[4].setColor('r', 'h', 'h', 'h', 'h', 'h');
	rubic[5].setPoint(4.0f, -3.0f, -10.0f);
	rubic[5].setColor('r', 'h', 'h', 'g', 'h', 'h');
	rubic[6].setPoint(-10.0f, 4.0f, -10.0f);
	rubic[6].setColor('r', 'h', 'b', 'h', 'y', 'h');
	rubic[7].setPoint(-3.0f, 4.0f, -10.0f);
	rubic[7].setColor('r', 'h', 'h', 'h', 'y', 'h');
	rubic[8].setPoint(4.0f, 4.0f, -10.0f);
	rubic[8].setColor('r', 'h', 'h', 'g', 'y', 'h');

	// Declare all center cube
	rubic[9].setPoint(-10.0f, -10.0f, -3.0f);
	rubic[9].setColor('h', 'h', 'b', 'h', 'h', 'p');
	rubic[10].setPoint(-3.0f, -10.0f, -3.0f);
	rubic[10].setColor('h', 'h', 'h', 'h', 'h', 'p');
	rubic[11].setPoint(4.0f, -10.0f, -3.0f);
	rubic[11].setColor('h', 'h', 'h', 'g', 'h', 'p');
	rubic[12].setPoint(-10.0f, -3.0f, -3.0f);
	rubic[12].setColor('h', 'h', 'b', 'h', 'h', 'h');
	rubic[13].setPoint(-3.0f, -3.0f, -3.0f);
	rubic[13].setColor('h', 'h', 'h', 'h', 'h', 'h');
	rubic[14].setPoint(4.0f, -3.0f, -3.0f);
	rubic[14].setColor('h', 'h', 'h', 'g', 'h', 'h');
	rubic[15].setPoint(-10.0f, 4.0f, -3.0f);
	rubic[15].setColor('h', 'h', 'b', 'h', 'y', 'h');
	rubic[16].setPoint(-3.0f, 4.0f, -3.0f);
	rubic[16].setColor('h', 'h', 'h', 'h', 'y', 'h');
	rubic[17].setPoint(4.0f, 4.0f, -3.0f);
	rubic[17].setColor('h', 'h', 'h', 'g', 'y', 'h');

	// Declare all back cube
	rubic[18].setPoint(-10.0f, -10.0f, 4.0f);
	rubic[18].setColor('h', 'o', 'b', 'h', 'h', 'p');
	rubic[19].setPoint(-3.0f, -10.0f, 4.0f);
	rubic[19].setColor('h', 'o', 'h', 'h', 'h', 'p');
	rubic[20].setPoint(4.0f, -10.0f, 4.0f);
	rubic[20].setColor('h', 'o', 'h', 'g', 'h', 'p');
	rubic[21].setPoint(-10.0f, -3.0f, 4.0f);
	rubic[21].setColor('h', 'o', 'b', 'h', 'h', 'h');
	rubic[22].setPoint(-3.0f, -3.0f, 4.0f);
	rubic[22].setColor('h', 'o', 'h', 'h', 'h', 'h');
	rubic[23].setPoint(4.0f, -3.0f, 4.0f);
	rubic[23].setColor('h', 'o', 'h', 'g', 'h', 'h');
	rubic[24].setPoint(-10.0f, 4.0f, 4.0f);
	rubic[24].setColor('h', 'o', 'b', 'h', 'y', 'h');
	rubic[25].setPoint(-3.0f, 4.0f, 4.0f);
	rubic[25].setColor('h', 'o', 'h', 'h', 'y', 'h');
	rubic[26].setPoint(4.0f, 4.0f, 4.0f);
	rubic[26].setColor('h', 'o', 'h', 'g', 'y', 'h');
}

//Define an error callback  
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

void rotate_top() {
	glLoadIdentity();
	glTranslatef(0.0f, 7.0f, 0.0f);
	glRotatef(angle, 1.0f, 1.0f, 0.0f);

	glColor3f(0.5f, 0.5f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();
	//angle += 15;
}

//Define the key input callback  
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	/*else if (key == GLFW_KEY_T && action == GLFW_PRESS) {}
		int goal = 90;
		int degree_per_frame = 5;
		int frame = goal / degree_per_frame;
		for (int i = 0; i < frame; i++) {
			angle += degree_per_frame;
			DrawGLScene();
		}*/
}

int main(void)
{
	//Set the error callback  
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW  
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Declare a window object  
	GLFWwindow* window;

	//Create a window and create its OpenGL context  
	window = glfwCreateWindow(640, 640, "Test Window", NULL, NULL);

	//If the window couldn't be created  
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread.   
	glfwMakeContextCurrent(window);

	//Sets the key callback  
	glfwSetKeyCallback(window, key_callback);

	//Initialize GLEW  
	GLenum err = glewInit();

	//If GLEW hasn't initialized  
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return -1;
	}

	//Set a background color  
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Enable depth
	glEnable(GL_DEPTH_TEST);

	setRubic();

	//Main Loop  
	do
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-25.f, 25.f, -25.f, 25.f, -25.f, 25.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw rubic
		for (int i = 0; i < 27; i++) {
			glLoadIdentity();
			glRotatef(45, 1, 1, 0.5);
			rubic[i].draw();
		}

		//Swap buffers  
		glfwSwapBuffers(window);
		//Get and organize events, like keyboard and mouse input, window resizing, etc...  
		glfwPollEvents();

	} //Check if the ESC key had been pressed or if the window had been closed  
	while (!glfwWindowShouldClose(window));

	//Close OpenGL window and terminate GLFW  
	glfwDestroyWindow(window);
	//Finalize and clean up GLFW  
	glfwTerminate();

	exit(EXIT_SUCCESS);
}