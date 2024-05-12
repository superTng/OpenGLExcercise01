#include "MyShader.h"
#include <fstream>
#include<sstream>
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

		printf(vertexSource);
		printf(fragmentSource);

	}
	catch (const std::exception& ex)
	{
		throw ex.what();
	}
}


