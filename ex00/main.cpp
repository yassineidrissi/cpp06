/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:15:58 by yaidriss          #+#    #+#             */
/*   Updated: 2024/01/02 05:02:59 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"


int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert [literal]" << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}