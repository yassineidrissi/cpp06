/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:27:27 by yassine           #+#    #+#             */
/*   Updated: 2024/01/01 04:39:46 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    data_t foo;
    uintptr_t reinterpreted;

    foo.dummy_str = std::string("test");
    reinterpreted = Serialization::serialize(&foo);

    cout << "OG foo (Data) Address = " << &foo << endl
         << "dummy_str value = " << foo.dummy_str << endl;

    cout << endl;

    cout << "Reinterpreted foo value = " << reinterpreted << endl;

    cout << endl;

    data_t *deserialized;

    deserialized = Serialization::deserialize(reinterpreted);

    cout << "Deserialized Address = " << deserialized << endl
         << "dummy_str value = " << deserialized->dummy_str << endl;

    return EXIT_SUCCESS;
}