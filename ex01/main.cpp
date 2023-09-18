/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:00 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/18 13:46:51 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void) {
	int		i = 5;
	Data	*adrr = reinterpret_cast<Data*>(&i);

	std::cout << adrr << std::endl;

	uintptr_t	u = Serializer::serialize(adrr);
	std::cout << u << std::endl;

	Data	*data = Serializer::deserialize(u);
	std::cout << data << std::endl;

	int	*test = reinterpret_cast<int*>(data);
	std::cout << *test << std::endl;

	return 0;
}