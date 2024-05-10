
#include<iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include "main.h"


int main()
{
	printf("��ʼ���ƴ���!");
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


	//��OpenGL glfw window 
	GLFWwindow* window = glfwCreateWindow(900,600,"Hello World",NULL,NULL);
	if (window == NULL)
	{
		printf("��Windowʧ�ܣ�");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//init glew
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("��ʼ�� GLEW ʧ�ܣ�");
		glfwTerminate();
		return -1;
	}
	glViewport(0,0,900,600);

	//����������û�йر� ����ˢ�µ�ǰ����
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);//���� ESC �˳��������

		glClearColor(0.2f,0.3f,0.2f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);//draw Window����
		glfwPollEvents();


	}

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window,true);
	}
}
