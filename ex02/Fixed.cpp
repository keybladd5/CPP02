/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:57:46 by polmarti          #+#    #+#             */
/*   Updated: 2024/10/16 18:57:48 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const value)
{
	//std::cout << "Int constructor called" << std::endl;
	_fixedPoint = value << _fractional;
}

Fixed::Fixed(float const value)
{
	//std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(value * (1 << _fractional));
}

Fixed &Fixed::operator=(Fixed const &src)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fixedPoint = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void 	Fixed::setRawBits(int const num)
{
	_fixedPoint = num;
}


float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / (float)(1 << _fractional));
}

//bitwise to get the last fractional bits (fx/256 o 2^8)
int		Fixed::toInt(void) const
{
	return(_fixedPoint >> _fractional);
}

std::ostream& operator<<(std::ostream &os, Fixed const &in)
{
	os << in.toFloat();
	return os;
}

bool	Fixed::operator>(Fixed const &other) const
{
	if(this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &other) const
{
	if(this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	if(this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	if(this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &other) const
{
	if(this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	if(this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed const &other)
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &other)
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &other)
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &other)
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++()
{
	++_fixedPoint;
	return (*this);
}

// Special case for the compiler, postfix overload
// Return a temporary modified version
// Create a copy to return
// Modify the original
// Return the unmodified copy
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	--_fixedPoint;
	return (*this);
}

//special case
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

Fixed&	Fixed::min(Fixed &f_val, Fixed &s_val)
{
	return (f_val < s_val ? f_val : s_val);
}

Fixed const &Fixed::min(Fixed const &f_val, Fixed const &s_val)
{
	return (f_val < s_val ? f_val : s_val);
}
Fixed&	Fixed::max(Fixed &f_val, Fixed &s_val)
{
	return (f_val > s_val ? f_val : s_val);
}

Fixed const &Fixed::max(Fixed const &f_val, Fixed const &s_val)
{
	return (f_val > s_val ? f_val : s_val);
}
