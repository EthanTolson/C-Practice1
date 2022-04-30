#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "checkersGame.h"

using namespace std;
using namespace checkers;

//Vertex source code and fragment source code are copy/pasted as per the tutorial that I am following
//Vertex Shader Source Code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";


int main()
{
	//initialize glfw
	glfwInit();
	//tell it what version we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//points on the screen to draw shapes between
	//{ y axis, x axis, z axis}
	// I put them into groups of 5 to see how GL is rendering the triangles 
	// should create a triangle between vertices 1-3 and 3-5 to form a square
	GLfloat vertices[] =
	{
		-0.8f, -0.6f, 0.0f,
		-0.6f, -0.6f, 0.0f,
		-0.6f, -0.4f, 0.0f,
		-0.8f, -0.4f, 0.0f,
		-0.8f, -0.6f, 0.0f,

		-0.8f, -0.2f, 0.0f,
		-0.6f, -0.2f, 0.0f,
		-0.6f, 0.0f, 0.0f,
		-0.8f, 0.0f, 0.0f,
		-0.8f, -0.2f, 0.0f,

		-0.8f, 0.2f, 0.0f,
		-0.6f, 0.2f, 0.0f,
		-0.6f, 0.4f, 0.0f,
		-0.8f, 0.4f, 0.0f,
		-0.8f, 0.2f, 0.0f,

		-0.8f, 0.6f, 0.0f,
		-0.6f, 0.6f, 0.0f,
		-0.6f, 0.8f, 0.0f,
		-0.8f, 0.8f, 0.0f,
		-0.8f, 0.6f, 0.0f,

		-0.6f, -0.8f, 0.0f,
		-0.4f, -0.8f, 0.0f,
		-0.4f, -0.6f, 0.0f,
		-0.6f, -0.6f, 0.0f,
		-0.6f, -0.8f, 0.0f,

		-0.6f, -0.4f, 0.0f,
		-0.4f, -0.4f, 0.0f,
		-0.4f, -0.2f, 0.0f,
		-0.6f, -0.2f, 0.0f,
		-0.6f, -0.4f, 0.0f,

		-0.6f, 0.0f, 0.0f,
		-0.4f, 0.0f, 0.0f,
		-0.4f, 0.2f, 0.0f,
		-0.6f, 0.2f, 0.0f,
		-0.6f, 0.0f, 0.0f,

		-0.6f, 0.4f, 0.0f,
		-0.4f, 0.4f, 0.0f,
		-0.4f, 0.6f, 0.0f,
		-0.6f, 0.6f, 0.0f,
		-0.6f, 0.4f, 0.0f,

		-0.4f, -0.6f, 0.0f,
		-0.2f, -0.6f, 0.0f,
		-0.2f, -0.4f, 0.0f,
		-0.4f, -0.4f, 0.0f,
		-0.4f, -0.6f, 0.0f,

		-0.4f, -0.2f, 0.0f,
		-0.2f, -0.2f, 0.0f,
		-0.2f, 0.0f, 0.0f,
		-0.4f, 0.0f, 0.0f,
		-0.4f, -0.2f, 0.0f,

		-0.4f, 0.2f, 0.0f,
		-0.2f, 0.2f, 0.0f,
		-0.2f, 0.4f, 0.0f,
		-0.4f, 0.4f, 0.0f,
		-0.4f, 0.2f, 0.0f,

		-0.4f, 0.6f, 0.0f,
		-0.2f, 0.6f, 0.0f,
		-0.2f, 0.8f, 0.0f,
		-0.4f, 0.8f, 0.0f,
		-0.4f, 0.6f, 0.0f,
		
		-0.2f, -0.8f, 0.0f,
		0.0f, -0.8f, 0.0f,
		0.0f, -0.6f, 0.0f,
		-0.2f, -0.6f, 0.0f,
		-0.2f, -0.8f, 0.0f,

		-0.2f, -0.4f, 0.0f,
		0.0f, -0.4f, 0.0f,
		0.0f, -0.2f, 0.0f,
		-0.2f, -0.2f, 0.0f,
		-0.2f, -0.4f, 0.0f,

		-0.2f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.2f, 0.0f,
		-0.2f, 0.2f, 0.0f,
		-0.2f, 0.0f, 0.0f,

		-0.2f, 0.4f, 0.0f,
		0.0f, 0.4f, 0.0f,
		0.0f, 0.6f, 0.0f,
		-0.2f, 0.6f, 0.0f,
		-0.2f, 0.4f, 0.0f,

		0.0f, -0.6f, 0.0f,
		0.2f, -0.6f, 0.0f,
		0.2f, -0.4f, 0.0f,
		0.0f, -0.4f, 0.0f,
		0.0f, -0.6f, 0.0f,

		0.0f, -0.2f, 0.0f,
		0.2f, -0.2f, 0.0f,
		0.2f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -0.2f, 0.0f,

		0.0f, 0.2f, 0.0f,
		0.2f, 0.2f, 0.0f,
		0.2f, 0.4f, 0.0f,
		0.0f, 0.4f, 0.0f,
		0.0f, 0.2f, 0.0f,

		0.0f, 0.6f, 0.0f,
		0.2f, 0.6f, 0.0f,
		0.2f, 0.8f, 0.0f,
		0.0f, 0.8f, 0.0f,
		0.0f, 0.6f, 0.0f,

		0.2f, -0.8f, 0.0f,
		0.4f, -0.8f, 0.0f,
		0.4f, -0.6f, 0.0f,
		0.2f, -0.6f, 0.0f,
		0.2f, -0.8f, 0.0f,

		0.2f, -0.4f, 0.0f,
		0.4f, -0.4f, 0.0f,
		0.4f, -0.2f, 0.0f,
		0.2f, -0.2f, 0.0f,
		0.2f, -0.4f, 0.0f,

		0.2f, 0.0f, 0.0f,
		0.4f, 0.0f, 0.0f,
		0.4f, 0.2f, 0.0f,
		0.2f, 0.2f, 0.0f,
		0.2f, 0.0f, 0.0f,

		0.2f, 0.4f, 0.0f,
		0.4f, 0.4f, 0.0f,
		0.4f, 0.6f, 0.0f,
		0.2f, 0.6f, 0.0f,
		0.2f, 0.4f, 0.0f,

		0.4f, -0.6f, 0.0f,
		0.6f, -0.6f, 0.0f,
		0.6f, -0.4f, 0.0f,
		0.4f, -0.4f, 0.0f,
		0.4f, -0.6f, 0.0f,

		0.4f, -0.2f, 0.0f,
		0.6f, -0.2f, 0.0f,
		0.6f, 0.0f, 0.0f,
		0.4f, 0.0f, 0.0f,
		0.4f, -0.2f, 0.0f,

		0.4f, 0.2f, 0.0f,
		0.6f, 0.2f, 0.0f,
		0.6f, 0.4f, 0.0f,
		0.4f, 0.4f, 0.0f,
		0.4f, 0.2f, 0.0f,

		0.4f, 0.6f, 0.0f,
		0.6f, 0.6f, 0.0f,
		0.6f, 0.8f, 0.0f,
		0.4f, 0.8f, 0.0f,
		0.4f, 0.6f, 0.0f,

		0.6f, -0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
		0.8f, -0.6f, 0.0f,
		0.6f, -0.6f, 0.0f,
		0.6f, -0.8f, 0.0f,

		0.6f, -0.4f, 0.0f,
		0.8f, -0.4f, 0.0f,
		0.8f, -0.2f, 0.0f,
		0.6f, -0.2f, 0.0f,
		0.6f, -0.4f, 0.0f,

		0.6f, 0.0f, 0.0f,
		0.8f, 0.0f, 0.0f,
		0.8f, 0.2f, 0.0f,
		0.6f, 0.2f, 0.0f,
		0.6f, 0.0f, 0.0f,

		0.6f, 0.4f, 0.0f,
		0.8f, 0.4f, 0.0f,
		0.8f, 0.6f, 0.0f,
		0.6f, 0.6f, 0.0f,
		0.6f, 0.4f, 0.0f,

		-0.8f, -0.8f, 0.0f,
		-0.8f, 0.8f, 0.0f,
		0.8f, 0.8f, 0.0f,
		0.8f, -0.8f, 0.0f
	};

	//create a window of size 800 800 with name checkersboard
	GLFWwindow* window = glfwCreateWindow(800, 800, "Checkers Board", NULL, NULL);

	//make sure window opens
	if (window == NULL)
	{
		cout << "Failed to create window.\n";
		glfwTerminate();
		return -1;
	}

	//introduce window into current context
	glfwMakeContextCurrent(window);

	//load GLAD to configure opengl
	gladLoadGL();

	//specify the viewport
	glViewport(0,0,800,800);

	//create shaders and use unsigned integer to store memory location
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//create shader program
	GLuint shaderProgram = glCreateProgram();
	//add shaders to program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//delete shaders after they have been added
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	//use unsigned int to store memory location of vertex array object and vertex buffer object
	GLuint VAO, VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//vertex has x y and z values ie 3 floats
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//make background black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//clear back buffer and load new background color
	glClear(GL_COLOR_BUFFER_BIT);
	//swap buffers
	glfwSwapBuffers(window);

	//display window while it is not closed
	while (!glfwWindowShouldClose(window))
	{
		//background color
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		//draw board
		//draw triangles start at point in vertices and how many points to connect
		for (int i = 0; i < 32*5; i = i + 5)
		{
			glDrawArrays(GL_TRIANGLES, i, 3);
			glDrawArrays(GL_TRIANGLES, i + 2, 3);
		}
		glDrawArrays(GL_LINE_LOOP, 32*5, 4);
		//refresh buffer to show board
		glfwSwapBuffers(window);

		glfwPollEvents();
	}


	//remove things from memory
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	//get rid of window and terminate glfw
	glfwDestroyWindow(window);
	glfwTerminate();

	checkersGame checkers;
	int i = 0;
	while (i < 50 || !checkers.checkWin())
	{
		checkers.play();
		i++;
	}
	//exit code
	return 0;
}