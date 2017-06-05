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
	InitRandom();

	long long int count = 0;
	long long int maxCount = 100000000;
	
	for (long long int i = 0; i < maxCount; i++)
	{
		double x = Random();
		double y = Random();
		if (x*x + y*y < 1.0)
			count++;
	}
	
	double pi = 4.0f * count / (double)maxCount;
	cout << "count: " << count << " maxCount: " << maxCount << endl;
	cout << "pi is " << setprecision(7) << pi << endl;

	return 0;

}