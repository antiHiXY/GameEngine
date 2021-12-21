#include "engnpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Engine
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ENGN_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ENGN_CORE_ASSERT(status, "Failed to initialize Glad!");

		ENGN_CORE_INFO("OpenGL Info:");
		ENGN_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ENGN_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ENGN_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}