#include <iostream>
#include "src\math\vec2.h"
#include "src\math\vec3.h"
#include "src\math\vec4.h"

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

	vec4 v14(0);
	vec4 v24(v1,v2);
	vec4 v34(1, 2, 3, 4);
	vec4 v44 = v24;
	vec4 v54;
	v54 += v44;

	vec3 v53 = v13.cross(v23);
	std::cout << v13 << std::endl;
	std::cout << v23 << std::endl;
	std::cout << v33 << std::endl;
	std::cout << v43 << std::endl;
	std::cout << v53 << std::endl;

	std::cout << v14 << std::endl;
	std::cout << v24 << std::endl;
	std::cout << v34 << std::endl;
	std::cout << v44 << std::endl;
	std::cout << v54 << std::endl;


	system("PAUSE");
	return 0;
}