#include "vec3.h"

namespace phoenix
{
	namespace maths
	{

		vec3::vec3()
		{
			x = 0.0F;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float& X, const float& Y, const float& Z)
		{
			x = X;
			y = Y;
			z = Z;
		}

		vec3& vec3::Add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& vec3::Subtract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& vec3::Multi(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3& vec3::Divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}


		vec3 operator+(vec3 left, const vec3& right)
		{
			return left.Add(right);
		}
		
		vec3& vec3::operator+=(const vec3& other)
		{
			//*this + other;
			//return *this;
			return Add(other);
		}
		
		vec3 operator-(vec3 left, const vec3& right)
		{
			return left.Subtract(right);
		}

		vec3& vec3::operator-=(const vec3& other)
		{
			return Subtract(other);
		}
		
		vec3 operator*(vec3 left, const vec3& right)
		{
			return left.Multi(right);
		}

		vec3& vec3::operator*=(const vec3& other)
		{
			return Multi(other);
		}
		
		vec3 operator/(vec3 left, const vec3& right)
		{
			return left.Divide(right);
		}

		vec3& vec3::operator/=(const vec3& other)
		{
			return Divide(other);
		}

		bool vec3::operator==(const vec3& other)
		{
			return x == other.x && y == other.y && z==other.z;
		}
		
		bool vec3::operator!=(const vec3& other)
		{
			return !(*this==other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			stream << "vec3: (" << vector.x << "," << vector.y <<","<<vector.z<< ")";
			return stream;
		}

	}
}