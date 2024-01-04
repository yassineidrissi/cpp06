/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:31:08 by yassine           #+#    #+#             */
/*   Updated: 2024/01/01 17:18:40 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

typedef struct Data 
{
   std::string s; 
}t_Data;

class Serializer
{
    public:
        t_Data *d;
        Serializer();
        ~Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &src);
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
}; 