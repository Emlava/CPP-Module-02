#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void); // Default constructor
		Fixed(const Fixed& instance); // Copy constructor
		Fixed&	operator=(const Fixed& rhs_instance); // Copy assignment operator overload
		~Fixed(void); // Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int		value;
		static const int	fraction_bits = 8; // Non-member attribute
};

#endif
