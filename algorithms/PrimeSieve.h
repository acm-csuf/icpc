#ifndef PRIMEsieve
#define PRIMEsieve
#include <iostream>
#include <vector>
using namespace std;

/*-------------------------------------------------------------------
Name: Primesieve
Purpose: Utilizes the sieve of Eratosthenes to find lists of primes.
Example Uses:
1)
	Primesieve s;			
	s.sieve(2, 100000);		//Finds all primes between 2 and 100000.
							//Subsequent tests are fast for n<100000.
	cout << (s.TestPrime(92837)?"prime\n":"not prime\n");
	cout << (s.TestPrime(78391)?"prime\n":"not prime\n");
	cout << (s.TestPrime(78401)?"prime\n":"not prime\n");
	cout << (s.TestPrime(97281)?"prime\n":"not prime\n");
	//=================
2)
	Primesieve s;
	s.TestPrime(92837);		//Since s is empty, finds all primes from
							//2 to sqrt(92837) and tests whether any
							//divide 92837 evenly. This is faster if
							//only a few tests are performed, but the
							//use #1 is recommended for multiple
							//tests. Subsequent tests are slow.
-------------------------------------------------------------------*/

class Primesieve{
private:
	int lastEnd;
	vector< pair<int, int> > primeList;

	bool BinarySearch(int n)
	{
		int L = 0, R = primeList.size()-1, i;
		while (i = int((R-L)/2 + L), L<=R)
		{
			if (primeList[i].first == n)
			{
				return true;
			}
			else if (primeList[i].first < n)
			{
				L = i+1;
			}
			else
			{
				R = i-1;
			}
		}

		return false;
	}

	void Display()
	{
		for (int i=0; i<primeList.size(); i++)
		{
			cout << primeList[i].first << ' ';
		}
		cout << endl;
	}
public:
	Primesieve()
	{
		lastEnd = 2;
		pair<int,int> temp(2, 0);
		if (primeList.size() == 0) primeList.push_back(temp);
	}

	void sieve(int start, int end)
	{
		for (int i=lastEnd+1; i<=end; i++)
		{
			bool prime = true;
			for (int j=0; j<primeList.size(); j++)
			{
				if (primeList[j].first == i)
				{
					prime = false;
					break;
				}

				primeList[j].second++;
				if (primeList[j].second == primeList[j].first)
				{
					primeList[j].second = 0;
					prime = false;
				}
			}

			if (prime){
				pair<int,int> temp(i, 0);
				primeList.push_back(temp);
			}
		}

		lastEnd = end;
	}

	bool TestPrime(int n)
	{
		bool prime = true;

		if (primeList[primeList.size()-1].first >= n)
		{
			//The number is already in the sieve; search for it.
			return BinarySearch(n);
		}
		else if (primeList[primeList.size()-1].first < sqrt(double(n)))
		{
			//We don't have enough numbers to test n; sieve up to sqrt(n).
			sieve(primeList[primeList.size()-1].first+1, sqrt(double(n)));
			for (int i=0; i<primeList.size(); i++)
			{
				//Test if any of the primes found so far divide n.
				//This is theoretically faster than seiving up to n, but
				//it does not save any results for later. If multiple
				//tests will be made, it is recommended that sieve(n) be
				//called first.
				if (n % primeList[i].first == 0)
				{
					prime = false;
					break;
				}
			}
		}

		//Display();

		return prime;
	}
};

#endif