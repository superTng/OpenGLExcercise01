#include "MyTriangle.h"
#include <GL/glew.h>

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
	0,1,2,
	2,3,4
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
"void main()                                       \n"
"{gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}\n";


unsigned int fragmentShader;
const char* fragmentShaderSource =
"#version 330 core                           \n"
"out vec4 FragColor;                         \n"
"void main()                                 \n"
"{FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);} \n";


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

void MyTriangle::GlUseProgram()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glUseProgram(shaderProgram);
	//glDrawArrays(GL_TRIANGLES, 0, 6);

	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
}


