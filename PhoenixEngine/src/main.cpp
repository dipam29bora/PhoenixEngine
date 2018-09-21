#include "graphics/window.h"

int main()
{

	using namespace phoenix;
	using namespace graphics;

	Window window("Phoenix Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed())
	{
		window.Clear();
		
		double x, y;
		window.MousePosition(x, y);
		std::cout << x << " , " << y << std::endl;

#if 0
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#endif

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.Update();
	}

	return 0;
}