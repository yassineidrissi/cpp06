/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:17:24 by yaidriss          #+#    #+#             */
/*   Updated: 2023/12/31 16:18:53 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

const char* ScalarConverter::MyException::what() const throw()
{
	return (RED "input is not printable" RESET);
};

void convert_err(void)
{
	std::cout << RED << "char : " << RESET << "impossible" << std::endl;
	std::cout << RED << "int : " << RESET << "impossible" << std::endl;
	std::cout << RED << "float : " << RESET << "impossible" << std::endl;
	std::cout << RED << "double : " << RESET << "impossible" << std::endl;
}

void put_char(const char c)
{
	if (std::isprint(c))
		std::cout << GREEN << "char : " << RESET << "'" << c << "'" << std::endl;
	else
		std::cout << RED << "char : " << RESET << "Non displayable" << std::endl;
}
void convert_char(std::string c)
{
	const char *s = c.c_str();
	put_char(s[0]);
	std::cout << YELLOW << "int : " << RESET << static_cast<int>(s[0]) << std::endl;
	std::cout << GREEN << "float : " << RESET << static_cast<float>(s[0]) << std::endl;
	std::cout << YELLOW << "double : " << RESET << static_cast<double>(s[0]) << std::endl;

}

void printf_fd(std::string s)
{
	int f = std::atof(s.c_str());
    int n = static_cast<int>(f);
	if (f - n == 0)
	{
		std::cout << GREEN << "float : " << RESET << f << ".0f" << std::endl;
		std::cout << YELLOW << "double :" << RESET << f << ".0" << std::endl;
	}
	else
	{
		std::cout << GREEN << "float : " << RESET << f << "f" << std::endl;
		std::cout << YELLOW << "double :" << RESET << f << std::endl;
	}
}

void convert_int(std::string n)
{
	const char * s = n.c_str(); 
	put_char(static_cast<int>(std::atoi(s)));
	std::cout << YELLOW << "int : " << RESET << static_cast<int>(std::atoi(s))  << std::endl;
	printf_fd(n);
}


void convert_fd(std::string d)
{
	const char * s = d.c_str();	
	put_char(static_cast<int>(std::atof(s)));
	std::cout << YELLOW << "int : " << RESET << static_cast<int>(std::atof(s)) << std::endl;
	printf_fd(s);
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
	size_t i = 0;
	for(; i < s.length(); i++)
	{
		if(s[i] == '.' && !f)
			p++;
		else if(s[i] == 'f')
			f++;
		else if(std::isdigit(s[i]))
			d++;
		else
			err++;
	}
	if(s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff")
		convert_handl(s);
	else if(d == s.length())
		convert_int(s);
	else if(p < 2 && f < 2 && !err)
		convert_fd(s);
	else if(i == 1 && std::isdigit(s[0]))
		convert_int(s);
	else if(s.length() == 1)
		convert_char(s);
	else
		convert_err();
};