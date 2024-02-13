/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>

string calcSum(int* sequence, int size)
{

	int indice[size];
	int sum[size];
	int val = 0;

	for (int i = 0; i < size; i++){
		val = 0;
		// sum of subsequence starting at index i
		for ( int j = i; j < size; j++){
			val += sequence[j];
			if(i == 0 || val < sum[j-i]){
				sum[j-i] = val;
				indice[j - i] = i;
			}
		}
	}

	ostringstream s;
	for(int i = 0; i < size;i++){
		s << sum[i] << "," << indice[i]  << ";";
	}

	return s.str();
}

