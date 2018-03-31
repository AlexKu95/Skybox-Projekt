#include <iostream>
#include "src\math\math.h"

int main() {
	using namespace core;
	using namespace math;


	int zahl = 10;
	std::cout << zahl << std::endl;

	dvec2 ve(10.1,123.3);
	
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

	mat4 firstMat(2.0f);
	mat4 secondMat(v14, v24, v24, v54);
	mat4 thirdMat;
	thirdMat = firstMat * secondMat;

	vec4 vectorArray[4] = { v54,v44,v34,v24 };
	mat4 fourthMat(vectorArray);
	mat4 ortho;
	ortho = orthographicRH(-16.0f, 16.0f, -10.0f, 10.0f, 0.0f, 1.0f);


	std::cout << firstMat << std::endl;
	std::cout << secondMat << std::endl;
	std::cout << thirdMat << std::endl;
	std::cout << fourthMat << std::endl;
	std::cout << ortho << std::endl;

	float input[16] = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f};
	float input2[16] = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
	mat3 first3(input);
	mat3 second3(input2);
	mat3 place;
	place = first3 * second3;

	std::cout << first3 << std::endl;
	std::cout << second3 << std::endl;
	std::cout << place << std::endl;


	system("PAUSE");
	return 0;
}