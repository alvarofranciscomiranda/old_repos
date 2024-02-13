	/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if (n == 0)
		return 1;

	return n * factorialRecurs(n-1) ;
}

int factorialDinam(int n)
{
	int result = 1;
	for(int i = n; i > 0; i--){
		result *= i;
	}
	return result;
}