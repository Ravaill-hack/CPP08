/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:16:46 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/27 11:07:33 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vect;
	int					v1 = 2;
	int					v2 = 12;

	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(5);
	vect.push_back(6);
	vect.push_back(7);
	vect.push_back(8);
	vect.push_back(9);

	try
	{
		std::vector<int>::iterator iter = easyfind(vect, v1);
		std::cout << v1 << " has been found in container at " << *iter << std::endl;
	}
	catch(const OccurenceNotFoundException & e)
	{
		std::cerr << v1 << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator iter = easyfind(vect, v2);
		std::cout << v2 << " has been found in container at " << *iter << std::endl;
	}
	catch(const OccurenceNotFoundException & e)
	{
		std::cerr << v2 << e.what() << std::endl;
	}
	
}