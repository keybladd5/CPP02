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

//ad include guards
#include <iostream>

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
			~Fixed();
};

std::ostream &operator<<(std::ostream &os, Fixed const &in);
