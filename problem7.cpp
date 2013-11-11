#include <iostream>
#include <vector>

int main()
{
    int numPrime = 10001;
    int numCurrentPrime = 0;
    int currentNumber = 1;
    std::vector<int> foundPrimes;
    bool isPrime;
    while (numPrime != numCurrentPrime)
    {
	++currentNumber;
	isPrime = true;
	for (std::vector<int>::iterator it = foundPrimes.begin(); it != foundPrimes.end(); ++it)
	{
	    if (currentNumber % (*it) == 0)
	    {
		isPrime = false;
		break;
	    }
	}
	if (isPrime)
	{
	    foundPrimes.push_back(currentNumber);
	    ++numCurrentPrime;
	}
    }
    
    std::cout << numPrime << ". primenumber: " << currentNumber << std::endl;
}
