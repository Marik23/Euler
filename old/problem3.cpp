#include <iostream>
#include <cmath>
#include <set>
#include <vector>

void calculateSieveOfEratosthenes(std::vector<int>& primes, long long maxValue)
{
	// Low time complexy -> use a set
	std::set<int> noPrimes;
	long long sqrtMaxValue = std::sqrt(maxValue);
	for (int i = 2; i < sqrtMaxValue; ++i)
	{
		// Is current number a multiple of an already found prime?
		if (noPrimes.find(i) == noPrimes.end())
		{
			primes.push_back(i);
			// Insert new multiple of current prime
			for (int j = i*i; j < maxValue; j += i)
			{
				noPrimes.insert(j);
			}
		}
	}
	std::cout << "rest primes" << std::endl;
	long long halfMaxValue = maxValue / 2;
	for (int i = sqrtMaxValue; i < halfMaxValue; ++i)
	{
		if (noPrimes.find(i) == noPrimes.end())
			primes.push_back(i);
	}
}
	
int main()
{
	long long number = 600851475143;
	//long long number = 99;	
	int largestPrimeFactor = 1;

	std::vector<int> primes;
	calculateSieveOfEratosthenes(primes, number); 
	
	for (std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
	{
		if (number % (*it) == 0)
			largestPrimeFactor = (*it);	
	}
	std::cout << "Largest prime factor: " << largestPrimeFactor << std::endl;
}
