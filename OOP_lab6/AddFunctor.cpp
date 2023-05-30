#include "AddFunctor.h"

void AddFunctor::operator()(int* a, int b)
{
	*(a) += b;
}
