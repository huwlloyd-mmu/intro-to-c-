#include "stdafx.h"
using namespace std;

int main()
{
	int nTimesTable;

	cout << "Input a number :";
	cin >> nTimesTable;

	for (int i = 2; i <= 12; i++)
	{
		cout << nTimesTable << " * " << i << " = " << nTimesTable*i << endl;
	}


	return 0;
}