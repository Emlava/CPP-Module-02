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

		Fixed(const int i);
		Fixed(const float f);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		void	operator<<(std::ostream& os);

	private:
		int		value;
		static const int	fraction_bits = 8; // Non-member attribute
};

#endif
