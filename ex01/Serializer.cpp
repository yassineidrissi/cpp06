/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:35:14 by yassine           #+#    #+#             */
/*   Updated: 2024/01/03 21:31:07 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Call Constractor" << RESET << std::endl;
}

Serializer::~Serializer()
{
	std::cout << GREEN << "Call Destractor" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &src) {
    this->d = src.d;
}

Serializer& Serializer::operator=(Serializer const &src)
{
    if (this != &src)
        this->d = src.d;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}