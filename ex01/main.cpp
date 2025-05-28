/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:33:36 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/28 11:00:39 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	Span1(10);

	try
	{
		Span1.addNumber(8);
		Span1.addNumber(12);
		Span1.addNumber(24);
		Span1.addNumber(9);
		Span1.addNumber(14);
		Span1.addNumber(32);
		Span1.addNumber(13);
		Span1.addNumber(-8);
		Span1.addNumber(16);
		Span1.addNumber(-2);
		//Span1.addNumber(-800);
	}
	catch (const Span::FullSpanException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		int	longest_span = Span1.longestSpan();
		std::cout << "Longest span is " << longest_span << std::endl;
	}
	catch(const Span::EmptySpanException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Span::OnlyOneException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		int	shortest_span = Span1.shortestSpan();
		std::cout << "Shortest span is " << shortest_span << std::endl;
	}
	catch(const Span::EmptySpanException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Span::OnlyOneException & e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span				newSpan(10);
	std::list<int>		listToInsert;
	std::vector<int>	vectToInsert;
	
	listToInsert.push_back(11);
	listToInsert.push_back(14);
	listToInsert.push_back(-11);
	listToInsert.push_back(33);
	listToInsert.push_back(32);

	vectToInsert.push_back(12);
	vectToInsert.push_back(16);
	vectToInsert.push_back(-18);
	
	newSpan.addNumber(10);
	newSpan.addNumber(-14);
	
	try
	{
		newSpan.addNumber(listToInsert.begin(), listToInsert.end());
		newSpan.addNumber(vectToInsert.begin(), vectToInsert.end());
		
		int	shortest_span = newSpan.shortestSpan();
		std::cout << "Shortest span is " << shortest_span << std::endl;
		int	longest_span = newSpan.longestSpan();
		std::cout << "Longest span is " << longest_span << std::endl;
		
		newSpan.addNumber(vectToInsert.begin(), vectToInsert.end());
	}
	catch(const Span::FullSpanException & e)
	{
		std::cerr << e.what() << '\n';
	}
}
