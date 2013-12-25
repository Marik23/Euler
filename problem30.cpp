#include <iostream>
#include <cmath>

int main()
{
    int end = 200000;
    int remainder;
    int partSum;
    int sum = 0;

    for (int i = 10; i <= end; ++i)
    {
	remainder = i;
	partSum = 0;
	
	while (remainder > 9)
	{
	    partSum += pow((remainder % 10), 5);
	    remainder /= 10;
	}
	partSum += pow((remainder % 10), 5);

	if (partSum == i)
	{
	    sum += partSum;
	    std::cout << i << std::endl;
	}
    }

    std::cout << "Total sum: " << sum << std::endl;

    return 0;
}
