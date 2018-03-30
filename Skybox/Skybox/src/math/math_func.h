#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#define SP_PI 3.14159265358f

#include "mat4.h"

namespace core { namespace math {

	inline float toRadians(float degrees)
	{
		return degrees * (SP_PI / 180.0f);
	}


	template< typename T>
	inline tmat4<T> orthographicRH(T left, T right, T bottom, T top, T near, T far) {
		tmat4<T> result(1.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right - left);

		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);

		result.elements[2 + 2 * 4] = -2.0f / (far - near);

		result.elements[0 + 3 * 4] = -(left + right) / (right - left);
		result.elements[1 + 3 * 4] = -(bottom + top) / (top - bottom);
		result.elements[2 + 3 * 4] = -(far + near) / (far - near);

		return result;
	}

	template< typename T>
	tmat4<T> lookAtRH(tvec3<T> eye, tvec3<T> center, tvec3<T> up)
	{
		tvec3<T> f = center - eye;
		f = f.normalize();
		tvec3<T> s = f.cross(up);
		s = s.normalize();
		tvec3<T> u = s.cross(f);

		tmat4<T> Result(1.0f);

		Result.columns[0] = tvec4<T>(s.x, u.x, -f.x, 0);
		Result.columns[1] = tvec4<T>(s.y, u.y, -f.y, 0);
		Result.columns[2] = tvec4<T>(s.z, u.z, -f.z, 0);
		Result.columns[3] = tvec4<T>(-s.dot(eye), -u.dot(eye), f.dot(eye), 1);

		return Result;
	}

	template< typename T>
	tmat4<T> lookAtLH(tvec3<T> eye, tvec3<T> center, tvec3<T> up)
	{
		tvec3<T> f = center - eye;
		f.normalize();
		tvec3<T> s = up.cross(f);
		s.normalize();
		tvec3<T> u = f.cross(s);

		tmat4<T> Result(1.0f);
		Result.elements[0 + 0 * 4] = s.x;
		Result.elements[0 + 1 * 4] = s.y;
		Result.elements[0 + 2 * 4] = s.z;

		Result.elements[1 + 0 * 4] = u.x;
		Result.elements[1 + 1 * 4] = u.y;
		Result.elements[1 + 2 * 4] = u.z;

		Result.elements[2 + 0 * 4] = f.x;
		Result.elements[2 + 1 * 4] = f.y;
		Result.elements[2 + 2 * 4] = f.z;

		Result.elements[0 + 3 * 4] = -s.dot(eye);
		Result.elements[1 + 3 * 4] = -u.dot(eye);
		Result.elements[2 + 3 * 4] = -f.dot(eye);

		return Result;
	}

	template< typename T>
	tmat4<T> perspectiveRH(T fovy, T aspect, T zNear, T zFar)
	{
		tmat4 Result(0.0f);

		T tanHalfFovy = tan(fovy / 2);
		Result.columns[0].x = 1 / (aspect * tanHalfFovy);
		Result.columns[1].y = 1 / tanHalfFovy;
		Result.columns[2].z = -(zFar + zNear) / (zFar - zNear);
		Result.columns[2].w = -1;
		Result.columns[3].z = -(2 * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template< typename T>
	tmat4<T> perspectiveLH(T fovy, T aspect, T zNear, T zFar)
	{
		tmat4<T> Result(0.0f);

		T tanHalfFovy = tan(fovy / 2);
		Result.columns[0].x = 1 / (aspect * tanHalfFovy);
		Result.columns[1].y = 1 / tanHalfFovy;
		Result.columns[2].z = (zFar + zNear) / (zFar - zNear);
		Result.columns[2].w = 1;
		Result.columns[3].z = -(2 * zFar * zNear) / (zFar - zNear);
		return Result;

	}

	template< typename T>
	tmat4<T> translate(const tvec3<T>& translation)
	{
		tmat4<T> result(1.0f);

		result.elements[3 + 0 * 4] = translation.x;
		result.elements[3 + 1 * 4] = translation.y;
		result.elements[3 + 2 * 4] = translation.z;

		return result;
	}

	template< typename T>
	tmat4<T> rotate(T angle, const tvec3<T>& axis)
	{
		tmat4<T> result(1.0f);

		T r = toRadians(angle);
		T c = cos(r);
		T s = sin(r);
		T omc = 1.0f - c;

		T x = axis.x;
		T y = axis.y;
		T z = axis.z;

		result.elements[0 + 0 * 4] = x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = x * z * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;

		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * omc + c;

		return result;
	}

	template< typename T>
	tmat4<T> scale(const tvec3<T>& scale)
	{
		tmat4 result(1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}


}}