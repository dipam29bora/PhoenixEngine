#include "vec4.h"

namespace phoenix
{
	namespace maths
	{

		/*
		No need of this constructor because we have already a default constructor
		vec4::vec4()
		{
			x = 0.0F;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}*/

		vec4::vec4(const float& X, const float& Y, const float& Z, const float& W )
		{
			x = X;
			y = Y;
			z = Z;
			w = W;
		}

		vec4& vec4::Add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& vec4::Subtract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		vec4& vec4::Multi(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		vec4& vec4::Divide(const vec4& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}


		vec4 operator+(vec4 left, const vec4& right)
		{
			return left.Add(right);
		}
		
		vec4& vec4::operator+=(const vec4& other)
		{
			//*this + other;
			//return *this;
			return Add(other);
		}
		
		vec4 operator-(vec4 left, const vec4& right)
		{
			return left.Subtract(right);
		}

		vec4& vec4::operator-=(const vec4& other)
		{
			return Subtract(other);
		}
		
		vec4 operator*(vec4 left, const vec4& right)
		{
			return left.Multi(right);
		}

		vec4& vec4::operator*=(const vec4& other)
		{
			return Multi(other);
		}
		
		vec4 operator/(vec4 left, const vec4& right)
		{
			return left.Divide(right);
		}

		vec4& vec4::operator/=(const vec4& other)
		{
			return Divide(other);
		}

		bool vec4::operator==(const vec4& other)
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}
		
		bool vec4::operator!=(const vec4& other)
		{
			return !(*this==other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			stream << "vec4: (" << vector.x << "," << vector.y <<","<<vector.z<<","<<vector.w<< ")";
			return stream;
		}

	}
}