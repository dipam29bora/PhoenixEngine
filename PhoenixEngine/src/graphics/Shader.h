#pragma once

#include <iostream>
#include <vector>
#include "../maths/maths.h"
#include "GL/glew.h"

namespace phoenix
{
	namespace graphics
	{
		class Shader
		{
		private:
			GLuint m_shaderID;
			const char* m_Vertpath;
			const char* m_Fragpath;

		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void Enable() const;
			void Disable() const;

			void SetUniform1f(const GLchar* name, float value);
			void SetUniform1i(const GLchar* name, int value);
			void SetUniform2f(const GLchar* name, const maths::vec2& value);
			void SetUniform3f(const GLchar* name, const maths::vec3& value);
			void SetUniform4f(const GLchar* name, const maths::vec4& value);
			void SetUniformMat4(const GLchar* name, const maths::mat4& value);

		private:
			GLuint Load();
			GLint GetUniformLocation(const GLchar* name) const;
		};

	}
}