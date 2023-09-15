/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:08:22 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/15 15:37:20 by mjourno          ###   ########.fr       */
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

void ScalarConverter::convert(std::string str) {
	if (str.empty()) {
		std::cout << "Empty string" << std::endl;
		return;
	}

	bool	ok[4] = {0,0,0,0};
	char	c;
	int		i;
	float	f;
	double	d;

	//exceptions
	if (str == "-inff" || str == "-inf" || str == "+inff" || str == "+inf" || str == "nanf" || str == "nan")
		return exceptions(str);
	else if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0])) { //char
		ok[0] = 1; ok[1] = 1; ok[2] = 1; ok [3] = 1;
		c = static_cast<char>(str[0]);
		i = static_cast<int>(str[0]);
		f = static_cast<float>(str[0]);
		d = static_cast<double>(str[0]);
	}


	//float / double
	else if (str.find('.') != (long unsigned int)-1) {
		long unsigned int	j = 0;

		if (str[j] == '-') j++;						//skip '-'
		while (str[j] && isdigit(str[j])) j++;		//go until dot
		if (str[j] == '.') j++;						//skip dot
		while (str[j] && isdigit(str[j])) j++;		//skip numbers

		if (j == str.length() - 1 && str[j] == 'f') {	//float
			f = strtof(str.c_str(), NULL);
			if (f != HUGE_VALF && f != -HUGE_VALF) {
				if (f >= static_cast<float>(std::numeric_limits<int>::min()) && f <= static_cast<float>(std::numeric_limits<int>::max())) {
					ok[0] = 1; ok[1] = 1;
					c = static_cast<char>(f);
					i = static_cast<int>(f);
				}
				ok[2] = 1; ok[3] = 1;
				d = static_cast<double>(f);
			}
		}
		else if (j == str.length() && !str[j])	{	//double
			d = strtod(str.c_str(), NULL);
			if (d != HUGE_VAL && d != -HUGE_VAL) {
				if (d >= static_cast<double>(std::numeric_limits<float>::min()) && d <= static_cast<double>(std::numeric_limits<float>::max())) {
					ok[2] = 1;
					f = static_cast<float>(d);
				}
				if (d >= static_cast<double>(std::numeric_limits<int>::min()) && d <= static_cast<double>(std::numeric_limits<int>::max())) {
					ok[0] = 1;
					ok[1] = 1;
					c = static_cast<char>(d);
					i = static_cast<int>(d);
				}
				ok[3] = 1;
			}
		}
	}


	//int
	else if (str.length() <= 11) {
		int		j = 0;
		if (str[j] == '-')
			j++;
		while (str[j] && isdigit(str[j]))
			j++;

		long	l = strtol(str.c_str(), NULL, 10);
		if (!str[j] && l >= static_cast<long>(std::numeric_limits<int>::min()) && l <= static_cast<long>(std::numeric_limits<int>::max())) {
			ok[0] = 1; ok[1] = 1; ok[2] = 1; ok [3] = 1;
			i = static_cast<int>(l);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
	}

	//print
	if (ok[0])	//char
	{
		if (isprint(c) && i >= 0 && i <= 127)
			std::cout << "char:	" << c;
		else
			std::cout << "char:	Non displayable";
	}
	else
		std::cout << "char:	impossible";
	if (ok[1])	//int
		std::cout << "\nint:	" << i;
	else
		std::cout << "\nint:	impossible";
	if (ok[2])	//float
		std::cout << std::setprecision(1) << std::fixed << "\nfloat:	" << f << "f";
	else
		std::cout << std::setprecision(1) << std::fixed << "\nfloat:	impossible";
	if (ok[3])	//double
		std::cout << std::setprecision(1) << std::fixed << "\ndouble:	" << d << std::endl;
	else
		std::cout << std::setprecision(1) << std::fixed << "\ndouble:	impossible" << std::endl;
}