#include "MyInput.h"

void MyInput::ProcessInputKey_GlfwSetWindowShouldClose(GLFWwindow* window,int key)
{
	if (glfwGetKey(window, key) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
