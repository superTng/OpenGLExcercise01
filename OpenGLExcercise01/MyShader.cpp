#include "MyShader.h"
#include <fstream>
#include<sstream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include <iostream>

using namespace std;

MyShader::MyShader(const char* vertexPath,const char* fragmentPath)
{
	ifstream vertexFile;
	ifstream fragmentFile;
	stringstream vertexSStream;
	stringstream fragmentSStream;

	vertexFile.open(vertexPath);
	fragmentFile.open(fragmentPath);

	vertexFile.exceptions(ifstream::failbit || ifstream::badbit);
	fragmentFile.exceptions(ifstream::failbit || ifstream::badbit);


	try
	{
		if (!vertexFile.is_open() || !fragmentFile.is_open())
		{
			throw exception("打开文件错误！");
		}

		vertexSStream << vertexFile.rdbuf();
		fragmentSStream << fragmentFile.rdbuf();

		vertexFile.close();
		fragmentFile.close();

		vertexString = vertexSStream.str();
		fragmentString = fragmentSStream.str();

		vertexSource = vertexString.c_str();
		fragmentSource = fragmentString.c_str();

		unsigned int vertex, fragment;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex,1,&vertexSource,NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex,"VERTEX");

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment,1,&fragmentSource,NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment,"FRAGMENT");

		ID = glCreateProgram();
		glAttachShader(ID,vertex);
		glAttachShader(ID,fragment);

		glLinkProgram(ID);
		checkCompileErrors(ID,"PROGRAM");
		glDeleteShader(vertex);
		glDeleteShader(fragment);

	}
	catch (const std::exception& ex)
	{
		throw ex.what();
	}
}

void MyShader::useShader()
{
	glUseProgram(ID);
}

void MyShader::checkCompileErrors(unsigned int ID, string type)
{
	int success;
	char infoLog[512];
	if (type != "PROGRAM")
	{
		glGetShaderiv(ID,GL_SYNC_STATUS,&success);
		if (!success)
		{
			glGetShaderInfoLog(ID,512,NULL,infoLog);
			std::cout << "Error::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n------------------------------" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			std::cout << "Error::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n------------------------------" << std::endl;
		}
	}
}


