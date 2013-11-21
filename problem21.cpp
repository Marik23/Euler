#include <iostream>
#include <cmath>
#include <map>

int main()
{
    int limit = 10000;
    int sum = 0;
    std::map<int, int> sums;
    std::multimap<int, int> sumsInverse;
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
	sumsInverse.insert(std::pair<int, int>(sumDivisors, i));
    }


    std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> values;
    for (int i = 1; i < limit; ++i)
    {
	values = sumsInverse.equal_range(i);
	for (std::multimap<int, int>::iterator it = values.first; it != values.second; ++it)
	    if (it->second == sums[i] && it->second != it->first)
	    {
		sum += i;
	    }
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
