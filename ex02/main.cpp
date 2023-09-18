/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:24:21 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/18 15:19:07 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void) {
	std::srand((unsigned int)std::time(NULL));
	int i = std::rand() % 3;

	switch (i) {
		case 0:
			std::cout << "Generate:	A" << std::endl;
			return dynamic_cast<Base*>(new A());
			break;
		case 1:
			std::cout << "Generate:	B" << std::endl;
			return dynamic_cast<Base*>(new B());
			break;
		case 2:
			std::cout << "Generate:	C" << std::endl;
			return dynamic_cast<Base*>(new C());
			break;
	}
	return NULL;
}

void identify(Base* p) {
	A	*APtr = dynamic_cast<A*>(p);
	if (APtr)
		std::cout << "Identify*	A" << std::endl;
	B	*BPtr = dynamic_cast<B*>(p);
	if (BPtr)
		std::cout << "Identify*	B" << std::endl;
	C	*CPtr = dynamic_cast<C*>(p);
	if (CPtr)
		std::cout << "Identify*	C" << std::endl;
}

void identify(Base& p) {
	try {
		A &ARef = dynamic_cast<A&>(p);
		std::cout << "Identify&	A" << std::endl;
		(void)ARef;
	} catch (std::exception &e) {}
	try {
		B &BRef = dynamic_cast<B&>(p);
		std::cout << "Identify&	B" << std::endl;
		(void)BRef;
	} catch (std::exception &e) {}
	try {
		C &CRef = dynamic_cast<C&>(p);
		std::cout << "Identify&	C" << std::endl;
		(void)CRef;
	} catch (std::exception &e) {}
}

int	main(void) {
	Base *base = generate();

	identify(base);
	identify(*base);

	delete(base);
	return 0;
}