/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 03:03:02 by yaidriss          #+#    #+#             */
/*   Updated: 2023/12/30 03:03:05 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    // Literal value
    double literal = 65.5;

    // Output as different scalar types
    std::cout << "As char: " << static_cast<char>(literal) << std::endl;
    std::cout << "As int: " << static_cast<int>(literal) << std::endl;
    std::cout << "As float: " << static_cast<float>(literal) << std::endl;
    std::cout << "As double: " << literal << std::endl;

    return 0;
}