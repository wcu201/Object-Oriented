#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PerfectNum()
{
	int sum = 0;
	for (int i = 1; i < 29; i++)
	{
		sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i%j == 0)
				sum += j;
		}
		if (sum == i)
			cout << i + " is a perfect number" << endl;
	}
}

int main()
{
	int sum;
	for (int i = 6; i < 29; i++)
	{
		sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i%j == 0)
				sum += j;
		}
		if (sum == i)
			cout << i + " is a perfect number" << endl;
	}
	cin.get();
}