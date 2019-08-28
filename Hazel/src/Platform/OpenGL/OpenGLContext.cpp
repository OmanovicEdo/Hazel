#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hazel {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle) 
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null");
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize glad!");

		HZ_CORE_INFO("OpenGL info:");
		HZ_CORE_INFO("  Vendor: {}", glGetString(GL_VENDOR));
		HZ_CORE_INFO("  Renderer {}", glGetString(GL_RENDERER));
		HZ_CORE_INFO("  Version: {}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(m_WindowHandle);
	}

}