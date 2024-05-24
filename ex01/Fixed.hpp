/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:15:34 by amak              #+#    #+#             */
/*   Updated: 2024/05/24 23:06:09 by amak             ###   ########.fr       */
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
		Fixed(const Fixed &fixedPoint);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed &operator=(const Fixed &fixedPoint);
		~Fixed();
		
		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixedPoint);

#endif
