
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

class Span
{
	public:
		Span();
		~Span();
		Span(const Span & toCopy);
		Span & operator=(const Span & other);

		Span(int N);

		void	addNumber(int nb);
		void 	addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);
		void 	addNumber(std::list<int>::iterator itBegin, std::list<int>::iterator itEnd);
		int		shortestSpan() const;
		int		longestSpan() const;
		
		class FullSpanException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("Cannot add a number; the span is already full");
				} 
		};
		class EmptySpanException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("The span is empty");
				} 
		};
		class OnlyOneException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("There is only one value in the span");
				} 
		};

	private:
		int					_N;
		std::vector<int>	_Span;

};

#endif