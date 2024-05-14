#pragma once
#include "MyShader.h"
class MyTriangle
{
public:
	MyTriangle(MyShader* shader);
public:
	void DrawVAO();
	void DrawVBO();
	void DrawEBO();
	void GlUseProgram();

private:
	MyShader* myShader;
};

