/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:13:07 by amak              #+#    #+#             */
/*   Updated: 2024/05/27 21:32:51 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}
 
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

// ::###:: COMPARISON OPERATORS:

bool	Fixed::operator>(const Fixed &fixedValue) const {
	return (this->getRawBits() > fixedValue.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixedValue) const {
	return (this->getRawBits() < fixedValue.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixedValue) const {
	return (this->getRawBits() >= fixedValue.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixedValue) const {
	return (this->getRawBits() <= fixedValue.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixedValue) const {
	return (this->getRawBits() == fixedValue.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixedValue) const {
	return (this->getRawBits() != fixedValue.getRawBits());
}

// ::###::  ARITHMETIC OPERATORS: 

Fixed	Fixed::operator+(const Fixed &fixedValue) const {
	Fixed newFixedValue(this->toFloat() + fixedValue.toFloat());
	return (newFixedValue);
}

Fixed	Fixed::operator-(const Fixed &fixedValue) const {
	Fixed newFixedValue(this->toFloat() - fixedValue.toFloat());
	return (newFixedValue);
}

Fixed	Fixed::operator*(const Fixed &fixedValue) const {
	Fixed newFixedValue(this->toFloat() * fixedValue.toFloat());
	return (newFixedValue);
}

Fixed	Fixed::operator/(const Fixed &fixedValue) const {
	if (fixedValue.getRawBits() == 0) {
		std::cout << "Error: Cannot divide by zero!" << std::endl;
		exit(1);
	}
	Fixed newFixedValue(this->toFloat() / fixedValue.toFloat());
	return (newFixedValue);
}

// ::###::  INCREMENT/DECREMENT OPERATORS:

Fixed 	&Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed 	Fixed::operator++(int) {
	Fixed fixedValue(*this);
	
	this->setRawBits(this->getRawBits() + 1);
	return (fixedValue);
}

Fixed 	&Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed 	Fixed::operator--(int) {
	Fixed fixedValue(*this);
	
	this->setRawBits(this->getRawBits() - 1);
	return (fixedValue);
}

// ::###::  MEMBER FUNCTIONS:

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

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}

// FUNCTIONS:

std::ostream &operator<<(std::ostream &output, const Fixed &fixedValue) {
	output << fixedValue.toFloat();
	return output;
}
