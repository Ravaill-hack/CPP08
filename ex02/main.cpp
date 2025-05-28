/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:03:21 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/28 11:56:11 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

// int	main(void)
// {
// 	MutantStack<int>	MutantStack01;

// 	MutantStack01.push(10);
// 	MutantStack01.push(12);
// 	MutantStack01.push(8);
// 	MutantStack01.push(14);
// 	MutantStack01.push(-8);
// 	MutantStack01.push(26);
// 	MutantStack01.push(17);

// 	MutantStack<int>::iterator it = MutantStack01.begin();
// 	while (it != MutantStack01.end())
// 	{
// 		std::cout << *it << std::endl;
// 		*it++;
// 	}
// }

int main()
{
	std::cout << "\nATTEMPTING WITH A MUTANT STACK" << std::endl;
	MutantStack<int>	mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "\nATTEMPTING WITH A LIST" << std::endl;
	std::list<int>	mslist;
	
	mslist.push_back(5);
	mslist.push_back(17);
	
	std::cout << mslist.back() << std::endl;
	
	mslist.pop_back();
	
	std::cout << mslist.size() << std::endl;
	
	mslist.push_back(3);
	mslist.push_back(5);
	mslist.push_back(737);
	//[...]
	mslist.push_back(0);
	
	std::list<int>::iterator lit = mslist.begin();
	std::list<int>::iterator lite = mslist.end();
	
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> sl(mslist);
	return 0;
}
