/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:18:20 by amak              #+#    #+#             */
/*   Updated: 2024/05/22 23:06:00 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					rawBits;
		static const int	fracBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixedPoint);
		Fixed &operator=(const Fixed &fixedPoint);
		~Fixed();
		
		int		getRawBits( void ) const;
		void	setRawBits (int const raw );
};

#endif
