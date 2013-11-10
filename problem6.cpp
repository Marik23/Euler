#include <iostream>
#include <cmath>

int main()
{
	int sumSquares = 0;
	int squareSum = 0;
	int range = 100;
	for (int i = 1; i <= range; ++i)
	{
		sumSquares += pow(i, 2);
	}

	// With help of "Gaussche Summenformel"
	squareSum = pow((pow(range,2)+range)/2,2);
	
	std::cout << "Difference: " << squareSum << " - " << sumSquares << " = " << squareSum - sumSquares << std::endl;
}
