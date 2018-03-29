#pragma once
#include <iostream>
#include "vec2.h"

namespace core { namespace math {

	template<typename T>
	struct tvec3;


	typedef tvec3<float> vec3;
	typedef tvec3<int> ivec3;
	typedef tvec3<bool> bvec3;
	typedef tvec3<double> dvec3;

	template<typename T>
	struct tvec3 {

		union {
			struct { T x, y, z; };
			struct { T r, g, b; };
		};

		tvec3();
		tvec3(const T& _input);
		tvec3(const T& _x, const T& _y, const T& _z);
		template <typename U>
		tvec3(const tvec3<U>& _input) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y), z(static_cast<T>(_input.z))) {};
		
		template <typename U, typename R>
		tvec3(const tvec2<U>& _input, const R _rest) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y)), z(static_cast<T>(_rest)) {};
		template <typename U, typename R>
		tvec3(const R _rest, const tvec2<U>& _input) : x(static_cast<T>(_rest)), y(static_cast<T>(_input.x)), z(static_cast<T>(_input.y)) {};
		template <typename U>
		tvec3(const tvec2<U>& _input) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y), z(0)) {};


		tvec3& add(const tvec3& other);
		tvec3& subtract(const tvec3& other);
		tvec3& multiply(const tvec3& other);
		tvec3& divide(const tvec3& other);


		tvec3& normalize();
		tvec3& scale(T scalar);
		T distance(const tvec3& other);
		T magnitude();
		T dot(const tvec3& other);
		tvec3& cross(const tvec3& other);

		bool operator==(const tvec3& other);
		bool operator!=(const tvec3& other);

		inline friend tvec3<T> operator+(const tvec3<T>& left, const tvec3<T>& right) { return tvec3<T>(left.x + right.x, left.y + right.y , left.z + right.z); }
		template < typename U>
		inline friend tvec3<T> operator+(const U scalar, const tvec3<T>& other) { return tvec3<T>(other.x + static_cast<T>(scalar), other.y + static_cast<T>(scalar), other.z + static_cast<T>(scalar)); }

		inline friend tvec3<T> operator-(const tvec3<T>& left, const tvec3<T>& right) { return tvec3<T>(left.x - right.x, left.y - right.y , left.z - right.z); }
		template < typename U>
		inline friend tvec3<T> operator-(const U scalar, const tvec3<T>& other) { return tvec3<T>(other.x - static_cast<T>(scalar), other.y - static_cast<T>(scalar), other.z - static_cast<T>(scalar)); }

		inline friend tvec3<T> operator*(const tvec3<T>& left, const tvec3<T>& right) { return tvec3<T>(left.x * right.x, left.y * right.y , left.z * right.z); }
		template < typename U>
		inline friend tvec3<T> operator*(const U scalar, const tvec3<T>& other) { return tvec3<T>(other.x * static_cast<T>(scalar), other.y * static_cast<T>(scalar), other.z * static_cast<T>(scalar)); }

		inline friend tvec3<T> operator/(const tvec3<T>& left, const tvec3<T>& right) { return tvec3<T>(left.x / right.x, left.y / right.y , left.z / right.z); }
		template < typename U>
		inline friend tvec3<T> operator/(const U scalar, const tvec3<T>& other) { return tvec3<T>(other.x / static_cast<T>(scalar), other.y / static_cast<T>(scalar), other.z / static_cast<T>(scalar)); }



		tvec3<T>& operator=(const tvec3<T>& other) = default;

		template < typename U>
		inline tvec3<T>& operator=(const U scalar) {
			x = static_cast<T>(scalar);
			y = static_cast<T>(scalar);
			z = static_cast<T>(scalar);
			return *this;

		}

		template < typename U>
		inline tvec3<T>& operator+=(const U scalar) {
			x = x + static_cast<T>(scalar);
			y = y + static_cast<T>(scalar);
			z = z + static_cast<T>(scalar);
			return *this;
		};
		tvec3& operator+=(const tvec3& other);

		template < typename U>
		inline tvec3<T>& operator-=(const U scalar) {
			x = x - static_cast<T>(scalar);
			y = y - static_cast<T>(scalar);
			z = z - static_cast<T>(scalar);
			return *this;
		};
		tvec3& operator-=(const tvec3& other);


		template < typename U>
		inline tvec3<T>& operator*=(const U scalar) {
			x = x * static_cast<T>(scalar);
			y = y * static_cast<T>(scalar);
			z = z * static_cast<T>(scalar);
			return *this;
		};
		tvec3& operator*=(const tvec3& other);

		template < typename U>
		inline tvec3<T>& operator/=(const U scalar)
		{
			x = x / static_cast<T>(scalar);
			y = y / static_cast<T>(scalar);
			z = z / static_cast<T>(scalar);
			return *this;
		};
		tvec3& operator/=(const tvec3& other);

		inline friend std::ostream& operator<<(std::ostream& stream, const tvec3& vector) {
			stream << "vec3  : (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		};
	};

	//Implementation_____________________________________________
	//Construcotr
	template<typename T>
	tvec3<T>::tvec3() : x(0), y(0), z(0) {}

	template<typename T>
	tvec3<T>::tvec3(const T& _input) : x(_input), y(_input), z(_input) {}

	template<typename T>
	tvec3<T>::tvec3(const T& _x, const T& _y, const T& _z) : x(_x), y(_y), z(_z) {}

	template<typename T>
	tvec3<T>& tvec3<T>::add(const tvec3<T>& other) {
		x = x + other.x;
		y = y + other.y;
		z = z + other.z;
		return *this;
	}

	//methods
	template<typename T>
	tvec3<T>& tvec3<T>::subtract(const tvec3<T>& other) {
		x = x - other.x;
		y = y - other.y;
		z = z - other.z;
		return *this;
	}

	template<typename T>
	tvec3<T>& tvec3<T>::multiply(const tvec3<T>& other) {
		x = x * other.x;
		y = y * other.y;
		z = z * other.z;
		return *this;
	}

	template<typename T>
	tvec3<T>& tvec3<T>::divide(const tvec3<T>& other) {
		x = x / other.x;
		y = y / other.y;
		z = z / other.z;
		return *this;
	}


	template<typename T>
	tvec3<T>& tvec3<T>::scale(T scalar)
	{
		x = x * scalar;
		y = y * scalar;
		z = z * scalar;
		return *this;
	}

	template<typename T>
	tvec3<T>& tvec3<T>::normalize()
	{
		float n = 1 / sqrt(x * x + y * y + z * z);
		return this->scale(n);
	}

	template<typename T>
	T tvec3<T>::distance(const tvec3<T>& other)
	{
		float a = x - other.x;
		float b = y - other.y;
		float c = z - other.z;
		return tvec3(a,b,c).magnitude();
	}

	template<typename T>
	T tvec3<T>::magnitude()
	{
		return sqrt(this->dot(*this));
	}

	template<typename T>
	T tvec3<T>::dot(const tvec3<T>& other)
	{
		return (x*other.x) + (y*other.y)+ (z*other.z);
	}

	template<typename T>
	tvec3<T>& tvec3<T>::operator+=(const tvec3<T>& other)
	{
		return this->add(other);
	}

	template<typename T>
	tvec3<T>& tvec3<T>::operator-=(const tvec3<T>& other)
	{
		return this->subtract(other);
	}

	template<typename T>
	tvec3<T>& tvec3<T>::operator/=(const tvec3<T>& other)
	{
		return this->divide(other);
	}

	template<typename T>
	tvec3<T>& tvec3<T>::operator*=(const tvec3<T>& other)
	{
		return this->multiply(other);
	}

	template<typename T>
	bool tvec3<T>::operator==(const tvec3<T>& other)
	{
		if (x == other.x && y == other.y && z == other.z)
			return true;
		else
			return false;
	}

	template<typename T>
	bool tvec3<T>::operator!=(const tvec3<T>& other)
	{
		if (x == other.x && y == other.y && z == other.z)
			return false;
		else
			return true;
	}

}
}

