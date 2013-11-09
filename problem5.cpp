#include <iostream>
#include <vector>

bool isPrime(int number)
{
	bool isPrime = true;	
	for (int i = 2; i < number; ++i)
		if (number % i == 0)
		{
			isPrime = false;
			break;
		}
	return isPrime;
}	

int main()
{
	int range = 20;	
	int primeMultiple;	
	int leastCommonMultiple = 1;	
	for (int i = 2; i <= range; ++i)
		if (isPrime(i))
		{
			primeMultiple = i;
			while (primeMultiple <= range)
			{
				primeMultiple *= i;
			}
			leastCommonMultiple *= (primeMultiple / i);
		}	
	
	std::cout << "Least common multiple: " << leastCommonMultiple << std::endl;  
}
