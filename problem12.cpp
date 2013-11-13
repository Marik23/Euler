#include <iostream>
#include <cmath>

int main()
{
    int numberOfDivisors;
    int triangleNumber = 1;
    int consecutiveNumber = 2;
    int limit;

    while (numberOfDivisors < 500)
    {
	numberOfDivisors = 2;
	triangleNumber += consecutiveNumber;
	limit = sqrt(triangleNumber);
	
	for (int i = 2; i < limit; ++i)
	    if (triangleNumber % i == 0)
		numberOfDivisors += 2;
	
	// In case the tirangle number is a square
	if (triangleNumber % limit == 0)
	    ++numberOfDivisors;
	
	++consecutiveNumber;
    }

    std::cout << "Triangle number: " << triangleNumber << std::endl;

    return 0;
}
