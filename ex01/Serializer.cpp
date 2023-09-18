/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:22 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/18 13:49:34 by mjourno          ###   ########.fr       */
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
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}