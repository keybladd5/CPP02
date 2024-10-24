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

class Fixed
{
	private:

			int				_fixedPoint;
			static const int _fractional = 8;
	public:

			Fixed(void);
			Fixed(Fixed &);
			Fixed &operator=(Fixed&);
			int		getRawBits(void) const;
			void 	setRawBits(int const);
			~Fixed();
};

#endif
