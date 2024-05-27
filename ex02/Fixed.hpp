/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:13:05 by amak              #+#    #+#             */
/*   Updated: 2024/05/27 20:38:01 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fracBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixedValue);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed();

		Fixed	&operator=(const Fixed &fixedValue);

		bool	operator>(const Fixed &fixedValue) const;
		bool	operator<(const Fixed &fixedValue) const;
		bool	operator>=(const Fixed &fixedValue) const;
		bool	operator<=(const Fixed &fixedValue) const;
		bool	operator==(const Fixed &fixedValue) const;
		bool	operator!=(const Fixed &fixedValue) const;

		Fixed 	operator+(const Fixed &fixedValue) const;
		Fixed 	operator-(const Fixed &fixedValue) const;
		Fixed 	operator*(const Fixed &fixedValue) const;
		Fixed 	operator/(const Fixed &fixedValue) const;

		Fixed 	&operator++();
		Fixed 	operator++(int);
		Fixed 	&operator--();
		Fixed 	operator--(int);
		
		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		static Fixed		&min(Fixed &a, Fixed &b);
		const static Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		const static Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixedValue);

#endif
