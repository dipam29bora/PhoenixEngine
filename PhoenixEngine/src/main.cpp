#include "graphics/window.h"
//#include "maths/vec2.h"
#include "maths/math_func.h"

int main()
{

	using namespace phoenix;
	using namespace graphics;
	using namespace maths;

	Window window("Phoenix Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 a(9,10);
	vec2 b(9, 10);
	
	std::cout << (a==b?1:0) << std::endl;

	mat4 translate = mat4::Transtation(vec3(2, 3, 4));
	translate *= mat4::identity();
	while (!window.Closed())
	{
		window.Clear();
		

#if 1
		double x, y;
		window.MousePosition(x, y);
		std::cout << x << " , " << y << std::endl;
		
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