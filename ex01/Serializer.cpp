/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:22 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/18 13:41:51 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "useless in this execise" << std::endl;
}

Serializer::Serializer(const Serializer &src) {
	std::cout << "useless in this execise" << std::endl;
	(void)src;
}

Serializer	&Serializer::operator=(const Serializer &src) {
	std::cout << "useless in this execise" << std::endl;
	(void)src;
	return *this;
}

Serializer::~Serializer() {
	std::cout << "useless in this execise" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
	return	res;
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data* res = reinterpret_cast<Data*>(raw);
	return res;
}