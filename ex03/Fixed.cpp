/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:13:07 by amak              #+#    #+#             */
/*   Updated: 2024/05/27 18:55:34 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {}
 
Fixed::Fixed(const Fixed &fixedValue) {
	*this = fixedValue;
}

Fixed::Fixed(const int intValue) {
	this->_rawBits = intValue << this->_fracBits;
}

Fixed::Fixed(const float floatValue) {
	this->_rawBits = roundf(floatValue * (1 << this->_fracBits));
}

Fixed::~Fixed() {}

Fixed	&Fixed::operator=(const Fixed &fixedValue) {
	if (this != &fixedValue) {
		this->_rawBits = fixedValue.getRawBits();
	}
	return *this;
}

bool	Fixed::operator>(const Fixed &fixedValue) {
	return (this->getRawBits() > fixedValue.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixedValue) {
	return (this->getRawBits() < fixedValue.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixedValue) {
	return (this->getRawBits() >= fixedValue.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixedValue) {
	return (this->getRawBits() <= fixedValue.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixedValue) {
	return (this->getRawBits() == fixedValue.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixedValue) {
	return (this->getRawBits() != fixedValue.getRawBits());
}

Fixed	&Fixed::operator+(const Fixed &fixedValue) {
	Fixed newFixedValue;
	
	newFixedValue.setRawBits(this->getRawBits() + fixedValue.getRawBits());
	return (newFixedValue);
}

Fixed	&Fixed::operator-(const Fixed &fixedValue) {
	Fixed newFixedValue;
	
	newFixedValue.setRawBits(this->getRawBits() - fixedValue.getRawBits());
	return (newFixedValue);
}

Fixed	&Fixed::operator*(const Fixed &fixedValue) {
	Fixed newFixedValue;
	
	newFixedValue.setRawBits(this->getRawBits() * fixedValue.getRawBits());
	return (newFixedValue);
}

Fixed	&Fixed::operator/(const Fixed &fixedValue) {
	Fixed newFixedValue;
	
	newFixedValue.setRawBits(this->getRawBits() / fixedValue.getRawBits());
	return (newFixedValue);
}

int	Fixed::getRawBits( void ) const {
	return this->_rawBits;
}
void	Fixed::setRawBits ( int const raw ) {
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_rawBits / (1 << this->_fracBits));
}

int		Fixed::toInt( void ) const {
	return (this->_rawBits >> this->_fracBits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixedValue) {
	output << fixedValue.toFloat();
	return output;
}
