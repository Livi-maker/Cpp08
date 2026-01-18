#include "Span.hpp"

int main()
{
	{
		Span prova(9999);

		prova.addRange(1, 100000);
		std::cout << prova.shortestSpan() << std::endl;
	}
	{
		Span sp = Span(3);
		sp.addNumber(-2147483648);
		sp.addNumber(0);
		sp.addNumber(1);
		std::cout << "short " << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return 0;
	}
}
