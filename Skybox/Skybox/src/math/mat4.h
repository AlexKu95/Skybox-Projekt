#pragma once

#include "vec3.h"
#include "vec4.h"
#include "math_func.h"
#include <iostream>

namespace core { namespace math {

	template<typename T>
	struct tmat4;


	typedef tmat4<float> mat4;
	typedef tmat4<int> imat4;
	typedef tmat4<bool> bmat4;
	typedef tmat4<double> dmat4;


	template< typename T> tvec3<T> operator*(const tmat4<T>& left, const tvec3<T>& right);
	template< typename T> tvec4<T> operator*(const tmat4<T>& left, const tvec4<T>& right);
	template< typename T> tmat4<T> operator*(tmat4<T> left, const tmat4<T>& right);


	template <typename T>
	struct tmat4 {

		union {
			T elements[4 * 4];
			tvec4<T> columns[4];
		};

		tmat4();
		tmat4(T diagonal);
		tmat4(T elementArray[16]);
		tmat4(tvec4<T> _firstColumn, tvec4<T> _secondColumn, tvec4<T> _thirdColumn, tvec4<T> _fourthColumn);
		tmat4(tvec4<T> _columns[4]);

		inline tvec4<T> getColumn(int index){return columns[index];}
		inline tvec4<T> getRow(int index){return tvec4<T>(elements[index * 4], elements[index + 1 * 4], elements[index + 2 * 4], elements[index + 3 * 4]);}

		tmat4 identity();

		tmat4& multiply(const tmat4& other);
		friend tmat4<T> operator*<T>(tmat4<T> left, const tmat4<T>& other);
		tmat4& operator*=(const tmat4& other);

		tvec3<T> multiply(const tvec3<T>& other) const;
		friend tvec3<T> operator*<T>(const tmat4<T>& left, const tvec3<T>& right);

		tvec4<T> multiply(const tvec4<T>& other) const;
		friend tvec4<T> operator*<T>(const tmat4<T>& left, const tvec4<T>& right);


		tmat4 orthographicRH(T left, T right, T bottom, T top, T near, T far);

		tmat4 lookAtRH(tvec3<T> eye, tvec3<T> center, tvec3<T> up);
		tmat4 lookAtLH(tvec3<T> eye, tvec3<T> center, tvec3<T> up);

		tmat4 perspectiveRH(T fovy, T aspect, T zNear, T zFar);
		tmat4 perspectiveLH(T fovy, T aspect, T zNear, T zFar);

		tmat4 translate(const tvec3<T>& translation);
		tmat4 rotate(T angle, const tvec3<T>& axis);
		tmat4 scale(const tvec3<T>& scale);

		inline friend std::ostream& operator<<(std::ostream& stream, const tmat4<T>& matrix) {
			stream << "mat4  : (";
			for (int i = 0; i < 16; i++)
				stream << matrix.elements[i] << ", ";
			stream << ")";
			return stream;
		};
	};

	template< typename T>
	tmat4<T>::tmat4()
	{
		for (int i = 0; i < 16; i++)
		{
			elements[i] = 0.0f;
		}
	}

	template< typename T>
	tmat4<T>::tmat4(T diagonal)
	{
		for (int i = 0; i < 16; i++)
		{
			elements[i] = 0.0f;
		}

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	template< typename T>
	tmat4<T>::tmat4(T elementArray[16]) {
		for (int i = 0; i < 16; i++)
		{
			elements[i] = elementArray[i];
		}
	}

	template< typename T>
	tmat4<T>::tmat4(tvec4<T> _firstColumn, tvec4<T> _secondColumn, tvec4<T> _thirdColumn, tvec4<T> _fourthColumn)
	{
		columns[0] = _firstColumn;
		columns[1] = _secondColumn;
		columns[2] = _thirdColumn;
		columns[3] = _fourthColumn;
	}

	template< typename T>
	tmat4<T>::tmat4(tvec4<T> _columns[4]) {
		std::copy(_columns, _columns+4, columns);
	}

	template< typename T>
	tmat4<T> tmat4<T>::identity()
	{
		return tmat4(1.0f);
	}

	template< typename T>
	tmat4<T>& tmat4<T>::multiply(const tmat4<T>& other)
	{
		T data[16];
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
			{
				T sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				data[x + y * 4] = sum;
			}
		memcpy(elements, data, 4 * 4 * sizeof(T));
		return *this;
	}

	template< typename T>
	tmat4<T> operator*(tmat4<T> left, const tmat4<T>& right)
	{
		return left.multiply(right);
	}

	template< typename T>
	tmat4<T>& tmat4<T>::operator*=(const tmat4<T>& other)
	{
		return multiply(other);
	}

	template< typename T>
	tvec3<T> tmat4<T>::multiply(const tvec3<T>& other) const
	{
		return tvec3<T>(
			columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
			columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
			columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
		);
	}

	template< typename T>
	tvec4<T> tmat4<T>::multiply(const tvec4<T>& other) const
	{
		return tvec4<T>(
			columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x * other.w,
			columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y * other.w,
			columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z * other.w,
			columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[3].w * other.w
		);
	}

	template< typename T>
	tvec3<T> operator*(const tmat4<T>& left, const tvec3<T>& right)
	{
		return left.multiply(right);
	}

	template< typename T>
	tvec4<T> operator*(const tmat4<T>& left, const tvec4<T>& right)
	{
		return left.multiply(right);
	}

}}