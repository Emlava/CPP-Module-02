#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void); // Default constructor
		Fixed(const Fixed& instance); // Copy constructor
		Fixed	operator+(const Fixed& instance); // Copy assignment operator overload
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int		value;
		static const int	fraction_bits = 8;
};

#endif
