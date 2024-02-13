/*
 * Partioning.cpp
 */

#include "Partitioning.h"


int s_recursive(int n,int k)
{
   if(k == 1 || k >= n)
	   return 1;

   return s_recursive(n-1,k-1) + k * s_recursive(n-1,k);
}

int s_dynamic(int n,int k)
{
	int sum;
	int k1 = k;
	while(k != 1 || k != n)
		sum +=

		k1 --;
		n = n - 1;
	return sum;
}


int b_recursive(int n)
{
	int sum = 0;

	sum += s_recursive(n,1);

	return sum;
}

int b_dynamic(int n)
{
	return 0;
}


