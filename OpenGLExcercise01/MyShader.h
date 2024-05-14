#pragma once
#include<string>
using namespace std;
class MyShader
{
public:
	string vertexString;
	string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;
	unsigned int ID;//Shader Program ID

public:
	MyShader(const char* vertexPath, const char* fragmentPath);
	void useShader();

private:
	void checkCompileErrors(unsigned int ID,string type);
};

