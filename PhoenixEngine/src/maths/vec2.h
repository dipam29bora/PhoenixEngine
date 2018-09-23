#pragma once
#include <iostream>
namespace phoenix
{
	namespace maths
	{
		struct vec2
		{
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& Add(const vec2& other);
			vec2& Subtract(const vec2& other);
			vec2& Multi(const vec2& other);
			vec2& Divide(const vec2& other);

			friend vec2 operator+(vec2 left, const vec2& right);
			friend vec2 operator-(vec2 left, const vec2& right);
			friend vec2 operator*(vec2 left, const vec2& right);
			friend vec2 operator/(vec2 left, const vec2& right);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);


			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);

		};
	}
}