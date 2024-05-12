#include "MyWindow.h"
#include<iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include "MyInput.h"
#include "MyTriangle.h"

void MyWindow::DrawWindow()
{
	//创建输入类
	MyInput* myInput = new MyInput(); 


	printf("开始绘制窗口!");
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//打开OpenGL glfw window 
	GLFWwindow* window = glfwCreateWindow(900, 600, "Hello World", NULL, NULL);
	if (window == NULL)
	{
		printf("打开Window失败！");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	//初始化 glew
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("初始化 GLEW 失败！");
		glfwTerminate();
		return;
	}
	glViewport(0, 0, 900, 600);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//只画单面 GL_BACK  GL_FRONT
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//开始创建三角形
	MyTriangle* myTriangle = new MyTriangle();

	//如果这个窗口没有关闭 持续刷新当前窗口
	while (!glfwWindowShouldClose(window))
	{
		//按下 ESC 退出这个窗口
		myInput->ProcessInputKey_GlfwSetWindowShouldClose(window,GLFW_KEY_ESCAPE);

		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myTriangle->GlUseProgram();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();



}
