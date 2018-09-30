#pragma once
#include <iostream>
namespace phoenix
{
	namespace maths
	{
		struct vec4
		{
			float x, y,z,w;

			//vec4();
			vec4() = default;//making it as a default constructor so that we can unionize the matrixes into vec4 columns
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& Add(const vec4& other);
			vec4& Subtract(const vec4& other);
			vec4& Multi(const vec4& other);
			vec4& Divide(const vec4& other);

			friend vec4 operator+(vec4 left, const vec4& right);
			friend vec4 operator-(vec4 left, const vec4& right);
			friend vec4 operator*(vec4 left, const vec4& right);
			friend vec4 operator/(vec4 left, const vec4& right);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);


			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);

		};
	}
}