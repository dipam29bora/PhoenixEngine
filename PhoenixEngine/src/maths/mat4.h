#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "maths.h"

namespace phoenix
{
	namespace maths
	{
		struct mat4
		{
			union 
			{
				//Both of these two addressing to the same memory address and  the size is of 64 bytes
				//We have to  make the default default constructor of vec4 class 
				float elements[4 * 4];
				vec4 Columns[4];
			};

			mat4();
			mat4(float diagonal);

			static mat4 identity();

			mat4& Multiply(const mat4& other);
			friend mat4 operator* (mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			static mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 Perospective(float fov, float aspectRation, float near, float far);

			static mat4 Transtation(const vec3& translation);
			static mat4 Rotation(float angle, const vec3& axis);
			static mat4 Scale(const vec3& scale);

		};
	}
}