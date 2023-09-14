/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:26:19 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/13 13:26:33 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return (std::cout << "Enter one argument" << std::endl, 1);
	ScalarConverter::convert(argv[1]);
	return (0);
}