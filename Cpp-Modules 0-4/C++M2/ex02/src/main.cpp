#include "Fixed.hpp"

int	main(void)
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << "*****************" << std::endl;
	}
	{
		Fixed a(10);
		Fixed b(20);
		Fixed c;
		Fixed d;
		Fixed num1(5);
		Fixed num2(2);

		c = a + b;
		std::cout << c << std::endl;
		d = a - b;
		std::cout << d << std::endl;
		std::cout << c * d << std::endl;
		std::cout << num1 / num2 << std::endl;

		if (b > a)
			std::cout << "b > a" << std::endl;
		if (a < b)
			std::cout << "a < b" << std::endl;
		Fixed num3(5);
		if (num1 >= num3)
			std::cout << "true" << std::endl;
		if (num1 <= num3)
			std::cout << "true" << std::endl;
		if (num1 == num3)
			std::cout << "true" << std::endl;
		if (num2 != num3)
			std::cout << "true" << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		a--;
		std::cout << "a =" << a << std::endl;
		std::cout << "++a = " << ++a << std::endl;
		std::cout << "--a = " << --a << std::endl;
		std::cout << "max = " << Fixed::max(num1, num2) << std::endl;
		std::cout << "min = " << Fixed::min(num1, num2) << std::endl;
		num1 = num2;
		if (num1 == num2)
			std::cout << "true" << std::endl;
	}
	return (0);
}
