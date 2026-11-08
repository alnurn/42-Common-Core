#include "Point.hpp"

int main(void)
{
	{
	       	Point a(0, 0);
		Point b(6, 0);
		Point c(3, 6);
		std::cout << "TEST 1 - Inside (Expected 1): "
		       	<< bsp(a, b, c, Point(3, 2)) << std::endl;
		std::cout << "TEST 2 - Outside (Expected 0): "
			<< bsp(a, b, c, Point(7, 2)) << std::endl;
		std::cout << "TEST 3 - Vertex A (Expected 0): "
			<< bsp(a, b, c, Point(0, 0)) << std::endl;
		std::cout << "TEST 4 - On edge AB (Expected 0): "
			<< bsp(a, b, c, Point(3, 0)) << std::endl;
		std::cout << "TEST 5 - On edge BC (Expected 0): "
			<< bsp(a, b, c, Point(4.5f, 3)) << std::endl;
		std::cout << "TEST 6 - On edge CA (Expected 0): "
			<< bsp(a, b, c, Point(1.5f, 3)) << std::endl;
		std::cout << "TEST 7 - Above triangle (Expected 0): "
			<< bsp(a, b, c, Point(3, 7)) << std::endl;
		std::cout << "TEST 8 - Below triangle (Expected 0): "
			<< bsp(a, b, c, Point(3, -1)) << std::endl;
		std::cout << "TEST 9 - Reversed order (Expected 1): "
			<< bsp(c, b, a, Point(3, 2)) << std::endl;
	}
	{
		Point d(-4, -4);
		Point e(4, -4);
		Point f(0, 4);
		std::cout << "TEST 10 - Negative coordinates (Expected 1): "
			<< bsp(d, e, f, Point(0, 0)) << std::endl;
		Point g(0, 0);
		Point h(2, 2);
		Point i(4, 4);
		std::cout << "TEST 11 - all points on one line (Expected 0): "
			<< bsp(g, h, i, Point(2, 2)) << std::endl;
		Point j(1, 1);
		Point k(7, 2);
		Point l(3, 8);
		std::cout << "TEST 12 - Different triangle (Expected 1): "
			<< bsp(j, k, l, Point(3, 3)) << std::endl;
	}
	{
		Point fa(0.5f, 0.5f);
		Point fb(6.5f, 0.5f);
		Point fc(3.5f, 6.5f);
		std::cout << "TEST 13 - Float inside (Expected 1): "
			<< bsp(fa, fb, fc, Point(3.5f, 2.5f))
			<< std::endl;
		std::cout << "TEST 14 - Float outside (Expected 0): "
			<< bsp(fa, fb, fc, Point(7.5f, 2.5f))
			<< std::endl;
		std::cout << "TEST 15 - Float on edge (Expected 0): "
			<< bsp(fa, fb, fc, Point(3.5f, 0.5f))
			<< std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.01171875f, 0.0f);
		Point c(0.0f, 0.01171875f);

		std::cout << "TEST 16 - very small (Expected 1): "
			<< bsp(a, b, c, Point(0.00390625f, 0.00390625f))
			<< std::endl;
		std::cout << "TEST 17 - very small, on edge (Expected 0): " 
			<<bsp(a, b, c, Point(0.00390625f, 0.0f))
			<< std::endl;
		std::cout << "TEST 18 - vary small, outside (Expected 0): " 
			<< bsp(a, b, c, Point(0.01171875f, 0.01171875f))
			<< std::endl;
	}
	return 0;
}
