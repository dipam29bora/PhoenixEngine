#include "vec2.h"

namespace phoenix
{
	namespace maths
	{

		vec2::vec2()
		{
			x = 0.0F;
			y = 0.0f;
		}

		vec2::vec2(const float& X, const float& Y)
		{
			x = X;
			y = Y;
		}

		vec2& vec2::Add(const vec2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2& vec2::Subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::Multi(const vec2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& vec2::Divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}


		vec2 operator+(vec2 left, const vec2& right)
		{
			return left.Add(right);
		}
		
		vec2& vec2::operator+=(const vec2& other)
		{
			//*this + other;
			//return *this;
			return Add(other);
		}
		
		vec2 operator-(vec2 left, const vec2& right)
		{
			return left.Subtract(right);
		}

		vec2& vec2::operator-=(const vec2& other)
		{
			return Subtract(other);
		}
		
		vec2 operator*(vec2 left, const vec2& right)
		{
			return left.Multi(right);
		}

		vec2& vec2::operator*=(const vec2& other)
		{
			return Multi(other);
		}
		
		vec2 operator/(vec2 left, const vec2& right)
		{
			return left.Divide(right);
		}

		vec2& vec2::operator/=(const vec2& other)
		{
			return Divide(other);
		}

		bool vec2::operator==(const vec2& other)
		{
			return x == other.x && y == other.y;
		}
		
		bool vec2::operator!=(const vec2& other)
		{
			return !(*this==other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << "," << vector.y << ")";
			return stream;
		}

	}
}