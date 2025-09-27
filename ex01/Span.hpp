#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& ref);
		Span& operator= (const Span& ref);
		~Span(void);

		void	addNumber(int toAdd);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		void	printArray(void) const;

	private:
		unsigned int _N;
		std::vector<int> array;
};
