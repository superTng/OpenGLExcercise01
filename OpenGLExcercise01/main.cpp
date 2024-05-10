
#include<iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>


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

	//����������û�йر�
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}