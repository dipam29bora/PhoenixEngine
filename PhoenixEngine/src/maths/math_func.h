#pragma once
#include "mat4.h"

namespace phoenix
{
	namespace maths
	{
		inline float toRadians(float degrees) { return (float)(degrees * (M_PI / 180.0f)); }
	}
}