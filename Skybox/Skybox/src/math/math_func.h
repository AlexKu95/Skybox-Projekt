#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#define SP_PI 3.14159265358f


namespace core { namespace math {

	inline float toRadians(float degrees)
	{
		return degrees * (SP_PI / 180.0f);
	}

}}