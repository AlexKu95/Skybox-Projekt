#pragma once
#pragma once
#include <iostream>
#include "vec3.h"

namespace core {
	namespace math {

		template<typename T>
		struct tvec4;


		typedef tvec4<float> vec4;
		typedef tvec4<int> ivec4;
		typedef tvec4<bool> bvec4;
		typedef tvec4<double> dvec4;

		template<typename T>
		struct tvec4 {

			union {
				struct { T x, y, z, w; };
				struct { T r, g, b, a; };
			};

			tvec4();
			tvec4(const T& _input);
			tvec4(const T& _x, const T& _y, const T& _z, const T& _w);

			template <typename U>
			tvec4(const tvec4<U>& _input) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y)), z(static_cast<T>(_input.z)), w(static_cast<T>(_input.w)) {};

			template <typename U, typename R, typename S>
			tvec4(const tvec2<U>& _input, const R& _z, const S& _w) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w)) {};
			template <typename U, typename R, typename S>
			tvec4(const R& _x, const tvec2<U>& _input, const S& _w) : x(static_cast<T>(_x)), y(static_cast<T>(_input.x)), z(static_cast<T>(_input.y)), w(static_cast<T>(_w)) {};
			template <typename U>
			tvec4(const tvec2<U>& _input) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y)), z(0), w(0) {};
			template <typename U>
			tvec4(const tvec2<U>& _first, const tvec2<U>& _second) : x(static_cast<T>(_first.x)), y(static_cast<T>(_first.y)), z(static_cast<T>(_second.x)), w(static_cast<T>(_second.y)) {};

			template <typename U, typename R>
			tvec4(const tvec3<U>& _input, const R& _w) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y)), z(static_cast<T>(_input.z)), w(static_cast<T>(_w)) {};
			template <typename U, typename R>
			tvec4(const R& _x, const tvec3<U>& _input) : x(static_cast<T>(_x)), y(static_cast<T>(_input.x)), z(static_cast<T>(_input.y)), w(static_cast<T>(_input.z)) {};
			template <typename U>
			tvec4(const tvec3<U>& _input) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y)), z(static_cast<T>(_input.y)), w(0) {};

			tvec4& add(const tvec4& other);
			tvec4& subtract(const tvec4& other);
			tvec4& multiply(const tvec4& other);
			tvec4& divide(const tvec4& other);

			tvec4& normalize();
			tvec4& scale(T scalar);
			T distance(const tvec4& other);
			T magnitude();
			T dot(const tvec4& other);

			bool operator==(const tvec4& other);
			bool operator!=(const tvec4& other);

			inline friend tvec4<T> operator+(const tvec4<T>& left, const tvec4<T>& right) { return tvec4<T>(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w); }
			template < typename U>
			inline friend tvec4<T> operator+(const U scalar, const tvec4<T>& other) { return tvec4<T>(other.x + static_cast<T>(scalar), other.y + static_cast<T>(scalar), other.z + static_cast<T>(scalar), other.w + static_cast<T>(scalar)); }

			inline friend tvec4<T> operator-(const tvec4<T>& left, const tvec4<T>& right) { return tvec4<T>(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w); }
			template < typename U>
			inline friend tvec4<T> operator-(const U scalar, const tvec4<T>& other) { return tvec4<T>(other.x - static_cast<T>(scalar), other.y - static_cast<T>(scalar), other.z - static_cast<T>(scalar), other.w - static_cast<T>(scalar)); }

			inline friend tvec4<T> operator*(const tvec4<T>& left, const tvec4<T>& right) { return tvec4<T>(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w); }
			template < typename U>
			inline friend tvec4<T> operator*(const U scalar, const tvec4<T>& other) { return tvec4<T>(other.x * static_cast<T>(scalar), other.y * static_cast<T>(scalar), other.z * static_cast<T>(scalar), other.w * static_cast<T>(scalar)); }

			inline friend tvec4<T> operator/(const tvec4<T>& left, const tvec4<T>& right) { return tvec4<T>(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w); }
			template < typename U>
			inline friend tvec4<T> operator/(const U scalar, const tvec4<T>& other) { return tvec4<T>(other.x / static_cast<T>(scalar), other.y / static_cast<T>(scalar), other.z / static_cast<T>(scalar), other.w / static_cast<T>(scalar)); }

			tvec4<T>& operator=(const tvec4<T>& other) = default;

			template < typename U>
			inline tvec4<T>& operator=(const U scalar) {
				x = static_cast<T>(scalar);
				y = static_cast<T>(scalar);
				z = static_cast<T>(scalar);
				w = static_cast<T>(scalar);
				return *this;

			}

			template < typename U>
			inline tvec4<T>& operator+=(const U scalar) {
				x = x + static_cast<T>(scalar);
				y = y + static_cast<T>(scalar);
				z = z + static_cast<T>(scalar);
				w = w + static_cast<T>(scalar);
				return *this;
			};
			tvec4& operator+=(const tvec4& other);

			template < typename U>
			inline tvec4<T>& operator-=(const U scalar) {
				x = x - static_cast<T>(scalar);
				y = y - static_cast<T>(scalar);
				z = z - static_cast<T>(scalar);
				w = w - static_cast<T>(scalar);
				return *this;
			};
			tvec4& operator-=(const tvec4& other);


			template < typename U>
			inline tvec4<T>& operator*=(const U scalar) {
				x = x * static_cast<T>(scalar);
				y = y * static_cast<T>(scalar);
				z = z * static_cast<T>(scalar);
				w = w * static_cast<T>(scalar);
				return *this;
			};
			tvec4& operator*=(const tvec4& other);

			template < typename U>
			inline tvec4<T>& operator/=(const U scalar)
			{
				x = x / static_cast<T>(scalar);
				y = y / static_cast<T>(scalar);
				z = z / static_cast<T>(scalar);
				w = w / static_cast<T>(scalar);
				return *this;
			};
			tvec4& operator/=(const tvec4& other);

			inline friend std::ostream& operator<<(std::ostream& stream, const tvec4& vector) {
				stream << "vec4  : (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
				return stream;
			};
		};

		//Implementation_____________________________________________
		//Construcotr
		template<typename T>
		tvec4<T>::tvec4() : x(0), y(0), z(0), w(0) {}

		template<typename T>
		tvec4<T>::tvec4(const T& _input) : x(_input), y(_input), z(_input), w(_input) {}

		template<typename T>
		tvec4<T>::tvec4(const T& _x, const T& _y, const T& _z, const T& _w) : x(_x), y(_y), z(_z), w(_w) {}

		template<typename T>
		tvec4<T>& tvec4<T>::add(const tvec4<T>& other) {
			x = x + other.x;
			y = y + other.y;
			z = z + other.z;
			w = w + other.w;
			return *this;
		}

		//methods
		template<typename T>
		tvec4<T>& tvec4<T>::subtract(const tvec4<T>& other) {
			x = x - other.x;
			y = y - other.y;
			z = z - other.z;
			w = w - other.w;
			return *this;
		}

		template<typename T>
		tvec4<T>& tvec4<T>::multiply(const tvec4<T>& other) {
			x = x * other.x;
			y = y * other.y;
			z = z * other.z;
			w = w * other.w;
			return *this;
		}

		template<typename T>
		tvec4<T>& tvec4<T>::divide(const tvec4<T>& other) {
			x = x / other.x;
			y = y / other.y;
			z = z / other.z;
			w = w / other.w;
			return *this;
		}


		template<typename T>
		tvec4<T>& tvec4<T>::scale(T scalar)
		{
			x = x * scalar;
			y = y * scalar;
			z = z * scalar;
			w = w * scalar;
			return *this;
		}

		template<typename T>
		tvec4<T>& tvec4<T>::normalize()
		{
			float n = 1 / sqrt(x * x + y * y + z * z + w * w);
			return this->scale(n);
		}

		template<typename T>
		T tvec4<T>::distance(const tvec4<T>& other)
		{
			float a = x - other.x;
			float b = y - other.y;
			float c = z - other.z;
			float d = w - other.w;
			return tvec4(a, b, c, d).magnitude();
		}

		template<typename T>
		T tvec4<T>::magnitude()
		{
			return sqrt(this->dot(*this));
		}

		template<typename T>
		T tvec4<T>::dot(const tvec4<T>& other)
		{
			return (x*other.x) + (y*other.y) + (z*other.z)+ (w*other.w);
		}

		template<typename T>
		tvec4<T>& tvec4<T>::operator+=(const tvec4<T>& other)
		{
			return this->add(other);
		}

		template<typename T>
		tvec4<T>& tvec4<T>::operator-=(const tvec4<T>& other)
		{
			return this->subtract(other);
		}

		template<typename T>
		tvec4<T>& tvec4<T>::operator/=(const tvec4<T>& other)
		{
			return this->divide(other);
		}

		template<typename T>
		tvec4<T>& tvec4<T>::operator*=(const tvec4<T>& other)
		{
			return this->multiply(other);
		}

		template<typename T>
		bool tvec4<T>::operator==(const tvec4<T>& other)
		{
			if (x == other.x && y == other.y && z == other.z && w == other.w)
				return true;
			else
				return false;
		}

		template<typename T>
		bool tvec4<T>::operator!=(const tvec4<T>& other)
		{
			if (x == other.x && y == other.y && z == other.z && w == other.w)
				return false;
			else
				return true;
		}

	}
}

