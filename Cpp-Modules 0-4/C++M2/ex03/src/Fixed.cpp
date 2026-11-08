#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const Fixed&	other)
{
	*this = other;
}

Fixed::Fixed(const int value)
{
	int	shift;

	shift = 1 << bits;
	this->_value = value * shift;
}

Fixed::Fixed(const float value)
{
	int	shift;

	shift = 1 << bits;
	this->_value = (int) roundf(value * shift);
}

Fixed::~Fixed()
{

}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1._value < num2._value)
		return (num1);
	else
		return (num2);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1._value < num2._value)
		return (num1);
	else
		return (num2);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1._value > num2._value)
		return (num1);
	else
		return (num2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1._value > num2._value)
		return (num1);
	else
		return (num2);
}

Fixed&	Fixed::operator=(const Fixed&	other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed&	other) const
{
	Fixed	copy;

	copy.setRawBits(this->getRawBits() + other.getRawBits());
	return copy;
}

Fixed	Fixed::operator-(const Fixed&	other) const
{
	Fixed	copy;

	copy.setRawBits(this->getRawBits() - other.getRawBits());
	return copy;
}

Fixed	Fixed::operator/(const Fixed&	other) const
{
	Fixed	copy;
	long	temp;
	int	shift;
	int	res;

	shift = 1 << bits;
	temp = static_cast<long>(this->getRawBits()) * shift;
	res = temp / other.getRawBits();
	copy.setRawBits(res);
	return copy;
}

Fixed	Fixed::operator*(const Fixed&	other) const
{
	Fixed	copy;
	long	temp;
	int	shift;
	int	res;

	shift = 1 << bits;
	temp = static_cast<long>(this->getRawBits()) * other.getRawBits();
	res = temp / shift;
	copy.setRawBits(res);
	return copy;
}

Fixed	Fixed::operator++(int	n)
{
	(void) n;
	Fixed copy(*this);
	this->_value++;
	return (copy);
}

Fixed	Fixed::operator--(int	n)
{
	(void) n;
	Fixed copy(*this);
	this->_value--;
	return (copy);
}

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

bool	Fixed::operator>(const Fixed&	other) const
{
	if (this->_value > other._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed&	other) const
{
	if (this->_value >= other._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed&	other) const
{
	if (this->_value < other._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed&	other) const
{
	if (this->_value <= other._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed&	other) const
{
	if (this->_value == other._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed&	other) const
{
	if (this->_value != other._value)
		return (true);
	else
		return (false);
}


int	Fixed::toInt(void) const
{
	int	shift;

	shift = 1 << bits;
	return (this->_value / shift);
}

float	Fixed::toFloat(void) const
{
	int	shift;

	shift = 1 << bits;
	return ((float) this->_value / shift);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

std::ostream&	operator<<(std::ostream& cout, const Fixed& value)
{
	cout << value.toFloat();
	return (cout);
}
