#include "Fixed.hpp"


// Member functions needed to have canonical form -->

Fixed::Fixed() : value(0) // Default constructor
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& instance) // Copy Constructor
{
	std::cout << "Copy constructor called\n";
	*this = instance;
}

Fixed&	Fixed::operator=(const Fixed& rhs_instance) // Copy assignment operator overload
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs_instance)
		value = rhs_instance.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) // Destructor
{
	std::cout << "Destructor called\n";
}

// <--

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	value = i * std::pow(2, fraction_bits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	value = f * std::pow(2, fraction_bits);
}

float	Fixed::toFloat(void) const
{
	return (value / std::pow(2, fraction_bits));
}

int	Fixed::toInt(void) const
{
	return (value / std::pow(2, fraction_bits));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits() member function called\n";
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
	return ;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& instance)
{
	os << instance.toFloat();
	return (os);
}
