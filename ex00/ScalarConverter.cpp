/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:08:22 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/14 14:57:43 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "useless in this execise" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	std::cout << "useless in this execise" << std::endl;
	(void)src;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src) {
	std::cout << "useless in this execise" << std::endl;
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "useless in this execise" << std::endl;
}

void	exceptions(std::string str) {
	if (str == "-inff" || str == "-inf")
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
	else if (str == "+inff" || str == "+inf")
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
	else if (str == "nanf" || str == "nan")
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
}

//long long	atol(std::string str) {
//	int	i = 0;
//	int	pn = 1;
//	if (str[i] == '-') {
//		++i;
//		pn = -1;
//	}
//	long long	res = 0;
//	while (str[i] && isdigit(str[i])) {
//		res = res * 10 + (str[i] - '0');
//		++i;
//	}
//	if ((long unsigned)i != str.length())
//		return 2147483648;
//	return pn * res;
//}

void ScalarConverter::convert(std::string str) {
	std::cout << "string: " << str << std::endl; // delete
	if (str.empty()) {
		std::cout << "Empty string" << std::endl;
		return;
	}

	//exceptions
	if (str == "-inff" || str == "-inf" || str == "+inff" || str == "+inf" || str == "nanf" || str == "nan")
		return exceptions(str);
	//detect str type
	//char
	else if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
		std::cout << "char: " << (char)str[0] << "\nint: " << (int)str[0] << "\nfloat: " << (float)str[0] << ".0f\ndouble: " << (double)str[0] << ".0" << std::endl;

	//float / double
	else if (str.find('.') != (long unsigned int)-1) {
		int	i = 0;
		while (str[i] && isdigit(str[i]))
			i++;
		if (str[i] == '.')
			i++;
		while (str[i] && isdigit(str[i]))
			i++;

		if ((long unsigned int)i == str.length() - 1 && str[i] == 'f')
			//float;
			;
		else if ((long unsigned int)i == str.length() && !str[i])
			//double;
			;
		else
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
	//int
	//else {
	//	if (str.length() > 11 || atol(str) > 2147483647 || atol(str) < -2147483648)
	//		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	//	else {
	//		std::cout << "char: ";
	//		if (!isprint(atol(str)))
	//			std::cout << "Non displayable";
	//		else
	//			std::cout << "'" << (char)atol(str);
	//		std::cout << "'\nint: " << (int)atol(str) << "\nfloat: " << (float)atol(str) << ".0f\ndouble: " << (double)atol(str) << ".0" << std::endl;
	//	}
	//}
}