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
	value = roundf(f * std::pow(2, fraction_bits)); // Rounds to nearest value
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

bool	Fixed::operator>(const Fixed& rhs_instance)
{
	if (this->value > rhs_instance.value)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& rhs_instance)
{
	if (this->value < rhs_instance.value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& rhs_instance)
{
	if (this->value >= rhs_instance.value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& rhs_instance)
{
	if (this->value <= rhs_instance.value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& rhs_instance)
{
	if (this->value == rhs_instance.value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& rhs_instance)
{
	if (this->value != rhs_instance.value)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& rhs_instance)
{
	Fixed	result(this->toFloat() + rhs_instance.toFloat());

	return (result);
}

Fixed	Fixed::operator-(const Fixed& rhs_instance)
{
	Fixed	result(this->toFloat() - rhs_instance.toFloat());

	return (result);
}

Fixed	Fixed::operator*(const Fixed& rhs_instance)
{
	Fixed	result(this->toFloat() * rhs_instance.toFloat());

	return (result);
}

Fixed	Fixed::operator/(const Fixed& rhs_instance)
{
	Fixed	result(this->toFloat() / rhs_instance.toFloat());

	return (result);
}

Fixed&	Fixed::operator++(void) // Prefix
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int) // Postfix
{
	Fixed	old_value(*this);

	this->value++;
	return (old_value);
}

Fixed&	Fixed::operator--(void) // Prefix
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int) // Postfix
{
	Fixed	old_value(*this);

	this->value--;
	return (old_value);
}

Fixed&	Fixed::min(Fixed& instance_1, Fixed& instance_2)
{
	if (instance_1.value < instance_2.value)
		return (instance_1);
	return (instance_2); // Whether they are equal or instance_2 is less than instance_1
}

const Fixed&	Fixed::min(const Fixed& instance_1, const Fixed& instance_2)
{
	if (instance_1.value < instance_2.value)
		return (instance_1);
	return (instance_2); // Whether they are equal or instance_2 is less than instance_1
}

Fixed&	Fixed::max(Fixed& instance_1, Fixed& instance_2)
{
	if (instance_1.value > instance_2.value)
		return (instance_1);
	return (instance_2); // Whether they are equal or instance_2 is greater than instance_1
}

const Fixed&	Fixed::max(const Fixed& instance_1, const Fixed& instance_2)
{
	if (instance_1.value > instance_2.value)
		return (instance_1);
	return (instance_2); // Whether they are equal or instance_2 is greater than instance_1
}

std::ostream&	operator<<(std::ostream& os, const Fixed& instance)
{
	os << instance.toFloat();
	return (os);
}
