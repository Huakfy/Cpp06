/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:00 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/18 14:06:23 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void) {
	Data	data;
	data.c = 'A';
	Data	*d = &data;

	std::cout << "Content of data:	" << d->c << std::endl;
	std::cout << "Address of data:	" << d << std::endl;

	uintptr_t	u = Serializer::serialize(d);
	std::cout << "uintptr_t:		" << u << std::endl;
	Data	*res = Serializer::deserialize(u);

	std::cout << "Address of res:		" << res << std::endl;
	std::cout << "Content of res:		" << res->c << std::endl << std::endl;



	int		i = 5;
	Data	*addr = reinterpret_cast<Data*>(&i);

	std::cout << "Content of i:		" << i << std::endl;
	std::cout << "Address of i:		" << addr << std::endl;

	u = Serializer::serialize(addr);
	std::cout << "uintptr_t:		" << u << std::endl;

	res = Serializer::deserialize(u);
	std::cout << "Address of res:		" << res << std::endl;

	int	*test = reinterpret_cast<int*>(res);
	std::cout << "Content of res:		" << *test << std::endl;

	return 0;
}