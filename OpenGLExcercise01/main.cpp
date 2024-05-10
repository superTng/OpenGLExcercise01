
#include<iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>


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

	//如果这个窗口没有关闭
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}