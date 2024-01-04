/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:58:39 by yaidriss          #+#    #+#             */
/*   Updated: 2024/01/02 05:23:01 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip> 
#include <sstream>
#include <limits>
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class ScalarConverter
{
	private:
	    
	public:
		static void convert(std::string s);
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		class MyException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};	
};