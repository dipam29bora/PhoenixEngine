#include "Shader.h"
#include <string>
#include "../Utilities/fileutilitites.h"

namespace phoenix
{
	namespace graphics
	{

		Shader::Shader(const char* vertPath, const char* fragPath)
			: m_Vertpath(vertPath), m_Fragpath(fragPath)
		{
			m_shaderID = Load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_shaderID);
		}

		void Shader::Enable() const
		{
			glUseProgram(m_shaderID);
		}

		void Shader::Disable() const
		{
			glUseProgram(0);
		}

		/** TODO :: this process is very slow so we need to cache this operation while optimizing the code */
		GLint Shader::GetUniformLocation(const GLchar* name) const
		{
			return glGetUniformLocation(m_shaderID, name);
		}

		void Shader::SetUniform1f(const GLchar* name, float value)
		{
			glUniform1f(GetUniformLocation(name), value);
		}

		void Shader::SetUniform1i(const GLchar* name, int value)
		{
			glUniform1i(GetUniformLocation(name), value);
		}

		void Shader::SetUniform2f(const GLchar* name, const maths::vec2& value)
		{
			glUniform2f(GetUniformLocation(name), value.x, value.y);
		}

		void Shader::SetUniform3f(const GLchar* name, const maths::vec3& value)
		{
			glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
		}

		void Shader::SetUniform4f(const GLchar* name, const maths::vec4& value)
		{
			glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
		}

		void Shader::SetUniformMat4(const GLchar* name, const maths::mat4& value)
		{
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, value.elements);
		}

		GLuint Shader::Load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileUtilities::read_file(m_Vertpath);
			std::string fragSourceString = FileUtilities::read_file(m_Fragpath);

			const char* vertexSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			glShaderSource(vertex, 1, &vertexSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);


			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv (fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}


	}
}