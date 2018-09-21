
#include "window.h"

namespace phoenix
{

	namespace graphics
	{
		/* if static we need
		bool Window::m_Keys[MAX_KEY];
		bool Window::m_MouseButtons[MAX_MOUSE_BUTTON];
		double Window::m_xpos;
		double Window::m_ypos;*/
	
		//Callback Methods
		void resize_window(GLFWwindow* window, int width, int height);
		
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos);

		Window::Window(const char* title, int width, int height)
		{

			m_title = title;
			m_width = width;
			m_height = height;

			if (!init())
				glfwTerminate();
			
			for (int i=0; i<MAX_KEY; i++)
			{
				m_Keys[i] = false;
			}
			for (int i=0; i<MAX_MOUSE_BUTTON; i++)
			{
				m_MouseButtons[i] = false;
			}
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
			

			//All the callback from here
			glfwSetWindowUserPointer(m_window, this);
			glfwSetWindowSizeCallback(m_window, resize_window);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, mouse_position_callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Enable to Initialize GLEW!" << std::endl;
				return false;
			}

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

		bool Window::isKeyPressed(unsigned int keycode) const
		{
			//log
			if (keycode >= MAX_KEY)
				return false;

			return m_Keys[keycode];
		}

		bool Window::isMousePressed(unsigned int keycode) const
		{
			//log
			if (keycode >= MAX_MOUSE_BUTTON)
				return false;

			return m_MouseButtons[keycode];
		}

		void Window::MousePosition(double& x, double& y) const
		{
			//log
			x=m_xpos;
			y=m_ypos;
		}

		void resize_window(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
		
		
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_xpos = x_pos;
			win->m_ypos = y_pos;
		}
	}
}