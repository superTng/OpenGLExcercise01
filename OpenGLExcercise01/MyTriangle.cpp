#include "MyTriangle.h"
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include "MyShader.h"
//三角形的顶点数组
float vertices[] =
{
	-0.5f,0.5f,0.0f,1.0f,0,0,
	0.5f,0.5f,0.0f,0,1.0f,0,
	0.0f,0.0f,0.0f,0,0,1.0f,
	-0.5f,-0.5f,0.0f,0.5f,0.5f,0.5f,
	0.5f,-0.5f,0.0f,0.5f,0,0.5f,
};

//三角形的顶点集合
unsigned int indices[] = 
{
	2,1,0,
	3,4,2
};

unsigned int VAO;

MyTriangle::MyTriangle(MyShader* shader)
{
	myShader = shader;
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
unsigned int fragmentShader;
unsigned int shaderProgram;
unsigned int EBO;
float timeValue = 0;
float greenValue = 0;


void MyTriangle::DrawVBO()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(6,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)0);
	glEnableVertexAttribArray(6);
	glVertexAttribPointer(7, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3*sizeof(float)));
	glEnableVertexAttribArray(7);
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
	myShader->useShader();
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
}


