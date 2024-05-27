/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:15:49 by amak              #+#    #+#             */
/*   Updated: 2024/05/27 19:04:56 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}
 
Fixed::Fixed(const Fixed &FixedValue) {
	std::cout << "Copy constructor called" << std::endl;
	*this = FixedValue;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = intValue << this->_fracBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(floatValue * (1 << this->_fracBits));
}

Fixed &Fixed::operator=(const Fixed &FixedValue) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &FixedValue) {
		this->_rawBits = FixedValue.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}
void	Fixed::setRawBits ( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_rawBits / (1 << this->_fracBits));
}

int		Fixed::toInt( void ) const {
	return (this->_rawBits >> this->_fracBits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &FixedValue) {
	output << FixedValue.toFloat();
	return output;
}
