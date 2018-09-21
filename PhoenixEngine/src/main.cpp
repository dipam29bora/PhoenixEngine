#include "graphics/window.h"

int main()
{

	using namespace phoenix;
	using namespace graphics;

	Window window("Phoenix Engine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	

	while (!window.Closed())
	{
		window.Clear();
		
		std::cout << window.GetWidth() << std::endl;
		std::cout << window.GetHeight() << std::endl;

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		window.Update();
	}

	return 0;
}