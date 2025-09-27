#include "Span.hpp"

Span::Span(void) : _N(0), array(0)
{}

Span::Span(unsigned int N) : _N(N), array(0)
{}

Span::Span(const Span& ref) : array(0)
{
	_N = ref._N;
	for (size_t i = 0; i < ref.array.size(); i++)
		array.push_back(ref.array[i]);
}

Span&	Span::operator= (const Span& ref)
{
	_N =  ref._N;
	array.clear();
	for (size_t i = 0; i < ref.array.size(); i++)
		array.push_back(ref.array[i]);
	return (*this);
}

void	Span::addNumber(int toAdd)
{
	if (_N == 0)
		throw std::runtime_error("Array is full");
	array.push_back(toAdd);
	_N--;
}

void	Span::printArray(void) const
{
	for (size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;
}

unsigned int Span::shortestSpan(void)
{
	if (array.size() < 2)
		throw std::runtime_error("There are less than two elements");

	std::vector<int> sorted = array;
	std::sort(sorted.begin(), sorted.end());;
	unsigned int span = sorted[1] - sorted[0];
	for (size_t i = 0; i < sorted.size() - 1; i++)
		if (sorted[i + 1] - sorted[i] < (int)span)
			span = sorted[i + 1] - sorted[i];
	return (span);
}

unsigned int	Span::longestSpan(void)
{
	if (array.size() < 2)
		throw std::runtime_error("There are less than two elements");
	return (*(std::max_element(array.begin(), array.end())) - *(std::min_element(array.begin(), array.end())));
}

Span::~Span(void)
{}