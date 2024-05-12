#pragma once
#include<string>
using namespace std;
class MyShader
{
public:
	MyShader(const char* vertexPath, const char* fragmentPath);
	string vertexString;
	string fragmentString;
	const char* vertexSource;
	const char* fragmentSource;
};

