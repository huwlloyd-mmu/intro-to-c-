#include "stdafx.h"

using namespace std;

mt19937 randGen;
unsigned int seed = 12345;

void InitRandom()
{
	randGen = mt19937(seed);
}

double Random()
{
	return (double)randGen() / (double)randGen.max();
}

int main()
{
	// print out 10 random numbers
	for (int i = 0; i < 10; i++)
	{
		cout << Random() << endl;
	}
	return 0;
}