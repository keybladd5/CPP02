/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:57:26 by polmarti          #+#    #+#             */
/*   Updated: 2024/10/16 18:57:28 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:

			int				_fixedPoint;
			static const int _fractional = 8;

	public:

			Fixed(void);
			Fixed(int const);
			Fixed(float const);
			Fixed(Fixed const&);
			Fixed &operator=(Fixed const &);
			int		getRawBits(void) const;
			void 	setRawBits(int const);
			float	toFloat(void) const;
			int		toInt(void) const;
			bool	operator>(Fixed const &other) const;
			bool	operator<(Fixed const &other) const;
			bool	operator>=(Fixed const &other) const;
			bool	operator<=(Fixed const &other) const;
			bool	operator==(Fixed const &other) const;
			bool	operator!=(Fixed const &other) const;
			Fixed	operator+(Fixed const &other);
			Fixed	operator-(Fixed const &other);
			Fixed	operator*(Fixed const &other);
			Fixed	operator/(Fixed const &other);
			Fixed&	operator++();
			Fixed	operator++(int);
			Fixed&	operator--();
			Fixed	operator--(int);
			Fixed&	min(Fixed &f_val, Fixed &s_val);
			Fixed	const&	min(Fixed const &f_val, Fixed const &s_val);
			Fixed&	Fixed::max(Fixed &f_val, Fixed &s_val);
			Fixed	const& Fixed::max(Fixed const &f_val, Fixed const &s_val);
			~Fixed();
};

std::ostream &operator<<(std::ostream &os, Fixed const &in);

#endif