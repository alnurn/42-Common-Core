#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int			_value;
		static const int	bits; 

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed&	other);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);
		int	toInt(void) const;
		float	toFloat(void) const;
	
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
};

std::ostream&	operator<<(std::ostream& cout, const Fixed& value);

#endif
