#include <iostream>
#include <cmath>
#include <set>
#include <vector>

void calculateSieveOfEratosthenes(std::vector<int>& primes, int maxValue)
{
	// Low time complexy -> use a set
	std::set<int> noPrimes;
	for (int i = 2; i < maxValue; ++i)
	{
		// Is current number a multiple of an already found prime?
		if (noPrimes.find(i) == noPrimes.end())
		{
			primes.push_back(i);
			// Insert new multiple of current prime
			for (int j = 2*i; j < maxValue; j += i)
			{
				noPrimes.insert(j);
			}
		}
	}
}
	
int main()
{
	long long number = 600851475143;
	double loopEnd = std::sqrt(number);
	
	int largestPrimeFactor = 1;

	std::vector<int> primes;
	calculateSieveOfEratosthenes(primes, loopEnd); 
	
	for (std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
	{
		if (number % (*it) == 0)
			largestPrimeFactor = (*it);	
	}
	std::cout << "Largest prime factor: " << largestPrimeFactor << std::endl;
}
