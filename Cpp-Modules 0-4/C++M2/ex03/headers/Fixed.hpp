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
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		Fixed&	operator=(const Fixed&	other);
		Fixed	operator+(const Fixed&	other) const;
		Fixed	operator-(const Fixed&	other) const;
		Fixed	operator*(const Fixed&	other) const;
		Fixed	operator/(const Fixed&	other) const;
		Fixed	operator++(int n);
		Fixed	operator--(int	n);
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		bool	operator>(const Fixed&	other) const;
		bool	operator>=(const Fixed&	other) const;
		bool	operator<(const Fixed&	other) const;
		bool	operator<=(const Fixed&	other) const;
		bool	operator==(const Fixed&	other) const;
		bool	operator!=(const Fixed&	other) const;

		static Fixed&		min(Fixed& num1, Fixed& num2);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
		static Fixed&		max(Fixed& num1, Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);

		int	toInt(void) const;
		float	toFloat(void) const;
		void	setRawBits(int const raw);
		int	getRawBits(void) const;
};

std::ostream&	operator<<(std::ostream& cout, const Fixed& value);

#endif
