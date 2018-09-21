#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEY				1024
#define MAX_MOUSE_BUTTON	32

namespace phoenix
{
	namespace graphics
	{
		class Window
		{ 

		private:
			
			const char* m_title;
			int m_width;
			int m_height;
			bool m_closed;
			GLFWwindow *m_window;

			bool m_Keys[MAX_KEY];
			bool m_MouseButtons[MAX_MOUSE_BUTTON];
			double m_xpos, m_ypos;

		public:
			Window(const char* title, const int width, const int height);
			~Window();

			void Clear() const;
			void Update();
			bool Closed() const;
			
			inline int GetWidth() const { return m_width; }
			inline int GetHeight() const { return m_width; }

			bool isKeyPressed(unsigned int keycode) const;
			bool isMousePressed(unsigned int keycode) const;
			void MousePosition(double& x, double& y) const;


		private:
			bool init() ;
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos);

		};
	}
}
