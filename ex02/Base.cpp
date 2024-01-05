/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:20:29 by yaidriss          #+#    #+#             */
/*   Updated: 2024/01/05 19:49:39 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
}

Base* Base::generate(void)
{
	A* a = new A;
	B* b = new B;
	C* c = new C;
	std::srand(std::time(0));
	int hz = (std::rand() % 3);
    switch (hz)
	{
	case 0:
	{
		delete b;
		delete c;
		return  (reinterpret_cast<Base*>(a));
	}
		break;
	case 1:
	{
		delete a;
		delete c;
		return (reinterpret_cast<Base*>(b));
	}
		break;
	
	default:
	{
		delete a;
		delete b;
		return (reinterpret_cast<Base*>(c));
	}
		break;
	}
}

A::~A()
{
}

B::~B()
{
}

C::~C()
{
}

void Base::identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << GREEN << "for ptr : A" << RESET << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << GREEN << "for ptr : B" << RESET << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout <<GREEN << "for ptr : C" << RESET << std::endl;
	}
	else
	{
		std::cout << "There is no Data type" << std::endl;
	}
}

void Base::identify(Base& p) {
	try
	{
		__unused Base a = dynamic_cast<A&>(p);
		std::cout << GREEN  << "for ref : A" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			__unused Base b = dynamic_cast<B&>(p);
			std::cout << GREEN << "for ref : B" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{			
				__unused Base c = dynamic_cast<C&>(p);
				std::cout << GREEN << "for ref : C" << RESET << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << RED << "There is no Data" << RESET << std::endl;
			}
		}
	}
	
}