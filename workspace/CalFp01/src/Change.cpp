/*
 * Change.cpp
 */

#include "Change.h"

string calcChange(int m, int numCoins, int *coinValues)
{

	int minCoins[m + 1];
	int lastCoin[m + 1] = {0};

	if(m == 0){
		return "";
	}

	if(coinValues[0] > m){
		return "-";
	}



	minCoins[0] = 0;

	for(int i = 0; i < numCoins; i++)
			for( int k = coinValues[i]	; k <= m; k++)
				if(minCoins[k-coinValues[i]] + 1 < minCoins[k]){
					minCoins[k] = 1 + minCoins[k-coinValues[i]];
					lastCoin[k] = coinValues[i];
				}

	ostringstream oss;
	for(int k = m; k > 0; k -= lastCoin[k])
		oss << lastCoin[k] << ";";
	return oss.str();
}


