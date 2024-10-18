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
#include <ieee754.h>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	//_fixedPoint = src._fixedPoint;
	*this = src; //this is an actual call to the '=' overload
}
//para hacer correctamente este overload hay que acceder al dato de _fixedPoint con el geter
Fixed &Fixed::operator=(Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fixedPoint = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void 	Fixed::setRawBits(int const num)
{
	_fixedPoint = num;
}