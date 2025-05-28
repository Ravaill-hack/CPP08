/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:33:36 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/28 10:21:11 by lmatkows         ###   ########.fr       */
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
		Span1.addNumber(-800);
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
}
