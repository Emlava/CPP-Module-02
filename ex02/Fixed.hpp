#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void); // Default constructor
		Fixed(const Fixed& instance); // Copy constructor
		Fixed&	operator=(const Fixed& rhs_instance); // Copy assignment operator overload
		~Fixed(void); // Destructor

		Fixed(const int i);
		Fixed(const float f);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		bool	operator>(const Fixed& rhs_instance);
		bool	operator<(const Fixed& rhs_instance);
		bool	operator>=(const Fixed& rhs_instance);
		bool	operator<=(const Fixed& rhs_instance);
		bool	operator==(const Fixed& rhs_instance);
		bool	operator!=(const Fixed& rhs_instance);
		Fixed	operator+(const Fixed& rhs_instance);
		Fixed	operator-(const Fixed& rhs_instance);
		Fixed	operator*(const Fixed& rhs_instance);
		Fixed	operator/(const Fixed& rhs_instance);
		Fixed&	operator++(void); // Prefix
		Fixed	operator++(int); // Postfix
		Fixed&	operator--(void); // Prefix
		Fixed	operator--(int); // Postfix

		static Fixed&	min(Fixed& instance_1, Fixed& instance_2);
		static const Fixed&	min(const Fixed& instance_1, const Fixed& instance_2);
		static Fixed&	max(Fixed& instance_1, Fixed& instance_2);
		static const Fixed&	max(const Fixed& instance_1, const Fixed& instance_2);

	private:
		int		value;
		static const int	fraction_bits = 8; // Non-member attribute or class variable
};

std::ostream&	operator<<(std::ostream& os, const Fixed& instance);

#endif
