/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:33:05 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/28 10:52:41 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 CANONIC                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Span::Span() : _N(0) {}

Span::~Span(){}

Span::Span(const Span & toCopy)
{
	*this = toCopy;
}

Span & Span::operator=(const Span & other)
{
	if (this != &other)
	{
		_N = other._N;
		_Span = other._Span;
	}
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                           OTHER CONSTRUCTORS                             ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Span::Span(int N) : _N(N) {}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                             MEMBER FUNCTIONS                             ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	Span::addNumber(int nb)
{
	if (_Span.size() == static_cast<size_t>(_N))
		throw FullSpanException();
	_Span.push_back(nb);
}

void 	Span::addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd)
{
	if (_Span.size() + std::distance(itBegin, itEnd) > static_cast<size_t>(_N))
		throw Span::FullSpanException();
	else
		_Span.insert(_Span.end(), itBegin, itEnd);
}

void 	Span::addNumber(std::list<int>::iterator itBegin, std::list<int>::iterator itEnd)
{
	if (_Span.size() + std::distance(itBegin, itEnd) > static_cast<size_t>(_N))
		throw Span::FullSpanException();
	else
		_Span.insert(_Span.end(), itBegin, itEnd);
}
	
int		Span::shortestSpan() const
{
	if (_Span.size() == 0)
		throw EmptySpanException();
	if (_Span.size() == 1)
		throw OnlyOneException();
	std::vector<int>	tmp = _Span;
	std::sort(tmp.begin(), tmp.end());
	int	nb_min = tmp.end() - tmp.begin();
	int	i = 1;
	while (i < _N)
	{
		if (tmp[i] - tmp[i - 1] < nb_min)
			nb_min = tmp[i] - tmp[i - 1];
		i++;
	}
	return (nb_min);
}

int		Span::longestSpan() const
{
	if (_Span.size() == 0)
		throw EmptySpanException();
	if (_Span.size() == 1)
		throw OnlyOneException();
	return (*std::max_element(_Span.begin(), _Span.end()) - *std::min_element(_Span.begin(), _Span.end()));
}
