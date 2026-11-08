#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

#include <iostream>
#include <string>

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
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
};

#endif
