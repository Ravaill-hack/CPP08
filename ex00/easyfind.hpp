
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

class OccurenceNotFoundException : public std::exception
{
	public:
		const char * what() const throw()
		{
			return (" has been not found in container");
		}
};

template <typename T>
typename T::iterator	easyfind(T & cont, int val)
{
	typename T::iterator	iter = std::find(cont.begin(), cont.end(), val);
	if (iter == cont.end())
		throw OccurenceNotFoundException();
	return (iter);
}

#endif