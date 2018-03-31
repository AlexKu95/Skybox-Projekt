#pragma once

#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include <iostream>

namespace core { namespace math {

	template<typename T>
	struct tmat3;

	template<typename T>
	struct tmat4;

	typedef tmat3<float> mat3;
	typedef tmat3<int> imat3;
	typedef tmat3<bool> bmat3;
	typedef tmat3<double> dmat3;

	template< typename T> tvec3<T> operator*(const tmat3<T>& left, const tvec3<T>& right);
	template< typename T> tvec4<T> operator*(const tmat3<T>& left, const tvec4<T>& right);
	template< typename T> tmat3<T> operator*(tmat3<T> left, const tmat3<T>& right);

	template <typename T>
	struct tmat3 {

		union {
			T elements[3 * 3];
			tvec3<T> columns[3];
		};

		tmat3();
		tmat3(T diagonal);
		tmat3(T elementArray[9]);
		tmat3(tvec3<T> _firstColumn, tvec3<T> _secondColumn, tvec3<T> _thirdColumn);
		tmat3(tvec3<T> _columns[3]);
		tmat3(tmat4<T> _matrix4);

		inline tvec3<T> getColumn(int index) { return columns[index]; }
		inline tvec3<T> getRow(int index) { return tvec3<T>(elements[index], elements[index + 1 * 3], elements[index + 2 * 3]); }

		tmat3 identity();

		tmat3& multiply(const tmat3& other);
		friend tmat3<T> operator*<T>(tmat3<T> left, const tmat3<T>& other);
		tmat3& operator*=(const tmat3& other);

		tvec3<T> multiply(const tvec3<T>& other) const;
		friend tvec3<T> operator*<T>(const tmat3<T>& left, const tvec3<T>& right);

		tvec4<T> multiply(const tvec4<T>& other) const;
		friend tvec4<T> operator*<T>(const tmat3<T>& left, const tvec4<T>& right);

		inline friend std::ostream& operator<<(std::ostream& stream, const tmat3<T>& matrix) {
			stream << "mat3  : (";
			for (int i = 0; i < 9; i++)
				stream << matrix.elements[i] << ", ";
			stream << ")";
			return stream;
		};
	};

	template< typename T>
	tmat3<T>::tmat3()
	{
		for (int i = 0; i < 9; i++)
		{
			elements[i] = 0.0f;
		}
	}

	template< typename T>
	tmat3<T>::tmat3(T diagonal)
	{
		for (int i = 0; i < 9; i++)
		{
			elements[i] = 0.0f;
		}

		elements[0 + 0 * 3] = diagonal;
		elements[1 + 1 * 3] = diagonal;
		elements[2 + 2 * 3] = diagonal;
	}

	template< typename T>
	tmat3<T>::tmat3(T elementArray[9]) {
		for (int i = 0; i < 9; i++)
		{
			elements[i] = elementArray[i];
		}
	}

	template< typename T>
	tmat3<T>::tmat3(tvec3<T> _firstColumn, tvec3<T> _secondColumn, tvec3<T> _thirdColumn)
	{
		columns[0] = _firstColumn;
		columns[1] = _secondColumn;
		columns[2] = _thirdColumn;
	}

	template< typename T>
	tmat3<T>::tmat3(tvec3<T> _columns[3]) {
		std::copy(_columns, _columns + 3, columns);
	}

	template< typename T>
	tmat3<T>::tmat3(tmat4<T> _matrix4) {
		for (int i = 0; i < 9; i++)
		{
			elements[i] = _matrix4.elements[i];
		}
	}

	template< typename T>
	tmat3<T> tmat3<T>::identity()
	{
		return tmat3(1.0f);
	}

	template< typename T>
	tmat3<T>& tmat3<T>::multiply(const tmat3<T>& other)
	{
		T data[9];
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
			{
				T sum = 0.0f;
				for (int e = 0; e < 3; e++)
				{
					sum += elements[x + e * 3] * other.elements[e + y * 3];
				}
				data[x + y * 3] = sum;
			}
		memcpy(elements, data, 3 * 3 * sizeof(T));
		return *this;
	}

	template< typename T>
	tmat3<T> operator*(tmat3<T> left, const tmat3<T>& right)
	{
		return left.multiply(right);
	}

	template< typename T>
	tmat3<T>& tmat3<T>::operator*=(const tmat3<T>& other)
	{
		return multiply(other);
	}

	template< typename T>
	tvec3<T> tmat3<T>::multiply(const tvec3<T>& other) const
	{
		return tvec3<T>(
			columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z,
			columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z,
			columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z
			);
	}

	template< typename T>
	tvec4<T> tmat3<T>::multiply(const tvec4<T>& other) const
	{
		return tvec4<T>(
			columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + 0 * other.w,
			columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + 0 * other.w,
			columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + 0 * other.w,
			0
			);
	}

	template< typename T>
	tvec3<T> operator*(const tmat3<T>& left, const tvec3<T>& right)
	{
		return left.multiply(right);
	}

	template< typename T>
	tvec4<T> operator*(const tmat3<T>& left, const tvec4<T>& right)
	{
		return left.multiply(right);
	}

}}