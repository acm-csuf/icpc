#include <iostream>
using namespace std;

void PrimeFactors(int n)
{
	for (int i=2; i<=n; i++)
	{
		if (n % i == 0)
		{
			cout << i << " ";
			n /= i;
			i--;
		}
	}
}

void UniquePrimeFactors(int n)
{
	int last = 0;

	for (int i=2; i<=n; i++)
	{
		if (n % i == 0 && i != last)
		{
			cout << i << " ";
			n /= i;
			last = i;
			i--;
		}
	}
}

int main()
{
	int number;
	cout << "Please enter a number: ";
	cin >> number;

	cout << "Prime factorization: ";
	PrimeFactors(number);
	cout << endl;

	cout << "Unique prime factorization: ";
	UniquePrimeFactors(number);
	cout << endl;

	system("pause");
	return 0;
}