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
		std::vector<int>::iterator shortestSpan(void);
		std::vector<int>::iterator longestSpan(void);

	private:
		unsigned int _N;
		std::vector<int> array;
};		
