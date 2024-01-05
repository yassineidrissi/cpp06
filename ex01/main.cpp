/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:27:27 by yassine           #+#    #+#             */
/*   Updated: 2024/01/05 19:58:10 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
   Data *d;
   Data *data = new Data;
   uintptr_t ptr;
   data->s = "hello world!"; 
   ptr = Serializer::serialize(data);
   std::cout << YELLOW << "the ptr : " << RESET << ptr << std::endl;
   d = Serializer::deserialize(ptr);
   std::cout << YELLOW << "the data : " << RESET << d->s << std::endl;
   delete d;
   return 0;
}