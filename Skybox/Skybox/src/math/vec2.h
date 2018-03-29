#pragma once
#include <iostream>

namespace core { namespace math {

	template<typename T>
	struct tvec2;


	typedef tvec2<float> vec2;
	typedef tvec2<int> ivec2;
	typedef tvec2<bool> bvec2;
	typedef tvec2<double> dvec2;


	template<typename T>
	struct tvec2 {

		union {
			struct { T x, y; };
			struct { T r, g; };
		};

		tvec2();
		tvec2(const T& _input);
		tvec2(const T& _x,const T& _y);
		template <typename U>
		tvec2(const tvec2<U>& _input) : x(static_cast<T>(_input.x)), y(static_cast<T>(_input.y)) {};

		tvec2& add(const tvec2& other);
		tvec2& subtract(const tvec2& other);
		tvec2& multiply(const tvec2& other);
		tvec2& divide(const tvec2& other);

		tvec2& normalize();
		tvec2& scale(T scalar);

		T distance(const tvec2& other);
		T magnitude();
		T dot(const tvec2& other);

		bool operator==(const tvec2& other);
		bool operator!=(const tvec2& other);

		inline friend tvec2<T> operator+(const tvec2<T>& left, const tvec2<T>& right)	{	return tvec2<T>(left.x + right.x, left.y + right.y);	}
		template < typename U>
		inline friend tvec2<T> operator+(const U scalar, const tvec2<T>& other) { return tvec2<T>(other.x + static_cast<T>(scalar), other.y + static_cast<T>(scalar)); }
	
		inline friend tvec2<T> operator-(const tvec2<T>& left, const tvec2<T>& right) { return tvec2<T>(left.x - right.x, left.y - right.y); }
		template < typename U>
		inline friend tvec2<T> operator-(const U scalar, const tvec2<T>& other) { return tvec2<T>(other.x - static_cast<T>(scalar), other.y - static_cast<T>(scalar)); }
		
		inline friend tvec2<T> operator*(const tvec2<T>& left, const tvec2<T>& right) { return tvec2<T>(left.x * right.x, left.y * right.y); }
		template < typename U>
		inline friend tvec2<T> operator*(const U scalar, const tvec2<T>& other) { return tvec2<T>(other.x * static_cast<T>(scalar), other.y * static_cast<T>(scalar)); }
		
		inline friend tvec2<T> operator/(const tvec2<T>& left, const tvec2<T>& right) { return tvec2<T>(left.x / right.x, left.y / right.y); }
		template < typename U>
		inline friend tvec2<T> operator/(const U scalar, const tvec2<T>& other) { return tvec2<T>(other.x / static_cast<T>(scalar), other.y / static_cast<T>(scalar)); }



		tvec2<T>& operator=(const tvec2<T>& other) = default;
		
		template < typename U>
		inline tvec2<T>& operator=(const U scalar) {
			x = static_cast<T>(scalar);
			y = static_cast<T>(scalar);
			return *this;

		}

		template < typename U>
		inline tvec2<T>& operator+=(const U scalar) {
				x = x + static_cast<T>(scalar);
				y = y + static_cast<T>(scalar);
				return *this;
			};
		tvec2& operator+=(const tvec2& other);
		
		template < typename U>
		inline tvec2<T>& operator-=(const U scalar) {
				x = x - static_cast<T>(scalar);
				y = y - static_cast<T>(scalar);
				return *this;
			};
		tvec2& operator-=(const tvec2& other);

		
		template < typename U>
		inline tvec2<T>& operator*=(const U scalar)	{
				x = x * static_cast<T>(scalar);
				y = y * static_cast<T>(scalar);
				return *this;
			};
		tvec2& operator*=(const tvec2& other);

		template < typename U>
		inline tvec2<T>& operator/=(const U scalar)
			{
				x = x / static_cast<T>(scalar);
				y = y / static_cast<T>(scalar);
				return *this;
			};
		tvec2& operator/=(const tvec2& other);

		inline friend std::ostream& operator<<(std::ostream& stream, const tvec2& vector) {
			stream <<"vec2  : (" << vector.x << ", " << vector.y << ")";
			return stream;
		};
	};

	//Implementation_____________________________________________
	//Construcotr
	template<typename T>
	tvec2<T>::tvec2() : x(0), y(0) {}

	template<typename T>
	tvec2<T>::tvec2(const T& _input) : x(_input), y(_input) {}

	template<typename T>
	tvec2<T>::tvec2(const T& _x, const T& _y) : x(_x), y(_y) {}

	template<typename T>
	tvec2<T>& tvec2<T>::add(const tvec2<T>& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}
	
	//methods
	template<typename T>
	tvec2<T>& tvec2<T>::subtract(const tvec2<T>& other) {
		x = x - other.x;
		y = y - other.y;

		return *this;
	}

	template<typename T>
	tvec2<T>& tvec2<T>::multiply(const tvec2<T>& other) {
		x = x * other.x;
		y = y * other.y;

		return *this;
	}

	template<typename T>
	tvec2<T>& tvec2<T>::divide(const tvec2<T>& other) {
		x = x / other.x;
		y = y / other.y;

		return *this;
	}


	template<typename T>
	tvec2<T>& tvec2<T>::scale(T scalar)
	{
		x = x * scalar;
		y = y * scalar;
		return *this;
	}

	template<typename T>
	tvec2<T>& tvec2<T>::normalize()
	{
		float n = 1 / sqrt(pow(x, 2) + pow(y, 2));
		return this->scale(n);
	}

	template<typename T>
	T tvec2<T>::distance(const tvec2<T>& other)
	{
		float a = x - other.x;
		float b = y - other.y;
		return tvec2(a, b).magnitude();
	}

	template<typename T>
	T tvec2<T>::magnitude()
	{
		return sqrt(this->dot(*this));
	}

	template<typename T>
	T tvec2<T>::dot(const tvec2<T>& other)
	{
		return (x*other.x) + (y*other.y);
	}

	template<typename T>
	tvec2<T>& tvec2<T>::operator+=(const tvec2<T>& other)
	{
		return this->add(other);
	}

	template<typename T>
	tvec2<T>& tvec2<T>::operator-=(const tvec2<T>& other)
	{
		return this->subtract(other);
	}

	template<typename T>
	tvec2<T>& tvec2<T>::operator/=(const tvec2<T>& other)
	{
		return this->divide(other);
	}

	template<typename T>
	tvec2<T>& tvec2<T>::operator*=(const tvec2<T>& other)
	{
		return this->multiply(other);
	}

	template<typename T>
	bool tvec2<T>::operator==(const tvec2<T>& other)
	{
		if (x == other.x && y == other.y)
			return true;
		else
			return false;
	}

	template<typename T>
	bool tvec2<T>::operator!=(const tvec2<T>& other)
	{
		if (x == other.x && y == other.y)
			return false;
		else
			return true;
	}

}
}