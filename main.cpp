#include <GL/glew.h>  
#include <GLFW/glfw3.h>  
#include <stdio.h>  
#include <stdlib.h>  

//Define an error callback  
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

//Define the key input callback  
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

// Point & color for rubic
static const GLfloat front_side[] = {
	// Color
	1.0f,  0.0f,  0.0f,
	// Bottom left
	-10.0f, -10.0f, -11.0f,
	-4.0f, -10.0f, -11.0f,
	-4.0f, -4.0f, -11.0f,
	-10.0f, -4.0f, -11.0f,
	// Bottom center
	-3.0f, -10.0f, -11.0f,
	3.0f, -10.0f, -11.0f,
	3.0f, -4.0f, -11.0f,
	-3.0f, -4.0f, -11.0f,
	// Bottom right
	4.0f, -10.0f, -11.0f,
	10.0f, -10.0f, -11.0f,
	10.0f, -4.0f, -11.0f,
	4.0f, -4.0f, -11.0f,
	// Center left
	-10.0f, -3.0f, -11.0f,
	-4.0f, -3.0f, -11.0f,
	-4.0f, 3.0f, -11.0f,
	-10.0f, 3.0f, -11.0f,
	// Center center
	-3.0f, -3.0f, -11.0f,
	3.0f, -3.0f, -11.0f,
	3.0f, 3.0f, -11.0f,
	-3.0f, 3.0f, -11.0f,
	// Center right
	4.0f, -3.0f, -11.0f,
	10.0f, -3.0f, -11.0f,
	10.0f, 3.0f, -11.0f,
	4.0f, 3.0f, -11.0f,
	// Top left
	-10.0f, 10.0f, -11.0f,
	-4.0f, 10.0f, -11.0f,
	-4.0f, 4.0f, -11.0f,
	-10.0f, 4.0f, -11.0f,
	// Top center
	-3.0f, 10.0f, -11.0f,
	3.0f, 10.0f, -11.0f,
	3.0f, 4.0f, -11.0f,
	-3.0f, 4.0f, -11.0f,
	// Top right
	4.0f, 10.0f, -11.0f,
	10.0f, 10.0f, -11.0f,
	10.0f, 4.0f, -11.0f,
	4.0f, 4.0f, -11.0f
};
static const GLfloat back_side[] = {
	// Color
	1.0f,  0.5f,  0.25f,
	// Bottom left
	-10.0f, -10.0f, 11.0f,
	-4.0f, -10.0f, 11.0f,
	-4.0f, -4.0f, 11.0f,
	-10.0f, -4.0f, 11.0f,
	// Bottom center
	-3.0f, -10.0f, 11.0f,
	3.0f, -10.0f, 11.0f,
	3.0f, -4.0f, 11.0f,
	-3.0f, -4.0f, 11.0f,
	// Bottom right
	4.0f, -10.0f, 11.0f,
	10.0f, -10.0f, 11.0f,
	10.0f, -4.0f, 11.0f,
	4.0f, -4.0f, 11.0f,
	// Center left
	-10.0f, -3.0f, 11.0f,
	-4.0f, -3.0f, 11.0f,
	-4.0f, 3.0f, 11.0f,
	-10.0f, 3.0f, 11.0f,
	// Center center
	-3.0f, -3.0f, 11.0f,
	3.0f, -3.0f, 11.0f,
	3.0f, 3.0f, 11.0f,
	-3.0f, 3.0f, 11.0f,
	// Center right
	4.0f, -3.0f, 11.0f,
	10.0f, -3.0f, 11.0f,
	10.0f, 3.0f, 11.0f,
	4.0f, 3.0f, 11.0f,
	// Top left
	-10.0f, 10.0f, 11.0f,
	-4.0f, 10.0f, 11.0f,
	-4.0f, 4.0f, 11.0f,
	-10.0f, 4.0f, 11.0f,
	// Top center
	-3.0f, 10.0f, 11.0f,
	3.0f, 10.0f, 11.0f,
	3.0f, 4.0f, 11.0f,
	-3.0f, 4.0f, 11.0f,
	// Top right
	4.0f, 10.0f, 11.0f,
	10.0f, 10.0f, 11.0f,
	10.0f, 4.0f, 11.0f,
	4.0f, 4.0f, 11.0f
};
static const GLfloat left_side[] = {
	// Color
	1.0f,  1.0f,  1.0f,
	// Bottom left
	-11.0f, -10.0f, 10.0f,
	-11.0f, -10.0f, 4.0f,
	-11.0f, -4.0f, 4.0f,
	-11.0f, -4.0f, 10.0f,
	// Bottom center
	-11.0f, -10.0f, 3.0f,
	-11.0f, -10.0f, -3.0f,
	-11.0f, -4.0f, -3.0f,
	-11.0f, -4.0f, 3.0f,
	// Bottom right
	-11.0f, -10.0f, -4.0f,
	-11.0f, -10.0f, -10.0f,
	-11.0f, -4.0f, -10.0f,
	-11.0f, -4.0f, -4.0f,
	// Center left
	-11.0f, -3.0f, 10.0f,
	-11.0f, -3.0f, 4.0f,
	-11.0f, 3.0f, 4.0f,
	-11.0f, 3.0f, 10.0f,
	// Center center
	-11.0f, -3.0f, 3.0f,
	-11.0f, -3.0f,  -3.0f,
	-11.0f, 3.0f, -3.0f,
	-11.0f, 3.0f,3.0f,
	// Center right
	-11.0f, -3.0f, -4.0f,
	-11.0f, -3.0f,  -10.0f,
	-11.0f, 3.0f, -10.0f,
	-11.0f, 3.0f,-4.0f,
	// Top left
	-11.0f, 4.0f, 10.0f,
	-11.0f, 4.0f, 4.0f,
	-11.0f, 10.0f, 4.0f,
	-11.0f, 10.0f, 10.0f,
	// Top center
	-11.0f, 4.0f, 3.0f,
	-11.0f, 4.0f,  -3.0f,
	-11.0f, 10.0f, -3.0f,
	-11.0f, 10.0f,3.0f,
	// Top right
	-11.0f, 4.0f, -4.0f,
	-11.0f, 4.0f,  -10.0f,
	-11.0f, 10.0f, -10.0f,
	-11.0f, 10.0f,-4.0f
};
static const GLfloat right_side[] = {
	// Color
	1.0f,  0.75f,  0.25f,
	// Bottom left
	11.0f, -10.0f, 10.0f,
	11.0f, -10.0f, 4.0f,
	11.0f, -4.0f, 4.0f,
	11.0f, -4.0f, 10.0f,
	// Bottom center
	11.0f, -10.0f, 3.0f,
	11.0f, -10.0f, -3.0f,
	11.0f, -4.0f, -3.0f,
	11.0f, -4.0f, 3.0f,
	// Bottom right
	11.0f, -10.0f, -4.0f,
	11.0f, -10.0f, -10.0f,
	11.0f, -4.0f, -10.0f,
	11.0f, -4.0f, -4.0f,
	// Center left
	11.0f, -3.0f, 10.0f,
	11.0f, -3.0f, 4.0f,
	11.0f, 3.0f, 4.0f,
	11.0f, 3.0f, 10.0f,
	// Center center
	11.0f, -3.0f, 3.0f,
	11.0f, -3.0f,  -3.0f,
	11.0f, 3.0f, -3.0f,
	11.0f, 3.0f,3.0f,
	// Center right
	11.0f, -3.0f, -4.0f,
	11.0f, -3.0f,  -10.0f,
	11.0f, 3.0f, -10.0f,
	11.0f, 3.0f,-4.0f,
	// Top left
	11.0f, 4.0f, 10.0f,
	11.0f, 4.0f, 4.0f,
	11.0f, 10.0f, 4.0f,
	11.0f, 10.0f, 10.0f,
	// Top center
	11.0f, 4.0f, 3.0f,
	11.0f, 4.0f,  -3.0f,
	11.0f, 10.0f, -3.0f,
	11.0f, 10.0f,3.0f,
	// Top right
	11.0f, 4.0f, -4.0f,
	11.0f, 4.0f,  -10.0f,
	11.0f, 10.0f, -10.0f,
	11.0f, 10.0f,-4.0f
};
static const GLfloat top_side[] = {
	// Color
	0.0f,  0.0f,  1.0f,
	// Bottom left
	-10.0f, 11.0f, -10.0f,
	-4.0f, 11.0f, -10.0f,
	-4.0f, 11.0f, -4.0f,
	-10.0f, 11.0f, -4.0f,
	// Bottom center
	-3.0f, 11.0f, -10.0f,
	3.0f, 11.0f, -10.0f,
	3.0f, 11.0f, -4.0f,
	-3.0f, 11.0f, -4.0f,
	// Bottom right
	4.0f, 11.0f, -10.0f,
	10.0f, 11.0f, -10.0f,
	10.0f, 11.0f, -4.0f,
	4.0f, 11.0f, -4.0f,
	// Center left
	-10.0f, 11.0f, -3.0f,
	-4.0f, 11.0f, -3.0f,
	-4.0f, 11.0f, 3.0f,
	-10.0f, 11.0f, 3.0f,
	// Center center
	-3.0f, 11.0f, -3.0f,
	3.0f, 11.0f, -3.0f,
	3.0f, 11.0f, 3.0f,
	-3.0f, 11.0f, 3.0f,
	// Center right
	4.0f, 11.0f, -3.0f,
	10.0f, 11.0f, -3.0f,
	10.0f, 11.0f, 3.0f,
	4.0f, 11.0f, 3.0f,
	// Top left
	-10.0f, 11.0f, 4.0f,
	-4.0f, 11.0f, 4.0f,
	-4.0f, 11.0f, 10.0f,
	-10.0f, 11.0f, 10.0f,
	// Top center
	-3.0f, 11.0f, 4.0f,
	3.0f, 11.0f, 4.0f,
	3.0f, 11.0f, 10.0f,
	-3.0f, 11.0f, 10.0f,
	// Top right
	4.0f, 11.0f, 4.0f,
	10.0f, 11.0f, 4.0f,
	10.0f, 11.0f, 10.0f,
	4.0f, 11.0f, 10.0f
};
static const GLfloat bottom_side[] = {
	// Color
	0.0f,  1.0f,  0.0f,
	// Bottom left
	-10.0f, -11.0f, -10.0f,
	-4.0f, -11.0f, -10.0f,
	-4.0f, -11.0f, -4.0f,
	-10.0f, -11.0f, -4.0f,
	// Bottom center
	-3.0f, -11.0f, -10.0f,
	3.0f, -11.0f, -10.0f,
	3.0f, -11.0f, -4.0f,
	-3.0f, -11.0f, -4.0f,
	// Bottom right
	4.0f, -11.0f, -10.0f,
	10.0f, -11.0f, -10.0f,
	10.0f, -11.0f, -4.0f,
	4.0f, -11.0f, -4.0f,
	// Center left
	-10.0f, -11.0f, -3.0f,
	-4.0f, -11.0f, -3.0f,
	-4.0f, -11.0f, 3.0f,
	-10.0f, -11.0f, 3.0f,
	// Center center
	-3.0f, -11.0f, -3.0f,
	3.0f, -11.0f, -3.0f,
	3.0f, -11.0f, 3.0f,
	-3.0f, -11.0f, 3.0f,
	// Center right
	4.0f, -11.0f, -3.0f,
	10.0f, -11.0f, -3.0f,
	10.0f, -11.0f, 3.0f,
	4.0f, -11.0f, 3.0f,
	// Top left
	-10.0f, -11.0f, 4.0f,
	-4.0f, -11.0f, 4.0f,
	-4.0f, -11.0f, 10.0f,
	-10.0f, -11.0f, 10.0f,
	// Top center
	-3.0f, -11.0f, 4.0f,
	3.0f, -11.0f, 4.0f,
	3.0f, -11.0f, 10.0f,
	-3.0f, -11.0f, 10.0f,
	// Top right
	4.0f, -11.0f, 4.0f,
	10.0f, -11.0f, 4.0f,
	10.0f, -11.0f, 10.0f,
	4.0f, -11.0f, 10.0f
};

void draw_frame() {
	// Gambar frame hitam di keenam sisi rubik

	// Frame depan dan belakang
	float z = 11.0f;
	for (int j = 0; j < 2; j++) {
		float y = -11.0f;
		for (int i = 0; i < 4; i++) {
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(-11.0f, y, z);
			glVertex3f(11.0f, y, z);
			glVertex3f(11.0f, y + 1, z);
			glVertex3f(-11.0f, y + 1, z);
			glEnd();
			y += 7;
		}
		float x = -11.0f;
		for (int i = 0; i < 4; i++) {
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(x, -11.0f, z);
			glVertex3f(x + 1, -11.0f, z);
			glVertex3f(x + 1, 11.0f, z);
			glVertex3f(x, 11.0f, z);
			glEnd();
			x += 7;
		}
		z = z * -1;
	}

	// Frame kanan dan kiri
	float x = 11.0f;
	for (int j = 0; j < 2; j++) {
		float y = -11.0f;
		for (int i = 0; i < 4; i++) {
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(x, y, -11.0f);
			glVertex3f(x, y, 11.0f);
			glVertex3f(x, y + 1, 11.0f);
			glVertex3f(x, y + 1, -11.0f);
			glEnd();
			y += 7;
		}
		float z = -11.0f;
		for (int i = 0; i < 4; i++) {
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(x, -11.0f, z);
			glVertex3f(x, -11.0f, z+1);
			glVertex3f(x, 11.0f, z+1);
			glVertex3f(x, 11.0f, z);
			glEnd();
			z += 7;
		}
		x = x * -1;
	}

	// Frame atas dan bawah
	float y = 11.0f;
	for (int j = 0; j < 2; j++) {
		float x = -11.0f;
		for (int i = 0; i < 4; i++) {
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(x, y, -11.0f);
			glVertex3f(x+1, y, -11.0f);
			glVertex3f(x+1, y, 11.0f);
			glVertex3f(x, y, 11.0f);
			glEnd();
			x += 7;
		}
		float z = -11.0f;
		for (int i = 0; i < 4; i++) {
			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(-11.0f, y, z);
			glVertex3f(11.0f, y, z);
			glVertex3f(11.0f, y, z+1);
			glVertex3f(-11.0f, y, z+1);
			glEnd();
			z += 7;
		}
		y = y * -1;
	}
}

void draw_rubic() {
	draw_frame();
	// Draw front
	for (int i = 3; i < 111; i+=12) {
		glBegin(GL_QUADS);
		glColor3f(front_side[0], front_side[1], front_side[2]);
		glVertex3f(front_side[i], front_side[i+1], front_side[i+2]);
		glVertex3f(front_side[i+3], front_side[i+4], front_side[i+5]);
		glVertex3f(front_side[i+6], front_side[i+7], front_side[i+8]);
		glVertex3f(front_side[i+9], front_side[i+10], front_side[i+11]);
		glEnd();
	}
	// Draw back
	for (int i = 3; i < 111; i += 12) {
		glBegin(GL_QUADS);
		glColor3f(back_side[0], back_side[1], back_side[2]);
		glVertex3f(back_side[i], back_side[i + 1], back_side[i + 2]);
		glVertex3f(back_side[i + 3], back_side[i + 4], back_side[i + 5]);
		glVertex3f(back_side[i + 6], back_side[i + 7], back_side[i + 8]);
		glVertex3f(back_side[i + 9], back_side[i + 10], back_side[i + 11]);
		glEnd();
	}
	// Draw left
	for (int i = 3; i < 111; i += 12) {
		glBegin(GL_QUADS);
		glColor3f(left_side[0], left_side[1], left_side[2]);
		glVertex3f(left_side[i], left_side[i + 1], left_side[i + 2]);
		glVertex3f(left_side[i + 3], left_side[i + 4], left_side[i + 5]);
		glVertex3f(left_side[i + 6], left_side[i + 7], left_side[i + 8]);
		glVertex3f(left_side[i + 9], left_side[i + 10], left_side[i + 11]);
		glEnd();
	}
	// Draw right
	for (int i = 3; i < 111; i += 12) {
		glBegin(GL_QUADS);
		glColor3f(right_side[0], right_side[1], right_side[2]);
		glVertex3f(right_side[i], right_side[i + 1], right_side[i + 2]);
		glVertex3f(right_side[i + 3], right_side[i + 4], right_side[i + 5]);
		glVertex3f(right_side[i + 6], right_side[i + 7], right_side[i + 8]);
		glVertex3f(right_side[i + 9], right_side[i + 10], right_side[i + 11]);
		glEnd();
	}
	// Draw top
	for (int i = 3; i < 111; i += 12) {
		glBegin(GL_QUADS);
		glColor3f(top_side[0], top_side[1], top_side[2]);
		glVertex3f(top_side[i], top_side[i + 1], top_side[i + 2]);
		glVertex3f(top_side[i + 3], top_side[i + 4], top_side[i + 5]);
		glVertex3f(top_side[i + 6], top_side[i + 7], top_side[i + 8]);
		glVertex3f(top_side[i + 9], top_side[i + 10], top_side[i + 11]);
		glEnd();
	}
	// Draw bottom
	for (int i = 3; i < 111; i += 12) {
		glBegin(GL_QUADS);
		glColor3f(bottom_side[0], bottom_side[1], bottom_side[2]);
		glVertex3f(bottom_side[i], bottom_side[i + 1], bottom_side[i + 2]);
		glVertex3f(bottom_side[i + 3], bottom_side[i + 4], bottom_side[i + 5]);
		glVertex3f(bottom_side[i + 6], bottom_side[i + 7], bottom_side[i + 8]);
		glVertex3f(bottom_side[i + 9], bottom_side[i + 10], bottom_side[i + 11]);
		glEnd();
	}
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

	float angle = 0.0f;

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

		// Rotate axis
		glRotatef(angle, 1, 1, 0.5);
		angle += 0.01f;

		// Draw rubic
		draw_rubic();

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