
#include "window.h"

namespace phoenix
{
	namespace graphics
	{

		void ResizeWindow(GLFWwindow* window, int width, int height);

		

		Window::Window(const char* title, int width, int height)
		{
			m_title = title;
			m_width = width;
			m_height = height;

				init();
			//if (!init())
			
		}

		Window::~Window()
		{
			
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize" << std::endl;
				glfwTerminate();
				return false;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

			if (!m_window)
			{
				std::cout << "Failed to create window" << std::endl;
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(m_window);
			
			glfwSetWindowSizeCallback(m_window, ResizeWindow);

			return true;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_window, &m_width, &m_height);
			glfwSwapBuffers(m_window);
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_window) ==1;
		}

		void ResizeWindow(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

	}
}