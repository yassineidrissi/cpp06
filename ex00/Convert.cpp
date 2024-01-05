/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:17:24 by yaidriss          #+#    #+#             */
/*   Updated: 2024/01/05 19:34:08 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void convert_err(void)
{
	std::cout << RED << "char : " << RESET << "impossible" << std::endl;
	std::cout << RED << "int : " << RESET << "impossible" << std::endl;
	std::cout << RED << "float : " << RESET << "impossible" << std::endl;
	std::cout << RED << "double : " << RESET << "impossible" << std::endl;
}

void put_char(double c)
{
	if (c > 255 || c < 0)
		std::cout << RED << "char :" << RESET << " impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << GREEN << "char : " << RESET << "'" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << RED << "char : " << RESET << "Non displayable" << std::endl;
}

void printf_fd(double f)
{
	double max_f = std::numeric_limits<float>::max();
	double min_f = std::numeric_limits<float>::lowest();
	if (f > max_f || f < min_f) 
	{
		std::cout << RED << "float : " << RESET << "impossible" << std::endl;
		std::cout << RED << "double : " << RESET << "impossible" << std::endl;
	}
	else
	{
		std::cout << GREEN << "float : " << RESET <<  std::fixed << std::setprecision(1)  << f<< "f" << std::endl;
		std::cout << YELLOW << "double :" << RESET << std::fixed << std::setprecision(1)  << f << std::endl;
	}
}

void convert_print(std::string s)
{
	const char * d = s.c_str();
	double fd = static_cast<double>(std::atof(d));
	put_char(fd);
	if (fd > INT_MAX || fd < INT_MIN)
		std::cout << RED << " int : " << RESET << "impossible" << std::endl;
	else 
		std::cout << YELLOW << "int : " << RESET << static_cast<int>(std::atof(d)) << std::endl;

	printf_fd(fd);
}

void convert_handl(std::string s)
{
	if (s == "nan")
	{
		std::cout << GREEN << "char : " << RESET << "impossible" << std::endl;
		std::cout << YELLOW << "int : " << RESET << "impossible" << std::endl;
		std::cout << GREEN << "float : " << RESET << "nanf" << std::endl;
		std::cout << YELLOW << "double : " << RESET << "nan" << std::endl;
	}
	else if (s == "nanf")
	{
		std::cout << GREEN << "char : " << RESET << "impossible" << std::endl;
		std::cout << YELLOW << "int : " << RESET << "impossible" << std::endl;
		std::cout << GREEN << "float : " << RESET << "nanf" << std::endl;
		std::cout << YELLOW << "double : " << RESET << "nan" << std::endl;
	}
	else if (s == "+inf")
	{
		std::cout << GREEN << "char : " << RESET << "impossible" << std::endl;
		std::cout << YELLOW << "int : " << RESET << "impossible" << std::endl;
		std::cout << GREEN << "float : " << RESET << "+inff" << std::endl;
		std::cout << YELLOW << "double : " << RESET << "+inf" << std::endl;
	}
	else if (s == "+inff")
	{
		std::cout << GREEN << "char : " << RESET << "impossible" << std::endl;
		std::cout << YELLOW << "int : " << RESET << "impossible" << std::endl;
		std::cout << GREEN << "float : " << RESET << "+inff" << std::endl;
		std::cout << YELLOW << "double : " << RESET << "+inf" << std::endl;
	}
	else if (s == "-inf")
	{
		std::cout << GREEN << "char : " << RESET << "impossible" << std::endl;
		std::cout << YELLOW << "int : " << RESET << "impossible" << std::endl;
		std::cout << GREEN << "float : " << RESET << "-inff" << std::endl;
		std::cout << YELLOW << "double : " << RESET << "-inf" << std::endl;
	}
}

void ScalarConverter::convert(std::string s)
{
	size_t d = 0;
	size_t f = 0;
	size_t p = 0;
	size_t err = 0;
	size_t len = s.length();
	for(size_t i = 0; i < len; i++)
	{
		if(s[i] == '.' && !f && !p)
			p++;
		else if(s[i] == 'f' && !f && len == i + 1)
			f++;
		else if((std::isdigit(s[i])) || (!i && len > 1 && (s[i] == '-' || s[i] == '+')))
			d++;
		else
			err++;
	}
	if(s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff")
		convert_handl(s);
	else if(!err)
		convert_print(s);
	else
		convert_err();
};