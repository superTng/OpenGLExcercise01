#include "MyWindow.h"
#include<iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include "MyInput.h"
#include "MyTriangle.h"

void MyWindow::DrawWindow()
{
	//����������
	MyInput* myInput = new MyInput(); 


	printf("��ʼ���ƴ���!");
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//��OpenGL glfw window 
	GLFWwindow* window = glfwCreateWindow(900, 600, "Hello World", NULL, NULL);
	if (window == NULL)
	{
		printf("��Windowʧ�ܣ�");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	//��ʼ�� glew
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("��ʼ�� GLEW ʧ�ܣ�");
		glfwTerminate();
		return;
	}
	glViewport(0, 0, 900, 600);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//ֻ������ GL_BACK  GL_FRONT
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//��ʼ����������
	MyTriangle* myTriangle = new MyTriangle();

	//����������û�йر� ����ˢ�µ�ǰ����
	while (!glfwWindowShouldClose(window))
	{
		//���� ESC �˳��������
		myInput->ProcessInputKey_GlfwSetWindowShouldClose(window,GLFW_KEY_ESCAPE);

		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myTriangle->GlUseProgram();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();



}
