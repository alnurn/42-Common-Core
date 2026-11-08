#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed&	other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed&	other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	int	shift;

	shift = 1 << bits;
	this->_value = value * shift;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	int	shift;

	shift = 1 << bits;
	this->_value = (int) roundf(value * shift);
	std::cout << "Float constructor called" << std::endl;
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


