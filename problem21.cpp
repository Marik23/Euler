#include <iostream>
#include <cmath>

int main()
{
    int limit = 10000;
    int sum = 0;
    int sums[limit];
    int sumDivisors;
    int sqrtNum;
    for (int i = 1; i < limit; ++i)
    {
	sumDivisors = 1;
	sqrtNum = sqrt(i);
	for (int j = 2; j < sqrtNum; ++j)
	    if (i % j == 0)
	    {
		sumDivisors += j;
		sumDivisors += i/j;
	    }
	sums[i] = sumDivisors;
    }

    int currentDivisors;
    for (int i = 1; i < limit; ++i)
    {
	currentDivisors = sums[i];
	if (currentDivisors != i)
	{
	    if (currentDivisors < limit && i == sums[currentDivisors])
		sum += i;
	}
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
