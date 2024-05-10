
#include<iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include "main.h"


int main()
{
	printf("开始绘制窗口!");
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


	//打开OpenGL glfw window 
	GLFWwindow* window = glfwCreateWindow(900,600,"Hello World",NULL,NULL);
	if (window == NULL)
	{
		printf("打开Window失败！");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//init glew
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("初始化 GLEW 失败！");
		glfwTerminate();
		return -1;
	}
	glViewport(0,0,900,600);

	//如果这个窗口没有关闭 持续刷新当前窗口
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);//按下 ESC 退出这个窗口

		glClearColor(0.2f,0.3f,0.2f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);//draw Window窗口
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
