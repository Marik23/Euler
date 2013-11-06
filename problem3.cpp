#include <iostream>
#include <cmath>
#include <vector>

int main()
{
	long long number = 600851475143;
	//long long number = 99;	
	int largestPrimeFactor = 1;
	int factor = 2;

	while (number > 1)
	{
		if ((number % factor) == 0)
		{
			largestPrimeFactor = factor;
			number /= factor;
		} else { 
			++factor;	
		}	
	} 

	std::cout << "Largest prime factor: " << largestPrimeFactor << std::endl;
}
