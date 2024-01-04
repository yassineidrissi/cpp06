/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:17:24 by yaidriss          #+#    #+#             */
/*   Updated: 2024/01/04 22:21:39 by yaidriss         ###   ########.fr       */
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

void put_char(double c)
{
	if (c > 255 || c < 0)
		std::cout << RED << "char :" << RESET << " impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << GREEN << "char : " << RESET << "'" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << RED << "char : " << RESET << "Non displayable" << std::endl;
}

void printf_fd(std::string s)
{
	int i = 0;
	if (s[s.length() - 1] == '.' || s[s.length() - 1] == 'f')
		i++;
	if(s[s.length() - 2] == '.')
		i++;
	s.erase(s.length() - i);
	std::istringstream	ss(s);
	double f;
	ss >> f;

	double max_val = std::numeric_limits<float>::max();
	double min_val = std::numeric_limits<float>::lowest();
	if (f > max_val || f < min_val) 
	{
		std::cout << RED << "float : " << RESET << "impossible" << std::endl;
		std::cout << RED << "double : " << RESET << "impossible" << std::endl;
		return ;
	}
	std::cout << GREEN << "float : " << RESET <<  std::fixed << std::setprecision(1)  << f<< "f" << std::endl;
	std::cout << YELLOW << "double :" << RESET << f << std::endl;
}

void convert_int(std::string n)
{

	double d = static_cast<double>(std::atof(n.c_str()));
	if (d > INT_MAX || d < INT_MIN)
	{
		convert_err();
		return ;
	}
	put_char(d);
	std::cout << YELLOW << "int : " << RESET << static_cast<int>(d)  << std::endl;
	printf_fd(n);
}


void convert_d(std::string d)
{
	const char * s = d.c_str();	
	double fd = static_cast<double>(std::atof(s));
	put_char(static_cast<int>(std::atof(s)));
	if (fd > INT_MAX || fd < INT_MIN)
		std::cout << RED << " int : " << RESET << "impossible" << std::endl;
	else 
		std::cout << YELLOW << "int : " << RESET << static_cast<int>(std::atof(s)) << std::endl;
	printf_fd(s);
}

void convert_f(std::string d)
{
	const char * s = d.c_str();	
	double fd = static_cast<double>(std::atof(s));
	put_char(static_cast<int>(std::atof(s)));
	if (fd > INT_MAX || fd < INT_MIN)
		std::cout << RED << " int : " << RESET << "impossible" << std::endl;
	else 
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
	size_t len = s.length();
	for(; i < len; i++)
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
	else if((d == len) || (d = len -1 && (s[0] == '-' || s[0] == '+')))
		convert_int(s);
	else if(p < 2 && !f && !err)
		convert_d(s);
	else if(p < 2 && f < 2 && !err && s[len - 1] == 'f')
		convert_f(s);
	else if(i == 1 && std::isdigit(s[0]))
		convert_int(s);
	else
		convert_err();
};