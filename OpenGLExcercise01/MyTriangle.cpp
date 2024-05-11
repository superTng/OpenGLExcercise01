#include "MyTriangle.h"
#include <GL/glew.h>

float vertices[] =
{
	-0.5f,-0.5f,0.0f,
	0.5f,-0.5f,0.0f,
	0.0f,0.5f,0.0f
};


unsigned int VAO;
MyTriangle::MyTriangle()
{
	DrawVAO();
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
"layout (location = 0) in vec3 aPos;               \n"
"void main()                                       \n"
"{gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}\n";


unsigned int fragmentShader;
const char* fragmentShaderSource =
"#version 330 core                           \n"
"out vec4 FragColor;                         \n"
"void main()                                 \n"
"{FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);} \n";


unsigned int shaderProgram;

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

	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
	glEnableVertexAttribArray(0);
}




unsigned int VCO;
void MyTriangle::DrawVCO()
{
	
}

void MyTriangle::GlUseProgram()
{
	glBindVertexArray(VAO);
	glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}


