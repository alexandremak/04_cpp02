/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:18:22 by amak              #+#    #+#             */
/*   Updated: 2024/05/22 23:06:12 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}
 
Fixed::Fixed(const Fixed &fixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &fixedPoint) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixedPoint) {
		this->rawBits = fixedPoint.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}
void	Fixed::setRawBits (int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}
