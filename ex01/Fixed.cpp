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
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	//_fixedPoint = src._fixedPoint;
	*this = src; //this is an actual call to the '=' overload
}
//desplazo 8 posiciones los bits que definen la parte entera para almacenarlo en el fixed y obtener 8 para la parte fraccionaria (todos en 0)
Fixed::Fixed(int const value)
{
	std::cout << " constructor called" << std::endl;
	_fixedPoint = value << _fractional;
}

//lo multiplico por 2^8 (256) igual en el constr para int, pero en los 8 bits fraccionales se guarda la parte decimal multiplicado por 256 tambien
Fixed::Fixed(float const value)
{
	std::cout << " constructor called" << std::endl;
	_fixedPoint = roundf(value * (1 << _fractional));
}

Fixed &Fixed::operator=(Fixed const &src)
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

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void 	Fixed::setRawBits(int const num)
{
	_fixedPoint = num;
}

//hay que castearlo a float para no perder datos
float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / (float)(1 << _fractional));
}

//ya se han anyadido los 8 ceos en el constructor, ahora solo necesitamos el exponente
int		Fixed::toInt(void) const
{
	return(_fixedPoint >> _fractional);
}

std::ostream &operator<<(std::ostream &os, Fixed const &in)
{
	os << in.toFloat();
	return os;
}
