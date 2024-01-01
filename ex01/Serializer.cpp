/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:35:14 by yassine           #+#    #+#             */
/*   Updated: 2024/01/01 00:31:53 by yaidriss         ###   ########.fr       */
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
    if (this != &src) {
        // Assignment operator implementation goes here
        // For example:
        this->d = src.d;
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t ret;
	ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ret;
	ret = reinterpret_cast<Data*>(raw);
	return ret;
}