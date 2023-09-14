/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:26:05 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/14 11:32:39 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER

# include <string>
# include <iostream>
# include <stdlib.h>

class ScalarConverter {
	public:
		//canon
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter	&operator=(const ScalarConverter &src);
		~ScalarConverter();

		static void convert(std::string str);
};

#endif