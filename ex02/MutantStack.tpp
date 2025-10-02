#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& ref) : std::stack<T>(ref)
{}

template<typename T>
MutantStack<T>& MutantStack<T>::operator= (const MutantStack& ref)
{
	*this = ref;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}