#include "Span.hpp"

Span::Span(void) : _N(0), array(NULL)
{}

Span::Span(unsigned int N) : _N(N)
{
	array = new int[N];
}

Span::Span(const Span& ref)
{
	N = ref._N;
	for (unsigned int i = 0; i < ref._N; i++)
		array[i] = ref.array[i];
}
