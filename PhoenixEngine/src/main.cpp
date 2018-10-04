#include "graphics/window.h"
#include "maths/math_func.h"
#include "graphics/Shader.h"

int main()
{

	using namespace phoenix;
	using namespace graphics;
	using namespace maths;

	Window window("Phoenix Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);




	GLfloat vertices[] =
	{
		 0.0f,  0.0f, 0.0f,
		10.0f,  0.0f, 0.0f,
		10.0f,  4.0f, 0.0f,
		10.0f,  4.0f, 0.0f,
		 0.0f,  4.0f, 0.0f,
		 0.0f,  0.0f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/Shader/vertex.vert", "src/Shader/Fragment.frag");
	shader.Enable();
	
	//glUniformMatrix4fv(glGetUniformLocation(shader.m_shaderID, "projectionMatrix"), 1, GL_FALSE, ortho.elements);
	shader.SetUniformMat4("projectionMatrix", ortho);
	//shader.SetUniformMat4("modelMatrix", mat4::Rotation(45.0f, vec3(0, 0, 1)));

	shader.SetUniform2f("light_pos", vec2(5.0f, 2.0f));
	shader.SetUniform4f("colour", vec4(0.0f, 1.0f, 0.0f, 1.0f));

	while (!window.Closed())
	{
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}

	return 0;
}