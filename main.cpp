#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "checkersGame.h"

using namespace std;
using namespace checkers;

//Vertex source code and fragment source code are copy/pasted as per the tutorial that I am following
//Vertex Shader Source Code
//ges location and color data sends color data to fragment shader
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"in layout (location = 1) vec3 vertexColor;\n"
"out vec3 theColor;"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"   theColor = vertexColor;"
"}\0";
//Fragment Shader source code
//gets color data from vertex shader
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 theColor;"
"void main()\n"
"{\n"
"   FragColor = vec4(theColor, 1.0f);\n"
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
	//1st line{ x axis, y axis, z axis}
	// 2nd line RGB values
	// I put them into groups of 5 to see how GL is rendering the triangles 
	// should create a triangle between vertices 1-3 and 3-5 to form a square
	GLfloat vertices[] =
	{
		//vertex x, y, z
		//color r g b
		-0.8f, -0.6f, 0.0f,
		 1.0f, 0.0f, 0.0f,
		-0.6f, -0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, -0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, -0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, -0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.8f, -0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, -0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, -0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.8f, 0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, 0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, 0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.8f, 0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.8f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, 0.8f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.8f, 0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.6f, -0.8f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, -0.8f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, -0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, -0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, -0.8f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.6f, -0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, -0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, -0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, -0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, -0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.6f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, 0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.6f, 0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, 0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, 0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.6f, 0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.4f, -0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.2f, -0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.2f, -0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, -0.4f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, -0.6f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.4f, -0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.2f, -0.2f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.2f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.4f, -0.2f, 0.0f, 
		1.0f, 0.0f, 0.0f,


		-0.4f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.4f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.4f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,

		-0.4f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.4f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.4f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		
		-0.2f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,

		-0.2f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,

		-0.2f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,

		-0.2f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.2f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.0f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.0f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, -0.2f, 0.0f, 
			1.0f, 0.0f, 0.0f,


		0.0f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.0f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.0f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.2f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.2f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.2f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.2f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.2f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.4f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, -0.4f, 0.0f, 
			1.0f, 0.0f, 0.0f,
		0.4f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.4f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.4f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.4f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.4f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.6f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, -0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, -0.6f, 0.0f, 
			1.0f, 0.0f, 0.0f,
		0.6f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.6f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, -0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, -0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, -0.4f, 0.0f, 
			1.0f, 0.0f, 0.0f,

		0.6f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.2f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,

		0.6f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, 0.4f, 0.0f, 
			1.0f, 0.0f, 0.0f,
		0.8f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.6f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.6f, 0.4f, 0.0f,
			1.0f, 0.0f, 0.0f,

		//vertices for outline
		-0.8f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		-0.8f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, 0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
		0.8f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,

		//Vertices for blue pieces
		//1-4
		-0.75f, -0.75f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.75, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.65f, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,

		-0.35f, -0.75f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.35, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.25f, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,

		0.05f, -0.75f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.05, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.15f, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,

		0.45f, -0.75f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.45, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.55f, -0.65f, 0.0f,
			0.0f, 0.0f, 1.0f,

		//5-8
		-0.55f, -0.55f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.55, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.45f, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,

		-0.15f, -0.55f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.15, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.05f, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,

		0.25f, -0.55f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.25, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.35f, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,

		0.65f, -0.55f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.65, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.75f, -0.45f, 0.0f,
			0.0f, 0.0f, 1.0f,

		//9-12
		-0.75f, -0.35f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.75, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.65f, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,

		-0.35f, -0.35f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.35, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,
		-0.25f, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,

		0.05f, -0.35f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.05, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.15f, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,

		0.45f, -0.35f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.45, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,
		0.55f, -0.25f, 0.0f,
			0.0f, 0.0f, 1.0f,

		//13-16
		-0.55f, -0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.55, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.45f, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,

		-0.15f, -0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.15, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.05f, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.25f, -0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.25, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.35f, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.65f, -0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.65, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.75f, -0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,

		//17-20
		-0.75f, 0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.75, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.65f, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,

		-0.35f, 0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.35, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.25f, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.05f, 0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.05, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.15f, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.45f, 0.05f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.45, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.55f, 0.15f, 0.0f,
		0.0f, 0.0f, 1.0f,

		//21-24
		-0.55f, 0.25f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.55, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.45f, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,

		-0.15f, 0.25f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.15, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.05f, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.25f, 0.25f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.25, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.35f, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.65f, 0.25f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.65, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.75f, 0.35f, 0.0f,
		0.0f, 0.0f, 1.0f,

		//25-28
		-0.75f, 0.45f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.75, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.65f, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,

		-0.35f, 0.45f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.35, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.25f, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.05f, 0.45f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.05, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.15f, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.45f, 0.45f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.45, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.55f, 0.55f, 0.0f,
		0.0f, 0.0f, 1.0f,

		//21-24
		-0.55f, 0.65f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.55, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.45f, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,

		-0.15f, 0.65f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.15, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,
		-0.05f, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.25f, 0.65f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.25, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.35f, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,

		0.65f, 0.65f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.65, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.75f, 0.75f, 0.0f,
		0.0f, 0.0f, 1.0f,


		//redpieces
		//1-4
		-0.75f, -0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.75, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.65f, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.35f, -0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.35, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.25f, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.05f, -0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.05, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.15f, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.45f, -0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.45, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.55f, -0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//5-8
		-0.55f, -0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.55, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.45f, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.15f, -0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.15, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.05f, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.25f, -0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.25, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.35f, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.65f, -0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.65, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.75f, -0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//9-12
		-0.75f, -0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.75, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.65f, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.35f, -0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.35, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.25f, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.05f, -0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.05, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.15f, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.45f, -0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.45, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.55f, -0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//13-16
		-0.55f, -0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.55, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.45f, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.15f, -0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.15, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.05f, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.25f, -0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.25, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.35f, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.65f, -0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.65, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.75f, -0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//17-20
		-0.75f, 0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.75, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.65f, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.35f, 0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.35, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.25f, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.05f, 0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.05, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.15f, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.45f, 0.05f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.45, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.55f, 0.15f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//21-24
		-0.55f, 0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.55, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.45f, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.15f, 0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.15, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.05f, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.25f, 0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.25, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.35f, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.65f, 0.25f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.65, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.75f, 0.35f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//25-28
		-0.75f, 0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.75, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.65f, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.35f, 0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.35, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.25f, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.05f, 0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.05, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.15f, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.45f, 0.45f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.45, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.55f, 0.55f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//29-32
		-0.55f, 0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.55, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.45f, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,

		-0.15f, 0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.15, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		-0.05f, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.25f, 0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.25, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.35f, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.65f, 0.65f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.65, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.75f, 0.75f, 0.0f,
		1.0f, 0.0f, 0.0f,

		//king distinction
		//1-4
		-0.725f, -0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.725, -0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.675f, -0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.325f, -0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.325, -0.677f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.275f, -0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.075f, -0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.075, -0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.125f, -0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.475f, -0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.475, -0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.525f, -0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//5-8
		-0.525f, -0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.525, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.475f, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.125f, -0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.125, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.075f, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.275f, -0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.275, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.325f, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.675f, -0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.675, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.725f, -0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//9-12
		-0.725f, -0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.725, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.675f, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.325f, -0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.325, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.275f, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.075f, -0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.075, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.125f, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.475f, -0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.475, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.525f, -0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//13-16
		-0.525f, -0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.525, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.475f, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.125f, -0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.125, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.075f, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.275f, -0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.275, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.325f, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.675f, -0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.675, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.725f, -0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//17-20
		-0.725f, 0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.725, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.675f, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.325f, 0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.325, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.275f, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.075f, 0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.075, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.125f, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.475f, 0.075f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.475, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.525f, 0.125f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//21-24
		-0.525f, 0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.525, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.475f, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.125f, 0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.125, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.075f, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.275f, 0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.275, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.325f, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.675f, 0.275f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.675, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.725f, 0.325f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//25-28
		-0.725f, 0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.725, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.675f, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.325f, 0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.325, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.275f, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.075f, 0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.075, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.125f, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.475f, 0.475f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.475, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.525f, 0.525f, 0.0f,
		1.0f, 1.0f, 1.0f,

		//29-32
		-0.525f, 0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.525, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.475f, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.125f, 0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.125, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		-0.075f, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.275f, 0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.275, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.325f, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.675f, 0.675f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.675, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f,
		0.725f, 0.725f, 0.0f,
		1.0f, 1.0f, 1.0f

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

	//vertex position has x y and z values  = 3 floats
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	//vertex color has 3 floats
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(sizeof(float) * 3));

	glEnableVertexAttribArray(1);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindVertexArray(1);

	//make background black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//clear back buffer and load new background color
	glClear(GL_COLOR_BUFFER_BIT);
	//swap buffers
	glfwSwapBuffers(window);

	//create checkers object
	checkersGame checkers;

	//display window while it is not closed and game is not over
	while (!glfwWindowShouldClose(window) || !checkers.checkWin())
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

		//draw blue pieces
		for (int i = 0; i < 12; i++)
		{
			if (checkers.bluePieces[i] != 0)
			{
				//blue piece vertices are from 32 * 5  + 4 to 32 * 3 + 32*5  + 4
				glDrawArrays(GL_TRIANGLES, ((checkers.bluePieces[i] - 1) * 3) + (32 * 5 + 4), 3);
			}
		}

		//draw red pieces
		for (int i = 0; i < 12; i++)
		{
			if (checkers.redPieces[i] != 0)
			{
				//red piece vertices are from 32 * 3 + 32*5  + 4 to 32 * 3 + 32*5 *2  + 4
				glDrawArrays(GL_TRIANGLES, ((checkers.redPieces[i] - 1) * 3) + (32 * 5 + 4 + (32 * 3)), 3);
			}
		}
		//draw extra distinction for kings
		for (int i = 0; i < 32; i++)
		{
			if (checkers.position[i] > 2)
			{
				//vertices are from 32 * 3 + 32*5 *2  + 4 to sizeof(vertices)/2
				glDrawArrays(GL_TRIANGLES, (i * 3) + (32 * 5 + 4 + ((32 * 3) * 2)), 3);
			}
		}


		
		//refresh buffer to show board
		glfwSwapBuffers(window);

		glfwPollEvents();

		//start checkers game
		checkers.play();
	}


	//remove things from memory
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	//get rid of window and terminate glfw
	glfwDestroyWindow(window);
	glfwTerminate();

	//exit code
	return 0;
}