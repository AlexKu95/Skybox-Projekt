#include <iostream>
#include "src\math\vec2.h"
#include "src\math\vec3.h"

int main() {
	using namespace core;
	using namespace math;

	vec2 v1(0);
	vec2 v2 = vec2(1.5, 1.5);
	vec2 v3(3.5);
	vec2 v4(4, 5.6);
	vec2 v5(100, 0);

	vec2 v6 = 100 + 123;
	vec2 v7 = v1 + 10;
	vec2 v8 = 10 + vec2(0);
	vec2 v9 = v1 + v5;

	v4 = v2 + 5.9;

	v1 += 100;
	v1 += v2;

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << v4 << std::endl;
	std::cout << v5 << std::endl;
	std::cout << v6 << std::endl;
	std::cout << v7 << std::endl;
	std::cout << v8 << std::endl;
	std::cout << v9 << std::endl;


	vec3 v13(1, 23, 34);
	vec3 v23(v2, 10);
	vec3 v33(10,v2);
	vec3 v43(0);
	v43 += v13;

	std::cout << v13 << std::endl;
	std::cout << v23 << std::endl;
	std::cout << v33 << std::endl;
	std::cout << v43 << std::endl;


	system("PAUSE");
	return 0;
}