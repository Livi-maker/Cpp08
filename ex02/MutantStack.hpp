#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <list>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack& ref);
		MutantStack& operator= (const MutantStack& ref);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void);
		iterator end(void);
};

#include "MutantStack.tpp"