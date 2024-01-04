/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:29:43 by yaidriss          #+#    #+#             */
/*   Updated: 2024/01/04 22:49:56 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base a;
	Base *b = a.generate();
	Base &c = *b;
	a.identify(b);
	a.identify(c);
	delete(b);
	// system("leaks Base");
	return 0;
}