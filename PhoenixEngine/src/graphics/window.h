#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


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

		public:
			Window(const char* title, const int width, const int height);
			~Window();

		public:
			bool init() ;
			void Clear() const;
			void Update();
			bool Closed() const;
			
			inline int GetWidth() const { return m_width; }
			inline int GetHeight() const { return m_width; }
		
		};
	}
}
