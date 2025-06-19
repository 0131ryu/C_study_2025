#include "chapter04.h"

using namespace std;

namespace chapter04 {
	int testFunc(int param1, int param2 = 2) {
		return (param1 * param2);
	}

	void cpp_chapter04_ex1() {
		std::cout << testFunc(10) << std::endl;
		std::cout << testFunc(10, 5) << std::endl;
	}

	int add(int a, int b, int c) {
		std::cout << "add(int, int, int) : ";
		return (a + b + c);
	}

	int add(int a, int b) {
		std::cout << "add(int, int) : ";
		return (a + b);
	}

	double add(double a, double b)
	{
		std::cout << "add(double, double) : ";
		return (a + b);
	}

	void cpp_chapter04_ex2() {
		std::cout << add(3, 4) << std::endl;
		std::cout << add(3, 4, 5) << std::endl;
		std::cout << add(3.0, 4.0) << std::endl;
	}

	template <typename T>
	T add2(T a, T b)
	{
		return (a + b);
	}

	void cpp_chapter04_ex3() {
		std::cout << add2(3, 4) << std::endl;
		std::cout << add2(3.3, 4.4) << std::endl;
	}
}

void testFunc2() {
	cout << "::TestFunc()" << endl;
}

namespace Test
{
	void testFunc2() {
		cout << "Test::TestFunc()" << endl;
	}
}

namespace MyData
{
	void testFunc2()
	{
		cout << "MyData::TestFunc()" << endl;
	}
}