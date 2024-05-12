#include "MyTriangle.h"
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
//三角形的顶点数组
float vertices[] =
{
	-0.5f,0.5f,0.0f,
	0.5f,0.5f,0.0f,
	0.0f,0.0f,0.0f,
	-0.5f,-0.5f,0.0f,
	0.5f,-0.5f,0.0f,
};

//三角形的顶点集合
unsigned int indices[] = 
{
	2,1,0,
	3,4,2
};

unsigned int VAO;
MyTriangle::MyTriangle()
{
	DrawVAO();
	DrawEBO();
	DrawVBO();
}

void MyTriangle::DrawVAO()
{
	glGenVertexArrays(1,&VAO);
	glBindVertexArray(VAO);
}


unsigned int VBO;
unsigned int vertexShader;
const char* vertexShaderSource =
"#version 330 core                                 \n"
"layout (location = 6) in vec3 aPos;               \n"
"out vec4 vertexColor;                             \n"
"void main()                                       \n"
"{gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n"
"vertexColor=vec4(1.0,0,0,1.0);                    \n"
"}                                                 \n";


unsigned int fragmentShader;
const char* fragmentShaderSource =
"#version 330 core                           \n"
"in vec4 vertexColor;                        \n"
"uniform vec4 ourColor;                      \n"
"out vec4 FragColor;                         \n"
"void main()                                 \n"
"{FragColor = ourColor;}                     \n";


unsigned int shaderProgram;


unsigned int EBO;

void MyTriangle::DrawVBO()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram,vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glVertexAttribPointer(6,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
	glEnableVertexAttribArray(6);
}




void MyTriangle::DrawEBO()
{
	glGenBuffers(1,&EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices), indices,GL_STATIC_DRAW);
}

float timeValue = 0;
float greenValue = 0;
void MyTriangle::GlUseProgram()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);

	//获得时间
	timeValue = glfwGetTime();
	greenValue = (sin(timeValue) * 0.5f) + 0.5f;
	int vertexColorLocation = glGetUniformLocation(shaderProgram,"ourColor");

	glUseProgram(shaderProgram);
	glUniform4f(vertexColorLocation,0,greenValue,0,1.0f);
	//glDrawArrays(GL_TRIANGLES, 0, 6);

	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
}


